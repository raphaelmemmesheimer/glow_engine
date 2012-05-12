/*
 * SibenikScene.cpp
 *
 *  Created on: Jan 30, 2012
 *      Author: raphael
 */

#include "SibenikScene.h"

SibenikScene::SibenikScene() {
	// TODO Auto-generated constructor stub

}

SibenikScene::~SibenikScene() {
	// TODO Auto-generated destructor stub
}

void SibenikScene::init()
{
	name = "Sibenik";
	modelview = glm::mat4(1.0);
	projection = glm::perspective(60.0f,(float)engine->getWidth()/engine->getHeight(),0.1f,100000.0f);//glm::ortho(-1,1,-1,1);

	engine->resourceManager.shaderManager.addShader(new Shader("Texture","Shaders/texture.vert","Shaders/texture.frag"));
	engine->resourceManager.shaderManager.addShader(new Shader("Phong","Shaders/light/phong.vert","Shaders/light/phong.frag"));
#ifdef USEWX
	engine->getMainWindow()->getShaderEditor()->setShaderManager(engine->resourceManager.shaderManager);
#endif
	quad = new Quad(0.2);
	model = new ObjModel();
	model->setAutoCalcNormals(true);
	model->loadFile("/home/raphael/models/obj/sibenik/sibenik.obj");

	glEnable(GL_DEPTH_TEST);
	//cameraManager = new CameraManager();
	
}

void SibenikScene::draw(){



	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glm::mat4 normMatrix = glm::mat4(1.0);
	//Phong Lighting
	engine->resourceManager.shaderManager["Phong"]->bind();
	modelview = glm::translate(glm::mat4(1.0),glm::vec3(0.0,0.0,-40.0));
	//set shader params
	//cameraManager.getActiveCamera
	glm::scale(modelview, glm::vec3(0.1, 0.1, 0.1));
	modelview = glm::rotate(modelview, glm::degrees((float)engine->getTime()), glm::vec3(1.0, 1.0, 1.0));


	glm::vec4 lightPos = glm::vec4(1.0,1.0,1.0,0.0)*modelview*projection;
	glUniformMatrix3fv(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("NormalMatrix"), 1,0, &normMatrix[0][0]);
	glUniformMatrix4fv(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("Projection"), 1,0, &projection[0][0]);
	glUniform1f(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("time"), engine->getTime());
	glUniform3f(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("LightPosition"), 1.0, 1.0, 1.0);
	glUniformMatrix4fv(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("Modelview"), 1, 0,&modelview[0][0]);
	glUniform3f(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("AmbientMaterial"), 0.0, 0.0, 0.0);
	glUniform3f(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("DiffuseMaterial"), 0.5f, 0.5f, 0.5f);
	glUniform3f(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("SpecularMaterial"), lightPos.x, lightPos.y, lightPos.z );
	glUniform1f(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("Shininess"), 255); //track->getPeak()*engine->getTime()
	glUniform4f(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("iColor"), 0.0,0.0,1.0,0.0);
	glUniform1f(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("Time"),engine->getTime());
	glUniform1f(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("time"),engine->getTime());
	model->draw();
	engine->resourceManager.shaderManager["Phong"]->unbind();
}



void SibenikScene::resize(int width, int height)
{
	glViewport(0, 0, width, height);
    engine->setHeight(height);
    engine->setWidth(width);
}



void SibenikScene::handleMousePos(int x, int y)
{
}



void SibenikScene::handleMouseScroll(int hor, int vert)
{
}



void SibenikScene::handleMouseWheel(int mouseWheelPos)
{
}

void SibenikScene::handleKeyboard(int key, int action) {
	return;
}

void SibenikScene::update() {
	return;
}
