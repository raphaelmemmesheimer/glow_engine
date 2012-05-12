/*
 * Scenes.h
 *
 *  Created on: Nov 30, 2011
 *      Author: raphael
 */

#ifndef SCENES_H_
#define SCENES_H_
#include <vector>
#include "Scene.h"
#include "../System/Engine.h"
#include "../3rdParty/tinyxml/tinyxml.h"

#include <wx/choice.h>

class SceneManager {
	std::vector<Scene*> scenes;
	int mActiveSceneIndex;
public:
	SceneManager();
	virtual ~SceneManager();
	Scene* getActiveScene();
	int getActiveSceneIndex();
	void setActiveSceneIndex(int activeSceneIndex);
	void switchToNextScene();
	void switchToPreviousScene();
	void addScene(Scene* scene);
	unsigned int getSceneCount();
	void initScenes(Engine* engine);
    TiXmlElement * getScenesAsXmlElement();
	//void toWxChoice(wxChoice* choice);
};

#endif /* SCENES_H_ */
