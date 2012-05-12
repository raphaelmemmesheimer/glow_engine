/*
 * Particle.h
 *
 *  Created on: Jun 10, 2011
 *      Author: raphael
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <glm/glm.hpp>
#include "../Shapes/Quad.h"


class Particle {
	Quad* quad;
	glm::vec4 mColor;
	glm::vec3 mPosition;
public:
	Particle();
	virtual ~Particle();
	void setColor(glm::vec4 color);
	void setPosition(glm::vec3 position);
	void draw();
};

#endif /* PARTICLE_H_ */
