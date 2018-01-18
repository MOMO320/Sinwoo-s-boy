#include "stdafx.h"
#include "keyAniManager.h"
#include "image.h"
#include "animation.h"


keyAniManager::keyAniManager()
{
}
keyAniManager::~keyAniManager()
{
}

HRESULT keyAniManager::init() {

	return S_OK;
}

void keyAniManager::release() {

	//릴리즈에서는 삭제
	deleteAll();
}

void keyAniManager::update() {

	iterAnimations iter = _mTotalAnimation.begin();

	for (iter; iter != _mTotalAnimation.end(); ++iter) {

		// isPlay안의 _play는 frameUpdate함수에서 프레임이 돌면서 정의 됨
		// 이터레이터
		if (!iter->second->isPlay()) continue;

		iter->second->frameUpdate(TIMEMANAGER->getElapsedTime()*1.0f);


	}

}

void keyAniManager::render() {
	//랜더는 사용하지 않는다.
}


//디폴트 애니메이션
void keyAniManager::addDefaultFrameAnimation(string animationKeyName, char* imageKeyName, int fps, bool reverse, bool loop) {

	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	//애니메이션 클래스의 초기화는
	//내가 불러온 이미지 시트를 프레임단위로 나눠
	//1차원 배열로 만드는 것
	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setDefPlayFrame(reverse, loop);
	ani->setFPS(fps); //fps값이 높을수록 빨리 넘어감

	_mTotalAnimation.insert(pair<string, animation*>(animationKeyName, ani));

}

void keyAniManager::addDefaultFrameAnimation(string animationKeyName, char* imageKeyName, int fps, bool reverse, bool loop, int currentFrmaeY) {

	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight(), currentFrmaeY);
	ani->setDefPlayFrame(reverse, loop);
	ani->setFPS(fps);

	_mTotalAnimation.insert(pair<string, animation*>(animationKeyName, ani));

}

void keyAniManager::addDefaultFrameAnimation(string animationKeyName, char* imageKeyName, int fps, bool reverse, bool loop, void* cbFunction) {

	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setDefPlayFrame(reverse, loop, (CALLBACK_FUNCTION)cbFunction);
	ani->setFPS(fps);

	_mTotalAnimation.insert(pair<string, animation*>(animationKeyName, ani));

}
void keyAniManager::addDefaultFrameAnimation(string animationKeyName, char* imageKeyName, int fps, bool reverse, bool loop, void* cbFunction, void* obj) {

	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setDefPlayFrame(reverse, loop, (CALLBACK_FUNCTION_PARAMETER)cbFunction, obj);
	ani->setFPS(fps);

	_mTotalAnimation.insert(pair<string, animation*>(animationKeyName, ani));
}

//배열 애니메이션
void keyAniManager::addArrayFrameAnimation(string animationKeyName, char* imageKeyName, int* arr, int arrLen, int fps, bool loop) {

	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setPlayFrame(arr, arrLen, loop);
	ani->setFPS(fps);

	_mTotalAnimation.insert(pair<string, animation*>(animationKeyName, ani));

}

void keyAniManager::addArrayFrameAnimation(string animationKeyName, char* imageKeyName, int* arr, int arrLen, int fps, bool loop, int currentFrameY) {

	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight(), currentFrameY);
	ani->setPlayFrame(arr, arrLen, loop);
	ani->setFPS(fps);

	_mTotalAnimation.insert(pair<string, animation*>(animationKeyName, ani));

}


void keyAniManager::addArrayFrameAnimation(string animationKeyName, char* imageKeyName, int* arr, int arrLen, int fps, bool loop, void* cbFunction) {

	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setPlayFrame(arr, arrLen, loop, (CALLBACK_FUNCTION)cbFunction);
	ani->setFPS(fps);

	_mTotalAnimation.insert(pair<string, animation*>(animationKeyName, ani));

}
void keyAniManager::addArrayFrameAnimation(string animationKeyName, char* imageKeyName, int* arr, int arrLen, int fps, bool loop, void* cbFunction, void* obj) {

	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setPlayFrame(arr, arrLen, loop, (CALLBACK_FUNCTION_PARAMETER)cbFunction, obj);
	ani->setFPS(fps);

	_mTotalAnimation.insert(pair<string, animation*>(animationKeyName, ani));

}

//구간 애니메이션
void keyAniManager::addCoordinateFrameAnimation(string animationKeyName, char* imageKeyName, int start, int end, int fps, bool reverse, bool loop) {

	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setPlayFrame(start, end, reverse, loop);
	ani->setFPS(fps);

	_mTotalAnimation.insert(pair<string, animation*>(animationKeyName, ani));

}

void keyAniManager::addCoordinateFrameAnimation(string animationKeyName, char* imageKeyName, int start, int end, int fps, bool reverse, bool loop, void* cbFunction) {

	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setPlayFrame(start, end, reverse, loop, (CALLBACK_FUNCTION)cbFunction);
	ani->setFPS(fps);

	_mTotalAnimation.insert(pair<string, animation*>(animationKeyName, ani));

}

void keyAniManager::addCoordinateFrameAnimation(string animationKeyName, char* imageKeyName, int start, int end, int fps, bool reverse, bool loop, void* cbFunction, void* obj) {

	image* img = IMAGEMANAGER->findImage(imageKeyName);
	animation* ani = new animation;

	ani->init(img->getWidth(), img->getHeight(), img->getFrameWidth(), img->getFrameHeight());
	ani->setPlayFrame(start, end, reverse, loop, (CALLBACK_FUNCTION_PARAMETER)cbFunction, obj);
	ani->setFPS(fps);

	_mTotalAnimation.insert(pair<string, animation*>(animationKeyName, ani));

}



void keyAniManager::start(string animationKeyName) {
	iterAnimations iter = _mTotalAnimation.find(animationKeyName);
	iter->second->start();

}

void keyAniManager::stop(string animationKeyName) {
	iterAnimations iter = _mTotalAnimation.find(animationKeyName);
	iter->second->stop();
}

void keyAniManager::pause(string animationKeyName) {
	iterAnimations iter = _mTotalAnimation.find(animationKeyName);
	iter->second->pause();
}

void keyAniManager::resume(string animationKeyName) {
	iterAnimations iter = _mTotalAnimation.find(animationKeyName);
	iter->second->resume();
}

animation* keyAniManager::findAnimation(string animationKeyName) {
	iterAnimations iter = _mTotalAnimation.find(animationKeyName);

	if (iter != _mTotalAnimation.end()) {
		return iter->second;
	}

	return NULL;

}

void keyAniManager::deleteAll() {

	for (iterAnimations iter = _mTotalAnimation.begin(); iter != _mTotalAnimation.end();) {


		//*존나 중요한 것!
		//메모리제거후,
		//해당포인터 제거
		//포인터부터 먼저 제거하면
		//해당 메모리위치를 알수 없어 실질적인 메모리를 제거할 수 없다.


		if (iter->second != NULL) {
			iter->second->release();
			SAFE_DELETE(iter->second);		//위에서 만들어줬던 animation* ani = new animation 메모리를 제거해주는 것
			iter = _mTotalAnimation.erase(iter);
		}
		else ++iter;
	}

	_mTotalAnimation.clear();

}