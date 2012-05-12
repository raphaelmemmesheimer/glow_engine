/*
 * Curve.h
 *
 *  Created on: Oct 29, 2011
 *      Author: raphael
 */

#ifndef CURVE_H_
#define CURVE_H_

#include <vector>

enum CurveMode {cmBezier};

struct Point {
	double x;
	double y;
};
class Curve {
private:
	std::vector<Point> curvePoints;
	std::vector<Point> controlPoints;
	double startTime;
	double endTime;

public:
	Curve();
	virtual ~Curve();
};

#endif /* CURVE_H_ */
