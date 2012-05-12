/*
 * CTMModel.cpp
 *
 *  Created on: Mar 5, 2011
 *      Author: raphael
 */

#include "CTMModel.h"

CTMModel::CTMModel() {
	vertexCount = 0;
	faceCount = 0;
}

CTMModel::~CTMModel() {
	// TODO Auto-generated destructor stub
}

#include <stdio.h>
void CTMModel::loadFile(std::string filename)
{
	this->filename = filename;
	vertices.clear();
	//iVertices.clear();
	faces.clear();
	normals.clear();
	colors.clear();
	indices.clear();
	CTMcontext context;

	const CTMfloat * vertices;
	const CTMuint* indices;
	const CTMfloat* normals;
	const CTMfloat* colors;
	// Create a new context
	context = ctmNewContext(CTM_IMPORT);

	// Load the OpenCTM file
	ctmLoad(context, filename.c_str());
	if(ctmGetError(context) == CTM_NONE)
	{
	 // Access the mesh data
		this->vertexCount = ctmGetInteger(context, CTM_VERTEX_COUNT);
		this->faceCount = ctmGetInteger(context, CTM_TRIANGLE_COUNT);
		int attribCount = ctmGetInteger(context,CTM_ATTRIB_MAP_COUNT);
		  // Extract texture coordinates


		normals = ctmGetFloatArray(context, CTM_NORMALS);
		vertices = ctmGetFloatArray(context,CTM_VERTICES);
		indices = ctmGetIntegerArray(context, CTM_INDICES);
		CTMenum colorAttrib = ctmGetNamedAttribMap(context,"Color");
		colors = ctmGetFloatArray(context,colorAttrib);




	    unsigned int  i = 0;
	    glm::vec3 vertex;
		for (i = 0; i < vertexCount *3 ; i+=3) {
			vertex.x = vertices[i];
			vertex.y = vertices[i+1];
			vertex.z = vertices[i+2];
			this->vertices.push_back(vertex);
		}

		if(ctmGetInteger(context,CTM_UV_MAP_COUNT) > 0)
		{
		    textureCoordinates.clear();
		    const CTMfloat * texCoords = ctmGetFloatArray(context,CTM_UV_MAP_1);
		    for(CTMuint i = 0; i < vertexCount; ++ i)
		    {
		    	glm::vec2 texCoord;
		    	texCoord.x = texCoords[i * 2];
		    	texCoord.x = texCoords[i * 2 + 1];
		    	textureCoordinates.push_back(texCoord);
		    }
		    const char * str = ctmGetUVMapString(context,CTM_UV_MAP_1, CTM_FILE_NAME);
		    if(str)
		      setTextureFileName(str);
		    else
		      setTextureFileName(string(""));
		}

		if (colorAttrib != CTM_NONE){
			glm::vec4 color;
			for (i = 0; i < vertexCount *4 ; i+=4) {
				color.r = colors[i];
				color.g = colors[i+1];
				color.b = colors[i+2];
				color.w = colors[i+3];
				this->colors.push_back(color);
			}
		}

		glm::ivec3 face;
		for (i = 0; i < faceCount*3; i+=3) {
			face[0] = indices[i];
			face[1] = indices[i+1];
			face[2] = indices[i+2];
			this->faces.push_back(face);
		}

		for (i = 0; i < faceCount*3; i++) {
			this->indices.push_back(indices[i]);
		}

		if (normals)
		for (i = 0; i < faceCount*sizeof(CTMfloat); i+=3) {
			glm::vec3 normal;
			normal.x = normals[i];
			normal.y = normals[i+1];
			normal.z = normals[i+2];
			this->normals.push_back(normal);
		}
	}
	// Free the context
	ctmFreeContext(context);
	generateAndBindBuffers();
}
