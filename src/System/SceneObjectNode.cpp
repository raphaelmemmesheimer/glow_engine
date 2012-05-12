#include "SceneObjectNode.h"

//SceneObjectNode::SceneObjectNode() {

	//return;
//}

//SceneObjectNode::~SceneObjectNode(){
	
//}

TiXmlElement* SceneObjectNode::getSceneNodeValueAsXmlElement() {
	//printf("getSceneNodeAsXmlElement \n");
	TiXmlElement* element = new TiXmlElement("ObjectNode");
	element->LinkEndChild(drawable->getDrawableAsXmlElement());
	//element->LinkEndChild(((Mesh*)(drawable))->getDrawableAsXmlElement());
	return element;
}

void SceneObjectNode::setDrawable(Drawable* drawable){
	this->drawable = drawable;
}
