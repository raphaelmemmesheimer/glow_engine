#include "SceneNode.h"

SceneNode::SceneNode() {
	printf("SceneNode: \n");
}

SceneNode::~SceneNode(){

}

SceneNode* SceneNode::getNext(){
	return 0L;
}

SceneNode* SceneNode::getParent(){
	return 0L;
}

std::string SceneNode::getName() {
	return this->name;
}

void SceneNode::addNode(SceneNode* node) {
	nodes.push_back(node);
	Log::print(M,"addNode");
	//printf("[SceneNode] addNode\n");
}

std::vector<SceneNode*> SceneNode::getNodes() {
	return nodes;
}

TiXmlElement* SceneNode::getSceneNodeAsXmlElement() {
	TiXmlElement* element = new TiXmlElement("SceneNode");
	TiXmlElement* nodeElement = getSceneNodeValueAsXmlElement();
	//error somewhere here with subnodes
	for (unsigned int i = 0; i < nodes.size(); i++) {
		nodeElement->LinkEndChild(nodes[i]->getSceneNodeValueAsXmlElement());
	}
	element->LinkEndChild(nodeElement);	
	return element;
}
