/*
 * StrUtils.cpp
 *
 *  Created on: Mar 3, 2011
 *      Author: raphael
 */

#include "StrUtils.h"
#include "cstring"

int countCharsInString(char in, const char * str)
{
	unsigned int tmpcnt = 0;
	for (unsigned int i = 0; i < strlen(str);i++){
		if (str[i] == in)
			tmpcnt++;
	}
	return tmpcnt;
}
