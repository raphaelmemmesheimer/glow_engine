/*
 * FrameBufferObject.h
 *
 *  Created on: Apr 24, 2011
 *      Author: raphael
 */

#ifndef FRAMEBUFFEROBJECT_H_
#define FRAMEBUFFEROBJECT_H_

#include <GL3/gl3.h>
#include <GL3/gl3w.h>
#include <string>
#include <stdio.h>
#include <iostream>

class FrameBufferObject {
private:
	GLuint fboID;
	GLuint rboID;
	GLuint textureColor;
	GLuint textureNormal;
	GLuint textureRadiance;
    GLuint texturePosition;
    GLuint textureShadowMap;
    GLuint textureDepth;
    GLuint depthbuffer;
    GLuint width;
    GLuint height;
public:
    FrameBufferObject(GLuint width, GLuint height);
    virtual ~FrameBufferObject();
    void attach();
    void bind();
    void unbind();
    GLuint getTextureDepth() const;
    GLuint getTextureNormal() const;
    GLuint getTextureColor() const;
    GLuint getHeight() const;
    GLuint getWidth() const;
    void setHeight(GLuint height);
    void setWidth(GLuint width);
    std::string getError();
    void printError();
    GLuint getTexturePosition() const;
    void setTexturePosition(GLuint texturePosition);
    GLuint getTextureRadiance() const;
    void setTextureRadiance(GLuint textureRadiance);
    GLuint getTextureShadowMap() const;
    void setTextureShadowMap(GLuint textureShadowMap);
};

#endif /* FRAMEBUFFEROBJECT_H_ */
