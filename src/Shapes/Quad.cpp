/*
 * Quad.cpp
 *
 *  Created on: Mar 1, 2011
 *      Author: raphael
 */

#include "Quad.h"
#include "Rect.h"

Quad::Quad(float size) {
	this->setSize(size);
	rect = new Rect(size,size);
}

Quad::~Quad() {
	delete rect;
}

GLfloat Quad::getSize() const
{
    return size;
}

void Quad::setSize(GLfloat size)
{
    this->size = size;
}

void Quad::draw()
{
	rect->draw();
}
