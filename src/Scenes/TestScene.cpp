/*
 *
 * TestScene.cpp
 *
 *  Created on: Dec 27, 2011
 *      Author: raphael
 */

#include "TestScene.h"

void TestScene::handleMousePos(int x, int y){
	if (glfwGetMouseButton(/*w,*/GLFW_MOUSE_BUTTON_LEFT)){
		cameraManager.getActiveCamera()->setViewXY(engine->getLastMouseX()-x,engine->getLastMouseY()-y);
	}
	engine->setLastMouseX(x);
	engine->setLastMouseY(y);
}

void TestScene::handleMouseScroll(int hor, int vert){
	cameraManager.getActiveCamera()->setZ(cameraManager.getActiveCamera()->getZ()+(-vert*moveSpeed));
	cameraManager.getActiveCamera()->setRadius(cameraManager.getActiveCamera()->getRadius()+(-vert*moveSpeed));
}

void TestScene::handleMouseWheel(int mouseWheelPos){
	printf("mousewheel %d \n", mouseWheelPos);
	int deltaMouseWheel = mouseWheelPos - tmpMousePos;
	cameraManager.getActiveCamera()->setZ(cameraManager.getActiveCamera()->getZ()+(-deltaMouseWheel*cameraManager.getActiveCamera()->getMoveSpeed()));
	cameraManager.getActiveCamera()->setRadius(cameraManager.getActiveCamera()->getRadius()+(-deltaMouseWheel*cameraManager.getActiveCamera()->getMoveSpeed()));
	tmpMousePos = mouseWheelPos;
}

void TestScene::handleKeyboard(int key, int action) {
	if ((key == GLFW_KEY_SPACE) && (action == GLFW_PRESS)) {

//xx		if ((track->getState() == asPlaying))
//		{
//			track->pause();
//		}
//		else
//		{
//		    track->play();
//		}
	}

	// // move cam

	if ((key == 77) && (action == GLFW_PRESS)) {
		modelnr++;
		if (modelnr >= models.size()) 
		  modelnr = 0;
		ctm = (CTMModel*)models[modelnr];

	}

	//if ((key == 78) && (action == GLFW_PRESS)) {
        //modelobjnr++;
		//if (modelobjnr >= sizeof(modelsobj)/sizeof(modelsobj[0]))
		  //modelobjnr = 0;
		//obj->loadFile(modelsobj[modelobjnr]);

	//}


	int speedMult = (action == GLFW_PRESS) ? 1 : 0;
	switch(key){
	case GLFW_KEY_UP:
		this->getCameraManager()->getActiveCamera()->setSpeed(moveSpeed*speedMult);
		//moveSpeed*=speedMult;
		break;
	case GLFW_KEY_DOWN:
		this->getCameraManager()->getActiveCamera()->setSpeed(-moveSpeed*speedMult);
		break;
	case GLFW_KEY_LEFT:
		//demoTesting.getSceneManager()->getActiveScene()->getCameraManager()["TrackballCamera"]->setX(demoTesting.getSceneManager()->getActiveScene()->getCameraManager()["TrackballCamera"]->getX()-moveSpeed*speedMult);
		//demoTesting.getSceneManager()->getActiveScene()->getCameraManager()["TrackballCamera"]->setSpeedx(moveSpeed*speedMult);
//xx		stereoSeperation += 0.001;
		break;
	case GLFW_KEY_RIGHT:
		//demoTesting.getSceneManager()->getActiveScene()->getCameraManager()["TrackballCamera"]->setX(demoTesting.getSceneManager()->getActiveScene()->getCameraManager()["TrackballCamera"]->getX()+moveSpeed*speedMult);
//xx		stereoSeperation -= 0.001;
		//demoTesting.getSceneManager()->getActiveScene()->getCameraManager()["TrackballCamera"]->setSpeedx(-moveSpeed*speedMult);
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
	case 67:
		//CameraMode camMode;
////
		//camMode = (demoTesting.getSceneManager()->getActiveScene()->getCameraManager()["TrackballCamera"]->getMode() == cmEgo ? cmTrackball : cmEgo);
		//if (action == GLFW_PRESS)
		  //demoTesting.getSceneManager()->getActiveScene()->getCameraManager()["TrackballCamera"]->setMode(camMode);

		break;
	case 85:
		if (action == GLFW_PRESS)
//xx		  brightness += 0.05;
		break;
	case 74:
		if (action == GLFW_PRESS)
//xx		  brightness -= 0.05;
		break;
	}

	return;
}

void TestScene::resize(int width, int height){
    // Setup viewport
	glViewport(0, 0, width, height);
    ViewPort = glm::vec4(0,0,width,height);
    // Change to the projection matrix and set our viewing volume

    ProjectionMatrix = glm::perspective(60.0f,(float)width/height,0.1f,100000.0f);
    ProjectionFullScreenOrtho = glm::ortho(-1,1,-1,1); // for fullscreen quad //glm::perspective(60.0f,(float)width/height,0.001f,10000.0f);

    fbo = new FrameBufferObject(width,height);

    fboRed = new FrameBufferObject(width,height);
    fboCyan = new FrameBufferObject(width,height);

    fboScene = new FrameBufferObject(width,height);
    fboShadow = new FrameBufferObject(width,height);

    engine->setHeight(height);
    engine->setWidth(width);
}

TestScene::TestScene() {
	Modelview = glm::mat4(1.0);
	horseAnimationCount = 48;
	horseAnimationCurrent = 0;
	horseLoaded = false;
	horseSpeed = 0.05;
	deltaTimeHorse = 0.0;

	camInLightPos = false;

	brightness = 1.0;
	saturation = 1;

	stereoSeperation = 0.02;

	angleX = 0;
	angleY = 0;
	angleZ = 0;

	modelnr = 0;
	modelobjnr = 0;

	lastMouseX = 0;
	lastMouseY =0;

	diffuseRed, diffuseGreen, diffuseBlue = 0.5;
	specularRed, specularGreen, specularBlue = 1.0;
	ambientRed, ambientGreen, ambientBlue = 0.005;
	shininess = 8;

	lightPos = glm::vec4(20, 20, 0, 0);
	camInitPos = glm::vec3(100, 100, 0);
}

TestScene::~TestScene() {
	// TODO Auto-generated destructor stub
}

void TestScene::initCamera()
{
	cameraManager.addCamera(new Camera("TrackballCamera"));
	cameraManager["TrackballCamera"]->setZ(60.0);
	cameraManager["TrackballCamera"]->setMode(cmTrackball);

	cameraManager.addCamera(new Camera("EgoCamera"));
	cameraManager["EgoCamera"]->setMode(cmEgo);

	cameraManager.addCamera(new Camera("LightCamera",lightPos[0],lightPos[1],lightPos[2],0,0,0));
	cameraManager["LightCamera"]->setMode(cmStatic);
}

void TestScene::initHorse(){
	horseLoaded = false;
	for (int i = 0; i < horseAnimationCount; i++) {
		ObjModel * tmpObj;
		tmpObj = new ObjModel;
		char fileName[128];
		sprintf(fileName,"/home/raphael/models/obj/models/horse-gallop/horse-gallop-%02d.obj",i+1);
		tmpObj->loadFile(fileName);
		horseGallop.push_back(tmpObj);
		printf("%s \n",fileName);
	}
	horseLoaded = true;
}

void TestScene::initShader()
{

	//engine->resourceManager.shaderManager.addShader(new Shader("Phong","Shaders/tessellation/tessellation.vert", "Shaders/tessellation/tessellation.frag", "Shaders/tessellation/tessellation.geom", "Shaders/tessellation/tessellation.tessc", "Shaders/tessellation/tess_morph.tesse"));
	engine->resourceManager.shaderManager.addShader(new Shader("Phong","Shaders/light/phong.vert","Shaders/light/phong.frag"));
	engine->resourceManager.shaderManager.addShader(new Shader("ShadowMap","Shaders/light/phong.vert","Shaders/light/phong.frag"));
	engine->resourceManager.shaderManager.addShader(new Shader("NoLight","Shaders/light/nolight.vert","Shaders/light/nolight.frag"));
	engine->resourceManager.shaderManager.addShader(new Shader("Texture","Shaders/texture.vert","Shaders/texture.frag"));
	engine->resourceManager.shaderManager.addShader(new Shader("Particle","Shaders/particle.vert","Shaders/texture.frag"));
//	engine->resourceManager.shaderManager.addShader(new Shader("Skyox","Shaders/skybox.vert","Shaders/skybox.frag"));
	engine->resourceManager.shaderManager.addShader(new Shader("Post","Shaders/post/post1.vert","Shaders/post/post1.frag"));
//	engine->resourceManager.shaderManager.addShader(new Shader("ShadowMap","Shaders/shadow/shadowmapping.vert","Shaders/shadow/shadowmapping.frag"));

	glBindFragDataLocation(engine->resourceManager.shaderManager["Phong"]->id, 0, "FragColor");
	glBindFragDataLocation(engine->resourceManager.shaderManager["Phong"]->id, 1, "PositionColor");
	glBindFragDataLocation(engine->resourceManager.shaderManager["Phong"]->id, 2, "NormalColor");
	glBindFragDataLocation(engine->resourceManager.shaderManager["Phong"]->id, 3, "RadianceColor");
#ifdef USEWX
	engine->getMainWindow()->getShaderEditor()->setShaderManager(engine->resourceManager.shaderManager);
#endif
	glGetError();

}

void TestScene::drawScene(Shader* shader, Camera* camera, ChannelArt channel) {
	cameraManager["LightCamera"]->setPos(light.getLightPos());
	printf("lightPos %f %f %f \n", light.getLightPos()[0], light.getLightPos().y, light.getLightPos().z);
	//#ifdef USEWX
	//
//
		//models = engine->getMainWindow()->getModels(); TODO: change
		//printf("%d modelscnt\n", models.size());
//#endif
	Modelview = glm::translate(glm::mat4(1.0),glm::vec3(0.0));
	//Modelview = glm::rotate(Modelview,glm::degrees(90.0f),glm::vec3(0.0,1.0,0.0));
	switch (channel) {
		case caDefault:
			Modelview = camera->getCameraMatrix() * Modelview;
			break;
		case caRed:
			Modelview = glm::rotate(camera->getCameraMatrix(), glm::degrees(stereoSeperation), glm::vec3(1.0,1.0,1.0)) * Modelview;
			break;
		case caCyan:
			Modelview = glm::rotate(camera->getCameraMatrix(), glm::degrees(-stereoSeperation), glm::vec3(1.0,1.0,1.0)) * Modelview;
			break;
		default:
			break;
	}


	shader->bind();
	glPatchParameteri(GL_PATCH_VERTICES, 3);

    glUniformMatrix4fv( shader->getUniformLocation("Projection"), 1,0, &ProjectionMatrix[0][0]);
    glUniformMatrix4fv(shader->getUniformLocation("Modelview"), 1, 0,&Modelview[0][0]);
    glUniformMatrix3fv(shader->getUniformLocation("NormalMatrix"), 1,0, &normMatrix[0][0]);


  glUniform3f(shader->getUniformLocation("LightPosition"),lightPos[0],lightPos[1],lightPos[2]); //light at constant position
    glUniform3f(shader->getUniformLocation("LightPosition"), cameraManager["TrackballCamera"]->getX(), cameraManager["TrackballCamera"]->getY(), cameraManager["TrackballCamera"]->getZ()); // light at cam

    glUniform3f(shader->getUniformLocation("AmbientMaterial"), ambientRed,ambientGreen,ambientBlue);
    glUniform3f(shader->getUniformLocation("DiffuseMaterial"), diffuseRed,diffuseGreen,diffuseBlue);
    glUniform3f(shader->getUniformLocation("SpecularMaterial"), specularRed,specularGreen,specularBlue );
    glUniform1f(shader->getUniformLocation("Shininess"), shininess); //track->getPeak()*engine->getTime()
    glUniform4f(shader->getUniformLocation("iColor"), 0.0,0.0,1.0,0.0);
    glUniform1f(shader->getUniformLocation("Time"),engine->getTime());
    glUniform1f(shader->getUniformLocation("time"),engine->getTime());



    //obj->draw();
//    bspline->draw();
//    Modelview = glm::rotate(Modelview, glm::degrees((float)engine->getTime()/20), glm::vec3(1,1,0));
//    glUniformMatrix4fv(shader->getUniformLocation("Modelview"), 1, 0,&Modelview[0][0]);
	ctm->draw();


    //cube->draw();
    glm::mat4 upMatrix = glm::mat4(1.0);
    upMatrix = glm::rotate(upMatrix, glm::degrees((float)engine->getTime()/20), glm::vec3(1,1,0));
    upMatrix = glm::translate(upMatrix, glm::vec3(sin(engine->getTime()),sin(engine->getTime()),sin(engine->getTime())));

//    particleSystem->update(upMatrix);


#ifdef USEWX
    textures = engine->getMainWindow()->getTextures();
#endif
	for (unsigned int i = 0; i < textures.size(); ++i) {
		glActiveTexture(GL_TEXTURE0+0+i);
		textures[i]->bindTexture();
		char uniformName[32];
		sprintf(uniformName,"tex%.2d",i);
		glUniform1i(shader->getUniformLocation(uniformName),0+i);
		//printf("%s \n", uniformName);
	}

    //for (unsigned int i = 0; i < models.size(); ++i) {
		//models[i]->draw();
	//}

	//#ifdef DRAWANIMATEDHORSE TODO: change 
    //if (engine->getMainWindow()->cbAnimatedHorse->IsChecked()){
        //Modelview = glm::translate(glm::mat4(1.0),glm::vec3(0.0));
        //Modelview = glm::rotate(Modelview,glm::degrees(angleZ),glm::vec3(0.0,1.0,0.0));
        //Modelview = cameraManager["TrackballCamera"]->getCameraMatrix() * Modelview;
        //glUniformMatrix4fv(shader->getUniformLocation("Modelview"), 1, 0,&Modelview[0][0]);
        //horseGallop[horseAnimationCurrent]->draw(); // animate horse
		////printf("Horse\n");
    //}
	//#endif

//    cameraManager["TrackballCamera"]->setZ(20.0/track->getPeak());
//    for (int i = 2; i < 15; ++i) {
//    	Modelview = glm::scale(Modelview,glm::vec3(1.0/i,1.0/i,1.0/i));
//    	Modelview = glm::rotate(Modelview,glm::degrees(angleZ),glm::vec3(0.0,0.0,1.0));
//    	//Modelview = glm::translate(Modelview,glm::vec3(0.0,0.0,-i));
//        glUniformMatrix4fv(shader->getUniformLocation("Modelview"), 1, 0,&Modelview[0][0]);
//    	obj->draw();
//
//	}
    shader->unbind();

    engine->resourceManager.shaderManager["Particle"]->bind();
    glUniformMatrix4fv(engine->resourceManager.shaderManager["Particle"]->getUniformLocation("Projection"), 1,0, &ProjectionMatrix[0][0]);
    glUniformMatrix4fv(engine->resourceManager.shaderManager["Particle"]->getUniformLocation("Modelview"), 1, 0,&Modelview[0][0]);
    glUniform1f(engine->resourceManager.shaderManager["Particle"]->getUniformLocation("Time"),engine->getTime());
    particleSystem->draw(shader, Modelview);
    engine->resourceManager.shaderManager["Particle"]->unbind();
}

void TestScene::init(){
	printf("init TestScene\n");
	name = "TestScene";
	engine->resourceManager.textureManager.initFromDir("data/textures/");

	initShader();
	initCamera();

	glClearColor(0.0,0.0,1.0,1.0);

	glEnable(GL_DEPTH_TEST);
	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL); //useleys?!
	#ifdef DRAWANIMATEDHORSE 
	initHorse();
	#endif

//	#ifdef SSDO_SCENE
//	micronapalm = new CTMModel();
//	micronapalm->loadFile(modelfolder+"/ctm/micronapalm.ctm");
//	floorPlane = new Quad(64.0);
//	#endif

	//track = new Audio("orchestral.mp3");
#ifdef PLAY_TRACK
	track->play();
#endif


	skybox = new Skybox();
	skybox->setShader(engine->resourceManager.shaderManager["Texture"]);
	skybox->loadTextures("data/textures/negy.jpg",
						 "data/textures/posy.jpg",
						 "data/textures/negz.jpg",
						 "data/textures/posz.jpg",
						 "data/textures/negx.jpg",
						 "data/textures/posx.jpg");
#ifdef USEWX
	engine->getMainWindow()->skybox = skybox;
#endif
	//printf("getmousepos\n");
	engine->getMousePos(&lastMouseX,&lastMouseY);

	obj = new ObjModel;
	obj->setAutoCalcNormals(true);
	obj->loadFile("/home/raphael/models/obj/phoenix1.obj");

    ctm = new CTMModel();
    ctm->setAutoCalcNormals(true);
    ctm->loadFile("/home/raphael/models/ctm/torus.ctm");
    cube = new Cube();
//
//    ply = new PlyModel();
//    ply->setAutoCalcNormals(true);
//    ply->loadFile(modelfolder+"/ply/drill/reconstruction/drill_shaft_vrip.ply");



    screenQuad = new Quad(2.0);

//    printf("init midi");
//    initMidi();
    //printf("bezier spline\n");
    bspline = new BezierSpline();
    bspline->addPoint(glm::vec3(0.0,0.0,0.0));
    bspline->addPoint(glm::vec3(0.0,10.0,10.0));
    bspline->addPoint(glm::vec3(10.0,10.0,0.0));
    bspline->addPoint(glm::vec3(10.0,0.0,10.0));
    bspline->addPoint(glm::vec3(10.0,50.0,10.0));
    bspline->addPoint(glm::vec3(5.0,20.0,25.0));
    bspline->generateAndBindBuffersControlPoints();
    bspline->generateAndBindBuffers(30);

    sphere = new Sphere(1.0,100,100);

    particleSystem = new ParticleSystem(1000);

    text = new Text("airglow!\n if that works i eat ma underpants", "data/fonts/stitches.ttf");
	text->setPos(100, 200);
}

void TestScene::draw(){
#ifdef USEOPENCV_CAM
	pFrame = cvQueryFrame(pCapture);

	// Draw the original frame and low resolution version
	cvShowImage("WebCam", pFrame);
#endif
    #ifdef ENABLE_FSFBO
	fbo->bind();
    #endif
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    angleX += 0.01;
    angleY += 0.001;
    angleZ += 0.0001;

	//drawScene(engine->resourceManager.shaderManager["Phong"]); // draw

	// draw light source
	engine->resourceManager.shaderManager["NoLight"]->bind();

	double lightScale = 1.0;
#ifdef USEWX
	engine->getMainWindow()->eLightSize->GetValue().ToDouble(&lightScale);
#endif
    Modelview = glm::scale(glm::mat4(1.0),glm::vec3(lightScale));
	//light.lightPos
	//Modelview = glm::translate(Modelview,glm::vec3(lightPos[0],lightPos[1],lightPos[2]));//    NormalMatrix = Modelview.getUpper3x3();
	
	Modelview = glm::translate(Modelview,light.getLightPos());//    NormalMatrix = Modelview.getUpper3x3();
	Modelview = cameraManager.getActiveCamera()->getCameraMatrix() * Modelview; //*Modelview
	glUniformMatrix4fv(engine->resourceManager.shaderManager["NoLight"]->getUniformLocation("Modelview"), 1, 0,&Modelview[0][0]);
	glUniformMatrix4fv(engine->resourceManager.shaderManager["NoLight"]->getUniformLocation("Projection"), 1,0, &ProjectionMatrix[0][0]);
	glUniformMatrix3fv(engine->resourceManager.shaderManager["NoLight"]->getUniformLocation("NormalMatrix"), 1,0, &normMatrix[0][0]);
	glUniform4f(engine->resourceManager.shaderManager["NoLight"]->getUniformLocation("iColor"), 1.0,1.0,1.0,1.0);

	glm::vec3 screenSpaceLightPos = glm::project(glm::vec3(0),Modelview,ProjectionMatrix,ViewPort); // projection t
	screenSpaceLightPos.y /= engine->getHeight();
	screenSpaceLightPos.x /= engine->getWidth();

	sphere->draw(); // the light
	glUniform4f(engine->resourceManager.shaderManager["NoLight"]->getUniformLocation("iColor"), 0.0,0.0,0.0,1.0);
	drawScene(engine->resourceManager.shaderManager["NoLight"],cameraManager.getActiveCamera());
	engine->resourceManager.shaderManager["NoLight"]->unbind();
	// end draw light source



	fbo->unbind();
//////////////////////////////// stereo channels

	fboRed->bind();
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); // clear FBO
		drawScene(engine->resourceManager.shaderManager["Phong"], cameraManager.getActiveCamera(), caRed); // draw Scene
	fboRed->unbind();

	fboCyan->bind();
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);//clear FBO
		drawScene(engine->resourceManager.shaderManager["Phong"], cameraManager.getActiveCamera(), caCyan); // draw Scene
	fboCyan->unbind();


/////////////////////////////////



	fboScene->bind();

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	Modelview = glm::mat4(1.0);
	Modelview = cameraManager.getActiveCamera()->getCameraMatrix() * Modelview;

	//engine->resourceManager.shaderManager["Texture"]->bind();
		//Modelview = glm::translate(glm::mat4(1.0),glm::vec3(0.0));
		//Modelview = glm::rotate(Modelview,glm::degrees(90.0f),glm::vec3(0.0,1.0,0.0));
		//Modelview = cameraManager.getActiveCamera()->getCameraMatrix() * Modelview;

		//glUniformMatrix4fv(engine->resourceManager.shaderManager["Texture"]->getUniformLocation("Projection"), 1,0, &ProjectionMatrix[0][0]);
		//glUniformMatrix4fv(engine->resourceManager.shaderManager["Texture"]->getUniformLocation("Modelview"), 1, 0,&Modelview[0][0]);
		//glUniformMatrix3fv(engine->resourceManager.shaderManager["Texture"]->getUniformLocation("NormalMatrix"), 1,0, &normMatrix[0][0]);
		//skybox->draw();

	//engine->resourceManager.shaderManager["Texture"]->unbind();


    //engine->resourceManager.shaderManager["Texture"]->bind();
        //Modelview = glm::translate(glm::mat4(1.0),glm::vec3(0.0,0.0,0.0));
        //Modelview = glm::rotate(Modelview,glm::degrees(90.0f),glm::vec3(0.0,1.0,0.0));
        //Modelview = cameraManager.getActiveCamera()->getCameraMatrix() * Modelview;
        //Quad* q1 = new Quad(2.0);

        //glm::mat4 orthoproj;
        //orthoproj = glm::ortho( 0, 1, 1, 0);
        //glUniformMatrix4fv(engine->resourceManager.shaderManager["Texture"]->getUniformLocation("Projection"), 1,0, &orthoproj[0][0]);
        //glUniformMatrix4fv(engine->resourceManager.shaderManager["Texture"]->getUniformLocation("Modelview"), 1, 0,&glm::mat4(1.0)[0][0]);
        //glUniformMatrix3fv(engine->resourceManager.shaderManager["Texture"]->getUniformLocation("NormalMatrix"), 1,0, &normMatrix[0][0]);
		////text->setText("gagagugaga");
		//text->draw();
    //engine->resourceManager.shaderManager["Texture"]->unbind();



	drawScene(engine->resourceManager.shaderManager["Phong"],cameraManager.getActiveCamera()); // draw Scene
	fboScene->unbind();

	//shadow mapping
#ifdef ENABLE_SHADOW
	fboShadow->bind();
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	drawScene(engine->resourceManager.shaderManager["ShadowMap"],cameraManager["LightCamera"]); // draw Scene for Shadow out of light position
	fboShadow->unbind();
#endif


	#ifdef ENABLE_FSFBO
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	engine->resourceManager.shaderManager["Post"]->bind();
    //#ifdef ENABLE_FS_IMAGE
//	if (fMain)
    //textures = engine->getTextures(); TODO: change
    //for (unsigned int i = 0; i < textures.size(); ++i) {
        //glActiveTexture(GL_TEXTURE0+i);
        //textures[i]->bindTexture();
        //char uniformName[32];
        //sprintf(uniformName,"tex%.2d",i);
        //glUniform1i(engine->resourceManager.shaderManager["Phong"]->getUniformLocation(uniformName),i);
    //}
//
//
//    #else

	//texture assign

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, fbo->getTextureColor());
	glUniform1i(engine->resourceManager.shaderManager["Post"]->getUniformLocation("s"),0);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, fboScene->getTextureColor());
	glUniform1i(engine->resourceManager.shaderManager["Post"]->getUniformLocation("sScene"),1);

	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, fboScene->getTexturePosition());
	glUniform1i(engine->resourceManager.shaderManager["Post"]->getUniformLocation("sPosition"),2);


	glActiveTexture(GL_TEXTURE3);
	glBindTexture(GL_TEXTURE_2D, fboScene->getTextureNormal());
	glUniform1i(engine->resourceManager.shaderManager["Post"]->getUniformLocation("sNormal"),3);

	glActiveTexture(GL_TEXTURE4);
	glBindTexture(GL_TEXTURE_2D, fboScene->getTextureDepth());
	glUniform1i(engine->resourceManager.shaderManager["Post"]->getUniformLocation("sDepth"),4);

	glActiveTexture(GL_TEXTURE5);
	glBindTexture(GL_TEXTURE_2D, fboShadow->getTextureDepth());
	glUniform1i(engine->resourceManager.shaderManager["Post"]->getUniformLocation("sShadowMap"),5);

	//setereo channels
	glActiveTexture(GL_TEXTURE6);
	glBindTexture(GL_TEXTURE_2D, fboRed->getTextureColor());
	glUniform1i(engine->resourceManager.shaderManager["Post"]->getUniformLocation("sSceneRed"),6);
	glActiveTexture(GL_TEXTURE7);
	glBindTexture(GL_TEXTURE_2D, fboCyan->getTextureColor());
	glUniform1i(engine->resourceManager.shaderManager["Post"]->getUniformLocation("sSceneCyan"),7);


#ifdef USEWX
	 textures = engine->getMainWindow()->getTextures();
#endif
	for (unsigned int i = 0; i < textures.size(); ++i) {
		glActiveTexture(GL_TEXTURE5+i);
		textures[i]->bindTexture();
		char uniformName[32];
		sprintf(uniformName,"tex%.2d",i);
		glUniform1i(engine->resourceManager.shaderManager["Post"]->getUniformLocation(uniformName),5+i);
	}

//#endif
	Modelview = glm::mat4(1.0);
//	Modelview = glm::translate(glm::mat4(1.0f),glm::vec3(0,0,0.0));
	//texture->bindTexture();
    glUniformMatrix4fv(engine->resourceManager.shaderManager["Post"]->getUniformLocation("Projection"), 1,0, &ProjectionFullScreenOrtho[0][0]);
    glUniformMatrix4fv(engine->resourceManager.shaderManager["Post"]->getUniformLocation("Modelview"), 1, 0,&Modelview[0][0]);
    glUniformMatrix3fv(engine->resourceManager.shaderManager["Post"]->getUniformLocation("NormalMatrix"), 1,0, &normMatrix[0][0]);

#ifdef ENABLE_SHADOW
/*shadow mapping*/
    glm::mat4 shadowMapBiasMatrix = glm::scale(glm::mat4(1.0),glm::vec3(0.5));
    shadowMapBiasMatrix = glm::translate(shadowMapBiasMatrix,glm::vec3(0.5));
    glm::mat4 lightProjectionMatrix = glm::perspective(60.0f,1.0f,0.1f,100.0f);
    glm::mat4 lightLookAtMatrix = cameraManager["LightCamera"]->getStaticMatrix();
    glUniformMatrix4fv(engine->resourceManager.shaderManager["ShadowMap"]->getUniformLocation("ShadowMapBias"), 1,0, &shadowMapBiasMatrix[0][0]);
    glUniformMatrix4fv(engine->resourceManager.shaderManager["ShadowMap"]->getUniformLocation("LightProjectionMatrix"), 1,0, &lightProjectionMatrix[0][0]);
    glUniformMatrix4fv(engine->resourceManager.shaderManager["ShadowMap"]->getUniformLocation("LightLookAtMatrix"), 1,0, &lightLookAtMatrix[0][0]);
#endif
    glUniform1f(engine->resourceManager.shaderManager["Post"]->getUniformLocation("brightness"),brightness);
    glUniform1i(engine->resourceManager.shaderManager["Post"]->getUniformLocation("saturation"),saturation);
    glUniform1f(engine->resourceManager.shaderManager["Post"]->getUniformLocation("Time"),engine->getTime());
    glUniform1f(engine->resourceManager.shaderManager["Post"]->getUniformLocation("time"),engine->getTime());
    glUniform2f(engine->resourceManager.shaderManager["Post"]->getUniformLocation("resolution"),engine->getWidth(),engine->getHeight());
    int mouseX, mouseY;
    engine->getMousePos(&mouseX, &mouseY);
    mouseY = engine->getHeight()-mouseY;
    glUniform2f(engine->resourceManager.shaderManager["Post"]->getUniformLocation("mousePos"),(float)mouseX/engine->getWidth(), (float)mouseY/engine->getHeight());
    glUniform2f(engine->resourceManager.shaderManager["Post"]->getUniformLocation("lightPositionOnScreen"),screenSpaceLightPos.x, screenSpaceLightPos.y);


    //printf("%f %f\n",(float)mouseX/engine->getWidth(), (float)mouseY/engine->getHeight());

	screenQuad->draw();
	engine->resourceManager.shaderManager["Post"]->unbind();
	#endif

//	engine->resourceManager.shaderManager["Texture"]->bind();
//	glUniformMatrix4fv(engine->resourceManager.shaderManager["Post"]->getUniformLocation("Modelview"), 1, 0,&Modelview[0][0]);
//	glUniformMatrix4fv(engine->resourceManager.shaderManager["Texture"]->getUniformLocation("Projection"), 1,0, &ProjectionFullScreenOrtho[0][0]);
//
//    engine->resourceManager.shaderManager["Texture"]->unbind();

#ifdef USEOPENCV_CAM
	cvWaitKey(10);
#endif

	//return 1;
}

void TestScene::update() {

#ifdef DRAWANIMATEDHORSE
	if (engine->getTime() - deltaTimeHorse >= horseSpeed) { //animation
		horseAnimationCurrent++;
		horseAnimationCurrent = horseAnimationCurrent % horseAnimationCount;
		deltaTimeHorse = engine->getTime();
	}	
#endif
}

void TestScene::setLightPos(float x, float y, float z) {
	lightPos[0] = x;
	lightPos[1] = y;
	lightPos[2] = z;
}
