/*
 * Messages.cpp
 *
 *  Created on: Feb 24, 2011
 *      Author: raphael
 */

#include "Messages.h"
#include <stdio.h>

void msg(const char* sender, const char* message)
{
  printf("[%s]: %s \n",sender,message);
}
