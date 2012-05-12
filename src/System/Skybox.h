/*
 * Skybox.h
 *
 *  Created on: Feb 24, 2011
 *      Author: raphael
 */

#ifndef SKYBOX_H_
#define SKYBOX_H_

#include "constants.h"
#include <GL3/gl3w.h>

#include "Texture.h"
#include "Shader.h"
#include "../Shapes/Quad.h"

#include "Drawable.h"


class Skybox : public Drawable{
private:

	Texture* textureUp;
	Texture* textureNorth;
	Texture* textureSouth;
	Texture* textureWest;
	Texture* textureEast;

//	Quad* quadDown;
//	Quad* quadUp;
//	Quad* quadNorth;
//	Quad* quadSouth;
//	Quad* quadWest;
//	Quad* quadEast;

	GLuint vboVerticesID, vboTexCoordID, vboIndicesID, vaoID;

	GLuint vboVerticesIDs[6];
	GLuint vboTexCoordIDs[6];
	GLuint vboIndicesIDs[6];
	GLuint vaoIDs[6];

	void InitVAO();
	Shader* shader;


public:
	Texture* textureDown;
	Skybox();
	virtual ~Skybox();
	void loadTextures(std::string down,std::string up,std::string north,std::string south,std::string west,std::string east);
	void setShader(Shader* shader);
	void draw();
	TiXmlElement* getDrawableAsXmlElement();
};

#endif /* SKYBOX_H_ */
