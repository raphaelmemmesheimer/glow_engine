/*
 * Shader.h
 *
 *  Created on: Feb 26, 2011
 *      Author: raphael
 */

#ifndef SHADER_H_
#define SHADER_H_

#include <GL3/gl3w.h>

#include<iostream>
#include<fstream>
#include<cstring>
#include <stdio.h>

#include <stdlib.h>
#include "common.h"

using namespace std;

class Shader {

private:
	void createShaderAndProgram();
	std::string vsText;
	std::string fsText;
	std::string gsText;
	std::string tcsText;
	std::string tesText;

	std::string compileMessage;

	std::string name;
	void validateProgram(GLuint program);
	void validateShader(GLuint shader, const char* file);

public:
	GLuint id;    // Program
	GLuint fsid;  // Fragment Shader
	GLuint vsid;  // Vertex Shader
	GLuint gsid;  // Geometry Shader
	GLuint tcsid; // Tessellation Control Shader
	GLuint tesid; // Tessellation Evaluate Shader

	char linkMessage[512];

    std::string getCompileMessage();
    void setCompileMessage(std::string compileMessage);
    std::string getName() const;
    void setName(std::string name);

	std::string getFsText();
	std::string getVsText();
	std::string getGsText();
	std::string getTcsText();
	std::string getTesText();
    void setFsText(std::string fsText);
    void setVsText(std::string vsText);
    void setGsText(std::string gsText);
    void setTcsText(std::string tcsText);
    void setTesText(std::string tesText);

	Shader();
	Shader(std::string name, std::string filenameVS, std::string filenameFS, std::string filenameGS = "", std::string filenameTCS = "", std::string filenameTES = "");
	virtual ~Shader();
	//GLuint getId();
	//void init();
	void load(std::string filenameVS, std::string filenameFS, std::string filenameGS = "", std::string filenameTCS = "", std::string filenameTES = "");
	void setShaderSource(std::string fsString, std::string vsString, std::string gsString = "", std::string tcsString = "", std::string tesString = "");
	void compile();
	void attach();
	void link();
	void compileAttachLink();
	void bind();
	void unbind();

	GLuint getUniformLocation(const char * uniformName);
	GLuint getAttributeLocation(const char * attributeName);
	GLuint operator[](const char * uniformName);
	GLuint operator()(const char * attributeName);

	void setUniformValue(const char* uniformName, int value);
	void setUniformValue(const char* uniformName, float value);
	void setUniformValue(const char* uniformName, double value);



};

#endif /* SHADER_H_ */
