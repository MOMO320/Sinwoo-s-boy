#pragma once
#include <vector>

// 1.콜백함수를 사용하기 위한
//   포인터 함수 생성
typedef void(*CALLBACK_FUNCTION)(void);
typedef void(*CALLBACK_FUNCTION_PARAMETER)(void*);

class animation
{
public:
	typedef vector<POINT> vFrameList;	//프레임 번호 리스트
	typedef vector<int> vPlayList;		//애니메이션 플레이 리스트

private:
	int			_frameNum;
	vFrameList	_frameList;
	vPlayList	_playList;

	int			_frameWidth;
	int			_frameHeight;

	BOOL		_loop;

	float		_frameUpdateSec;
	float		_elapsedSec;

	DWORD		_nowPlayIndex;
	BOOL		_play;

	BOOL		_isStart;

	// 2. 아무것도 다가리킬수 있는 void 포인터와
	//    함수포인터 변수 생성
	void*							_obj;
	CALLBACK_FUNCTION				_cbFunction;
	CALLBACK_FUNCTION_PARAMETER		_cbFunctionPara;

public:
	animation();
	~animation();

	HRESULT init(int totalW, int totalH, int frameW, int frameH);
	HRESULT init(int totalW, int totalH, int frameW, int frameH, int currentIndexY);
	void release(void);

	//디폴트 애니메이션 재생
	void setDefPlayFrame(BOOL reverse = FALSE, BOOL loop = FALSE);
	//배열로 애니메이션 재생(원하는 프레임 번호 넣을수있다)
	void setPlayFrame(int* playArr, int arrLen, BOOL loop = FALSE);
	//구간 애니메이션 재생(ex : 2 ~ 8번만 혹은 9 ~ 1번만)
	void setPlayFrame(int start, int end, BOOL reverse = FALSE, BOOL loop = FALSE);


	//콜백 스타일 플레이 프레임을 만든다
	void setDefPlayFrame(BOOL reverse, BOOL loop, CALLBACK_FUNCTION cbFunction);
	void setDefPlayFrame(BOOL reverse, BOOL loop, CALLBACK_FUNCTION_PARAMETER cbFunctionPara, void* obj);

	void setPlayFrame(int* playArr, int arrLen, BOOL loop, CALLBACK_FUNCTION cbFunction);
	void setPlayFrame(int* playArr, int arrLen, BOOL loop, CALLBACK_FUNCTION_PARAMETER cbFunctionPara, void* obj);

	void setPlayFrame(int start, int end, BOOL reverse, BOOL loop, CALLBACK_FUNCTION cbFunction);
	void setPlayFrame(int start, int end, BOOL reverse, BOOL loop, CALLBACK_FUNCTION_PARAMETER cbFunctionPara, void* obj);

	//프레임 재생 속도 셋팅
	void setFPS(int framePerSec);

	void frameUpdate(float elapsedTime);

	void start(void);
	void onceStart(void);			// 업데이트안에서도 계속 반복해서 나오지 않음.
	void stop(void);
	void pause(void);
	void resume(void);

	inline BOOL isPlay(void) { return _play; }
	inline POINT getFramePos(void) { return _frameList[_playList[_nowPlayIndex]]; }
	inline int getFrameWidth(void) { return _frameWidth; }
	inline int getFrameHeight(void) { return _frameHeight; }

};

