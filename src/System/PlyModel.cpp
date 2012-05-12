/*
 * PlyModel.cpp
 *
 *  Created on: Apr 13, 2011
 *      Author: raphael
 */

#include "PlyModel.h"

PlyModel::PlyModel() {
	// TODO Auto-generated constructor stub

}

PlyModel::~PlyModel() {
	// TODO Auto-generated destructor stub
}

void PlyModel::loadFile(const char * filename) {

	this->vertices.clear();
	this->faces.clear();
	this->normals.clear();
	this->vertexCount = 0;
	this->faceCount = 0;
	FILE* fp;

	if((fp=fopen(filename, "r")) == NULL) {
	    printf("Cannot open file.\n");
	    //exit(1);
	}

	char line[128];
	bool header = true;

	float x,y,z = 0.0;

	int headerCnt = 0;
	int contentCounter = 0;
	while (fgets(line,sizeof(line),fp) ) //&& cnt <= 10
	{

//		if (line == "ply") // ignore first line
//			continue;
    	//printf("%s\n",line);
		char* name;
		char* type;
		char* value;

		if (header) { //parse header
		    if (headerCnt++ == 0)
		    	continue;


			sscanf(line,"%as %as %as",&name,&type,&value);
			//printf("[PLY_Header] %s %s %s\n",name,type,value);
			if (!strcmp(name,"element")) {
			  if (!strcmp(type,"vertex"))
				  vertexCount = atoi(value);
			  if (!strcmp(type,"face"))
				  faceCount = atoi(value);
			}
			if (!strcmp(name,"end_header")){
				header = false;
			}

		} else { // parse context
			if (contentCounter <= vertexCount) { //parse vertices
				sscanf(line,"%f %f %f",&x,&y,&z);
				//printf("v %d %f %f %f \n",contentCounter, x,y,z);
				this->vertices.push_back(glm::vec3(x,y,z));
			} else { //parse faces
				glm::ivec3 face;
				int indexCount = 0;
				sscanf(line,"%d %d %d %d",&indexCount,&face[0],&face[1],&face[2]);
				//printf("f %d %d %d \n",face[0],face[1],face[2]);
				this->faces.push_back(face);
			}
			contentCounter++;
		}


	}
	fclose(fp);
	//printf("ply file loaded (%d %d) || (%d %d)\n",this->faceCount,this->faces.size(),this->vertexCount,this->vertices.size());

	generateAndBindBuffers();
}
