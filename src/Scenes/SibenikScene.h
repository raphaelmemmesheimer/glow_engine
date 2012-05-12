/*
 * SibenikScene.h
 *
 *  Created on: Jan 30, 2012
 *      Author: raphael
 */

#ifndef SIBENIKSCENE_H_
#define SIBENIKSCENE_H_

#include "../System/Scene.h"
#include <glm/glm.hpp>
#include "../System/ObjModel.h"
#include "../Shapes/Quad.h"
#include <glm/gtc/matrix_transform.hpp>

class SibenikScene: public Scene {
	glm::mat4 projection;
	glm::mat4 modelview;

	Quad* quad;
	ObjModel* model;
public:
	SibenikScene();
	virtual ~SibenikScene();
	void init();
	void draw();
	void resize(int width, int height);
	void update();

	void handleMousePos(int x, int y);
	void handleMouseScroll(int hor, int vert);
	void handleMouseWheel(int mouseWheelPos);
	void handleKeyboard(int key, int action);
};

#endif /* SIBENIKSCENE_H_ */
