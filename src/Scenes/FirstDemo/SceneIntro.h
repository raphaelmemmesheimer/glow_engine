/*
 * SceneIntro.h
 *
 *  Created on: Nov 30, 2011
 *      Author: raphael
 *
 *      Idea: 	Print Loss, then rotate the o to e maybe motionblur that
 */

#ifndef SCENEINTRO_H_
#define SCENEINTRO_H_

#include <glm/gtc/matrix_transform.hpp>
#include "../../System/Scene.h"
#include "../../System/Engine.h"
#include "../../System/ObjModel.h"
#include "../../Shapes/Quad.h"

class SceneIntro: public Scene {
	//Engine* engine;
	glm::mat4 projection;
	glm::mat4 modelview;
	float zoom;

	Quad* quad;
	ObjModel* model;
public:
	SceneIntro();
	virtual ~SceneIntro();
	void init();
	void draw();
	void resize(int width, int height);
	void update();

	void handleMousePos(int x, int y);
	void handleMouseScroll(int hor, int vert);
	void handleMouseWheel(int mouseWheelPos);
	void handleKeyboard(int key, int action);

};

#endif /* SCENEINTRO_H_ */
