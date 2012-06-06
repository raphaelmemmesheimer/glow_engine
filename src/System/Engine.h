/*
 * Engine.h
 *
 *  Created on: Apr 6, 2011
 *      Author: raphael
 */

#ifndef ENGINE_H_
#define ENGINE_H_

//#define GLFW3
#define GLFW2
#define GLFW_INCLUDE_GL3
#define GLFW_NO_GLU
#include <GL3/gl3w.h>
#include <GL3/gl3.h>

//#ifdef USEWX
//#include "../Forms/GlowEditorfMainEditor.h"
//#endif

#ifdef GLFW3
	#include <GL/glfw3.h>
#endif
#ifdef GLFW2
	#include <GL/glfw.h>
#endif
#include <stdio.h>
#include <iostream>
#include "common.h"
//#include "CameraManager.h"
//#include "ShaderManager.h"
//#include "TextureManager.h"
#include "ResourceManager.h"
//#include "Demo.h"

using namespace std;

//class SceneManager;
//class Demo;


class Engine {
private:
    int height;
    int width;
    int fps;
    int fpsLimit;
    bool fpsLimitEnabled;
    const char *title;

	int lastMouseX;
	int lastMouseY;
	//Demo demo;

//#ifdef USEWX
    //GlowEditorfMainEditor *fMainWindow;
//#endif
    //void render();
public:
    void (*draw)();
    Engine();
    void init(int width, int height);
    void mainLoop();
    virtual ~Engine();
    const char *getTitle() const;
    void setTitle(const char *title);
    int getHeight() const;
    int getWidth() const;
    void setHeight(int height);
    void setWidth(int width);
    int getFpsLimit() const;
    bool getFpsLimitEnabled() const;
    void setFpsLimit(int fpsLimit);
    void setFpsLimitEnabled(bool fpsLimitEnabled);
    void printGLinfo();
    double getTime();
    void setMousePos(int mouseX, int mouseY);
    void getMousePos(int *mouseX, int *mouseY);
//#ifdef USEWX
	//GlowEditorfMainEditor *getMainWindow() const;
	//void setMainWindow(GlowEditorfMainEditor *mainWindow);
	//Demo getDemo();
	//void setDemo(Demo demo);
//#endif
    int getLastMouseX() const;
    int getLastMouseY() const;
    void setLastMouseX(int lastMouseX);
    void setLastMouseY(int lastMouseY);
	ResourceManager resourceManager;
};

#endif /* ENGINE_H_ */
