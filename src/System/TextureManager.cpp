/*
 * TextureManager.cpp
 *
 *  Created on: Dec 22, 2011
 *      Author: raphael
 */

#include "TextureManager.h"

TextureManager::TextureManager() {
	// TODO Auto-generated constructor stub

}

TextureManager::~TextureManager() {
	// TODO Auto-generated destructor stub
}

std::vector<Texture*> TextureManager::getTextures() const
{
	return textures;
}


void TextureManager::setTextures(std::vector<Texture*> textures)
{
	this->textures = textures;
}

void TextureManager::addTexture(Texture *texture)
{
	textures.push_back(texture);
}

void TextureManager::deleteTexture(int index)
{
	textures.erase(textures.begin()+index);
}


Texture *TextureManager::getTexture(int index)
{
	return textures[index];
}


Texture *TextureManager::operator [](std::string textureName)
{
	for (unsigned int i = 0; i < textures.size(); ++i) {
		if (textureName == textures[i]->getName())
			return textures[i];
	}
	printf("texture %s can not be found\n",textureName.c_str());
	return 0L;
}


TextureManager::TextureManager(std::string dirName)
{
	initFromDir(dirName);
}


void TextureManager::initFromDir(std::string dirName)
{
	std::vector<std::string> files = getFilesInDir(dirName);
	for (unsigned int i = 0; i < files.size(); i++) {
		//filter
		if (files[i].at(0) == '.') // no dirs or hidden files
			continue;
		addTexture(new Texture(dirName+files[i]));
	}
}


Texture *TextureManager::operator [](int index)
{
	for (unsigned int i = 0; i < textures.size(); i++) {
		printf("textures[%d] = %s", i, textures[i]->getName().c_str());
	}
	return textures[index];
}


void TextureManager::print(){
	for(unsigned int i = 0; i < textures.size(); i++) {
		printf("%s \n ", textures[i]->getName().c_str());
	}
}


