/*
 * PlyModel.h
 *
 *  Created on: Apr 13, 2011
 *      Author: raphael
 */

#ifndef PLYMODEL_H_
#define PLYMODEL_H_

#include "Mesh.h"
#include <stdio.h>
#include <glm/glm.hpp>
#include <string.h>

class PlyModel: public Mesh {
public:
	PlyModel();
	virtual ~PlyModel();

	void loadFile(const char * filename);
};

#endif /* PLYMODEL_H_ */
