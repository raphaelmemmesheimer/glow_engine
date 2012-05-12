/*
 * CameraManager.cpp
 *
 *  Created on: Nov 23, 2011
 *      Author: raphael
 */

#include "CameraManager.h"

CameraManager::CameraManager() {
	activeCameraIndex = 0;
}

CameraManager::~CameraManager() {
}

std::vector<Camera*> CameraManager::getCameras() const
{
	return this->cameras;
}

void CameraManager::setCameras(std::vector<Camera*> cameras)
{
	this->cameras = cameras;
}

void CameraManager::addCamera(Camera *camera)
{
	cameras.push_back(camera);
}

void CameraManager::deleteCamera(int index)
{
	cameras.erase(this->cameras.begin()+index);
}

Camera *CameraManager::getCamera(int index)
{
	return cameras[index];
}

Camera *CameraManager::operator [](std::string cameraName)
{
	int index = getCameraIndexByName(cameraName);
	if (index >= 0)
		return cameras[index];
	else
	{
		printf("Camera %s can not be found\n",cameraName.c_str());
		return 0L;
	}
}

Camera *CameraManager::operator [](int index)
{
	return cameras[index];
}

void CameraManager::setActiveCamera(int  cameraIndex)
{
	this->activeCameraIndex = cameraIndex;
}



void CameraManager::setActiveCamera(std::string cameraName)
{
	activeCameraIndex = getCameraIndexByName(cameraName);
}



int CameraManager::getCameraIndexByName(std::string cameraName)
{
	for (unsigned int i = 0; i < cameras.size(); i++) {
		if (cameraName == cameras[i]->getName())
			return i;
	}
	return -1;
}

Camera* CameraManager::getActiveCamera()
{
	return cameras[activeCameraIndex];
}

void CameraManager::activateNextCamera()
{
	activeCameraIndex = (activeCameraIndex+1) % (cameras.size());
	printf("camindex %d\n",activeCameraIndex);
	printf("Active Cam : %s \n",getActiveCamera()->getName().c_str());
}

int CameraManager::getActiveCameraIndex()
{
	return activeCameraIndex;
}









