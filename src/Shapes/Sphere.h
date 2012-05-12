/*
 * Sphere.h
 *
 *  Created on: May 11, 2011
 *      Author: raphael
 */

#ifndef SPHERE_H_
#define SPHERE_H_

#include <GL3/gl3.h>
#include <GL3/gl3w.h>
#include <glm/glm.hpp>
#include <vector>
#include "../System/constants.h"

using namespace std;
class Sphere {
private:
	GLuint vaoID;
	GLuint vboID;

	GLfloat radius;
	GLuint numStacks;
	GLuint numSlices;

	vector<glm::vec3> vertices;
	void generate();
public:
	Sphere(GLfloat radius, unsigned int numStacks, unsigned int numSlices);
	virtual ~Sphere();
    GLfloat getRadius() const;
    void setRadius(GLfloat radius);
    GLuint getNumSlices() const;
    GLuint getNumStacks() const;
    void setNumSlices(GLuint numSlices);
    void setNumStacks(GLuint numStacks);
    void draw();
};

#endif /* SPHERE_H_ */
