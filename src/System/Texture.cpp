/*
 * Texture.cpp
 *
 *  Created on: Jan 17, 2011
 *      Author: raphael
 */

#include "Texture.h"
#include "stb_image.c"
#include "GL3/gl3w.h"

#include "../System/Messages.h"

Texture::Texture() {
	this->width = 0;
	this->height = 0;
	this->components = 0;
	this->flipY = true;
	//this->filename = "";
}

Texture::Texture(std::string filename)
{
	this->name = filename;
	this->filename = filename;
	this->flipY = true;
	textureID = loadTexture(filename);
}


std::string Texture::getFilename() const
{
    return this->filename;
}

int Texture::getHeight() const
{
    return height;
}

int Texture::getWidth() const
{
    return width;
}

void Texture::setFilename(std::string filename)
{
    this->filename = filename;
}

void Texture::setHeight(int height)
{
    this->height = height;
}

void Texture::enableTexturing()
{
	glEnable(GL_TEXTURE_2D);
}

bool Texture::getFlipY() const
{
    return flipY;
}

unsigned int Texture::getTextureID() const
{
    return textureID;
}

std::string Texture::getName() const
{
    return name;
}

void Texture::setName(std::string name)
{
    this->name = name;
}

void Texture::setTextureID(unsigned int textureID)
{
    this->textureID = textureID;
}

void Texture::setFlipY(bool flipY)
{
    this->flipY = flipY;
}

unsigned int Texture::loadTexture(std::string filename) //code mostly adapted from rasums(loonies) http://visualizethis.tumblr.com/post/2756241415/code-snippet-for-loading-textures
{
	unsigned int id=0;
	//glPushAttrib(GL_TEXTURE_2D);
	//glEnable(GL_TEXTURE_2D);

	//msg(ModuleName,"LOAD TEXTURE : %s \n",filename);


	unsigned char * data = stbi_load(filename.c_str(), &this->width, &this->height, &this->components, 4);
	if (data)
	{
		if( this->flipY )
		{
			int i, j;
			for( j = 0; j*2 < height; ++j )
			{
				int index1 = j * width * 4;
				int index2 = (height - 1 - j) * width * 4;
				for( i = width * 4; i > 0; --i )
				{
					unsigned char temp = data[index1];
					data[index1] = data[index2];
					data[index2] = temp;
					++index1;
					++index2;
				}
			}
		}
		glGenTextures(1, &id);
		this->textureID = id;
		glBindTexture(GL_TEXTURE_2D, id);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		if (glGetError() != GL_NO_ERROR) {
			printf("GLERROR");
		}
		glBindTexture(GL_TEXTURE_2D, 0);

		//Log::print(lmInfo,)
		printf("[TEXTURE LOADER] TEXTURE LOADED : %s Size (w,h): %d %d ID %d \n",filename.c_str(),width,height,id);

	}
	else
	{
		printf("[TEXTURE LOADER] ERROR : %s \n",filename.c_str());
	}
	stbi_image_free(data);
//	glDisable(GL_TEXTURE_2D);
//	glPopAttrib();
	return id;
}

int Texture::getComponents() const
{
    return components;
}

void Texture::bindTexture()
{
	glBindTexture(GL_TEXTURE_2D,textureID);
}

void Texture::setComponents(int components)
{
    this->components = components;
}

void Texture::setWidth(int width)
{
    this->width = width;
}

Texture::~Texture() {
	glDeleteTextures(GL_TEXTURE_2D, &textureID);
}
