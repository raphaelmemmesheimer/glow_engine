#ifndef SCENEOBJECTNODE_H

#define SCENEOBJECTNODE_H

#include <string>
#include <stdio.h>
#include "Drawable.h"
#include "Mesh.h"
#include "../3rdParty/tinyxml/tinyxml.h"
#include "SceneNode.h"

typedef enum {
	sonMesh,
	sonDrawable
} SceneObjectArt;

class SceneObjectNode : public SceneNode {
private:
	Drawable* drawable;
public:
	//SceneObjectNode();
	//SceneObjectNode(std::string filename);
	//virtual ~SceneObjectNode();
	TiXmlElement* getSceneNodeValueAsXmlElement();
	//Drawable* getValue();
	void setDrawable(Drawable* object);
};


#endif /* end of include guard: SCENEOBJECTNODE_H */
