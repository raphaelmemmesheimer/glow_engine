/*
 * Sphere.cpp
 *
 *  Created on: May 11, 2011
 *      Author: raphael
 */

#include "Sphere.h"

Sphere::Sphere(GLfloat radius, unsigned int numStacks, unsigned int numSlices) {
	this->radius = radius;
	this->numStacks = numStacks;
	this->numSlices = numSlices;

	vertices.clear();

	generate();

	glGenVertexArrays(1,&vaoID);
	glBindVertexArray(this->vaoID);

	if (vertices.size()) {
		glGenBuffers(1,&vboID);
		glBindBuffer(GL_ARRAY_BUFFER,vboID);
		glBufferData(GL_ARRAY_BUFFER,vertices.size()*sizeof(GL_FLOAT) * 3 ,&vertices[0],GL_STATIC_DRAW);
		glEnableVertexAttribArray(SH_VERTEX);
		glVertexAttribPointer(SH_VERTEX,3,GL_FLOAT,GL_FALSE,0,0);
	};
	glEnableVertexAttribArray(0);
	glBindVertexArray(0); //unbind
}

GLfloat Sphere::getRadius() const
{
    return radius;
}

GLuint Sphere::getNumSlices() const
{
    return numSlices;
}

GLuint Sphere::getNumStacks() const
{
    return numStacks;
}

void Sphere::setNumSlices(GLuint numSlices)
{
    this->numSlices = numSlices;
}

void Sphere::setNumStacks(GLuint numStacks)
{
    this->numStacks = numStacks;
}

void Sphere::setRadius(GLfloat radius)
{
    this->radius = radius;
}

Sphere::~Sphere() {
	// TODO Auto-generated destructor stub
}

void Sphere::generate(){
	float PI = 3.14159;
	float phi = 0;
	float theta = 0;
	float deltaTheta = PI / (float)(numStacks);
	float deltaPhi = 2 * PI / (float)(numSlices);
	float x,y,z,y1,y2;
	int i,j;

	theta = deltaTheta;
	for (i = 1 ; i < numStacks+2; i++) {

		y1 = radius * cos(theta);
		y2 = radius * cos(theta + deltaTheta);

		phi = 0.0f;
		for (j = 0 ; j <= numSlices; j++) {
			vertices.push_back(glm::vec3(radius * sin(theta + deltaTheta) * cos(phi), y2, radius * sin(theta + deltaTheta) * sin(phi)));
			vertices.push_back(glm::vec3(radius * sin(theta) * cos(phi), y1, radius * sin(theta) * sin(phi)));
			phi += deltaPhi;
		}

		theta += deltaTheta;
	}
}

void Sphere::draw()
{
	glBindVertexArray(this->vaoID);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, vertices.size());
	glBindVertexArray(0);
}


