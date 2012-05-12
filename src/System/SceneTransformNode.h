
#ifndef SCENETRANSFORMNODE_H

#define SCENETRANSFORMNODE_H


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "SceneNode.h"
#include "../3rdParty/tinyxml/tinyxml.h"
#include <iostream>


typedef enum {
	sttScale,
	sttRotate,
	sttTranslate
} SceneTransformType;

class SceneTransformNode : public SceneNode {
protected:
	double xValue;
	double yValue;
	double zValue;
	SceneTransformType sceneTransformType;
public:
	//SceneTransformNode();
	//virtual ~SceneTransformNode();
	virtual TiXmlElement* getSceneNodeTransformValueAsXmlElement() = 0;
	virtual glm::mat4 getMatrix() = 0;
	virtual SceneTransformType getType() = 0;
	TiXmlElement* getSceneNodeValueAsXmlElement();
};

class SceneTranslateNode : SceneTransformNode {
public:
	void setTranslateValues(double xValue, double yValue, double zValue);
	glm::mat4 getMatrix();
	SceneTransformType getType();
	TiXmlElement* getSceneNodeTransformValueAsXmlElement();
};

class SceneRotateNode : SceneTransformNode {
private:
	double angleValue;
public:
	void setRotateValues(double angleValue, double xValue, double yValue, double zValue);
	glm::mat4 getMatrix();
	SceneTransformType getType();
	TiXmlElement* getSceneNodeTransformValueAsXmlElement();
};

class SceneScaleNode : SceneTransformNode {
public:
	void setScaleValues(double xValue, double yValue, double zValue);
	glm::mat4 getMatrix();
	SceneTransformType getType();
	TiXmlElement* getSceneNodeTransformValueAsXmlElement();
};

#endif /* end of include guard: ddd */
