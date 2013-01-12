//My little OpenGL Configuration File to be more flexible with different GL Versions on different Plattforms
//TODO: GLES 2.0/3.0 on Raspberry Pi
#define USE_GL_CORE_HEADER

#define GLCOREARB_PROTOTYPES

#ifdef USE_GL_CORE_HEADER
	#include <glcorearb.h>
#endif

#ifdef USE_GL3_HEADER
	#include <GL3_tmp/gl3.h>
	#include <GL3_tmp/gl3w.h>
#endif
