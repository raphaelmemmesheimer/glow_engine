/*
 * CameraManager.h
 *
 *  Created on: Nov 23, 2011
 *      Author: raphael
 */

#ifndef CAMERAMANAGER_H_
#define CAMERAMANAGER_H_

#include <vector>
#include <iostream>
#include "Camera.h"
#include "stdio.h"
class CameraManager {
private:
	std::vector<Camera*> cameras;
	int activeCameraIndex;
public:
	CameraManager();
	virtual ~CameraManager();

	std::vector<Camera*> getCameras() const;
	int getCameraIndexByName(std::string cameraName);
	void setCameras(std::vector<Camera*> cameras);
	void addCamera(Camera* camera);
	void deleteCamera(int index);
    Camera* getCamera(int index);
    Camera* operator[](std::string cameraName);
    Camera* operator[](int index);
    void setActiveCamera(int cameraIndex);
    void setActiveCamera(std::string cameraName);
    void activateNextCamera();


    Camera* getActiveCamera();
    int getActiveCameraIndex();
    //friend ostream& operator<<(ostream&, const CameraManager&);
};

#endif /* CAMERAMANAGER_H_ */
