/*
 * Camera.h
 *
 *  Created on: Jan 15, 2011
 *      Author: raphael
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include "GL3/gl3.h"
#include "glm/glm.hpp"
#include <string>

struct ViewDirection1{
	GLfloat x;
	GLfloat y;
	GLfloat z;
};

struct ViewDirection{
	GLfloat theta;
	GLfloat phi;
};

struct ViewDestination{
	GLfloat x;
	GLfloat y;
	GLfloat z;
};

enum CameraMode {
		cmEgo = 0,
		cmTrackball,
		cmStatic
};

class Camera {
private:
	GLfloat x;
	GLfloat y;
	GLfloat z;
	GLfloat speed;
	GLfloat radius;
	GLfloat moveSpeed;
	ViewDirection viewDirection;
	ViewDestination viewDestination;
	CameraMode mode;
	std::string name;
public:
	Camera(std::string name);
	Camera(std::string name,GLfloat posX,GLfloat posY,GLfloat posZ,GLfloat speed,GLfloat theta,GLfloat phi);
	Camera(std::string name,GLfloat posX,GLfloat posY,GLfloat posZ,GLfloat speed,ViewDirection viewDirection);
	virtual ~Camera();
    GLfloat getX() const;
    GLfloat getY() const;
    GLfloat getZ() const;
    void setX(GLfloat x);
    void setY(GLfloat y);
    void setZ(GLfloat z);
	void setPos(glm::vec3 pos);
    GLfloat getSpeed() const;
    ViewDirection getViewDirection() const;
    void setSpeed(GLfloat speed);
    void setViewDestination(GLfloat destX, GLfloat destY, GLfloat destZ);
    void setViewDestination(ViewDestination viewDestination);
    ViewDestination getViewDestination() const;
    void setViewDirection(ViewDirection viewDirection);
    void setViewDirection(GLfloat theta, GLfloat phi);
    void setViewXY(GLfloat deltaX, GLfloat Y);
    void setCamera();
    glm::mat4 getCameraMatrix();
    CameraMode getMode() const;
    void setMode(CameraMode mode);
    glm::mat4 getEgoMatrix();
    glm::mat4 getTrackballMatrix();
    glm::mat4 getStaticMatrix();
    GLfloat getRadius() const;
    void setRadius(GLfloat radius);
    std::string getName() const;
    void setName(std::string name);
    GLfloat getMoveSpeed() const;
    void setMoveSpeed(GLfloat moveSpeed);

};

#endif /* CAMERA_H_ */
