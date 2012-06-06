/*
 * Engine.cpp
 *
 *  Created on: Apr 6, 2011
 *      Author: raphael
 */

#include "Engine.h"
//#include "Demo.h"

Engine::Engine() {
	fpsLimit = 30;
	fpsLimitEnabled = true;
}

void Engine::init(int width, int height) {
	this->width = width;
	this->height = height;

	//init glf
	if( !glfwInit()){
		fprintf( stderr, "Failed to initialize GLFW\n" );
	}
	//init gl3w
	if (!gl3wInit()){
		fprintf( stderr, "Failed to initialize gl3w\n" );
	}

	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR,4); //set up opengl 3.3 context
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR,1);
	//glfwOpenWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

//

	//glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 8); // for 4x multisample

    #ifdef GLFW3
	window = glfwOpenWindow(width, height, GLFW_WINDOWED, "glow:engine", NULL);
	if (!window)//if( !glfwOpenWindow(WIDTH, HEIGHT, 0,0,0,0, 16,0, GLFW_WINDOW  ) )
	{
		fprintf( stderr, "Failed to open GLFW window\n" );
		glfwTerminate();
	}
	#endif
	#ifdef GLFW2
	if( !glfwOpenWindow(width, height, 0,0,0,0, 16,0, GLFW_WINDOW ) )
	{
		fprintf( stderr, "Failed to open GLFW window\n" );
		glfwTerminate();
		//return 0;
	}
	#endif

	//glEnable(GL_MULTISAMPLE);

	printGLinfo();
//	printf("1\n");
	//glfwSwapInterval( 1 );
	setMousePos(width/2,height/2);
	//glfwSetMousePos(window,width/2,height/2);
//	printf("2\n");
	glViewport(0,0,width,height);

}

const char *Engine::getTitle() const
{
    return title;
}

int Engine::getHeight() const
{
    return height;
}

int Engine::getWidth() const
{
    return width;
}

void Engine::setHeight(int height)
{
    this->height = height;
}

#ifdef GLFW3
GLFWwindow Engine::getWindow() const
{
    return window;width/2,height/2
}

void Engine::setWindow(GLFWwindow window)
{
    this->window = window;
}

#endif

int Engine::getFpsLimit() const
{
    return fpsLimit;
}

bool Engine::getFpsLimitEnabled() const
{
    return fpsLimitEnabled;
}

void Engine::setFpsLimit(int fpsLimit)
{
    this->fpsLimit = fpsLimit;
}

void Engine::setFpsLimitEnabled(bool fpsLimitEnabled)
{
    this->fpsLimitEnabled = fpsLimitEnabled;
}



void Engine::setWidth(int width)
{
    this->width = width;

}

void Engine::setTitle(const char *title)
{
    this->title = title;
    #ifdef GLFW3
    	glfwSetWindowTitle(window,title);
	#endif
	#ifdef GLFW2
    	glfwSetWindowTitle(title);
	#endif
}

Engine::~Engine() {

	// Terminate GLFW
		glfwTerminate();

//		TwTerminate();

}

void Engine::mainLoop() {
	double deltaTime = 0.0;
	double timePerFrame = 0.0;
	float sleepTimeInUSeconds = 0.0;


	double frameLimit = 100.0/double(fpsLimit); //e.g 1.6 = max 60fps = 100ms / 60

	bool running = true;
    do
    {
    	timePerFrame = glfwGetTime();

    	draw(); // draw scene
		//TwDraw();
		glfwSwapBuffers();
		glfwPollEvents();
		timePerFrame = glfwGetTime()-timePerFrame;

		if (glfwGetTime() - deltaTime >= 1.0) {

		  char c[100];
		  //sprintf(c, "%s %dfps %ftpf %f sec running",title, fps, timePerFrame, glfwGetTime());

		  setTitle(c);
		  fps = 0;
		  deltaTime = glfwGetTime();
		} else {
		  fps++; // inc fps
		}

		if (fpsLimitEnabled) {
			//frame limiter mit micro ms sleeper

			if (frameLimit > timePerFrame)
			  sleepTimeInUSeconds = frameLimit - timePerFrame;
			else
			  sleepTimeInUSeconds = 0.0;
			//printf("%f %f %f %f \n",timePerFrame, glfwGetTime(), sleepTimeInUSeconds,frameLimit);
			usleep(sleepTimeInUSeconds*10000);
		}

		#ifdef GLFW3
			running = glfwIsWindow(window) && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS;
		#endif
		#ifdef GLFW2
			running = glfwGetWindowParam(GLFW_OPENED);
		#endif
    }
    while (running);
}

void Engine::printGLinfo()
{
	int glVersionMajor = 0;
	int glVersionMinor = 0;
	int glVersionRev = 0;
	//glfwGetGLVersion(&glVersionMajor,&glVersionMinor,&glVersionRev);

	printf("OpenGL: %d.%d.%d\n",glVersionMajor,glVersionMinor,glVersionRev);
	cout<<"Vendor: "<<glGetString (GL_VENDOR)<<endl;
	cout<<"Renderer: "<<glGetString (GL_RENDERER)<<endl;
	cout<<"Version: "<<glGetString (GL_VERSION)<<endl;
	cout<<"GLSL: "<<glGetString (GL_SHADING_LANGUAGE_VERSION)<<endl;
}

void Engine::setMousePos(int mouseX, int mouseY)
{
}

double Engine::getTime()
{
	return glfwGetTime();
}



int Engine::getLastMouseX() const
{
    return lastMouseX;
}

int Engine::getLastMouseY() const
{
    return lastMouseY;
}

void Engine::setLastMouseX(int lastMouseX)
{
    this->lastMouseX = lastMouseX;
}

void Engine::setLastMouseY(int lastMouseY)
{
    this->lastMouseY = lastMouseY;
}

//#ifdef USEWX
//GlowEditorfMainEditor *Engine::getMainWindow() const
//{
	//return fMainWindow;
//}

//void Engine::setMainWindow(GlowEditorfMainEditor *mainWindow)
//{
	//fMainWindow = mainWindow;
	//fMainWindow->getShaderEditor()->setShaderManager(shaderManager);
//}
//#endif

void Engine::getMousePos(int *mouseX, int *mouseY)
{
	glfwGetMousePos(mouseX,mouseY);
}


//void Engine::setDemo(Demo demo) {
  //this->Demo = demo;
//}

//Demo Engine::getDemo() {
  //return this->demo;
//}

