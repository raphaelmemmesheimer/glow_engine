/*
 * ParticleSystem.cpp
 *
 *  Created on: Jun 10, 2011
 *      Author: raphael
 */

#include "ParticleSystem.h"
#include <vector>
#include <math.h>

ParticleSystem::ParticleSystem(int particleCount) {
	// TODO Auto-generated constructor stub
	mCount = particleCount;
	mTex = new Texture();
	glGenBuffers(1, &initVelBuffer);
	glGenBuffers(1, &startTimeBuffer);
	addPoints(mCount);
}

ParticleSystem::~ParticleSystem() {
	// TODO Auto-generated destructor stub
}

void ParticleSystem::addPoints(int pCount){
//	for (int i = 0; i < pCount; ++i) {
//		Particle* p = new Particle();
//		p->setColor(glm::vec4(1.0,1.0,1.0,1.0));
//		p->setPosition(glm::vec3(sin(pCount),sin(pCount),-sin(pCount)));
//		mParticles.push_back(p);
//	}


	glm::vec3(0.0);
	float velocity, theta, phi;
	vector<glm::vec3> particles;
	for (unsigned int i = 0; i < pCount; i++ ) {
		theta = glm::mix(0.0f, (float)M_PI/6.0f, randFloat());
		phi = glm::mix(0.0f, (float)M_2_PI, randFloat());
		glm::vec3 particle = glm::vec3(sinf(theta) * cosf(phi), cosf(theta), sinf(theta) * sinf(phi));
		velocity = glm::mix(1.25f, 1.5f, randFloat());
		particles.push_back(particle);
	}
	glBindBuffer(GL_ARRAY_BUFFER, initVelBuffer);
	glBufferSubData(GL_ARRAY_BUFFER, 0, pCount * 3 * sizeof(float), &particles[0][0]);

	vector<float> startTimeData;
	float time = 0.0f;
	float rate = 0.0000075f;

	for (unsigned int i = 0; i < pCount; i++) {
		startTimeData.push_back(time);
		time += rate;
	}

	glBindBuffer(GL_ARRAY_BUFFER, startTimeBuffer);
	glBufferSubData(GL_ARRAY_BUFFER, 0, pCount * sizeof(float), &startTimeData[0]);


    glGenVertexArrays(1, &particlesBuffer);
    glBindVertexArray(particlesBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, initVelBuffer);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, startTimeBuffer);
    glVertexAttribPointer(1, 1, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

}

void ParticleSystem::draw(Shader* shader, glm::mat4 modelview) {
//	for (unsigned int i = 0; i < mParticles.size(); i++) {
//
//		//modelview = glm::translate(modelview,glm::vec3(0.1,0.1,0.1));//glm::rotate(Modelview,glm::degrees((float)i),glm::vec3(0.0,0.0,1.0));
//		modelview = modelview * mUpdateMatrix;
//		glUniformMatrix4fv(shader->getUniformLocation("Modelview"), 1, 0,&modelview[0][0]);
//		mParticles[i]->draw();
//	}
	glPointSize(10.0);
    glBindVertexArray(particlesBuffer);
    glDrawArrays(GL_POINTS, 0, mCount);
}

void ParticleSystem::update(glm::mat4 updateMatrix){
	mUpdateMatrix = updateMatrix;
}
