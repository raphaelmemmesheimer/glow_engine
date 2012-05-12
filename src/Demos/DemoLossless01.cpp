/*
 * Lossless01.cpp
 *
 *  Created on: Jan 30, 2012
 *      Author: raphael
 */

#include "DemoLossless01.h"

DemoLossless01::DemoLossless01() {
	// TODO Auto-generated constructor stub

}

DemoLossless01::~DemoLossless01() {
	// TODO Auto-generated destructor stub
}

void DemoLossless01::init(){
	sceneManager.addScene(&introScene);
	sceneManager.addScene(&sibenikScene);
	sceneManager.addScene(&testScene);

	sceneManager.initScenes(engine);
}

void DemoLossless01::draw(float time){
	sceneManager.getActiveScene()->draw();
}

void DemoLossless01::release(){

}

SceneManager* DemoLossless01::getSceneManager(){
	//printf("scenescount %d \n", sceneManager.getSceneCount());
	return &sceneManager;
}
