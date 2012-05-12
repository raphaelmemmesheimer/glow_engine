/*
 * Scenes.cpp
 *
 *  Created on: Nov 30, 2011
 *      Author: raphael
 */

#include "SceneManager.h"

SceneManager::SceneManager() {
	// TODO Auto-generated constructor stub
	mActiveSceneIndex = 0;
}

SceneManager::~SceneManager() {
	// TODO Auto-generated destructor stub
}

Scene* SceneManager::getActiveScene(){
//	printf("getActiveScene %d/%d \n", mActiveSceneIndex,getSceneCount());
	return scenes[mActiveSceneIndex];
}

int SceneManager::getActiveSceneIndex()
{
	return mActiveSceneIndex;
}


void SceneManager::setActiveSceneIndex(int activeSceneIndex)
{
	mActiveSceneIndex = activeSceneIndex;
	scenes[activeSceneIndex]->resize(scenes[activeSceneIndex]->getEngine()->getWidth(), scenes[activeSceneIndex]->getEngine()->getHeight()); //dirty
}


void SceneManager::switchToNextScene()
{
	printf("bf %d %d %s \n", mActiveSceneIndex, (int)scenes.size(), getActiveScene()->getName().c_str());
	setActiveSceneIndex((mActiveSceneIndex+1) % (scenes.size()) );
	printf("af %d %d %s \n", mActiveSceneIndex, (int)scenes.size(), getActiveScene()->getName().c_str());
}

void SceneManager::switchToPreviousScene()
{
	mActiveSceneIndex = mActiveSceneIndex == 0 ?  scenes.size() - 1 : mActiveSceneIndex - 1 ;
}

void SceneManager::addScene(Scene *scene)
{
	printf("add scene %s \n", scene->getName().c_str());
	scenes.push_back(scene);
}

unsigned int SceneManager::getSceneCount(){
	return scenes.size();
}

void SceneManager::initScenes(Engine* engine){
	for (unsigned int i = 0; i < scenes.size(); i++){
		scenes[i]->setEngine(engine);
		scenes[i]->init();
	}
}

TiXmlElement * SceneManager::getScenesAsXmlElement() {
	// return scenes as xml tag 
	TiXmlElement * element = new TiXmlElement("Scenes"); 
	for (unsigned int i = 0; i < scenes.size(); i++) {
		element->LinkEndChild(scenes[i]->getSceneAsXmlElement());
	}
    return element;
}


//void SceneManager::toWxChoice(wxChoice* choice) {
	//choice->Clear();

	//for (unsigned int i = 0; i < scenes.size(); i++){
		//choice->Append(wxString::FromAscii(scenes[i]->getName().c_str()));
	//}

//}
