#include "KinectScene.h"

KinectScene::KinectScene() {
	
}

KinectScene::~KinectScene() {
}


void KinectScene::init() {
	//name = "Intro";	
	
	//modelview = glm::mat4(1.0);
	//projection = glm::ortho(-1,1,-1,1);

	//engine->resourceManager.textureManager.initFromDir("data/FirstDemo/");
	//engine->resourceManager.textureManager.print();
	//engine->resourceManager.shaderManager.addShader(new Shader("Texture","Shaders/texture.vert","Shaders/texture.frag"));
	//engine->resourceManager.shaderManager.addShader(new Shader("Phong","Shaders/light/phong.vert","Shaders/light/phong.frag"));

	//quad = new Quad(0.2);

	//glEnable(GL_DEPTH_TEST);
}

void KinectScene::draw() {
	//glClearColor(1.0, 1.0, 1.0, 1.0);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glm::mat4 normMatrix = glm::mat4(1.0);
	//Phong Lighting

	//engine->resourceManager.shaderManager["Phong"]->bind();
		//for(int i = 4; i < 20; i++){
			//modelview = glm::translate(glm::mat4(1.0),glm::vec3(0.0,0.0,-0.5));
			//modelview = glm::scale(modelview, glm::vec3(1.0/(float)i, 1.0/(float)i, 1.0/(float)i*2));
			////set shader params
			//modelview = glm::rotate(modelview, glm::degrees((float)engine->getTime()*(float)i), glm::vec3(1.0, 1.0, 1.0));
			//float colorR = 1.0;
			//float colorG = 0.71;
			//float colorB = 0;

			//if (i % 3 == 2) {
				//colorR = 0.86;
				//colorG = 1.0;
				//colorB = 0;
			//}
			//if (i % 3 == 1) {
				//colorR = 0;
				//colorG = 0.517;
				//colorB = 1.0;
			//}

			//glm::vec4 lightPos = glm::vec4(1.0,1.0,1.0,0.0)*modelview*projection;
			//glUniformMatrix3fv(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("NormalMatrix"), 1,0, &normMatrix[0][0]);
			//glUniformMatrix4fv(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("Projection"), 1,0, &projection[0][0]);
			//glUniform1f(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("time"), engine->getTime());
			//glUniform3f(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("LightPosition"), 1.0, 1.0, 1.0);
			//glUniformMatrix4fv(enginet in->resourceManager.shaderManager["Phong"]->getUniformLocation("Modelview"), 1, 0,&modelview[0][0]);
			//glUniform3f(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("AmbientMaterial"), 0.0, 0.0, 0.0);
			//glUniform3f(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("DiffuseMaterial"), colorR, colorG, colorB);
			//glUniform3f(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("SpecularMaterial"), lightPos.x, lightPos.y, lightPos.z );
			//glUniform1f(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("Shininess"), 255); //track->getPeak()*engine->getTime()
			//glUniform4f(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("iColor"), 0.0,0.0,1.0,0.0);
			//glUniform1f(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("Time"),engine->getTime());
			//glUniform1f(engine->resourceManager.shaderManager["Phong"]->getUniformLocation("time"),engine->getTime());
			//model->draw();
		//}
	//engine->resourceManager.shaderManager["Phong"]->unbind();



	//draw lossless
    //engine->resourceManager.shaderManager["Texture"]->bind();
        //glUniformMatrix4fv(engine->resourceManager.shaderManager["Texture"]->getUniformLocation("Projection"), 1,0, &projection[0][0]);
        //glUniform1f(engine->resourceManager.shaderManager["Texture"]->getUniformLocation("time"), engine->getTime());
        //modelview = glm::translate(glm::mat4(1.0), glm::vec3(-0.3, 0.0, zoom));
        //glUniformMatrix4fv(engine->resourceManager.shaderManager["Texture"]->getUniformLocation("Modelview"), 1, 0,&modelview[0][0]);
        //engine->resourceManager.textureManager["data/FirstDemo/l.png"]->bindTexture();
        //quad->draw();

        ////printf("%f %f %f \n", glm::degrees((float)engine->getTime()), fmod(glm::degrees((float)engine->getTime()), 180.0), 0.0);
        //float angle = fmod(glm::degrees((float)engine->getTime()), 360.0);
        //if ((angle >= 90.0) && (angle <= 270.0))
            //engine->resourceManager.textureManager["data/FirstDemo/o.png"]->bindTexture();
        //else
            //engine->resourceManager.textureManager["data/FirstDemo/e.png"]->bindTexture();
        //modelview = glm::translate(glm::mat4(1.0), glm::vec3(-0.1, 0.0, 0.0));
        //modelview = glm::rotate(modelview, glm::degrees((float)engine->getTime()), glm::vec3(0.0, 1.0, 0.0));//glm::rotate(glm::mat4(1.0), glm::degrees(engine->getTime()), glm::vec3(1.0, 0.0, 0.0));
        //modelview = glm::translate(modelview, glm::vec3(+0.1, 0.0, 0.0));
        //modelview = glm::translate(glm::mat4(modelview), glm::vec3(-0.1, 0.0, 0.0));
        //glUniformMatrix4fv(engine->resourceManager.shaderManager["Texture"]->getUniformLocation("Modelview"), 1, 0,&modelview[0][0]);
        ////engine->resourceManager.textureManager["data/FirstDemo/o.png"]->bindTexture();
        //quad->draw();

        //modelview = glm::translate(glm::mat4(1.0), glm::vec3(0.1, 0.0, 0.0));
        //engine->resourceManager.textureManager["data/FirstDemo/s.png"]->bindTexture();
        //glUniformMatrix4fv(engine->resourceManager.shaderManager["Texture"]->getUniformLocation("Modelview"), 1, 0,&modelview[0][0]);
        //quad->draw();

        //modelview = glm::translate(glm::mat4(1.0), glm::vec3(0.3, 0.0, 0.0));
        //glUniformMatrix4fv(engine->resourceManager.shaderManager["Texture"]->getUniformLocation("Modelview"), 1, 0,&modelview[0][0]);
        //quad->draw();
    //engine->resourceManager.shaderManager["Texture"]->unbind();
}

void KinectScene::resize(int width, int height){
	//glViewport(0, 0, width, height);
    //engine->setHeight(height);
    //engine->setWidth(width);
}

void KinectScene::handleMousePos(int x, int y){

}
void KinectScene::handleMouseScroll(int hor, int vert){

}
void KinectScene::handleMouseWheel(int mouseWheelPos){

}

void KinectScene::handleKeyboard(int key, int action) {
	//printf("key %d \n" ,key);
	//zoom+=0.001;	glClearColor(1.0, 1.0, 1.0, 1.0);
}
void KinectScene::update() {
	//return;
}
