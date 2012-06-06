/*
 * Scene.h
 *
 *  Created on: Nov 30, 2011
 *      Author: raphael
 */

#ifndef SCENE_H_
#define SCENE_H_

#include <string>
#include "Engine.h"
#include "CameraManager.h"
#include "../3rdParty/tinyxml/tinyxml.h"
#include "SceneGraph.h"
#include "Skybox.h"
#include "Light.h"

class Scene {
	int startTime; // time in ms
	int endTime; // time in ms
protected:
	CameraManager cameraManager;
	std::string name;
	SceneGraph sceneGraph;
	std::string description; // to print help infos on screen
	Skybox* skybox;
	float cameraMoveSpeed;
public:
	Light light;
	int tmpMousePos; // do private or so
	Scene();
	virtual ~Scene();
	//void loadFromFile(); // load Scene from xml or an other File :)
    TiXmlElement * getSceneAsXmlElement();
	virtual void init() = 0;
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void resize(int width, int height) = 0;
	virtual void handleMousePos(int x, int y) = 0;
	virtual void handleMouseWheel(int mouseWheelPos) = 0;
	virtual void handleMouseScroll(int hor, int vert) = 0;
	virtual void handleKeyboard(int key, int action) = 0;
    Engine *getEngine() const;
    void setEngine(Engine *engine);
    CameraManager* getCameraManager();
    void setCameraManager(CameraManager cameraManager);
    std::string getDescription() const;
    std::string getName() const;
    void setDescription(std::string description);
    void setName(std::string name);
	SceneGraph getSceneGraph();
    Engine* engine;
	//void setSkybox(Skybox* skybox);
	//Light getLight(); //TODO multiple Lights per Scene
	//void setLight(Light light);
};

#endif /* SCENE_H_ */
