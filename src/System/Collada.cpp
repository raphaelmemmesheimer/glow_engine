/*
 * Collada.cpp
 *
 *  Created on: May 12, 2011
 *      Author: raphael
 */

#include "Collada.h"

Collada::Collada() {
	// TODO Auto-generated constructor stub

}

Collada::~Collada() {
	// TODO Auto-generated destructor stub
}

void parseFile(TiXmlNode* node){


	printf("%s \n ",node->Value());

}

char *Collada::getName() const
{
    return name;
}

void Collada::setName(char *name)
{
    this->name = name;
}

void Collada::loadFile(const char *filename)
{
	vertices.clear();
	normals.clear();
//	/indices.clear();
	TiXmlDocument file(filename);
	if (file.LoadFile()) {
		printf("[Collada Loader] LoadFile Success \n");
		TiXmlElement *root = file.RootElement();
		char* xmlvalue;
		// vertices
		this->vertexCount = atof(root->FirstChildElement("library_geometries")->
				 FirstChildElement("geometry")->
				  FirstChildElement("mesh")->
				   FirstChildElement("source")->
				    FirstChildElement("float_array")->Attribute("count"));

		char* verticesList = const_cast<char*>(root->FirstChildElement("library_geometries")->
						 FirstChildElement("geometry")->
						  FirstChildElement("mesh")->
						   FirstChildElement("source")->
						    FirstChildElement("float_array")->
			    			 FirstChild()->Value());


		printf("vertices: %s \n",verticesList);

		xmlvalue = strtok(verticesList," ");

		glm::vec3 vertex;
		vertex.x = atof(xmlvalue); //get frist x
		unsigned int cnt = 1; // not that elegant :)
		while ((xmlvalue != NULL)) {
			xmlvalue = strtok (NULL, " ");
			switch (cnt % 3) { //parse xmlvalue 0 = x, 1 = y, 2 = z
				case 0:
					vertices.push_back(vertex);
					printf("[Collada Loader] vertex %f %f %f \n",vertex.x,vertex.y,vertex.z);
					if (xmlvalue != NULL)
					  vertex.x = atof(xmlvalue);
					break;
				case 1:
					vertex.y = atof(xmlvalue);
				    break;
				case 2:
					vertex.z = atof(xmlvalue);
					break;
			}
			cnt++;

		}

		//normals
		char* normalList = const_cast<char*>(root->FirstChildElement("library_geometries")->
				 FirstChildElement("geometry")->
				  FirstChildElement("mesh")->
				   FirstChildElement("source")->
					NextSibling()->
					 FirstChildElement("float_array")->
					  FirstChild()->Value());
		printf("normals: %s \n",normalList);
		xmlvalue = strtok(normalList," ");
		glm::vec3 normal;
		normal.x =
		cnt = 1;
		while ((xmlvalue != NULL)) {
			xmlvalue = strtok (NULL, " ");
			switch (cnt % 3) { //parse xmlvalue 0 = x, 1 = y, 2 = z
				case 0:
					normals.push_back(normal);
					printf("[Collada Loader] normal %f %f %f \n",normal.x,normal.y,normal.z);
					if (xmlvalue != NULL)
					  normal.x = atof(xmlvalue);
					break;
				case 1:
					normal.y = atof(xmlvalue);
				    break;
				case 2:
					normal.z = atof(xmlvalue);
					break;
			}
			cnt++;

		}

		//indices
		char* indicesList = const_cast<char*>(root->FirstChildElement("library_geometries")->
				 FirstChildElement("geometry")->
				  FirstChildElement("mesh")->
				   FirstChildElement("polylist")->
					FirstChildElement("p")->
					FirstChild()->Value());
		printf("indices: %s \n",indicesList);
		xmlvalue = strtok(indicesList," ");
		glm::ivec3 face;
		face[0] = atoi(xmlvalue);
		cnt = 1;
		while ((xmlvalue != NULL)) {
			xmlvalue = strtok (NULL, " ");
			switch (cnt % 3) { //parse xmlvalue 0 = x, 1 = y, 2 = z
				case 0:
					normals.push_back(normal);
					printf("[Collada Loader] face %d %d %d \n",face[0],face[1],face[2]);
					if (xmlvalue != NULL)
					  face[0] = atoi(xmlvalue);
					break;
				case 1:
					face[1] = atoi(xmlvalue);
				    break;
				case 2:
					face[2] = atoi(xmlvalue);
					break;
			}
			cnt++;

		}


	} else {
		printf("[Collada Loader] LoadFile Error \n");
	}

}


