/*
 * TestScene.h
 *
 *  Created on: Dec 27, 2011
 *      Author: raphael
 */

#ifndef TESTSCENE_H_
#define TESTSCENE_H_

#define ENABLE_FSFBO

#include <GL3/gl3w.h>
#include "../System/Scene.h"
#include "../System/Shader.h"
#include "../System/ShaderManager.h"
#include "../System/Camera.h"
#include "../System/CameraManager.h"
#include "../System/TextureManager.h"
#include "../System/CTMModel.h"
#include "../System/ObjModel.h"
#include "../System/Engine.h"
#include "../System/BezierSpline.h"
#include "../Shapes/Sphere.h"
#include "../Shapes/Quad.h"
#include "../Shapes/Cube.h"
#include "../System/ParticleSystem.h"
#include "../System/Text.h"
#include "../System/Skybox.h"
#include "../System/FrameBufferObject.h"
#include "../System/Audio.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#define DRAWANIMATEDHORSE
#define ENABLE_SHADOW

enum ChannelArt {caDefault, caRed, caCyan};

class TestScene : public Scene {
	ObjModel* obj;
	CTMModel* ctm;
	Text* text;
	Skybox* skybox;

	FrameBufferObject* fbo;
	FrameBufferObject* fboRed;
	FrameBufferObject* fboCyan;
	FrameBufferObject* fboScene;
	FrameBufferObject* fboShadow;

	glm::mat4 ProjectionMatrix;
	glm::mat4 ProjectionFullScreenOrtho;
	glm::vec4 ViewPort;

	BezierSpline* bspline;
	Sphere* sphere;
	Cube* cube;
	ParticleSystem* particleSystem;
	Quad* screenQuad;

	vector<ObjModel*> horseGallop;

	float diffuseRed, diffuseGreen, diffuseBlue;
	float specularRed, specularGreen, specularBlue;
	float ambientRed, ambientGreen, ambientBlue;
	int shininess;

	Audio* track;
	enum ChannelArt {caDefault, caRed, caCyan};

	glm::mat4 Modelview;

	glm::mat3 normMatrix;

	int horseAnimationCount;
	int horseAnimationCurrent;
	bool horseLoaded;
	double horseSpeed;

	glm::vec4 lightPos;
	glm::vec3 camInitPos;
	bool camInLightPos;

	float brightness;
	int saturation;

	float stereoSeperation;

	float angleX;
	float angleY;
	float angleZ;

	unsigned int modelnr;
	unsigned int modelobjnr;
	std::vector<Texture*> textures;
	std::vector<Mesh*> models;

	int lastMouseX;
	int lastMouseY;
	float moveSpeed;
//	ShaderManager shaderManager;
//	CameraManager cameraManager;
//	TextureManager textureManager;


	Texture* texture;
	Texture* texture1;
	Quad* q;
	double deltaTimeHorse;





	void initCamera();
	void initHorse();
	void initShader();
	void drawScene(Shader* shader, Camera* camera, ChannelArt channel = caDefault);

	void handleMousePos(int x, int y);
	void handleMouseScroll(int hor, int vert);
	void handleMouseWheel(int mouseWheelPos);

	void handleKeyboard(int key, int action);
public:
	TestScene();

	void init();
	void draw();
	void update();
	virtual ~TestScene();

    void resize(int height, int width);
};

#endif /* TESTSCENE_H_ */
