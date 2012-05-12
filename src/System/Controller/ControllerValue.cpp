/*
 * ControllerValue.cpp
 *
 *  Created on: Aug 27, 2011
 *      Author: raphael
 */

#include "ControllerValue.h"
template <class T>
ControllerValue<T>::ControllerValue() {
	// TODO Auto-generated constructor stub

}
template <class T>
T ControllerValue<T>::getValue() const
{
    return value;
}
template <class T>
void ControllerValue<T>::setValue(T value)
{
    this->value = value;
}
template <class T>
ControllerValue<T>::~ControllerValue() {
	// TODO Auto-generated destructor stub
}
