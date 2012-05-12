/*
 * ControllerValue.h
 *
 *  Created on: Aug 27, 2011
 *      Author: raphael
 */

#ifndef CONTROLLERVALUE_H_
#define CONTROLLERVALUE_H_

template <class T>
class ControllerValue {
private:
	T value;
public:
	ControllerValue();
	virtual ~ControllerValue();
    T getValue() const;
    void setValue(T value);
	//TODO Template
};

#endif /* CONTROLLERVALUE_H_ */
