/*
 * Light.cpp
 *
 *  Created on: Jul 24, 2011
 *      Author: raphael
 */

#include "Light.h"


Light::Light(glm::vec3 lightPosition, glm::vec4 lightColor, float lightSize)
{
	this->setLightSize(lightSize);
	this->setLightPos(lightPosition);
	this->setLightColor(lightColor);

}
Light::Light() {
	// TODO Auto-generated constructor stub
	this->setLightSize(1.0f);
	this->setLightPos(glm::vec3(0.0,0.0,0.0));
	this->setLightColor(glm::vec4(1.0,1.0,1.0,1.0));

}

glm::vec4 Light::getLightColor() const
{
    return lightColor;
}

glm::vec3 Light::getLightPos() 
{
    return lightPos;
}

float Light::getLightSize() const
{
    return lightSize;
}

void Light::setLightColor(glm::vec4 lightColor)
{
    this->lightColor = lightColor;
}

void Light::setLightPos(glm::vec3 lightPos)
{
	printf("%f %f %f\n", this->lightPos[0], this->lightPos[1], this->lightPos[2]);
	printf("%f %f %f\n", lightPos[0], lightPos[1], lightPos[2]);
	printf("%f %f %f\n", getLightPos()[0], getLightPos()[1], getLightPos()[2]);
    this->lightPos = lightPos;
	printf("%f %f %f\n", this->lightPos[0], this->lightPos[1], this->lightPos[2]);
	printf("%f %f %f\n", lightPos[0], lightPos[1], lightPos[2]);


	printf("%f %f %f\n", getLightPos()[0], getLightPos()[1], getLightPos()[2]);
}


void Light::setLightSize(float lightSize)
{
    this->lightSize = lightSize;
}

Light::~Light() {
	// TODO Auto-generated destructor stub
}

