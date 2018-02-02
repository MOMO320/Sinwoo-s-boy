#include "stdafx.h"
#include "animation.h"


animation::animation()
	: _frameNum(0),
	_frameWidth(0),
	_frameHeight(0),
	_loop(FALSE),
	_frameUpdateSec(0),
	_elapsedSec(0),
	_nowPlayIndex(0),
	_play(FALSE),
	_isStart(FALSE)
{
}


animation::~animation()
{

}

HRESULT animation::init(int totalW, int totalH, int frameW, int frameH)
{
	_frameWidth = frameW;
	int _frameNumWidth = totalW / _frameWidth;

	_frameHeight = frameH;
	int _frameNumHeight = totalH / _frameHeight;

	//총 몇개의 프레임인지 계산한다
	_frameNum = _frameNumWidth * _frameNumHeight;

	for (int i = 0; i < _frameNumHeight; ++i)
	{
		for (int j = 0; j < _frameNumWidth; ++j)
		{
			POINT framePos;

			framePos.x = j * _frameWidth;
			framePos.y = i * _frameHeight;

			_frameList.push_back(framePos);
		}
	}

	//처음엔 디폴트 애니메이션 재생으로 둔다
	setDefPlayFrame();

	return S_OK;
}

HRESULT animation::init(int totalW, int totalH, int frameW, int frameH, int currentFrameY) {  //y번째 열에서 x개의 프래임 갯수

	_frameWidth = frameW;
	int _frameNumWidth = totalW / _frameWidth;

	_frameHeight = frameH;
	int _frameNumHeight = totalH / _frameHeight;

	_frameNum = _frameNumWidth;

	int _currentFrameY = currentFrameY;


	for (int i = 0; i < _frameNumWidth; ++i) {

		POINT framePos;

		framePos.x = i*_frameWidth;
		framePos.y = _currentFrameY *_frameHeight;

		_frameList.push_back(framePos);

	}

	setDefPlayFrame();

	return S_OK;
}

void animation::release(void)
{

}


//디폴트 애니메이션 재생
void animation::setDefPlayFrame(BOOL reverse, BOOL loop)
{

	_obj = NULL;
	_cbFunction = NULL;
	_cbFunctionPara = NULL;

	//루프여부 
	_loop = loop;
	//벡터는 한 번 초기화해준다
	_playList.clear();

	if (reverse)
	{
		if (_loop)
		{
			for (int i = 0; i < _frameNum; ++i)
			{
				_playList.push_back(i);
			}
			for (int i = _frameNum - 1; i >= 0; --i)
			{
				_playList.push_back(i);
			}

		}
		else
		{
			for (int i = 0; i < _frameNum; ++i)
			{
				_playList.push_back(i);
			}
			for (int i = _frameNum - 1; i >= 0; --i)
			{
				_playList.push_back(i);
			}
		}
	}
	else
	{
		if (_loop)
		{
			for (int i = 0; i < _frameNum; ++i)
			{
				_playList.push_back(i);
			}
		}
		else
		{
			for (int i = 0; i < _frameNum; ++i)
			{
				_playList.push_back(i);
			}
		}
	}
}

//배열로 애니메이션 재생(원하는 프레임 번호 넣을수있다)
void animation::setPlayFrame(int* playArr, int arrLen, BOOL loop)
{
	_obj = NULL;
	_cbFunction = NULL;
	_cbFunctionPara = NULL;

	_loop = loop;

	_playList.clear();

	for (int i = 0; i < arrLen; ++i)
	{
		_playList.push_back(playArr[i]);
	}
}

//구간 애니메이션 재생(ex : 2 ~ 8번만 혹은 9 ~ 1번만)
void animation::setPlayFrame(int start, int end, BOOL reverse, BOOL loop)
{
	_obj = NULL;
	_cbFunction = NULL;
	_cbFunctionPara = NULL;

	//루프 여부
	_loop = loop;
	//플레이 벡터 초기화
	_playList.clear();

	//재생할 프레임이 1이라면
	if (start == end)
	{
		_playList.clear();
		stop();
		return;
	}

	//start 프레임번호가 end번호보다 클때(ex : 5 ~ 1)
	if (start > end)
	{
		if (reverse)
		{
			if (_loop)
			{
				for (int i = start; i >= end; --i)
				{
					_playList.push_back(i);
				}
				for (int i = end + 1; i < start; ++i)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i >= end; --i)
				{
					_playList.push_back(i);
				}
				for (int i = end + 1; i < start; ++i)
				{
					_playList.push_back(i);
				}
			}
		}
		else
		{
			if (_loop)
			{
				for (int i = start; i >= end; --i)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i >= end; --i)
				{
					_playList.push_back(i);
				}
			}
		}
	}
	else
	{
		if (reverse)
		{
			if (_loop)
			{
				for (int i = start; i < end; ++i)
				{
					_playList.push_back(i);
				}
				for (int i = end - 1; i >= start; --i)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i < end; ++i)
				{
					_playList.push_back(i);
				}
				for (int i = end - 1; i >= start; --i)
				{
					_playList.push_back(i);
				}
			}
		}
		else
		{
			if (_loop)
			{
				for (int i = start; i < end; ++i)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i < end; ++i)
				{
					_playList.push_back(i);
				}
			}
		}
	}
}


//프레임 재생 속도 셋팅
void animation::setFPS(int framePerSec)
{
	_frameUpdateSec = 1.0f / framePerSec;
}


void animation::frameUpdate(float elapsedTime)
{
	// _elapsedSec이 처음엔 '0'인데
	// elapsedTime이 계속 더해지면서
	// setFPS에서 설정한 값보다 높아질때 다음프레임으로 넘어가는원리임
	// 즉 setFPS의 값이 높거나, elapsedTime이 높을수록
	// 더 빨리 다음프레임으로 넘어간다
	if (_play)
	{
		_elapsedSec += elapsedTime;

		if (_elapsedSec >= _frameUpdateSec)
		{
			_elapsedSec -= _frameUpdateSec;
			_nowPlayIndex++;
			//끝까지 재생이 되었다면
			if (_nowPlayIndex == _playList.size())
			{
				_isStart = FALSE;

				if (_loop) _nowPlayIndex = 0;
				else
				{
					if (_obj == NULL) {
						if (_cbFunction != NULL) _cbFunction();
					}
					else {
						_cbFunctionPara(_obj);
					}
					_nowPlayIndex--;
					_play = FALSE;
				}
			}
		}
	}
}


void animation::setDefPlayFrame(BOOL reverse, BOOL loop, CALLBACK_FUNCTION cbFunction) {
	_obj = NULL;
	_cbFunction = cbFunction;
	_cbFunctionPara = NULL;

	_loop = loop;

	_playList.clear();		//프레임 번호 초기화 (vector<POINT> 형태)

							// *playList와 frameList는 다른거니 구별해야함*
	if (reverse) {

		for (int i = 0; i < _frameNum; ++i) {
			_playList.push_back(i);
		}
		for (int i = _frameNum - 1; i >= 0; --i) {
			_playList.push_back(i);
		}

	}
	else {
		for (int i = 0; i < _frameNum; ++i) {
			_playList.push_back(i);
		}
	}
}
void animation::setDefPlayFrame(BOOL reverse, BOOL loop, CALLBACK_FUNCTION_PARAMETER cbFunctionPara, void* obj) {

	_obj = obj;
	_cbFunction = NULL;
	_cbFunctionPara = cbFunctionPara;

	_loop = loop;

	_playList.clear();		//프레임 번호 초기화 (vector<POINT> 형태)

							// *playList와 frameList는 다른거니 구별해야함*
	if (reverse) {

		for (int i = 0; i < _frameNum; ++i) {
			_playList.push_back(i);
		}
		for (int i = _frameNum - 1; i >= 0; --i) {
			_playList.push_back(i);
		}

	}
	else {
		for (int i = 0; i < _frameNum; ++i) {
			_playList.push_back(i);
		}
	}

}

void animation::setPlayFrame(int* playArr, int arrLen, BOOL loop, CALLBACK_FUNCTION cbFunction) {

	_obj = NULL;
	_cbFunction = cbFunction;
	_cbFunctionPara = NULL;

	_loop = loop;

	_playList.clear();

	for (int i = 0; i < arrLen; ++i) {
		_playList.push_back(playArr[i]);
	}

}
void animation::setPlayFrame(int* playArr, int arrLen, BOOL loop, CALLBACK_FUNCTION_PARAMETER cbFunctionPara, void* obj) {

	_obj = obj;
	_cbFunction = NULL;
	_cbFunctionPara = cbFunctionPara;

	_loop = loop;

	_playList.clear();

	for (int i = 0; i < arrLen; ++i) {
		_playList.push_back(playArr[i]);
	}

}

void animation::setPlayFrame(int * playArr, int arrLen, BOOL reverse, BOOL looop, hitFunc cbhitFund)
{
	_cbFunction = NULL;
	_cbFunctionPara = NULL;
	_cbFunctionHit = move(cbhitFund);

	_loop = looop;

	_playList.clear();

	for (int i = 0; i < arrLen; ++i) {
		_playList.push_back(playArr[i]);
	}
}

void animation::setPlayFrame(int start, int end, BOOL reverse, BOOL loop, CALLBACK_FUNCTION cbFunction) {

	_obj = NULL;
	_cbFunction = cbFunction;
	_cbFunctionPara = NULL;

	_loop = loop;

	_playList.clear();

	if (start == end) {		//시작프레임과 끝프레임이 같다면 (프레임이 1이라는 뜻)
		_playList.clear();
		stop();
		return;
	}

	if (start > end) {		// 시작프레임이 끝프레임보다 크다면 (리버스?)

		if (reverse) {
			for (int i = start; i >= end; --i) {
				_playList.push_back(i);
			}
			for (int i = end + 1; i < start; ++i) {
				_playList.push_back(i);
			}
		}
		else {
			for (int i = start; i >= end; --i) {
				_playList.push_back(i);
			}
		}

	}
	else {//시작프레임이 끝프레임 보다 작다면 (정순환)

		if (reverse) {

			for (int i = start; i < end; ++i) {
				_playList.push_back(i);
			}
			for (int i = end - 1; i >= start; --i) {
				_playList.push_back(i);
			}

		}
		else {

			for (int i = start; i < end; ++i) {
				_playList.push_back(i);
			}
		}

	}

}

void animation::setPlayFrame(int start, int end, BOOL reverse, BOOL loop, CALLBACK_FUNCTION_PARAMETER cbFunctionPara, void* obj) {

	_obj = obj;
	_cbFunction = NULL;
	_cbFunctionPara = cbFunctionPara;

	_loop = loop;

	_playList.clear();

	if (start == end) {
		_playList.clear();
		stop();
		return;
	}

	if (start > end) {
		if (reverse) {
			for (int i = start; i >= end; --i) {
				_playList.push_back(i);
			}
			for (int i = end + 1; i < start; ++i) {
				_playList.push_back(i);
			}
		}
		else {
			for (int i = start; i >= end; --i) {
				_playList.push_back(i);
			}
		}
	}
	else {
		if (reverse) {

			for (int i = start; i < end; ++i) {
				_playList.push_back(i);
			}
			for (int i = end - 1; i >= start; --i) {
				_playList.push_back(i);
			}

		}
		else {

			for (int i = start; i < end; ++i) {
				_playList.push_back(i);
			}
		}
	}

}


void animation::start(void)
{
	_play = TRUE;
	_nowPlayIndex = 0;
}

void animation::onceStart(void) {

	if (!_isStart) {
		_isStart = TRUE;
		_play = TRUE;
		_nowPlayIndex = 0;
	}

}
void animation::onceStart(int nowPlayIndex) {

	if (!_isStart) {
		_isStart = TRUE;
		_play = TRUE;
		_nowPlayIndex = nowPlayIndex;
	}

}


void animation::stop(void)
{
	_isStart = FALSE;
	_play = FALSE;
	_nowPlayIndex = 0;
}

void animation::pause(void)
{
	_play = FALSE;
}

void animation::resume(void)
{
	_play = TRUE;
}
