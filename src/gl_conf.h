#define GLFW2
#define GLFW_INCLUDE_GL3
#define GLFW_NO_GLU
#include "gl_inc.h"

#ifdef GLFW3
	#include <GL/glfw3.h>
#endif
#ifdef GLFW2
	#include <GL/glfw.h>
#endif
