/*
 * CTMModel.h
 *
 *  Created on: Mar 5, 2011
 *      Author: raphael
 */

#ifndef CTMMODEL_H_
#define CTMMODEL_H_

#include "../3rdParty/OpenCTM/lib/openctm.h"
#include "Mesh.h"
using namespace std;

class CTMModel :public Mesh{
private:

public:
	CTMModel();
	virtual ~CTMModel();
	void loadFile(std::string filename);
};

#endif /* CTMMODEL_H_ */
