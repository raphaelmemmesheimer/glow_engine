#include "ShadowMapScene.h"

ShadowMapScene::ShadowMapScene() {
}

ShadowMapScene::~ShadowMapScene() {
}

void ShadowMapScene::init()
{
	name = "ShadowMap";

	cameraManager.addCamera(new Camera("TrackballCamera"));
	cameraManager["TrackballCamera"]->setZ(60.0);
	cameraManager["TrackballCamera"]->setMode(cmTrackball);

	cameraManager.addCamera(new Camera("EgoCamera"));
	cameraManager["EgoCamera"]->setMode(cmEgo);

	cameraManager.addCamera(new Camera("LightCamera",light.getLightPos()[0], light.getLightPos()[1], light.getLightPos()[2],0,0,0));
	cameraManager["LightCamera"]->setMode(cmStatic);


	modelview = glm::mat4(1.0);
	projection = glm::perspective(60.0f,(float)engine->getWidth()/engine->getHeight(),0.1f,100000.0f);//glm::ortho(-1,1,-1,1);

	engine->resourceManager.shaderManager.addShader(new Shader("Texture","Shaders/texture.vert","Shaders/texture.frag"));
	engine->resourceManager.shaderManager.addShader(new Shader("Phong","Shaders/light/phong.vert","Shaders/light/phong.frag"));
#ifdef USEWX
	engine->getMainWindow()->getShaderEditor()->setShaderManager(engine->resourceManager.shaderManager);
#endif
	quad = new Quad(0.2);
	model = new AssimpModel();
	model->setAutoCalcNormals(true);
	//model->loadFile("/home/raphael/code/src/liblub/media/meshes/monkey.blend");
	//model->loadFile("/home/raphael/models/ctm/sibenik.ctm");
	model->loadFile("/home/raphael/models/obj/airglow.obj");

	glEnable(GL_DEPTH_TEST);
	//cameraManager = new CameraManager();
	cameraMoveSpeed = 0.2;	
}

void ShadowMapScene::draw(){



	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glm::mat4 normMatrix = glm::mat4(1.0);
	//Phong Lighting
	engine->resourceManager.shaderManager["Phong"]->bind();
	modelview = glm::translate(glm::mat4(1.0),glm::vec3(0.0,0.0,-40.0));
	//set shader params
	//cameraManager.getActiveCamera
	//glm::scale(modelview, glm::vec3(0.1, 0.1, 0.1));
	modelview = cameraManager.getActiveCamera()->getCameraMatrix();  // glm::mat4(1.0); // glm::rotate(modelview, glm::degrees((float)engine->getTime()), glm::vec3(1.0, 1.0, 1.0));


	glm::vec4 lightPos = glm::vec4(1.0,1.0,1.0,0.0)*modelview*projection;
	glUniformMatrix3fv(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("NormalMatrix"), 1,0, &normMatrix[0][0]);
	glUniformMatrix4fv(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("Projection"), 1,0, &projection[0][0]);
	glUniform1f(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("time"), engine->getTime());
	glUniform3f(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("LightPosition"), light.getLightPos().x, light.getLightPos().y, light.getLightPos().z);
	glUniformMatrix4fv(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("Modelview"), 1, 0,&modelview[0][0]);
	glUniform3f(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("AmbientMaterial"), 0.0, 0.0, 0.0);
	glUniform3f(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("DiffuseMaterial"), 0.5f, 0.5f, 0.5f);
	glUniform3f(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("SpecularMaterial"), 1.0, 1.0, 1.0 );
	glUniform1f(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("Shininess"), 255); //track->getPeak()*engine->getTime()
	glUniform4f(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("iColor"), 0.0,0.0,1.0,0.0);
	glUniform1f(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("Time"),engine->getTime());
	glUniform1f(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("time"),engine->getTime());
	model->draw();
	engine->resourceManager.shaderManager["Phong"]->unbind();
}



void ShadowMapScene::resize(int width, int height)
{
	glViewport(0, 0, width, height);
    engine->setHeight(height);
    engine->setWidth(width);
}



void ShadowMapScene::handleMousePos(int x, int y)
{	
	if (glfwGetMouseButton(/*w,*/GLFW_MOUSE_BUTTON_LEFT)){
		cameraManager.getActiveCamera()->setViewXY(engine->getLastMouseX()-x,engine->getLastMouseY()-y);
	}
	engine->setLastMouseX(x);
	engine->setLastMouseY(y);
}



void ShadowMapScene::handleMouseScroll(int hor, int vert)
{
}



void ShadowMapScene::handleMouseWheel(int mouseWheelPos)
{
}

void ShadowMapScene::handleKeyboard(int key, int action) {

	cameraMoveSpeed = this->getCameraManager()->getActiveCamera()->getMoveSpeed();
	int speedMult = (action == GLFW_PRESS) ? 1 : 0;
	switch(key){
	case GLFW_KEY_UP:
		this->getCameraManager()->getActiveCamera()->setSpeed(speedMult * cameraMoveSpeed);
		//moveSpeed*=speedMult;
		break;
	case GLFW_KEY_DOWN:
		this->getCameraManager()->getActiveCamera()->setSpeed(speedMult * -cameraMoveSpeed);
		break;
	case 87: // w
		this->getCameraManager()->getActiveCamera()->setMoveSpeed(this->getCameraManager()->getActiveCamera()->getMoveSpeed()*2.0);
		break;
	case 83: //s
		this->getCameraManager()->getActiveCamera()->setMoveSpeed(this->getCameraManager()->getActiveCamera()->getMoveSpeed()/2.0);
		break;
	case 66: //b
		if (action == GLFW_PRESS) {
			this->getCameraManager()->activateNextCamera();//setActiveCamera(demoTesting.getSceneManager()->getActiveScene()->getCameraManager()->getActiveCameraIndex()+1);
		}
		break;

	case 76:
		if (action == GLFW_PRESS)
			//demoTesting.getSceneManager()->switchToPreviousScene();
		break;
	}

}

void ShadowMapScene::update() {
	return;
}
