#ifndef ASSIMPMODEL_H

#define ASSIMPMODEL_H
#include "Mesh.h"

#include <assimp/assimp.h>
#include <assimp/aiPostProcess.h>
#include <assimp/aiScene.h>

using namespace glm;

class AssimpModel : public Mesh
{
public:
	AssimpModel();
	~AssimpModel();

private:
	const struct aiScene* scene;
	vec3 aiVec3ToVec3(aiVector3D vector);
	vec4 aiCol4ToVec4(aiColor4D* color);
	void loadFile(std::string filename);
	/* data */
};


#endif /* end of include guard: ASSIMPMODEL_H */
