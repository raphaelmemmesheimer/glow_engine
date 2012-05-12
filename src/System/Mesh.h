/*
 * Mesh.h
 *
 *  Created on: Mar 24, 2011
 *      Author: raphael
 */

#ifndef MESH_H_
#define MESH_H_
#include <GL3/gl3.h>
#include <GL3/gl3w.h>
#include <glm/glm.hpp>
#include <vector>
#include "constants.h"
#include <string>
#include "Drawable.h"

using namespace std;

class Mesh : public Drawable {
protected:
	Mesh();
	Mesh(const char* filename);
	virtual ~Mesh();
	std::string textureFileName;
	std::string filename;
public:
    virtual void loadFile(std::string filename) = 0;
    std::string getTextureFileName() const;
    void setTextureFileName(std::string textueFileName);
	std::string getFilename();
	TiXmlElement* getDrawableAsXmlElement();

};

#endif /* MESH_H_ */
