/*
 * Text.h
 *
 *  Created on: Dec 23, 2011
 *      Author: raphael
 */

#ifndef TEXT_H_
#define TEXT_H_


#include <GL3/gl3w.h>
///#include "Drawable.h"
#include <string>
#include <vector>

#include <stdio.h>
#include "../Shapes/Quad.h"
#include "Texture.h"
#include <stb_truetype.h>
//typedef struct stbtt_fontinfo;


class FontGlyph {
private:
	GLuint vaoID;
	GLuint vboID;
public:
	void createRect(stbtt_aligned_quad q);
	void draw();
};

class Text {



	std::string mText;
	float mPosX;
	float mPosY;
	unsigned char mtemp_bitmap[512*512];

	unsigned char * mBitmap;
	char ttfBuffer[1<<20];
	GLuint mftex;
	std::vector<FontGlyph*> mTextQuads;
	Texture* tex;
	std::string mFontName;
public:
	Text();
	Text(std::string text, std::string fontName);
	virtual ~Text();
    std::string getText() const;
    void setText(std::string text);
    std::string getFontName() const;
    void setFontName(std::string fontName);
};

#endif /* TEXT_H_ */
