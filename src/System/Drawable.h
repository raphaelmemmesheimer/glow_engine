/*
 * Drawable.h
 *
 *  Created on: Dec 18, 2011
 *      Author: raphael
 */

#ifndef DRAWABLE_H_
#define DRAWABLE_H_

#include <glm/glm.hpp>
#include <GL3/gl3.h>
#include <GL3/gl3w.h>
#include <vector>
#include <stdio.h>

#include "constants.h"
#include "../3rdParty/tinyxml/tinyxml.h"

using namespace std;
class Drawable {
private:
	bool autoCalcNormals;
public:
	Drawable();
	virtual ~Drawable();

	int vertexCount;
	int faceCount;

	GLuint vaoID;
	GLuint vboID;

	vector<glm::vec3> vertices;
	vector<glm::vec3> normals;
	vector<glm::vec4> colors;
	vector<glm::vec2> textureCoordinates;

	vector<unsigned int> indices;
	vector<glm::ivec3> faces;

	void generateAndBindBuffers();
	void draw();
	void calcNormals();
    bool getAutoCalcNormals() const;
    void setAutoCalcNormals(bool autoCalcNormals);
    void facesToIndices();
	virtual	TiXmlElement* getDrawableAsXmlElement(); 
};

#endif /* DRAWABLE_H_ */
