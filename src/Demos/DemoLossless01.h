/*
 * Lossless01.h
 *
 *  Created on: Jan 30, 2012
 *      Author: raphael
 */

#ifndef LOSSLESS01_H_
#define LOSSLESS01_H_
#include "../System/Demo.h"
#include "../Scenes/TestScene.h"
#include "../Scenes/SibenikScene.h"
#include "../Scenes/FirstDemo/SceneIntro.h"
#include "../System/SceneManager.h"
#include "../System/Audio.h"

class DemoLossless01 : public Demo {
	//SceneManager sceneManager;
	TestScene testScene;
	SceneIntro introScene;
	SibenikScene sibenikScene;
public:
	DemoLossless01();
	virtual ~DemoLossless01();
	void init();
	void draw(float time);
	void release();
    
	SceneManager* getSceneManager();
};

#endif /* LOSSLESS01_H_ */
