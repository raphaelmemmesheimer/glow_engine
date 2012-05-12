/*
 * Triangle.h
 *
 *  Created on: Mar 1, 2011
 *      Author: raphael
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <GL3/gl3w.h>
#include "../System/Shader.h"



class Triangle {
private:
	GLuint vboID;
	GLuint vaoID;
	GLfloat width;
    GLfloat height;
    Shader* shader;
    //void initVBO;
public:
    Triangle();
    virtual ~Triangle();
    void draw();
    GLfloat getHeight() const;
    GLfloat getWidth() const;
    void setHeight(GLfloat height);
    void setWidth(GLfloat width);
    void setShader(Shader* shader);
};

#endif /* TRIANGLE_H_ */
