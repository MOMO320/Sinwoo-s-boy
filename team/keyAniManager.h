#pragma once
#include "singletonBase.h"
#include <map>

// 1. 이미지클래스와 애니메이션 전방선인
class image;
class animation;

class keyAniManager :public singletonBase<keyAniManager>
{
private:
	// 2. 키와 애니메이션포인터 맵을 하나 만든다.
	typedef map<string, animation*>				arrAnimation;
	typedef map<string, animation*>::iterator	iterAnimations;

private:
	arrAnimation _mTotalAnimation;

public:
	keyAniManager();
	~keyAniManager();

	HRESULT init();
	void release();
	void update();
	void render();

	//디폴트 애니메이션
	void addDefaultFrameAnimation(string animationKeyName, char* imageKeyName, int fps, bool reverse, bool loop);
	void addDefaultFrameAnimation(string animationKeyName, char* imageKeyName, int fps, bool reverse, bool loop, void* cbFunction);
	void addDefaultFrameAnimation(string animationKeyName, char* imageKeyName, int fps, bool reverse, bool loop, void* cbFunction, void* obj);

	void addDefaultFrameAnimation(string animationKeyName, char* imageKeyName, int fps, bool reverse, bool loop, int currentFrmaeY);

	//배열 애니메이션
	void addArrayFrameAnimation(string animationKeyName, char* imageKeyName, int* arr, int arrLen, int fps, bool loop);
	void addArrayFrameAnimation(string animationKeyName, char* imageKeyName, int* arr, int arrLen, int fps, bool loop, void* cbFunction);
	void addArrayFrameAnimation(string animationKeyName, char* imageKeyName, int* arr, int arrLen, int fps, bool loop, void* cbFunction, void* obj);

	void addArrayFrameAnimation(string animationKeyName, char* imageKeyName, int* arr, int arrLen, int fps, bool loop, int currentFrameY);  //키애니메이션키값, 이미지매니저키값, 해당배열, 배열길이, fps, true

																																			//구간 애니메이션
	void addCoordinateFrameAnimation(string animationKeyName, char* imageKeyName, int start, int end, int fps, bool reverse, bool loop);
	void addCoordinateFrameAnimation(string animationKeyName, char* imageKeyName, int start, int end, int fps, bool reverse, bool loop, void* cbFunction);
	void addCoordinateFrameAnimation(string animationKeyName, char* imageKeyName, int start, int end, int fps, bool reverse, bool loop, void* cbFunction, void* obj);

	void start(string animationKeyName);
	void stop(string animationKeyName);
	void pause(string animationKeyName);
	void resume(string animationKeyName);

	animation* findAnimation(string animationKeyName);

	void deleteAll();

};

