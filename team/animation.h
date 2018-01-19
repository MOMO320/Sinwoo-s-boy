#pragma once
#include <vector>

// 1.�ݹ��Լ��� ����ϱ� ����
//   ������ �Լ� ����
typedef void(*CALLBACK_FUNCTION)(void);
typedef void(*CALLBACK_FUNCTION_PARAMETER)(void*);

class animation
{
public:
	typedef vector<POINT> vFrameList;	//������ ��ȣ ����Ʈ
	typedef vector<int> vPlayList;		//�ִϸ��̼� �÷��� ����Ʈ

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

	// 2. �ƹ��͵� �ٰ���ų�� �ִ� void �����Ϳ�
	//    �Լ������� ���� ����
	void*							_obj;
	CALLBACK_FUNCTION				_cbFunction;
	CALLBACK_FUNCTION_PARAMETER		_cbFunctionPara;

public:
	animation();
	~animation();

	HRESULT init(int totalW, int totalH, int frameW, int frameH);
	HRESULT init(int totalW, int totalH, int frameW, int frameH, int currentIndexY);
	void release(void);

	//����Ʈ �ִϸ��̼� ���
	void setDefPlayFrame(BOOL reverse = FALSE, BOOL loop = FALSE);
	//�迭�� �ִϸ��̼� ���(���ϴ� ������ ��ȣ �������ִ�)
	void setPlayFrame(int* playArr, int arrLen, BOOL loop = FALSE);
	//���� �ִϸ��̼� ���(ex : 2 ~ 8���� Ȥ�� 9 ~ 1����)
	void setPlayFrame(int start, int end, BOOL reverse = FALSE, BOOL loop = FALSE);


	//�ݹ� ��Ÿ�� �÷��� �������� �����
	void setDefPlayFrame(BOOL reverse, BOOL loop, CALLBACK_FUNCTION cbFunction);
	void setDefPlayFrame(BOOL reverse, BOOL loop, CALLBACK_FUNCTION_PARAMETER cbFunctionPara, void* obj);

	void setPlayFrame(int* playArr, int arrLen, BOOL loop, CALLBACK_FUNCTION cbFunction);
	void setPlayFrame(int* playArr, int arrLen, BOOL loop, CALLBACK_FUNCTION_PARAMETER cbFunctionPara, void* obj);

	void setPlayFrame(int start, int end, BOOL reverse, BOOL loop, CALLBACK_FUNCTION cbFunction);
	void setPlayFrame(int start, int end, BOOL reverse, BOOL loop, CALLBACK_FUNCTION_PARAMETER cbFunctionPara, void* obj);

	//������ ��� �ӵ� ����
	void setFPS(int framePerSec);

	void frameUpdate(float elapsedTime);

	void start(void);
	void onceStart(void);			// ������Ʈ�ȿ����� ��� �ݺ��ؼ� ������ ����.
	void stop(void);
	void pause(void);
	void resume(void);

	inline BOOL isPlay(void) { return _play; }
	inline POINT getFramePos(void) { return _frameList[_playList[_nowPlayIndex]]; }
	inline int getFrameWidth(void) { return _frameWidth; }
	inline int getFrameHeight(void) { return _frameHeight; }

};

