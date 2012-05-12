/*
 * ObjModel.h
 *
 *  Created on: Mar 1, 2011
 *      Author: raphael
 */

#ifndef OBJMODEL_H_
#define OBJMODEL_H_

#include "Mesh.h"

using namespace std;

class ObjModel :public Mesh{
public:
	ObjModel();
	~ObjModel();
	void loadFile(std::string filename);
	TiXmlElement* getDrawableAsXmlElement();

};

#endif /* OBJMODEL_H_ */
