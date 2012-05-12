/*
 * Skybox.cpp
 *
 *  Created on: Feb 24, 2011
 *      Author: raphael
 */


#include "Skybox.h"
#include <cassert>

#define GL_CHECK_ERRORS assert(glGetError()== GL_NO_ERROR);
GLubyte tSkyBox[6];

GLfloat vSkyBoxFront[] =
    {
        -1000, -1000, 1000,   // vertex v0 front left bottom
        1000,  -1000, 1000,   // vertex v1 front right bottom
        1000,   1000, 1000,   // v3 front right top
        -1000,  1000, 1000	// v4 front left top
    };

GLfloat vSkyBoxBack[] =
    {
        -1000, -1000, -1000,   // vertex v0 front left bottom
        1000,  -1000, -1000,   // vertex v1 front right bottom
        1000,   1000, -1000,   // v3 front right top
        -1000,  1000, -1000	// v4 front left top
    };

GLfloat vSkyBoxBottom[] =
    {
    	-1000, -1000, 1000,   // vertex v0 bottom left front
    	1000,  -1000, 1000,   // vertex v1 bottom right front
    	1000,  -1000, -1000,  // vertex v2 bottom right back
    	-1000, -1000, -1000   // vertex v3 bottom left back
    };

GLfloat vSkyBoxTop[] =
    {
    	-1000, 1000, 1000,   // vertex v0 top left front
    	1000,  1000, 1000,   // vertex v1 top right front
    	1000,  1000, -1000,  // vertex v2 top right back
    	-1000, 1000, -1000   // vertex v3 top left back
    };

GLfloat vSkyBoxLeft[] =
    {
		-1000, -1000, 1000,   // vertex v0
		-1000, -1000, -1000,  // vertex v3
		-1000, 1000,  -1000,   // vertex v7
		-1000, 1000,  1000   // vertex v7
    };

GLfloat vSkyBoxRight[] =
    {
        1000, -1000, 1000,   // vertex v0
        1000, -1000, -1000,  // vertex v3
        1000, 1000,  -1000,   // vertex v7
        1000, 1000,  1000   // vertex v7
    };

GLfloat vSkyBox[] =
    {
        -1000, -1000, 1000,   // vertex v0 flb
        1000,  -1000, 1000,   // vertex v1 frb
        1000,  -1000, -1000,  // vertex v2 brb
        -1000, -1000, -1000,  // vertex v3 blb
        -1000, 1000,  1000,   // vertex v4 flt
        1000,  1000,  1000,   // vertex v5 frt
        1000,  1000,  -1000,  // vertex v6 brt
        -1000, 1000,  -1000   // vertex v7 blt
    };

GLuint iSkyBox[] =
    {
        0,1,5, // front
        0,4,5,
        0,1,2,//bottom
        0,3,2,
        3,2,6,//back
        3,7,6,
        4,5,6, //top
        4,7,6,
        0,3,7,//left
        0,4,7,
        1,2,6, //right
        1,5,6
    };

GLuint iSkyBoxFront[] =
    {
        0,1,2, // front
        0,2,3
    };
GLuint iSkyBoxBottom[] =
    {
        0,1,2,//bottom
        0,3,2
    };
GLuint iSkyBoxBack[] =
    {
        0,1,2,//back
        0,2,3
    };
GLuint iSkyBoxTop[] =
    {
        0,1,2, //top
        0,3,2
    };
GLuint iSkyBoxLeft[] =
    {
		0,1,2,
		0,3,2
    };
GLuint iSkyBoxRight[] =
    {
        0,1,2,
        0,3,2
    };

GLfloat tcSkyBox[] =
	{
        0.0, 0.0,  // mapping coordinates for vertex v0
        0.0, 1.0,  // mapping coordinates for vertex v1
        0.0, 1.0,  // mapping coordinates for vertex v2
        0.0, 0.0,  // mapping coordinates for vertex v3
        1.0, 0.0,  // mapping coordinates for vertex v4
        1.0, 1.0,  // mapping coordinates for vertex v5
        1.0, 0.0,  // mapping coordinates for vertex v6
        1.0, 1.0   // mapping coordinates for vertex v7
    };

GLfloat tcSkyBoxFront[] =
	{
			1.0, 0.0,  // mapping coordinates for vertex v0
        0,0,  // mapping coordinates for vertex v1
          // mapping coordinates for vertex v2
        0.0, 1.0,
        1.0, 1.0// mapping coordinates for vertex v3
    };

GLfloat tcSkyBoxBack[] =
	{
        0.0, 0.0,  // mapping coordinates for vertex v0
        1.0, 0.0,  // mapping coordinates for vertex v1
        1.0, 1.0,  // mapping coordinates for vertex v2
        0.0, 1.0,  // mapping coordinates for vertex v3
    };

GLfloat tcSkyBoxTop[] =
	{

          // mapping coordinates for vertex v2
        0.0, 1.0,
        1.0, 1.0,// mapping coordinates for vertex v3
		1.0, 0.0,  // mapping coordinates for vertex v0
    0,0  // mapping coordinates for vertex v1
    };

GLfloat tcSkyBoxBottom[] =
	{
        0.0, 0.0,  // mapping coordinates for vertex v0
        1.0, 0.0,  // mapping coordinates for vertex v1
        1.0, 1.0,  // mapping coordinates for vertex v2
        0.0, 1.0,  // mapping coordinates for vertex v3
    };

GLfloat tcSkyBoxRight[] =
	{
			1.0, 0.0,  // mapping coordinates for vertex v0
        0,0,  // mapping coordinates for vertex v1
          // mapping coordinates for vertex v2
        0.0, 1.0,
        1.0, 1.0// mapping coordinates for vertex v3
    };

GLfloat tcSkyBoxLeft[] =
	{
        0.0, 0.0,  // mapping coordinates for vertex v0
        1.0, 0.0,  // mapping coordinates for vertex v1
        1.0, 1.0,  // mapping coordinates for vertex v2
        0.0, 1.0,  // mapping coordinates for vertex v3
    };

void Skybox::InitVAO() {

	//Create vao and vbo stuff
	glGenVertexArrays(6, vaoIDs);

	glGenBuffers (6, vboVerticesIDs);
	glGenBuffers (6, vboTexCoordIDs);
	glGenBuffers (6, vboIndicesIDs);
	GL_CHECK_ERRORS;

	//north
	glBindVertexArray(vaoIDs[0]);
		glBindBuffer (GL_ARRAY_BUFFER, vboVerticesIDs[0]);
		glBufferData (GL_ARRAY_BUFFER, sizeof(vSkyBoxFront), &vSkyBoxFront[0], GL_STATIC_DRAW);
		GL_CHECK_ERRORS
		glEnableVertexAttribArray(SH_VERTEX);
		glVertexAttribPointer (SH_VERTEX, 3, GL_FLOAT, GL_FALSE,sizeof(GL_FLOAT)*3,0);
		GL_CHECK_ERRORS
		glEnableVertexAttribArray(SH_TEXTURECOORD);
		glBindBuffer (GL_ARRAY_BUFFER, vboTexCoordIDs[0]);
		glBufferData (GL_ARRAY_BUFFER, sizeof(tcSkyBoxFront), &tcSkyBoxFront[0], GL_STATIC_DRAW);
		glVertexAttribPointer (SH_TEXTURECOORD, 2, GL_FLOAT, GL_FALSE,sizeof(GLfloat)*2,0);
		GL_CHECK_ERRORS
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboIndicesIDs[0]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(iSkyBoxFront), &iSkyBoxFront[0], GL_STATIC_DRAW);
	    GL_CHECK_ERRORS;
	//south
	glBindVertexArray(vaoIDs[1]);
			glBindBuffer (GL_ARRAY_BUFFER, vboVerticesIDs[1]);
			glBufferData (GL_ARRAY_BUFFER, sizeof(vSkyBoxBack), &vSkyBoxBack[0], GL_STATIC_DRAW);
			GL_CHECK_ERRORS
			glEnableVertexAttribArray(SH_VERTEX);
			glVertexAttribPointer (SH_VERTEX, 3, GL_FLOAT, GL_FALSE,sizeof(GL_FLOAT)*3,0);
			GL_CHECK_ERRORS
			glEnableVertexAttribArray(SH_TEXTURECOORD);
			glBindBuffer (GL_ARRAY_BUFFER, vboTexCoordIDs[1]);
			glBufferData (GL_ARRAY_BUFFER, sizeof(tcSkyBoxBack), &tcSkyBoxBack[0], GL_STATIC_DRAW);
			glVertexAttribPointer (SH_TEXTURECOORD, 2, GL_FLOAT, GL_FALSE,sizeof(GLfloat)*2,0);
			GL_CHECK_ERRORS
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboIndicesIDs[1]);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(iSkyBoxBack), &iSkyBoxBack[0], GL_STATIC_DRAW);
		    GL_CHECK_ERRORS;
    //top
	glBindVertexArray(vaoIDs[2]);
			glBindBuffer (GL_ARRAY_BUFFER, vboVerticesIDs[2]);
			glBufferData (GL_ARRAY_BUFFER, sizeof(vSkyBoxTop), &vSkyBoxTop[0], GL_STATIC_DRAW);
			GL_CHECK_ERRORS
			glEnableVertexAttribArray(SH_VERTEX);
			glVertexAttribPointer (SH_VERTEX, 3, GL_FLOAT, GL_FALSE,sizeof(GL_FLOAT)*3,0);
			GL_CHECK_ERRORS
			glEnableVertexAttribArray(SH_TEXTURECOORD);
			glBindBuffer (GL_ARRAY_BUFFER, vboTexCoordIDs[2]);
			glBufferData (GL_ARRAY_BUFFER, sizeof(tcSkyBoxTop), &tcSkyBoxTop[0], GL_STATIC_DRAW);
			glVertexAttribPointer (SH_TEXTURECOORD, 2, GL_FLOAT, GL_FALSE,sizeof(GLfloat)*2,0);
			GL_CHECK_ERRORS
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboIndicesIDs[2]);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(iSkyBoxTop), &iSkyBoxTop[0], GL_STATIC_DRAW);
			GL_CHECK_ERRORS;
	glBindVertexArray(vaoIDs[3]);
		glBindBuffer (GL_ARRAY_BUFFER, vboVerticesIDs[3]);
		glBufferData (GL_ARRAY_BUFFER, sizeof(vSkyBoxBottom), &vSkyBoxBottom[0], GL_STATIC_DRAW);
		GL_CHECK_ERRORS
		glEnableVertexAttribArray(SH_VERTEX);
		glVertexAttribPointer (SH_VERTEX, 3, GL_FLOAT, GL_FALSE,sizeof(GL_FLOAT)*3,0);
		GL_CHECK_ERRORS
		glEnableVertexAttribArray(SH_TEXTURECOORD);
		glBindBuffer (GL_ARRAY_BUFFER, vboTexCoordIDs[3]);
		glBufferData (GL_ARRAY_BUFFER, sizeof(tcSkyBoxBottom), &tcSkyBoxBottom[0], GL_STATIC_DRAW);
		glVertexAttribPointer (SH_TEXTURECOORD, 2, GL_FLOAT, GL_FALSE,sizeof(GLfloat)*2,0);
		GL_CHECK_ERRORS
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboIndicesIDs[3]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(iSkyBoxBottom), &iSkyBoxBottom[0], GL_STATIC_DRAW);
		GL_CHECK_ERRORS;

	glBindVertexArray(vaoIDs[4]);
		glBindBuffer (GL_ARRAY_BUFFER, vboVerticesIDs[4]);
		glBufferData (GL_ARRAY_BUFFER, sizeof(vSkyBoxRight), &vSkyBoxRight[0], GL_STATIC_DRAW);
		GL_CHECK_ERRORS
		glEnableVertexAttribArray(SH_VERTEX);
		glVertexAttribPointer (SH_VERTEX, 3, GL_FLOAT, GL_FALSE,sizeof(GL_FLOAT)*3,0);
		GL_CHECK_ERRORS
		glEnableVertexAttribArray(SH_TEXTURECOORD);
		glBindBuffer (GL_ARRAY_BUFFER, vboTexCoordIDs[4]);
		glBufferData (GL_ARRAY_BUFFER, sizeof(tcSkyBoxRight), &tcSkyBoxRight[0], GL_STATIC_DRAW);
		glVertexAttribPointer (SH_TEXTURECOORD, 2, GL_FLOAT, GL_FALSE,sizeof(GLfloat)*2,0);
		GL_CHECK_ERRORS
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboIndicesIDs[4]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(iSkyBoxRight), &iSkyBoxRight[0], GL_STATIC_DRAW);
		GL_CHECK_ERRORS;

	glBindVertexArray(vaoIDs[5]);
		glBindBuffer (GL_ARRAY_BUFFER, vboVerticesIDs[5]);
		glBufferData (GL_ARRAY_BUFFER, sizeof(vSkyBoxLeft), &vSkyBoxLeft[0], GL_STATIC_DRAW);
		GL_CHECK_ERRORS
		glEnableVertexAttribArray(SH_VERTEX);
		glVertexAttribPointer (SH_VERTEX, 3, GL_FLOAT, GL_FALSE,sizeof(GL_FLOAT)*3,0);
		GL_CHECK_ERRORS
		glEnableVertexAttribArray(SH_TEXTURECOORD);
		glBindBuffer (GL_ARRAY_BUFFER, vboTexCoordIDs[5]);
		glBufferData (GL_ARRAY_BUFFER, sizeof(tcSkyBoxLeft), &tcSkyBoxLeft[0], GL_STATIC_DRAW);
		glVertexAttribPointer (SH_TEXTURECOORD, 2, GL_FLOAT, GL_FALSE,sizeof(GLfloat)*2,0);
		GL_CHECK_ERRORS
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboIndicesIDs[5]);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(iSkyBoxLeft), &iSkyBoxLeft[0], GL_STATIC_DRAW);
		GL_CHECK_ERRORS;
	glBindVertexArray(0);
}

Skybox::Skybox() {
	textureDown = new Texture();
	textureUp = new Texture();
	textureNorth = new Texture();
	textureSouth = new Texture();
	textureWest = new Texture();
	textureEast = new Texture();

	this->InitVAO();
}

Skybox::~Skybox() {
	delete textureDown;
	delete textureUp;
	delete textureNorth;
	delete textureSouth;
	delete textureWest;
	delete textureEast;
}

void Skybox::draw()
{
	shader->bind();
	glBindVertexArray(vaoIDs[0]);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureNorth->getTextureID());
	glUniform1i(shader->getUniformLocation("s"),0);
	glDrawElements(GL_TRIANGLES,sizeof(iSkyBoxFront),GL_UNSIGNED_INT,0);

	glBindVertexArray(vaoIDs[1]);
	glBindTexture(GL_TEXTURE_2D, textureSouth->getTextureID());
	glUniform1i(shader->getUniformLocation("s"),0);
	glDrawElements(GL_TRIANGLES,sizeof(iSkyBoxBack),GL_UNSIGNED_INT,0);

	glBindVertexArray(vaoIDs[2]);
	glBindTexture(GL_TEXTURE_2D, textureUp->getTextureID());
	glUniform1i(shader->getUniformLocation("s"),0);
	glDrawElements(GL_TRIANGLES,sizeof(iSkyBoxTop),GL_UNSIGNED_INT,0);


	glBindVertexArray(vaoIDs[3]);
	glBindTexture(GL_TEXTURE_2D, textureDown->getTextureID());
	glUniform1i(shader->getUniformLocation("s"),0);
	glDrawElements(GL_TRIANGLES,sizeof(iSkyBoxBottom),GL_UNSIGNED_INT,0);


	glBindVertexArray(vaoIDs[4]);
	glBindTexture(GL_TEXTURE_2D, textureEast->getTextureID());
	glUniform1i(shader->getUniformLocation("s"),0);
	glDrawElements(GL_TRIANGLES,sizeof(iSkyBoxRight),GL_UNSIGNED_INT,0);

	glBindVertexArray(vaoIDs[5]);
	glBindTexture(GL_TEXTURE_2D, textureWest->getTextureID());
	glUniform1i(shader->getUniformLocation("s"),0);
	glDrawElements(GL_TRIANGLES,sizeof(iSkyBoxLeft),GL_UNSIGNED_INT,0);
}

void Skybox::loadTextures(std::string down, std::string up, std::string north, std::string south, std::string west, std::string east)
{
	tSkyBox[0] = textureDown->loadTexture(down);
	tSkyBox[1] = textureUp->loadTexture(up);
	tSkyBox[2] = textureNorth->loadTexture(north);
	tSkyBox[3] = textureSouth->loadTexture(south);
	tSkyBox[4] = textureWest->loadTexture(west);
	tSkyBox[5] = textureEast->loadTexture(east);
}

void Skybox::setShader(Shader* shader)
{
	this->shader = shader;
}

TiXmlElement* Skybox::getDrawableAsXmlElement() {
	TiXmlElement* element = new TiXmlElement("Skybox");
	// add texures as xml attributes
	return element;
}

