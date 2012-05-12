/*
 * SceneGraph.cpp
 *
 *  Created on: Dec 17, 2011
 *      Author: raphael
 */

#include "SceneGraph.h"


//SceneObjectNode::SceneObjectNode() {
	//nodeArt = snObject;
//}


//TiXmlElement* SceneTransformNode::getSceneNodeAsXmlElement() {
	//TiXmlElement* element = new TiXmlElement("TransformNode");
	//return element;
//}


//void SceneObjectNode::setDrawable(Drawable* drawable) {
	//this->drawable = drawable;
//}

SceneGraph::SceneGraph() {
	// TODO Auto-generated constructor stub

}

SceneGraph::~SceneGraph() {
	// TODO Auto-generated destructor stub
}

TiXmlElement * SceneGraph::getSceneGraphAsXmlElement() {
	TiXmlElement* element = new TiXmlElement("Scenegraph");

	Log::print("GetSceneGraphAsXmlElement()");
	//root->getSceneNodeAsXmlElement();
	if (root)
		element->LinkEndChild(root->getSceneNodeAsXmlElement());
	return element;
}

void SceneGraph::init(SceneNode* rootNode) {
	this->root = rootNode;
}

void SceneGraph::draw() {
	vector<SceneNode*> nodes = root->getNodes();
	for (unsigned int i =0; i < nodes.size(); i++) {
		//nodes[i] //TODO: add drawing routine
	} 
}


SceneNode* SceneGraph::getRootNode() {
	return root;
}

void SceneGraph::toWxTree(wxTreeCtrl* tree) {
	tree->DeleteAllItems();
	tree->AddRoot(wxString::FromAscii("SceneGraph"));
	return;
}
