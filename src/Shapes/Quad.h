/*
 * Quad.h
 *
 *  Created on: Mar 1, 2011
 *      Author: raphael
 */

#ifndef QUAD_H_
#define QUAD_H_

#include <GL3/gl3w.h>
#include "Rect.h"
#include "../System/constants.h"

class Quad {
private:
	GLuint vaoID;
	GLuint vboID;
	GLfloat size;
	Rect* rect;
public:
	Quad(float size);
	virtual ~Quad();
	void createSquare();
	void draw();
    GLfloat getSize() const;
    void setSize(GLfloat size);
};

#endif /* QUAD_H_ */
