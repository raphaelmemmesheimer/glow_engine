/*
 * Scene.cpp
 *
 *  Created on: Nov 30, 2011
 *      Author: raphael
 */

#include "Scene.h"

Scene::Scene() {
	// TODO Auto-generated constructor stub

}

Scene::~Scene() {
	// TODO Auto-generated destructor stub
}

Engine *Scene::getEngine() const
{
    return engine;
}

CameraManager* Scene::getCameraManager()
{
    return &cameraManager;
}

std::string Scene::getDescription() const
{
    return description;
}

std::string Scene::getName() const
{
    return name;
}

void Scene::setDescription(std::string description)
{
    this->description = description;
}

void Scene::setName(std::string name)
{
    this->name = name;
}

void Scene::setCameraManager(CameraManager cameraManager)
{
    this->cameraManager = cameraManager;
}

void Scene::setEngine(Engine *engine)
{
    this->engine = engine;
}


TiXmlElement * Scene::getSceneAsXmlElement() {
    TiXmlElement * element = new TiXmlElement("Scene"); 
    element->SetAttribute("Name",this->name.c_str());
	element->LinkEndChild(sceneGraph.getSceneGraphAsXmlElement());
    return element;
}

SceneGraph Scene::getSceneGraph() {
	return sceneGraph;
}
