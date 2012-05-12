/*
 * ShaderManager.cpp
 *
 *  Created on: Aug 27, 2011
 *      Author: raphael
 */

#include "ShaderManager.h"

ShaderManager::ShaderManager() {

}

std::vector<Shader*> ShaderManager::getShaders() const
{
    return shaders;
}

void ShaderManager::setShaders(std::vector<Shader*> shaders)
{
    this->shaders = shaders;
}

ShaderManager::~ShaderManager() {
	// TODO Auto-generated destructor stub
}

void ShaderManager::addShader(Shader *shader)
{
	shaders.push_back(shader);
}



void ShaderManager::deleteShader(int index)
{
	shaders.erase(shaders.begin()+index);
}

Shader *ShaderManager::getShader(int index)
{
	return shaders[index];
}

Shader* ShaderManager::operator [](std::string shaderName)
{
	for (int i = 0; i < shaders.size(); ++i) {
		if (shaderName == shaders[i]->getName())
			return shaders[i];
	}
	printf("shader %s can not be found\n",shaderName.c_str());
	return 0L;
}

Shader* ShaderManager::operator [](int index)
{
	for (int i = 0; i < shaders.size(); ++i) {
		printf("shader[%d] = %s",i,shaders[i]->getName().c_str());
	}
	return shaders[index];
}

