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

glm::vec3 Light::getLightPos() const
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
    this->lightPos = lightPos;
}


void Light::setLightSize(float lightSize)
{
    this->lightSize = lightSize;
}

Light::~Light() {
	// TODO Auto-generated destructor stub
}

