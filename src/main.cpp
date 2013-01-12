#define USEWX //show gui
#define ENABLE_FSFBO
//#define USEROCKET
//#define DRAWANIMATEDHORSRE
#define SSDO_SCENE
//#define PLAY_TRACK
#define ENABLE_SHADOW
#define ENABLE_FS_IMAGE
//#define USEOPENCV_CAM

#define GLFW_INCLUDE_GL3

#include "System/Engine.h"
#include <stdio.h>

#include <iostream>

#include <string>
#include <iostream>

#include "3rdParty/gnurocket/sync/sync.h"
#include "Demos/DemoLossless01.h"



#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

//#ifdef USEWX
//#include "Forms/GlowEditorfPhongEditor.h"
//#include "Forms/GlowEditorfShaderEditor.h"
//#include "Forms/GlowEditorfPostProcessEditor.h"
#include "Forms/GlowEditorfMainEditor.h"
//#include <wx/wx.h>
//#endif

#ifdef USEOPENCV_CAM
//http://r3dux.org/2010/12/how-to-manipulate-webcam-streams-with-opencv-and-opengl/
#include <opencv/cv.h>
#include "opencv/highgui.h"
CvCapture* pCapture = NULL;
IplImage* pFrame = NULL;
#endif

#define WIDTH 1024
#define HEIGHT 768




bool running = true;

float moveSpeed = 0.001;

int fps = 0;

#ifdef USEWX
GlowEditorfMainEditor * fMainWindow;
//GlowEditorfShaderEditor* fShaderEditor;
//GlowEditorfPhongEditor* fPhongEditor;
#endif


Engine* engine;

int tmpMousePos = 0;

//gnu rocket sync
#ifdef USEROCKET
sync_device *rocket;
const struct sync_track *lightX, *lightY, *lightZ;
const struct sync_track *colorR, *colorG, *colorB;
#endif
//
Demo* demo;
DemoLossless01 demoTesting;




//pass handles over to scene
void handleKeys( int key, int action)
{
	demoTesting.getSceneManager()->getActiveScene()->handleKeyboard(key, action);
	printf("%d \n",key);
	switch (key){
		case 79:
			if (action == GLFW_PRESS)	
				demoTesting.getSceneManager()->switchToNextScene();
			break;
	}
}

void handleMousePos(int x, int y)
{
	demoTesting.getSceneManager()->getActiveScene()->handleMousePos(x, y);
}

void handleScroll(int hor,int vert){
	demoTesting.getSceneManager()->getActiveScene()->handleMouseScroll(hor, vert);
}

void handleMouseWheel(int mouseWheelPos){
	demoTesting.getSceneManager()->getActiveScene()->handleMouseWheel(mouseWheelPos);
}

void window_resize_callback(int width, int height) {
	demoTesting.getSceneManager()->getActiveScene()->resize(width,height);
}

void draw()
{
	demoTesting.getSceneManager()->getActiveScene()->draw();
}
/////////////////////////////////////////////////////////////////////////////////////



void initglfw()
{
	  glfwSetMousePosCallback(handleMousePos);

	  glfwSetKeyCallback(handleKeys);
	#ifdef GLFW3
		glfwSetScrollCallback(handleScroll);
	#endif
	#ifdef GLFW2
		glfwSetMouseWheelCallback(handleMouseWheel);
	#endif
}

void initWebcam()
{
#ifdef USEOPENCV_CAM
	cvNamedWindow("WebCam", CV_WINDOW_AUTOSIZE);
	pCapture = cvCaptureFromCAM(0);
	pFrame = cvQueryFrame(pCapture);
	if( !pCapture )
	{
		printf( "failed to create webcam capture\n" );

	}
#endif
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef USEWX

int main() { //int argc, char **argv
//	initWebcam();
//	engine = new Engine();
//	engine->setTitle("glow:engine");
//	printf("before engine-init\n");
//	engine->init(WIDTH,HEIGHT);
//	printf("before init \n");
//
//	init();
//	initglfw();
//	//track->play();
//
//	glViewport(0,0,WIDTH,HEIGHT);
//    engine->setFpsLimit(60);
//	engine->draw = render1;
//
//
//	engine->mainLoop();

	engine = new Engine();
 
////xx	fMainWindow->setTextures(textures);

	  engine->init(WIDTH,HEIGHT);

	  engine->setTitle("glow:engine");
	  demoTesting.setEngine(engine);
	  demoTesting.init();
	initglfw();
	  glfwSetWindowSizeCallback(window_resize_callback);

	 //track->play();

	engine->setFpsLimit(60);
	engine->setFpsLimitEnabled(true);

	engine->draw = draw;
	engine->mainLoop();
	// Release our stream capture object
#ifdef USEOPENCV_CAM
	cvReleaseCapture(&pCapture);

	// Release our images and destroy all windows
	cvReleaseImage(&pFrame);
	cvDestroyAllWindows();
#endif
	delete engine;
	return 0;
}
#else

class DerivedFrame : public GlowEditorfPhongEditor
{
public:
	double deltaTime;
	double deltaTimeHorse;
	double timePerFrame;
	float sleepTimeInUSeconds;
	DerivedFrame(wxWindow* parent);
	//<GlowEditorfPhongEditor(  );
	void OnIdle(wxIdleEvent& event);
};

DerivedFrame::DerivedFrame(wxWindow* parent) :GlowEditorfPhongEditor(parent)
{
	deltaTime = 0.0;
	deltaTimeHorse = 0.0;
	timePerFrame = 0.0;
	sleepTimeInUSeconds = 0.0;
}

void DerivedFrame::OnIdle(wxIdleEvent& event)
{

	 engine->setFpsLimitEnabled(fMainWindow->cbFPSLimiter->IsChecked());

	//double time = engine->getTime();
	double frameLimit = 100.0/double(engine->getFpsLimit());



	timePerFrame = engine->getTime();
#ifdef ENABLE_SHADOW
	//switchCam(true);
	engine->draw(); // draw out of lightPos
	//switchCam(false);
#endif
	engine->draw(); //draw scene out of CamPos

	timePerFrame = engine->getTime()-timePerFrame;

	demoTesting.getSceneManager()->getActiveScene()->update();

	if (engine->getTime() - deltaTime >= 1.0) {
		//printf("%d \n",fps);
		wxString fpsString = wxString::Format(wxT("%i"), fps);
		 fMainWindow->eFpsValue->SetLabel(fpsString);
		fps = 0;
		deltaTime = engine->getTime();
	} else {
	  fps++; // inc fps
	}


	if (engine->getFpsLimitEnabled()) {
		//frame limiter mit micro us sleeper
		if (frameLimit > timePerFrame)
		  sleepTimeInUSeconds = frameLimit - timePerFrame;
		else
		  sleepTimeInUSeconds = 0.0;
		usleep(sleepTimeInUSeconds*10000);
	}
	glfwSwapBuffers();
	glfwPollEvents();



//	shininess = fMainWindow->fPhongEditor->sliderShininess->GetValue();
//
//	ambientRed = fMainWindow->fPhongEditor->colourPickerAmbient->GetColour().Red()/255.0;
//	ambientGreen = fMainWindow->fPhongEditor->colourPickerAmbient->GetColour().Green()/255.0;
//	ambientBlue = fMainWindow->fPhongEditor->colourPickerAmbient->GetColour().Blue()/255.0;
//
//	diffuseRed = fMainWindow->fPhongEditor->colourPickerDiffuse->GetColour().Red()/255.0;
//	diffuseGreen = fMainWindow->fPhongEditor->colourPickerDiffuse->GetColour().Green()/255.0;
//	diffuseBlue = fMainWindow->fPhongEditor->colourPickerDiffuse->GetColour().Blue()/255.0;
//<F11>
//	specularRed = fMainWindow->fPhongEditor->colourPickerSpecular->GetColour().Red()/255.0;
//	specularGreen = fMainWindow->fPhongEditor->colourPickerSpecular->GetColour().Green()/255.0;
//	specularBlue = fMainWindow->fPhongEditor->colourPickerSpecular->GetColour().Blue()/255.0;



//	brightness = fMainWindow->getPostProcessEditor()->brightnessSlider->GetValue()/256.0;
//	saturation = fMainWindow->getPostProcessEditor()->saturationSlider->GetValue();

//	fMainWindow->mLightPosX->GetValue().ToDouble(&lightPos[0]);
//	fMainWindow->mLightPosY->GetValue().ToDouble(&lightPos[1]);
//	fMainWindow->mLightPosZ->GetValue().ToDouble(&lightPos[2]);


//#ifdef USEROCKET
	//sync_update(rocket,(int)floor(engine->getTime()*0.2));

	//lightPos[0] = sync_get_val(lightX,engine->getTime());
////	lightPos[1] = sync_get_val(lightY,engine->getTime());
////	lightPos[2] = sync_get_val(lightZ,engine->getTime());
////
	//diffuseRed = sync_get_val(colorR,engine->getTime())/255.0;
	//diffuseGreen = sync_get_val(colorG,engine->getTime())/255.0;
	//diffuseBlue = sync_get_val(colorB,engine->getTime())/255.0;
	//printf("%f %f %f \n",lightPos[0],lightPos[1],lightPos[2]);
//#endif

	event.RequestMore();
}


class DerivedApp : public wxApp
{
public:
  virtual bool OnInit();
};

IMPLEMENT_APP(DerivedApp)

bool DerivedApp::OnInit()
{
	engine = new Engine();
	DerivedFrame *fPhongEditor1 = new DerivedFrame(0L);

	fMainWindow = new GlowEditorfMainEditor(0L);
	fMainWindow->Show(true);
	fMainWindow->getShaderEditor()->Show(true);
	//fMainwindow->m_SceneTree
	//
	//fMainWindow->setTextures(textures);
	
	fMainWindow->m_SceneTree->AddRoot(wxString::FromAscii("Hello Word"));
	  engine->init(WIDTH,HEIGHT);
	  engine->setTitle("glow:engine");


	//demo = new DemoLossless01();
	demo = (Demo*)&demoTesting;
	  demoTesting.setEngine(engine);
	demoTesting.init();
	demoTesting.saveToFile("lossless01.glow");
	//demoTesting.sceneManager.toWxChoice(fMainWindow->m_choiceScene);

	fMainWindow->getShaderEditor()->setShaderManager(engine->resourceManager.shaderManager);
	fMainWindow->setResourceManager(&(engine->resourceManager));
	fMainWindow->setDemo(demo);
	//fMainWindow->setDemo(Demo(&demoTesting)); 
	//engine->setMainWindow(fMainWindow); TODO: change
	//demoTesting.getSceneManager()->getActiveScene()->getSceneGraph().toWxTree(fMainWindow->m_SceneTree);
	  glfwSetWindowSizeCallback(window_resize_callback);

	 //track->play();
	  initglfw();

	engine->setFpsLimit(60);
	engine->setFpsLimitEnabled(true);

//#ifdef USEROCKET
	//rocket = sync_create_device("sync");
	//if (!rocket)
		//printf("gnu rocket error\n");

	//if (sync_connect(rocket, "192.168.2.106", SYNC_DEFAULT_PORT))
		//printf("failed to connect to host\n");


	 ////get tracks
	//lightX = sync_get_track(rocket, "light.x");
	//lightY = sync_get_track(rocket, "light.y");
	//lightZ = sync_get_track(rocket, "light.z");

	//colorR = sync_get_track(rocket, "color.r");
	//colorG = sync_get_track(rocket, "color.g");
	//colorB = sync_get_track(rocket, "color.b");
//#endif
	  engine->draw = draw; //render1;
	  return true;
}
#endif
