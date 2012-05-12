/*
 * TextureManager.h
 *
 *  Created on: Dec 22, 2011
 *      Author: raphael
 */

#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_

#include "Texture.h"
#include <vector>
#include <string>
#include <stdio.h>
#include "common.h"

class TextureManager {
	std::vector<Texture*> textures;
public:
	TextureManager();
	TextureManager(std::string dirName);
	virtual ~TextureManager();

	void initFromDir(std::string dirName);

	std::vector<Texture*> getTextures() const;
	void setTextures(std::vector<Texture*> textures);
	void addTexture(Texture* texture);
	void deleteTexture(int index);
	Texture* getTexture(int index);

	Texture* operator[](std::string textureName);
	Texture* operator[](int index);

	void print();
};

#endif /* TEXTUREMANAGER_H_ */
