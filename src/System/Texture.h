/*
 * Texture.h
 *
 *  Created on: Jan 17, 2011
 *      Author: raphael
 *
 *      depends on http://nothings.org/stb_image.c
 *
 *      TODO: MipMaps
 *      TODO: Options (modulate decal, repeat, clamp) ...;
 *      TODO: Filter
 *
 *
 *      USAGE:
 *      	delaration:
 *      		Texture *texture;
 *
 *      	init:
 *				texture = new Texture();
 *				texture->loadTexture(<filename>);
 *
 *			alternative init:
 *				texture = new Texture(<filename>);
 *
 *			bind texture:
 *				text1->bindTexture();
 *
 *
 */

#ifndef Texture_H_
#define Texture_H_

#include <string>
#include "Log.h"

//const char * ModuleNameT = "Texture";

class Texture {
private:
	std::string name;
	std::string filename;
	int height;
	int width;
	int components;
	unsigned int textureID;
	bool flipY;
public:
	Texture();
	Texture(std::string filename);
	virtual ~Texture();
	std::string getFilename() const;
    int getHeight() const;
    int getWidth() const;
    void setFilename(std::string filename);
    void setHeight(int height);
    void setWidth(int width);
    int getComponents() const;
    void setComponents(int components);

    void bindTexture();
    void enableTexturing();
    unsigned int loadTexture(std::string filename);
    bool getFlipY() const;
    void setFlipY(bool flipY);
    unsigned int getTextureID() const;
    void setTextureID(unsigned int textureID);
    std::string getName() const;
    void setName(std::string name);

};

#endif /* Texture_H_ */
