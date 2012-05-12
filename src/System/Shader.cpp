/*
 * Shader.cpp
 *
 *  Created on: Feb 26, 2011
 *      Author: raphael
 */

using namespace std;

#include "Shader.h"

void Shader::validateShader(GLuint shader, const char* file = 0) {
    const unsigned int BUFFER_SIZE = 512;
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    GLsizei length = 0;

    glGetShaderInfoLog(shader, BUFFER_SIZE, &length, buffer);

    GLint shaderCompiled;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &shaderCompiled);

    if (length > 0){
		if (!shaderCompiled) {
			cerr << "[Shader] " << shader << " (" << (file?file:"") << ")"<< endl << "compile error: " << buffer<< endl;
		}
		else
		{
			cout << "[Shader] " << shader << " compile message: " << buffer<<endl;
		}
		compileMessage = buffer;
    }
    else {
    	compileMessage = buffer;
    }

}

void Shader::validateProgram(GLuint program) {
    const unsigned int BUFFER_SIZE = 512;
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    GLsizei length = 0;

    memset(buffer, 0, BUFFER_SIZE);
    glGetProgramInfoLog(program, BUFFER_SIZE, &length, buffer);
    GLint programLinked;
    glGetProgramiv(program,GL_LINK_STATUS,&programLinked);
    if (length > 0){
		if (!programLinked)
			cerr << "[Shader][Program] " << program << " link error: " << buffer << endl;
		else
			cout << "[Shader][Program] " << program << " link message: " << buffer << endl;
		//linkMessage = buffer;

		strcpy(linkMessage,buffer);
	}
    glValidateProgram(program);
    GLint status;
    glGetProgramiv(program, GL_VALIDATE_STATUS, &status);
    if (status == GL_FALSE)
        cerr << "Error validating shader " << program << endl;
}

void Shader::createShaderAndProgram()
{
	this->vsid = glCreateShader(GL_VERTEX_SHADER);
	this->fsid = glCreateShader(GL_FRAGMENT_SHADER);
	this->gsid = glCreateShader(GL_GEOMETRY_SHADER);
	this->tcsid = glCreateShader(GL_TESS_CONTROL_SHADER);
	this->tesid = glCreateShader(GL_TESS_EVALUATION_SHADER);
	this->id = glCreateProgram();
}

Shader::Shader() {
  createShaderAndProgram();
}

Shader::~Shader() {
	//Detach shaders
	glDetachShader(this->id, this->vsid);
    glDetachShader(this->id, this->fsid);
    glDetachShader(this->id, this->gsid);
    glDetachShader(this->id, this->tcsid);
    glDetachShader(this->id, this->tesid);
    //Delete shaders
    glDeleteShader(this->vsid);
    glDeleteShader(this->fsid);
    glDeleteShader(this->gsid);
    glDeleteShader(this->tcsid);
    glDeleteShader(this->tesid);
    //Delete program
    glDeleteProgram(this->id);
}

void Shader::setShaderSource(std::string fsString,std::string vsString, std::string gsString, std::string tcsString, std::string tesString)
{
	const char *vsText = vsString.c_str();
	const char *fsText = fsString.c_str();

	this->fsText = fsString;
	this->vsText = vsString;

	glShaderSource(this->vsid, 1, &vsText,NULL);
	glShaderSource(this->fsid, 1, &fsText,NULL);

	if (!gsString.empty()){ // if has geometry shader
		this->gsText = gsString;
		const char *gsText = gsString.c_str();
		glShaderSource(this->gsid, 1, &gsText, NULL);
	}

	if (!tcsString.empty()){ // if has tessellation control shader
		this->tcsText = tcsString;
		const char *tcsText = tcsString.c_str();
		glShaderSource(this->tcsid, 1, &tcsText, NULL);
	}

	if (!tcsString.empty()){ // if has tessellation evaluate shader
		this->tesText = tesString;
		const char *tesText = tesString.c_str();
		glShaderSource(this->tesid, 1, &tesText, NULL);
	}
}

void Shader::load(std::string filenameVS, std::string filenameFS, std::string filenameGS, std::string filenameTCS, std::string filenameTES)
{
	this->vsText = textFileRead(filenameVS.c_str());
	this->fsText = textFileRead(filenameFS.c_str());

	std::string vs = this->vsText;
	std::string fs = this->fsText;
	std::string gs = "";
	std::string tcs = "";
	std::string tes = "";
	if (!filenameGS.empty()) {
		this->gsText = textFileRead(filenameGS.c_str());
		gs = this->gsText;
	}
	if (!filenameTCS.empty()) {
		this->tcsText = textFileRead(filenameTCS.c_str());
		tcs = this->tcsText;
	}
	if (!filenameTES.empty()) {
		this->tesText = textFileRead(filenameTES.c_str());
		tes = this->tesText;
	}
	this->setShaderSource(fs, vs, gs, tcs, tes);

}

void Shader::compile()
{
	glCompileShader(this->vsid);
	validateShader(this->vsid,this->vsText.c_str());
	glCompileShader(this->fsid);
	validateShader(this->fsid,this->fsText.c_str());

	if (!this->gsText.empty()) {
		glCompileShader(this->gsid);
		validateShader(this->gsid,this->gsText.c_str());
	}

	if (!this->tcsText.empty()) {
		glCompileShader(this->tcsid);
		validateShader(this->tcsid,this->tcsText.c_str());
	}

	if (!this->tesText.empty()) {
		glCompileShader(this->tesid);
		validateShader(this->tesid,this->tesText.c_str());
	}


}

void Shader::attach()
{
	glAttachShader(this->id,this->vsid);
	glAttachShader(this->id,this->fsid);
	if (!this->gsText.empty()) {
		glAttachShader(this->id,this->gsid);
	}
	if (!this->tcsText.empty()) {
		glAttachShader(this->id,this->tcsid);
	}
	if (!this->tesText.empty()) {
		glAttachShader(this->id,this->tesid);
	}

}

void Shader::link()
{
	glLinkProgram(this->id);
	validateProgram(this->id);
}

std::string Shader::getName() const
{
    return name;
}

void Shader::setName(std::string name)
{
    this->name = name;
}

std::string Shader::getCompileMessage()
{
    return compileMessage;
}


void Shader::compileAttachLink(){
	this->compile();
	this->attach();
	this->link();
}

Shader::Shader(std::string name, std::string filenameVS, std::string filenameFS, std::string filenameGS, std::string filenameTCS, std::string filenameTES)
{
	this->setName(name);
	createShaderAndProgram();
	this->load(filenameVS, filenameFS, filenameGS, filenameTCS, filenameTES);
	this->compileAttachLink();

}

void Shader::bind()
{
	//printf("%d\n", this->getId());
	glUseProgram(this->id);
}

//GLuint Shader::getId()
//{
//	return this->id;
//}

void Shader::unbind()
{
	glUseProgram(0);
}

GLuint Shader::operator[](const char* uniformName)
{
	return glGetUniformLocation(this->id,uniformName);
}

GLuint Shader::getAttributeLocation(const char *attributeName)
{
	return glGetAttribLocation(this->id,attributeName);
}

GLuint Shader::getUniformLocation(const char *uniformName)
{
	return glGetUniformLocation(this->id,uniformName);
}

GLuint Shader::operator()(const char* attributeName)
{
	return glGetAttribLocation(this->id,attributeName);
}

void Shader::setUniformValue(const char* uniformName, int value)
{
	glUniform1i(getUniformLocation(uniformName),value);
}

void Shader::setUniformValue(const char* uniformName, float value)
{
	glUniform1f(getUniformLocation(uniformName),value);
}

std::string Shader::getFsText()
{
    return fsText;
}

std::string Shader::getVsText()
{
    return vsText;
}

void Shader::setFsText(std::string fsText)
{
    this->fsText = fsText;
    setShaderSource(fsText,this->vsText);
}

void Shader::setVsText(std::string vsText)
{
    this->vsText = vsText;
    setShaderSource(this->fsText,vsText);
}

std::string Shader::getGsText()
{
	return this->gsText;
}

void Shader::setGsText(std::string gsText)
{
	this->gsText = gsText;
	setShaderSource(this->fsText,this->vsText,gsText);
}

std::string Shader::getTcsText()
{
	return tcsText;
}

std::string Shader::getTesText()
{
	return tesText;
}

void Shader::setTcsText(std::string tcsText)
{
	this->tcsText = tcsText;
}

void Shader::setTesText(std::string tesText)
{
	this->tesText = tesText;
}

//void Shader::setShaderEditor(GlowEditorfShaderEditor *fShaderEditor)
//{
//    this->fShaderEditor = fShaderEditor;
//
////    fShaderEditor->rtVertex->SetValue(this->getVsText());
////    fShaderEditor->rtFragment->SetValue(this->getFsText());
////
////    fShaderEditor->mLog->SetValue(linkMessage);
//}

void Shader::setUniformValue(const char* uniformName, double value)
{
	glUniform1f(getUniformLocation(uniformName), value);
}
