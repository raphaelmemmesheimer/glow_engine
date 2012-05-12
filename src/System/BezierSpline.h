#ifndef _BEZIERSPLINE_H
#define _BEZIERSPLINE_H

#include "glm/glm.hpp"
#include <stdio.h>
#include "constants.h"
#include <vector>
#include <GL3/gl3.h>
#include <GL3/gl3w.h>
#include <iostream>

using namespace std;

class BezierSpline
{
private:
	unsigned int vaoID;
	unsigned int vboID;
	unsigned int vaoIDControlPoints;

	vector<glm::vec3> vertices;
	vector<GLuint> indices;
	vector<glm::vec3> _controlPoints;      // Kontrollpunkte
public:
    BezierSpline();
    ~BezierSpline();

    glm::vec3 deCasteljau(float t);        // Punkt fuer Parameter t bestimmen

    void addPoint(glm::vec3 newPoint);     // neuen Punkt anfuegen

    void generateAndBindBuffers(int resolution);
    void generateAndBindBuffersControlPoints();
    void drawControlPolygon();            // Kontrollpolygon zeichnen
    void draw();            // Spline in <resolution> Schritten zeichnen
    void drawControlPoints();
};

#endif

