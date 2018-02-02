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

	//�� ��� ���������� ����Ѵ�
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

	//ó���� ����Ʈ �ִϸ��̼� ������� �д�
	setDefPlayFrame();

	return S_OK;
}

HRESULT animation::init(int totalW, int totalH, int frameW, int frameH, int currentFrameY) {  //y��° ������ x���� ������ ����

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


//����Ʈ �ִϸ��̼� ���
void animation::setDefPlayFrame(BOOL reverse, BOOL loop)
{

	_obj = NULL;
	_cbFunction = NULL;
	_cbFunctionPara = NULL;

	//�������� 
	_loop = loop;
	//���ʹ� �� �� �ʱ�ȭ���ش�
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

//�迭�� �ִϸ��̼� ���(���ϴ� ������ ��ȣ �������ִ�)
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

//���� �ִϸ��̼� ���(ex : 2 ~ 8���� Ȥ�� 9 ~ 1����)
void animation::setPlayFrame(int start, int end, BOOL reverse, BOOL loop)
{
	_obj = NULL;
	_cbFunction = NULL;
	_cbFunctionPara = NULL;

	//���� ����
	_loop = loop;
	//�÷��� ���� �ʱ�ȭ
	_playList.clear();

	//����� �������� 1�̶��
	if (start == end)
	{
		_playList.clear();
		stop();
		return;
	}

	//start �����ӹ�ȣ�� end��ȣ���� Ŭ��(ex : 5 ~ 1)
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


//������ ��� �ӵ� ����
void animation::setFPS(int framePerSec)
{
	_frameUpdateSec = 1.0f / framePerSec;
}


void animation::frameUpdate(float elapsedTime)
{
	// _elapsedSec�� ó���� '0'�ε�
	// elapsedTime�� ��� �������鼭
	// setFPS���� ������ ������ �������� �������������� �Ѿ�¿�����
	// �� setFPS�� ���� ���ų�, elapsedTime�� ��������
	// �� ���� �������������� �Ѿ��
	if (_play)
	{
		_elapsedSec += elapsedTime;

		if (_elapsedSec >= _frameUpdateSec)
		{
			_elapsedSec -= _frameUpdateSec;
			_nowPlayIndex++;
			//������ ����� �Ǿ��ٸ�
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

	_playList.clear();		//������ ��ȣ �ʱ�ȭ (vector<POINT> ����)

							// *playList�� frameList�� �ٸ��Ŵ� �����ؾ���*
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

	_playList.clear();		//������ ��ȣ �ʱ�ȭ (vector<POINT> ����)

							// *playList�� frameList�� �ٸ��Ŵ� �����ؾ���*
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

	if (start == end) {		//���������Ӱ� ���������� ���ٸ� (�������� 1�̶�� ��)
		_playList.clear();
		stop();
		return;
	}

	if (start > end) {		// ������������ �������Ӻ��� ũ�ٸ� (������?)

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
	else {//������������ �������� ���� �۴ٸ� (����ȯ)

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
