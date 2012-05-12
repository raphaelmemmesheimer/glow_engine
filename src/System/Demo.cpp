/*
 * Demo.cpp
 *
 *  Created on: Jan 30, 2012
 *      Author: raphael
 */

#include "Demo.h"

Demo::Demo() {
	// TODO Auto-generated constructor stu

}

Engine *Demo::getEngine() const
{
    return engine;
}

//SceneManager Demo::getSceneManager() const
//{
//    return sceneManager;
//}
//
//void Demo::setSceneManager(SceneManager sceneManager)
//{
//    this->sceneManager = sceneManager;
//}

void Demo::setEngine(Engine *engine)
{
    this->engine = engine;
}

Demo::~Demo() {
	// TODO Auto-generated destructor stub
}

void Demo::saveToFile(std::string fileName) {
  	// Make xml: <?xml ..><Hello>World</Hello>
	TiXmlDocument doc;
	TiXmlDeclaration * decl = new TiXmlDeclaration( "1.0", "", "" );
	TiXmlElement * elementDemo = new TiXmlElement("Demo");
	elementDemo->SetAttribute("Name", this->name.c_str());
	elementDemo->SetAttribute("Tune", this->tuneFileName.c_str());
	doc.LinkEndChild( decl );

	TiXmlElement * elementScenes = new TiXmlElement("Scenes");
	elementDemo->LinkEndChild(sceneManager.getScenesAsXmlElement());
	doc.LinkEndChild( elementDemo );
	doc.SaveFile( fileName.c_str() );
 
    printf("saved %s \n", fileName.c_str());
        
}

void Demo::loadFromFile(std::string fileName) {
	//TODO:
	//
}

void Demo::start() {
	tune.play();	
	return;
}

std::string Demo::getName() {
  return this->name;
}

void Demo::setName(std::string name) {
  this->name = name;
}

void Demo::setTuneFileName(std::string tuneFileName) {
	this->tuneFileName = tuneFileName;
}

Audio Demo::getTune() {
	return tune;
}

