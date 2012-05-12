/*
 * Light.h
 *
 *  Created on: Jul 24, 2011
 *      Author: raphael
 */

#ifndef LIGHT_H_
#define LIGHT_H_
#include "glm/glm.hpp"

class Light {
private:
	glm::vec3 lightPos;
	float lightSize;
	glm::vec4 lightColor;
public:
	Light();
	Light(glm::vec3 lightPosition, glm::vec4 lightColor, float lightSize);
	virtual ~Light();
    glm::vec4 getLightColor() const;
    glm::vec3 getLightPos() const;
    float getLightSize() const;
    void setLightColor(glm::vec4 lightColor);
    void setLightPos(glm::vec3 lightPos);
    void setLightSize(float lightSize);
};

#endif /* LIGHT_H_ */
