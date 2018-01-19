#pragma once
#include "singletonBase.h"
#include <map>

// 1. �̹���Ŭ������ �ִϸ��̼� ���漱��
class image;
class animation;

class keyAniManager :public singletonBase<keyAniManager>
{
private:
	// 2. Ű�� �ִϸ��̼������� ���� �ϳ� �����.
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

	//����Ʈ �ִϸ��̼�
	void addDefaultFrameAnimation(string animationKeyName, char* imageKeyName, int fps, bool reverse, bool loop);
	void addDefaultFrameAnimation(string animationKeyName, char* imageKeyName, int fps, bool reverse, bool loop, void* cbFunction);
	void addDefaultFrameAnimation(string animationKeyName, char* imageKeyName, int fps, bool reverse, bool loop, void* cbFunction, void* obj);

	void addDefaultFrameAnimation(string animationKeyName, char* imageKeyName, int fps, bool reverse, bool loop, int currentFrmaeY);

	//�迭 �ִϸ��̼�
	void addArrayFrameAnimation(string animationKeyName, char* imageKeyName, int* arr, int arrLen, int fps, bool loop);
	void addArrayFrameAnimation(string animationKeyName, char* imageKeyName, int* arr, int arrLen, int fps, bool loop, void* cbFunction);
	void addArrayFrameAnimation(string animationKeyName, char* imageKeyName, int* arr, int arrLen, int fps, bool loop, void* cbFunction, void* obj);

	void addArrayFrameAnimation(string animationKeyName, char* imageKeyName, int* arr, int arrLen, int fps, bool loop, int currentFrameY);  //Ű�ִϸ��̼�Ű��, �̹����Ŵ���Ű��, �ش�迭, �迭����, fps, true

																																			//���� �ִϸ��̼�
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

