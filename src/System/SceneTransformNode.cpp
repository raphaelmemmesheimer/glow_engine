#include "SceneTransformNode.h"

//SceneTransformNode::SceneTransformNode() {

//}
void SceneTranslateNode::setTranslateValues(double xValue, double yValue, double zValue) {
	this->xValue = xValue;
	this->yValue = yValue;
	this->zValue = zValue;
}


TiXmlElement* SceneTransformNode::getSceneNodeValueAsXmlElement() {
	//SceneNode::getSceneNodeAsXmlElement();
	TiXmlElement* element = new TiXmlElement("TransformNode");
	element->SetAttribute("Type",  getType());
	element->LinkEndChild(getSceneNodeTransformValueAsXmlElement());
	return element;
}

TiXmlElement* SceneTranslateNode::getSceneNodeTransformValueAsXmlElement() {
	TiXmlElement* element = new TiXmlElement("Translate");
	element->SetAttribute("x", xValue);
	element->SetAttribute("y", yValue);
	element->SetAttribute("z", zValue);
	return element;
}

glm::mat4 SceneTranslateNode::getMatrix() {
	return glm::translate(glm::mat4(1.0), glm::vec3(xValue, yValue, zValue));
}

SceneTransformType SceneTranslateNode::getType() {
	return sttTranslate;
}

void SceneRotateNode::setRotateValues(double angleValue, double xValue, double yValue, double zValue) {
	this->angleValue = angleValue;
	this->xValue = xValue;
	this->yValue = yValue;
	this->zValue = zValue;
}

glm::mat4 SceneRotateNode::getMatrix() {
	return glm::rotate(glm::mat4(1.0), glm::degrees((float)angleValue), glm::vec3(xValue, yValue, zValue));
}

SceneTransformType SceneRotateNode::getType() {
	return sttRotate;
}

TiXmlElement* SceneRotateNode::getSceneNodeTransformValueAsXmlElement() {
	TiXmlElement* element = new TiXmlElement("Rotate");
	element->SetAttribute("angle", angleValue);
	element->SetAttribute("x", xValue);
	element->SetAttribute("y", yValue);
	element->SetAttribute("z", zValue);
	return element;
}

void SceneScaleNode::setScaleValues(double xValue, double yValue, double zValue) {
	this->xValue = xValue;
	this->yValue = yValue;
	this->zValue = zValue;
}

glm::mat4 SceneScaleNode::getMatrix() {
	return glm::scale(glm::mat4(1.0), glm::vec3(xValue, yValue, zValue));
}

SceneTransformType SceneScaleNode::getType() {
	return sttScale;
}

TiXmlElement* SceneScaleNode::getSceneNodeTransformValueAsXmlElement() {
	TiXmlElement* element = new TiXmlElement("Scale");
	element->SetAttribute("x", xValue);
	element->SetAttribute("y", yValue);
	element->SetAttribute("z", zValue);
	return element;
}
