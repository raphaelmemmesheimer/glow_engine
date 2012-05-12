#ifndef SCENENODE_H

#define SCENENODE_H

#define M "SceneNode"

#include "Log.h"
#include "../3rdParty/tinyxml/tinyxml.h"
//#include "Drawable.h"
#include <vector>
#include <string>
#include <stdio.h>

typedef enum {
	snRoot,
	snGroup,
	snTransformation,
	snObject,
	snLight,
	snCamera
} SceneNodeArt;

class SceneNode 
{
	protected:
		SceneNodeArt nodeArt;
		std::string name;
		SceneNode* parent;
		std::vector<SceneNode*> nodes;
	public:
		SceneNode();
		virtual ~SceneNode();
		SceneNode* getNext();
		SceneNode* getParent();
		std::string getName();
		void addNode(SceneNode* node);
		std::vector<SceneNode*> getNodes();
		//virtual getValue();
		TiXmlElement* getSceneNodeAsXmlElement(); //forward declaration
		virtual TiXmlElement* getSceneNodeValueAsXmlElement() = 0;
};


#endif /* end of include guard: SCENENODE_H */
