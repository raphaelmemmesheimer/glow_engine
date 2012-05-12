/*
 * Triangle.cpp
 *
 *  Created on: Mar 1, 2011
 *      Author: raphael
 */

#include "Triangle.h"



Triangle::Triangle() {
	const GLfloat vTriangle[] = {
				    0.5f, 0.5f, 0.0f,
				    0.5f, -0.5f, 0.0f,
				    -0.5f, -0.5f, 0.0f
	};
	glGenVertexArrays(1, &vaoID); // Create our Vertex Array Object
	glBindVertexArray(vaoID); // Bind our Vertex Array Object so we can use it

	glGenBuffers(1,&vboID);
	glBindBuffer(GL_ARRAY_BUFFER,vboID);
	glBufferData(GL_ARRAY_BUFFER,sizeof(vTriangle),vTriangle,GL_STATIC_DRAW);
	glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
}

GLfloat Triangle::getHeight() const
{
    return height;
}

GLfloat Triangle::getWidth() const
{
    return width;
}

void Triangle::setHeight(GLfloat height)
{
    this->height = height;
}

void Triangle::draw()
{
	//shader->bind();
	glBindVertexArray(vaoID);

	glDrawArrays(GL_TRIANGLES,0,3);
	//glDisableVertexAttribArray(0);
	glBindVertexArray(0);
	//shader->unbind();
}


void Triangle::setWidth(GLfloat width)
{
    this->width = width;
}

void Triangle::setShader(Shader* shader)
{
	this->shader = shader;
}

Triangle::~Triangle() {

}
