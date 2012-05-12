/*
 * ObjModel.cpp
 *
 *  Created on: Mar 1, 2011
 *      Author: raphael
 *
 *  Hard cutted  wavefront *.obj file loader into vao
 *
 *  should be able to load:
 *  *vertices (v)
 *  *vertex normals (vn)
 *	*vertex texture coordinates (vt)
 *  *faces (f)
 *  
 *  changes:
 *  08.05.2011 - fixed error in parsing triangulated obj files
 *
 */

#include "ObjModel.h"
#include "StrUtils.h"
#include <stdio.h>

using namespace std;

ObjModel::ObjModel() {
	// TODO Auto-generated constructor stub
	this->vertexCount = 0;
	this->faceCount = 0;
}

ObjModel::~ObjModel() {
	// TODO Auto-generated destructor stub
}

void ObjModel::loadFile(std::string filename) {

	this->vertices.clear();
	this->faces.clear();
	this->normals.clear();
	this->vertexCount = 0;
	this->faceCount = 0;
	this->filename = filename;
	FILE* fp;

	if((fp=fopen(filename.c_str(), "r")) == NULL) {
	    printf("Cannot open file.\n");
	    //exit(1);
	}

	char line[128];

	while (fgets(line,sizeof(line),fp) ) //&& cnt <= 10
	{
    	//printf("%s\n",line);
    	float x,y,z;
    	switch(line[0]){
    		case '#':
    		{
    			continue;
    		}
			case 'v':
			{
				switch(line[1]){
					case ' ': //vertex
					{
						sscanf(line,"v %f %f %f",&x,&y,&z);
						glm::vec3 vertex;
						vertex.x = x;
						vertex.y = y;
						vertex.z = z;
						this->vertices.push_back(vertex);
						this->vertexCount++;
						break;
					}
					case 'n':
					{
						sscanf(line,"vn %f %f %f",&x,&y,&z);
						glm::vec3 normal;
						normal.x = x;
						normal.y = y;
						normal.z = z;
						this->normals.push_back(normal);
						//this->normalCount++;
						break;
					}
					case 't':
					{
						sscanf(line,"vt %f %f",&x,&y);
						glm::vec2 tc;
						tc.x = x;
						tc.y = y;
						this->textureCoordinates.push_back(tc);
						//this->textureCoordinates.push_back(y);
    					break;
					}
				}
				break;
			}
			case 'f':
			{
				//TODO: add faces
				int f1 = 0;
				int f2 = 0;
				int f3 = 0;
		        int f4 = 0;
				int n1 = 0;
				int n2 = 0;
				int n3 = 0;
				int n4 = 0;

				//printf("cnt in lines spaces %d | / %d \n",countCharsInString(' ',line),countCharsInString('/',line));
				//printf("%d\n",);

				//TODO: is triangle or quad face
				if ((countCharsInString('/',line) == 0) && (countCharsInString(' ',line) == 3)) { // v index triangle face
					sscanf(line,"%*c %d %d %d ",&f1,&f2,&f3);
					glm::ivec3 face;
					face[0] = f1-1;
					face[1] = f2-1;
					face[2] = f3-1;
					faces.push_back(face);
					this->faceCount++;


				}

				if ((countCharsInString('/',line) == 0) && (countCharsInString(' ',line) == 4)) { // v index quad face
					sscanf(line,"%*c %d %d %d %d",&f1,&f2,&f3,&f4);

					glm::ivec3 face;
					face[0] = f1-1;
					face[1] = f2-1;
					face[2] = f3-1;
					faces.push_back(face);
					this->faceCount++;

					face[0] = f1-1;
					face[1] = f3-1;
					face[2] = f4-1;
					faces.push_back(face);
					this->faceCount++;
				}

				if ((countCharsInString('/',line) == 6)) { // vn index triangle face
					sscanf(line,"%*c %d//%d %d//%d %d//%d",&f1,&n1,&f2,&n2,&f3,&n3);

					glm::ivec3 face;
					face[0] = f1-1;
					face[1] = f2-1;
					face[2] = f3-1;
					//printf("%d %d %d | %d %d %d  \n",face[0],face[1],face[2],n1,n2,n3);
					faces.push_back(face);
					this->faceCount++;
					continue;
				}

//				if ((countCharsInString('/',line) == 6)) { // vn index triangle face // for sponca
//					sscanf(line,"%*c %d/%d/%d %d/%d/%d %d/%d/%d",&f1,&n1,&n1,&f2,&n2,&n2,&f3,&n3,&n3);
//
//					glm::ivec3 face;
//					face[0] = f1-1;
//					face[1] = f2-1;
//					face[2] = f3-1;
//					//printf("%d %d %d | %d %d %d  \n",face[0],face[1],face[2],n1,n2,n3);
//					faces.push_back(face);
//					this->faceCount++;
//					continue;
//				}
				if ((countCharsInString('/',line) == 3)) { // vn index triangle face
					sscanf(line,"%*c %d/%d %d/%d %d/%d",&f1,&n1,&f2,&n2,&f3,&n3);

					glm::ivec3 face;
					face[0] = f1-1;
					face[1] = f2-1;
					face[2] = f3-1;
					//printf("%d %d %d | %d %d %d  \n",face[0],face[1],face[2],n1,n2,n3);
					faces.push_back(face);
					this->faceCount++;
					continue;
				}

				if ((countCharsInString('/',line) == 8) && (countCharsInString(' ',line) == 4)) { // vn index quad face
					sscanf(line,"%*c %d//%d %d//%d %d//%d %d//%d",&f1,&n1,&f2,&n2,&f3,&n3,&f4,&n4);
                    //convert to 2 triangle faces

					glm::ivec3 face;
					face[0] = f1-1;
					face[1] = f2-1;
					face[2] = f3-1;
					faces.push_back(face);
					this->faceCount++;

					face[0] = f1-1;
					face[1] = f3-1;
					face[2] = f4-1;
					faces.push_back(face);
					this->faceCount++;

				}
				break;
			}

    	}
	}
	fclose(fp);
	printf("obj file loaded %d %d\n",this->faceCount,this->vertexCount);

	generateAndBindBuffers();
}

TiXmlElement* ObjModel::getDrawableAsXmlElement() {
	TiXmlElement* element = new TiXmlElement("ObjModel");
	element->SetAttribute("Type", "OBJ");
	element->SetAttribute("Filename", filename.c_str());
	return element;
}
