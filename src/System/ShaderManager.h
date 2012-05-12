/*
 * ShaderManager.h
 *
 *  Created on: Aug 27, 2011
 *      Author: raphael
 */

#ifndef SHADERMANAGER_H_
#define SHADERMANAGER_H_

#include <vector>
#include "Shader.h"
#include "stdio.h"
#include "../3rdParty/tinyxml/tinyxml.h"

#ifdef USEWX
class GlowEditorfShaderEditor;
#endif
class ShaderManager {
private:
	std::vector<Shader*> shaders;
	typedef void(*AddShaderFunc)(Shader* shader);
public:
	ShaderManager();
	virtual ~ShaderManager();
    std::vector<Shader*> getShaders() const;
    void setShaders(std::vector<Shader*> shaders);
    void addShader(Shader* shader);
    void deleteShader(int index);
    Shader* getShader(int index);

    Shader* operator[](std::string shaderName);
    Shader* operator[](int index);


    //AddShaderFunc OnAddShader;
};

#endif /* SHADERMANAGER_H_ */
