/*
 * Particle.cpp
 *
 *  Created on: Jun 10, 2011
 *      Author: raphael
 */

#include "Particle.h"

Particle::Particle() {
	quad = new Quad(0.2);
}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

void Particle::setColor(glm::vec4 color)
{
}



void Particle::setPosition(glm::vec3 position)
{
}

void Particle::draw()
{
	quad->draw();
}


