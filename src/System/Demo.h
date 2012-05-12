/*
 * Demo.h
 *
 *	Abstract Class for Demos
 *  Created on: Jan 30, 2012
 *      Author: raphael
 */

#ifndef DEMO_H_
#define DEMO_H_
#include "SceneManager.h"
#include "Engine.h"
#include <string>
#include "Audio.h"
#include "../3rdParty/tinyxml/tinyxml.h"

class Demo {

private:
	Audio tune;

protected:
	Engine* engine;
    std::string name;
	std::string tuneFileName;
	
public:
	Demo();
	virtual ~Demo();
	SceneManager sceneManager;
	virtual void init() = 0;
	virtual void draw(float time) = 0;
	virtual void release() = 0;
    Engine *getEngine() const;
    void setEngine(Engine *engine);
    void saveToFile(std::string fileName);
	void loadFromFile(std::string fileName);
    void setName(std::string name);
	void setTuneFileName(std::string tuneFileName);
	void start();
    std::string getName();
	Audio getTune(); 
};

#endif /* DEMO_H_ */
