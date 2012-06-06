#ifndef RESOURCEMANAGER_H

#define RESOURCEMANAGER_H

#include "TextureManager.h"
#include "ShaderManager.h"
//#include "SceneManager.h"

class ResourceManager 
{
public:
	ResourceManager();
	~ResourceManager();
	//TextureManager getTextureManager();
	//ShaderManager getShaderManager();
	TextureManager textureManager;
	ShaderManager shaderManager;
	//SceneManager sceneManager;
private:
	
};


#endif /* end of include guard: RESOURCEMANAGER_H */
