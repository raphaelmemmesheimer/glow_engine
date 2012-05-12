/*
 * FrameBufferObject.cpp
 *
 *  Created on: Apr 24, 2011
 *      Author: raphael
 */

#include "FrameBufferObject.h"

FrameBufferObject::FrameBufferObject(GLuint width, GLuint height) {
//
	this->height = height;
	this->width = width;

	glGenFramebuffers(1,&fboID);
	glGenRenderbuffers(1, &depthbuffer);
	glGenTextures(1, &textureColor);

	glBindFramebuffer(GL_FRAMEBUFFER,fboID);


	glBindTexture(GL_TEXTURE_2D, textureColor);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8 , width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY, 4);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glFramebufferTexture2D(
	      GL_FRAMEBUFFER,
	      GL_COLOR_ATTACHMENT0,
	      GL_TEXTURE_2D,
		  textureColor,
		  0
		);

	glGenTextures(1, &texturePosition);
	glBindTexture(GL_TEXTURE_2D, texturePosition);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8 , width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY, 4);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glFramebufferTexture2D(
		  GL_FRAMEBUFFER,
		  GL_COLOR_ATTACHMENT1,
		  GL_TEXTURE_2D,
		  texturePosition,
		  0
		);

	glGenTextures(1, &textureNormal);
	glBindTexture(GL_TEXTURE_2D, textureNormal);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8 , width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY, 4);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glFramebufferTexture2D(
	      GL_FRAMEBUFFER,
	      GL_COLOR_ATTACHMENT2,
	      GL_TEXTURE_2D,
		  textureNormal,
		  0
		);

	glGenTextures(1, &textureShadowMap);
	glBindTexture(GL_TEXTURE_2D, textureShadowMap);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8 , width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY, 4);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glFramebufferTexture2D(
	      GL_FRAMEBUFFER,
	      GL_COLOR_ATTACHMENT3,
	      GL_TEXTURE_2D,
	      textureShadowMap,
		  0
		);

	glGenTextures(1, &textureRadiance);
	glBindTexture(GL_TEXTURE_2D, textureRadiance);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8 , width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY, 4);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glFramebufferTexture2D(
	      GL_FRAMEBUFFER,
	      GL_COLOR_ATTACHMENT4,
	      GL_TEXTURE_2D,
		  textureRadiance,
		  0
		);


	glBindRenderbuffer(GL_RENDERBUFFER, depthbuffer);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT24, width, height);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthbuffer);
	printError();
	glBindRenderbuffer(GL_RENDERBUFFER, 0);
	glGenTextures(1, &textureDepth);
	glBindTexture(GL_TEXTURE_2D, textureDepth);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT24, width, height, 0, GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, NULL);//	//glDrawBuffer(GL_DEPTH_BUFFER);

	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, textureDepth, 0);

	GLenum buffers[4];
	buffers[0] = GL_COLOR_ATTACHMENT0;
	buffers[1] = GL_COLOR_ATTACHMENT1;
	buffers[2] = GL_COLOR_ATTACHMENT2;
	buffers[3] = GL_COLOR_ATTACHMENT3;
//	buffers[4] = GL_COLOR_ATTACHMENT4;
//	buffers[5] = GL_COLOR_ATTACHMENT5;
//	buffers[6] = GL_COLOR_ATTACHMENT6;
	glDrawBuffers(4, buffers);
	printError();

	glBindFramebuffer(GL_FRAMEBUFFER,0);
}

FrameBufferObject::~FrameBufferObject() {
	glDeleteFramebuffers(1,&fboID);
}

void FrameBufferObject::attach() {
	glBindFramebuffer(GL_FRAMEBUFFER,fboID);
//
//	GLenum buffers[2];
//	buffers[0] = GL_COLOR_ATTACHMENT0;
//	buffers[1] = GL_COLOR_ATTACHMENT1;
//	glDrawBuffers(2, buffers);

}

void FrameBufferObject::bind(){
	glBindFramebuffer(GL_FRAMEBUFFER,fboID);
	glViewport(0, 0, width, height);
	//this->printGetError();
}

GLuint FrameBufferObject::getTextureDepth() const
{
    return textureDepth;
}

GLuint FrameBufferObject::getTextureNormal() const
{
    return textureNormal;
}

GLuint FrameBufferObject::getHeight() const
{
    return height;
}

GLuint FrameBufferObject::getWidth() const
{
    return width;
}

void FrameBufferObject::setHeight(GLuint height)
{
    this->height = height;
}

void FrameBufferObject::setWidth(GLuint width)
{
    this->width = width;
}

GLuint FrameBufferObject::getTextureColor() const
{
    return textureColor;
}


void FrameBufferObject::unbind(){
	glBindFramebuffer(GL_FRAMEBUFFER,0);
}

GLuint FrameBufferObject::getTexturePosition() const
{
    return texturePosition;
}

GLuint FrameBufferObject::getTextureRadiance() const
{
    return textureRadiance;
}

GLuint FrameBufferObject::getTextureShadowMap() const
{
    return textureShadowMap;
}

void FrameBufferObject::setTextureShadowMap(GLuint textureShadowMap)
{
    this->textureShadowMap = textureShadowMap;
}

void FrameBufferObject::setTextureRadiance(GLuint textureRadiance)
{
    this->textureRadiance = textureRadiance;
}

void FrameBufferObject::setTexturePosition(GLuint texturePosition)
{
    this->texturePosition = texturePosition;
}

void FrameBufferObject::printError(){
	std::cout<<this->getError()<<std::endl;
}

std::string FrameBufferObject::getError()
{
	GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
	switch (status) {
	case GL_FRAMEBUFFER_COMPLETE:
	return "Framebuffer complete.";
	case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT:
	return "Framebuffer incomplete: Attachment is NOT complete.";
	case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT:
	return "Framebuffer incomplete: No image is attached to FBO.";
	case GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER:
	return "Framebuffer incomplete: Draw buffer.";
	case GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER:
	return "Framebuffer incomplete: Read buffer.";
	case GL_FRAMEBUFFER_UNSUPPORTED:
	return "Unsupported by FBO implementation.";
	default:
	return "Unknow error.";
	}

}


