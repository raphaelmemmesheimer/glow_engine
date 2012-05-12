/*
 * Cube.cpp
 *
 *  Created on: Dec 18, 2011
 *      Author: raphael
 */

#include "Cube.h"

Cube::Cube() {
	glm::vec3 vertices[] = {glm::vec3(-1.0, -1.0, -1.0),
							glm::vec3(1.0, -1.0, -1.0),
							glm::vec3(1.0, 1.0, -1.0),
							glm::vec3(-1.0, 1.0, -1.0),
							glm::vec3(-1.0, -1.0, 1.0),
							glm::vec3(1.0, -1.0, 1.0),
							glm::vec3(1.0, 1.0, 1.0),
							glm::vec3(-1.0, 1.0, 1.0)};

	glm::vec4 colors[] = {glm::vec4(1.0, 0.0, 0.0, 0.0 ),
							glm::vec4(1.0, 1.0, 0.0, 0.0),
							glm::vec4(0.0, 1.0, 0.0, 0.0),
							glm::vec4(0.0, 0.0, 1.0, 0.0),
							glm::vec4(1.0, 0.0, 1.0, 0.0),
							glm::vec4(1.0, 0.0, 1.0, 0.0),
							glm::vec4(1.0, 1.0, 1.0, 0.0),
							glm::vec4(1.0, 1.0, 0.0, 0.0)};

	glm::vec3 normals[] = {glm::vec3(0, -1, 0),
								glm::vec3(1, 0, 0),
								glm::vec3(0, 0, 1),
								glm::vec3(0, 1.0, -0),
								glm::vec3(-1.0, -0, 1.0),
								glm::vec3(1.0, -1.0, 1.0),
								glm::vec3(1.0, 0, 1.0),
								glm::vec3(-1.0, 1.0, 1.0)};

	glm::ivec3 indices[] = {glm::ivec3(0,1,2), // FRONT
							glm::ivec3(0,2,3),
							glm::ivec3(4,5,6), //BACK
							glm::ivec3(4,6,7),
							glm::ivec3(4,0,3), //LEFT
							glm::ivec3(4,3,7),
							glm::ivec3(5,1,2),//RIGHT
							glm::ivec3(5,2,6),
							glm::ivec3(0,4,5), //BOTTOM
							glm::ivec3(0,5,1),
							glm::ivec3( 3,7,6), //TOP
							glm::ivec3(3,6,2)};

	this->vertices = vector<glm::vec3>(&vertices[0], &vertices[8]);
	//this->normals = vector<glm::vec3>(&normals[0],&normals[6]);
	this->faces = vector<glm::ivec3>(&indices[0],&indices[12]);
	this->colors = vector<glm::vec4>(&colors[0],&colors[8]);
	this->faceCount = 12;
	this->vertexCount = 8;
	this->facesToIndices();
	this->setAutoCalcNormals(false);
	generateAndBindBuffers();

}

Cube::~Cube() {
	// TODO Auto-generated destructor stub
}

