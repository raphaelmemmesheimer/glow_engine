/*
 * Camera.cpp
 *
 *  Created on: Jan 15, 2011
 *      Author: raphael
 *
 *      based on CG1 slides
 */

#include "Camera.h"
#include <math.h>

#include <stdio.h>
#include <glm/gtc/matrix_transform.hpp>
double PI = 3.141592;

Camera::Camera(std::string name) {
	this->name = name;
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->radius = 10.0;

	this->speed = 0;
	this->moveSpeed = 1.0;
	this->setViewDirection(PI/2.0,1.5*PI);
}

Camera::Camera(std::string name,GLfloat posX,GLfloat posY,GLfloat posZ,GLfloat speed,ViewDirection viewDirection) {
	this->name = name;

	this->x = x;
	this->y = y;
	this->z = z;

	this->speed = speed;
	this->moveSpeed = 1.0;

	this->viewDirection = viewDirection;
	this->setViewDirection(PI/2.0,1.5*PI);
}

Camera::Camera(std::string name,GLfloat posX,GLfloat posY,GLfloat posZ,GLfloat speed,GLfloat theta,GLfloat phi) {
	this->name = name;
	this->x = x;
	this->y = y;
	this->z = z;
	this->moveSpeed = 1.0;
	this->speed = speed;
	this->setViewDirection(PI/2.0,1.5*PI);
}



Camera::~Camera() {
	// TODO Auto-generated constructor stub

}

GLfloat Camera::getX() const
{
    return x;
}

GLfloat Camera::getY() const
{
    return y;
}

GLfloat Camera::getSpeed() const
{
    return speed;
}

ViewDirection Camera::getViewDirection() const
{
    return viewDirection;
}

void Camera::setSpeed(GLfloat speed)
{
    this->speed = speed;
}

void Camera::setViewDirection(ViewDirection viewDirection)
{
    this->viewDirection = viewDirection;
}

void Camera::setViewDirection(GLfloat theta, GLfloat phi)
{
	this->viewDirection.theta = theta;
    this->viewDirection.phi = phi;
}

void Camera::setViewXY(GLfloat deltaX, GLfloat deltaY){
	//GLfloat theta = camera->getViewDirection().theta;
	//GLfloat phi = camera->getViewDirection().phi;
	this->viewDirection.theta -= (float)deltaY/100;
	this->viewDirection.phi -= (float)deltaX/100;

//	if (this->viewDirection.phi > 2*PI)
//		this->viewDirection.phi = 2*PI;
//	else if (this->viewDirection.phi < 0)
//		this->viewDirection.phi = 0;
//	if (this->viewDirection.theta >= 2*PI)
//		this->viewDirection.theta = PI;
//	else if (this->viewDirection.theta < 0)
//		this->viewDirection.theta = PI;


    if (this->viewDirection.theta < 0.01) this->viewDirection.theta = 0.01;      // Gueltigkeitsbereich testen
    else if (this->viewDirection.theta > PI - 0.01) this->viewDirection.theta = PI - 0.01; // nie entlang up-Vector fliegen

	//printf("%f %f \n",this->viewDirection.theta,this->viewDirection.phi);
	this->setViewDirection(this->viewDirection.theta,this->viewDirection.phi);
}

GLfloat Camera::getZ() const
{
    return z;
}

void Camera::setX(GLfloat x)
{
    this->x = x;
}

void Camera::setY(GLfloat y)
{
    this->y = y;
}

void Camera::setZ(GLfloat z)
{
    this->z = z;
}

void Camera::setCamera(){
	GLfloat viewX = sin(this->viewDirection.theta)*cos(this->viewDirection.phi);
	GLfloat viewY = cos(this->viewDirection.theta);
	GLfloat viewZ = sin(this->viewDirection.theta)*sin(this->viewDirection.phi);
	this->x += this->speed * viewX;
	this->y += this->speed * viewY;
	this->z += this->speed * viewZ;
}

CameraMode Camera::getMode() const
{
    return mode;
}

void Camera::setMode(CameraMode mode)
{
    this->mode = mode;
}

glm::mat4 Camera::getEgoMatrix() {
	GLfloat viewX = sin(this->viewDirection.theta)*cos(this->viewDirection.phi);
	GLfloat viewY = cos(this->viewDirection.theta);
	GLfloat viewZ = sin(this->viewDirection.theta)*sin(this->viewDirection.phi);
	this->x += this->speed * viewX;
	this->y += this->speed * viewY;
	this->z += this->speed * viewZ;

	return glm::lookAt(glm::vec3(this->x, this->y, this->z),
			glm::vec3(this->x+viewX,this->y+viewY,this->z+viewZ),
			glm::vec3(0.0,1.0,0.0));
}

GLfloat Camera::getRadius() const
{
    return radius;
}

void Camera::setViewDestination(GLfloat destX, GLfloat destY, GLfloat destZ){

	ViewDestination vd;
	vd.x = destX;
	vd.y = destY;
	vd.z = destZ;

	setViewDestination(vd);
}

void Camera::setViewDestination(ViewDestination viewDestination){
	this->viewDestination = viewDestination;
}

ViewDestination Camera::getViewDestination() const
{
    return viewDestination;
}

std::string Camera::getName() const
{
    return name;
}

GLfloat Camera::getMoveSpeed() const
{
    return moveSpeed;
}

void Camera::setMoveSpeed(GLfloat moveSpeed)
{
    this->moveSpeed = moveSpeed;
}

void Camera::setName(std::string name)
{
    this->name = name;
}

void Camera::setRadius(GLfloat radius)
{
    this->radius = radius;
}

glm::mat4 Camera::getTrackballMatrix() { // trackball cam around the center
	GLfloat viewX = sin(this->viewDirection.theta)*cos(this->viewDirection.phi);
	GLfloat viewY = cos(this->viewDirection.theta);
	GLfloat viewZ = sin(this->viewDirection.theta)*sin(this->viewDirection.phi);

	this->x = this->radius * viewX;
	this->y = this->radius * viewY;
	this->z = this->radius * viewZ;

	return glm::lookAt(glm::vec3(this->x, this->y, this->z),
			glm::vec3(viewX,viewY,viewZ),
			glm::vec3(0.0,1.0,0.0));
}

glm::mat4 Camera::getStaticMatrix() { // static camera e.g for LightPos
	return glm::lookAt(glm::vec3(this->x, this->y, this->z),
			glm::vec3(this->viewDestination.x,this->viewDestination.y,this->viewDestination.z),
			glm::vec3(0.0,1.0,0.0));
}

glm::mat4 Camera::getCameraMatrix(){
	switch (mode) {
		case cmEgo:
			return getEgoMatrix();
			break;
		case cmTrackball:
			return getTrackballMatrix();
			break;
		case cmStatic:
			return getStaticMatrix();
			break;
	}
	return getEgoMatrix();
}
