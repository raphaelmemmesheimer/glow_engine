#include "AssimpModel.h"

AssimpModel::AssimpModel() {
	scene = NULL;
}

AssimpModel::~AssimpModel() {

}

vec3 AssimpModel::aiVec3ToVec3(aiVector3D vector) {
	vec3 result;
	result.x = vector.x;
	result.y = vector.y;
	result.z = vector.z;
	return result;
}

vec4 AssimpModel::aiCol4ToVec4(aiColor4D* color) {
	vec4 result;
	result.r = color->r ;
	result.g = color->g;
	result.b = color->b;
	result.a = color->a;
	return result;
}

void AssimpModel::loadFile(std::string filename) {

	this->filename =  filename;
	
	vertices.clear();
	//iVertices.clear();
	faces.clear();
	normals.clear();
	colors.clear();
	indices.clear();

	scene = aiImportFile(filename.c_str(), aiProcessPreset_TargetRealtime_Quality);
	
	// draw all meshes assigned to this node
	for (unsigned int n = 0; scene->mNumMeshes; ++n) {
		const struct aiMesh* mesh = scene->mMeshes[n];

		//apply_material(sc->mMaterials[mesh->mMaterialIndex]);

		//if(mesh->mNormals == NULL) {
			//glDisable(GL_LIGHTING);
		//} else {
			//glEnable(GL_LIGHTING);
		//}

		this->faceCount = mesh->mNumFaces;
		for (unsigned int t = 0; t < this->faceCount; ++t) {
			const struct aiFace* face = &mesh->mFaces[t];
			GLenum face_mode;

			//switch(face->mNumIndices) {
				//case 1: face_mode = GL_POINTS; break;:A
				//
				//case 2: face_mode = GL_LINES; break;
				//case 3: face_mode = GL_TRIANGLES; break;
				//default: face_mode = GL_POLYGON; break;
			//}

			//glBegin(face_mode);
			for(unsigned int i = 0; i < face->mNumIndices; i++) {

				int index = face->mIndices[i];
				this->indices.push_back(index);
				glm::vec3 vertex;
				vertex = aiVec3ToVec3(mesh->mVertices[index]);
				this->vertices.push_back(vertex);
				glm::vec3 normal;
				normal = aiVec3ToVec3(mesh->mNormals[index]);
				this->normals.push_back(normal);

				if (mesh->mColors[0]) {
					vec4 color;
					color = aiCol4ToVec4(mesh->mColors[index]); 
					this->colors.push_back(color);
				}
				
			

				//if(mesh->mColors[0] != NULL)
					//glColor4fv((GLfloat*)&mesh->mColors[0][index]);
				//if(mesh->mNormals != NULL) 
					//glNormal3fv(&mesh->mNormals[index].x);
				//glVertex3fv(&mesh->mVertices[index].x);
			}

			//glEnd();
		}

	}

}
