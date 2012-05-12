/*
 * Rect.h
 *
 *  Created on: Apr 22, 2011
 *      Author: raphael
 */

#ifndef RECT_H_
#define RECT_H_

#include <GL3/gl3.h>
#include <GL3/gl3w.h>
#include "../System/constants.h"

class Rect {
private:
	float height;
	float width;
	GLuint vaoID;
	GLuint vboID;
	GLfloat size;
public:
	Rect(float height, float width);
	virtual ~Rect();
	void createRect();
    float getHeight() const;
    float getWidth() const;
    void setHeight(float height);
    void setWidth(float width);
    void draw();
};

#endif /* RECT_H_ */
