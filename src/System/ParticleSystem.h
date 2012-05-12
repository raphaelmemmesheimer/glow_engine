/*
 * ParticleSystem.h
 *
 *  Created on: Jun 10, 2011
 *      Author: raphael
 */

#ifndef PARTICLESYSTEM_H_
#define PARTICLESYSTEM_H_

#include "Particle.h"
#include "Texture.h"
#include <vector>
#include "../System/Shader.h"
#include <glm/gtc/matrix_transform.hpp>
#include <math.h>


class ParticleSystem {
	GLuint initVelBuffer;
	GLuint startTimeBuffer;
	GLuint particlesBuffer;

	int mCount;
	std::vector<Particle*> mParticles;
	glm::mat4 mUpdateMatrix;
	Texture* mTex;
	//Particle* mParticles;
public:
	ParticleSystem(int particleCount);
	virtual ~ParticleSystem();
	void addPoints(int pCount);
	void draw(Shader* shader , glm::mat4 modelview);
	void update(glm::mat4 updateMatrix);
};

#endif /* PARTICLESYSTEM_H_ */
