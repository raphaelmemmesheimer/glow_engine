#ifndef RESOURCEMANAGER_H

#define RESOURCEMANAGER_H

#include "TextureManager.h"
#include "ShaderManager.h"

class ResourceManager 
{
public:
	ResourceManager();
	~ResourceManager();
	//TextureManager getTextureManager();
	//ShaderManager getShaderManager();
	TextureManager textureManager;
	ShaderManager shaderManager;
private:
	
};


#endif /* end of include guard: RESOURCEMANAGER_H */
