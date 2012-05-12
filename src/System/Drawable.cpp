/*
 * Drawable.cpp
 *
 *  Created on: Dec 18, 2011
 *      Author: raphael
 */

#include "Drawable.h"

Drawable::Drawable() {
	// TODO Auto-generated constructor stub

}

Drawable::~Drawable() {
	// TODO Auto-generated destructor stub
}

void Drawable::draw(){
	glBindVertexArray(this->vaoID);
	glDrawElements(GL_TRIANGLES,this->faceCount*3,GL_UNSIGNED_INT,0); //vertexCount*3*2
	glBindVertexArray(0);
}

void Drawable::generateAndBindBuffers() {
	glGenVertexArrays(1,&vaoID);
	glBindVertexArray(vaoID);

    //printf("loading vertices Mesh.cpp\n");
	if (vertices.size()) { // create vertex buffer
		glGenBuffers(1,&vboID);
		glBindBuffer(GL_ARRAY_BUFFER,vboID);
		glBufferData(GL_ARRAY_BUFFER,vertices.size()*sizeof(GL_FLOAT) * 3 ,&vertices[0],GL_STATIC_DRAW);
		glEnableVertexAttribArray(SH_VERTEX);
		glVertexAttribPointer(SH_VERTEX,3,GL_FLOAT,GL_FALSE,0,0);
	}

	//printf("loading color Mesh.cpp\n");
	if (colors.size()) { // create color buffer
		glGenBuffers(1,&vboID);
		glBindBuffer(GL_ARRAY_BUFFER,vboID);
		glBufferData(GL_ARRAY_BUFFER,colors.size()*sizeof(GL_FLOAT)*4,&colors[0],GL_STATIC_DRAW);
		glEnableVertexAttribArray(SH_COLOR);
		glVertexAttribPointer(SH_COLOR,4,GL_FLOAT,GL_FALSE,0,0);
	}
	//printf("loading textureCoordinates Mesh.cpp\n");
	if (textureCoordinates.size()) { // create textureCoordinates buffer
		glGenBuffers(1,&vboID);
		glBindBuffer(GL_ARRAY_BUFFER,vboID);
		glBufferData(GL_ARRAY_BUFFER,textureCoordinates.size()*sizeof(GL_FLOAT)*2,&textureCoordinates[0],GL_STATIC_DRAW);
		glEnableVertexAttribArray(SH_TEXTURECOORD);
		glVertexAttribPointer(SH_TEXTURECOORD,2,GL_FLOAT,GL_FALSE,0,0);
	}
	//normals
	if (!normals.size() && autoCalcNormals) // when there are no normals and atoCalc in enabled then calc them
		calcNormals();

	//printf("loading normals Mesh.cpp\n");
	if (normals.size()) { //create normal buffer
		glGenBuffers(1,&vboID);
		glBindBuffer(GL_ARRAY_BUFFER,vboID);
		glBufferData(GL_ARRAY_BUFFER,normals.size()*sizeof(GL_FLOAT)*3,&normals[0],GL_STATIC_DRAW);
		glEnableVertexAttribArray(SH_NORMAL);
		glVertexAttribPointer(SH_NORMAL,3,GL_FLOAT,GL_FALSE,0,0);
	}

	//indices
	//printf("binding faces\n");
	if (faces.size()) {
		glGenBuffers(1,&vboID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,vboID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER,(faces.size())* sizeof(faces[0]),&faces[0],GL_STATIC_DRAW);
	}
	//printf("[Drawable] loaded faces %d/%d | vertices %d/%d \n",faces.size(), faceCount, vertices.size(),vertexCount);



	glEnableVertexAttribArray(0);
	glBindVertexArray(0);

}

void Drawable::setAutoCalcNormals(bool autoCalcNormals)
{
    this->autoCalcNormals = autoCalcNormals;
}


bool Drawable::getAutoCalcNormals() const
{
    return autoCalcNormals;
}

void Drawable::facesToIndices()
{
	for (unsigned int i = 0; i < faces.size(); ++i) {
		indices.push_back(faces[i].x);
		indices.push_back(faces[i].y);
		indices.push_back(faces[i].z);
	}
}


void Drawable::calcNormals() {
	// calc per vertex normal
	//printf("normals %d autocalc Mesh.cpp\n",normals.size());
	normals.clear();
	if (!normals.size()) { // no normals ... calc em
	  printf("calcNormals Drawable.cpp init\n");
	  normals.resize(vertices.size());
	  for (unsigned int j = 0; j < normals.size(); j++) {
		  glm::vec3 normal;
		  normal = glm::vec3(0.0,0.0,0.0);
		  normals[j] = normal;

	  }
	  //printf("indices.size = %d \n", indices.size());
	  if (indices.size() == 0) {
		  facesToIndices();
	  }
	  //printf("indices.size = %d \n", indices.size());
	  for (unsigned int i = 0; i <= indices.size(); i+=3){
		  glm::vec3 p1, p2, p3;
		  p1 = vertices[indices[i]];
		  p2 = vertices[indices[(i+1)%indices.size()]];
		  p3 = vertices[indices[(i+2)%indices.size()]];

		  glm::vec3 v1 = p3-p1;
		  glm::vec3 v2 = p2-p1;
		  glm::vec3 cp = glm::normalize(glm::cross(v1,v2));
		  normals[indices[i]] += cp; //[i] += cp;
		  normals[indices[(i+1)%indices.size()]] += cp;
		  normals[indices[(i+2)%indices.size()]] += cp;
	  }
//
//	  for (unsigned int i = 0; i <= faces.size(); i++){
//	  		  glm::vec3 p1, p2, p3;
//	  		  p1 = vertices[faces[i].x];
//	  		  p2 = vertices[faces[i].y];
//	  		  p3 = vertices[faces[i].z];
//
//	  		  glm::vec3 v1 = p3-p1;
//	  		  glm::vec3 v2 = p2-p1;
//	  		  glm::vec3 cp = glm::normalize(glm::cross(v1,v2));
//	  		  normals[faces[i].x] += cp; //[i] += cp;
//	  		  normals[faces[i].y] += cp;
//	  		  normals[faces[i].z] += cp;
//	  	  }
  }

}

TiXmlElement* Drawable::getDrawableAsXmlElement() {
	TiXmlElement* element = new TiXmlElement("Drawable");
	return element;
}
