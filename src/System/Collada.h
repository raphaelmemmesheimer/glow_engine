/*
 * Collada.h
 *
 *  Created on: May 12, 2011
 *      Author: raphael
 */

#ifndef COLLADA_H_
#define COLLADA_H_

#include <string>
#include "Mesh.h"
#include "../3rdParty/tinyxml/tinyxml.h"
#include "glm/glm.hpp"

class Collada :public Mesh{
private:
    char *name;
    //void parseFloatArray(char* values, &array);
public:
    Collada();
    virtual ~Collada();
    void loadFile(const char *filename);
    char *getName() const;
    void setName(char *name);
};

#endif /* COLLADA_H_ */
