/*
 * Rect.cpp
 *
 *  Created on: Apr 22, 2011
 *      Author: raphael
 */

#include "Rect.h"

Rect::Rect(float width, float height) {
	setWidth(width);
	setHeight(height);
	createRect();
}

float Rect::getHeight() const
{
    return height;
}

float Rect::getWidth() const
{
    return width;
}

void Rect::setHeight(float height)
{
    this->height = height;
}

void Rect::setWidth(float width)
{
    this->width = width;
}

Rect::~Rect() {
	// TODO Auto-generated destructor stub
}

void Rect::createRect()
{
    GLfloat vRect[] = {
    		-this->height/2.0,-this->width/2.0,0.0,
    		-this->height/2.0,this->width/2.0,0.0,
    		this->height/2.0,this->width/2.0,0.0,
    		this->height/2.0,-this->width/2.0,0.0,
    		-this->height/2.0,-this->width/2.0,0.0,
    		this->height/2.0,this->width/2.0,0.0
    };

    GLubyte tRect[] = {
    		0,0,
    		0,1,
    		1,1,
    		1,0,
    		0,0,
    		1,1
    };


	glGenVertexArrays(1, &vaoID); // Create our Vertex Array Object
	glBindVertexArray(vaoID); // Bind our Vertex Array Object so we can use it

	glGenBuffers(1, &vboID); // Generate our Vertex Buffer Object

	glBindBuffer(GL_ARRAY_BUFFER, vboID); // Bind our Vertex Buffer Object
	glBufferData(GL_ARRAY_BUFFER, sizeof(vRect), vRect, GL_STATIC_DRAW); // Set the size and data of our VBO and set it to STATIC_DRAW
	glEnableVertexAttribArray(SH_VERTEX);
	glVertexAttribPointer(SH_VERTEX, 3, GL_FLOAT, GL_FALSE, 0, 0); // Set up our vertex attributes pointer


	glGenBuffers(1, &vboID); // Generate our Vertex Buffer Object

	glBindBuffer(GL_ARRAY_BUFFER, vboID); // Bind our Vertex Buffer Object
	glBufferData(GL_ARRAY_BUFFER, sizeof(tRect), tRect, GL_STATIC_DRAW); // Set the size and data of our VBO and set it to STATIC_DRAW
	glEnableVertexAttribArray(SH_TEXTURECOORD);
	glVertexAttribPointer(SH_TEXTURECOORD, 2, GL_UNSIGNED_BYTE, GL_FALSE, 0, 0); // Set up our vertex attributes pointer


	glEnableVertexAttribArray(0); // Disable our Vertex Array Object
	glBindVertexArray(0); // Disable our Vertex Buffer Object*/
}

void Rect::draw(){
	glBindVertexArray(vaoID); // Bind our Vertex Array Object

	glDrawArrays(GL_TRIANGLES, 0, 6); // Draw our square

	glBindVertexArray(0); // Unbind our Vertex Array Object
}
