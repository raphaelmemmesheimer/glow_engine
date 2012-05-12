/*
 * Mesh.cpp
 *
 *  Created on: Mar 24, 2011
 *      Author: raphael
 */

#include "Mesh.h"
#include <stdio.h>
#include <glm/glm.hpp>
Mesh::Mesh() {

}

Mesh::Mesh(const char* filename) {
}

Mesh::~Mesh() {
}

std::string Mesh::getTextureFileName() const
{
    return textureFileName;
}

void Mesh::setTextureFileName(std::string textueFileName)
{
    this->textureFileName = textueFileName;
}

std::string Mesh::getFilename() {
	return filename;
}

TiXmlElement* Mesh::getDrawableAsXmlElement() {
	TiXmlElement* element = new TiXmlElement("Mesh");
	//element->SetAttribute("Type", "OBJ");
	element->SetAttribute("Filename", filename.c_str());
	return element;
}
