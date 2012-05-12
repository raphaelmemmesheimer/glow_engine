/*
 * SceneGraph.h
 *
 *  Created on: Dec 17, 2011
 *      Author: raphael
 */

#ifndef SCENEGRAPH_H_
#define SCENEGRAPH_H_

#include "../3rdParty/tinyxml/tinyxml.h"
#include "Drawable.h"
#include "Log.h"
#include <string>
#include <glm/glm.hpp>
#include "SceneNode.h"
#include "SceneObjectNode.h"
#include "SceneTransformNode.h"
#include <wx/treectrl.h>

class SceneGraph {
	private:
		SceneNode* root ;
	public:
		SceneGraph();
		virtual ~SceneGraph();
		void draw();
		void init(SceneNode* rootNode);
		SceneNode* getRootNode();
		TiXmlElement* getSceneGraphAsXmlElement();
		void toWxTree(wxTreeCtrl* tree);
};

#endif /* SCENEGRAPH_H_ */
