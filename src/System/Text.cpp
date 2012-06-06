/*
 * Text.cpp
 *
 *  Created on: Dec 23, 2011
 *      Author: rap<F4>mahael
 */

#include "Text.h"
#define STB_TRUETYPE_IMPLEMENTATION
#include <stb_truetype.h>



Text::Text() {
	// TODO Auto-generated constructor stub

}

std::string Text::getText() const
{
	return mText;
}

Text::Text(std::string text, std::string fontName)
{
	//	Quad* q = new Quad(1.0);
	//	mTextQuads.push_back(q);// main Quad printing the complete baked font

	//static stbtt_bakedchar g_cdata[96]; // ASCII 32..126 is 95 glyphs
	
	mPosX = 20;
	mPosY = 20;

	FILE* fp = fopen(fontName.c_str(), "rb");
	fseek(fp, 0, SEEK_END);
	int size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	fread(ttfBuffer, 1, size, fp);

	mBitmap = (unsigned char*)malloc(512*512);

	stbtt_BakeFontBitmap((unsigned char*)ttfBuffer, 0, 32.0, mBitmap, 512, 512, 32, 96, g_cdata); // no guarantee this fits!

	glGenTextures(1, &mftex);
	glBindTexture(GL_TEXTURE_2D, mftex);
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, 512,512, 0, GL_RED, GL_UNSIGNED_BYTE, mBitmap);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, 512,512, 0, GL_RED, GL_UNSIGNED_BYTE, mBitmap);

	// can free temp_bitmap at this point
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	free(mBitmap);

	this->setText(text);
	//const char* txt = text.c_str();
	//mPosX = 100;
	//mPosY = 100;
	//while (*txt) {
		//if (*txt >= 32 && *txt < 128) {
			//stbtt_aligned_quad q;
			//stbtt_GetBakedQuad(g_cdata, 512, 512, *txt-32, &mPosX, &mPosY, &q, 1);//1=opengl,0=old d3d
			////printf("%d %d \n", mPosX, mPosY );
			//FontGlyph* fg = new FontGlyph();
			//fg->createRect(q);
			//mTextQuads.push_back(fg);//
		//}
		//++txt;
	//}

}

std::string Text::getFontName() const
{
	return mFontName;
}

void Text::setFontName(std::string fontName)
{
	mFontName = fontName;
}

void Text::setText(std::string text)
{
	mText = text;
	mTextQuads.clear();
	float posX = mPosX;
	float posY = mPosY;

	const char* txt = text.c_str();
	while (*txt) {
		if (*txt >= 32 && *txt < 128) {
			stbtt_aligned_quad q;
			stbtt_GetBakedQuad(g_cdata, 512, 512, *txt-32, &posX, &posY, &q, 1);//1=opengl,0=old d3d
			//printf("%d %d \n", mPosX, mPosY );
			FontGlyph* fg = new FontGlyph();
			fg->createRect(q);
			mTextQuads.push_back(fg);//
		}
		++txt;
	}
}

void Text::draw() {
	glBindTexture(GL_TEXTURE_2D, mftex);

	for (int unsigned i = 0; i < mTextQuads.size(); i++) { //draw glyphs
		mTextQuads[i]->draw();
	}
}

Text::~Text() {

}

void Text::setPos(float posX, float posY) {
	this->mPosX = posX;
	this->mPosY = posY;
}

void FontGlyph::createRect(stbtt_aligned_quad q)
{
	GLfloat vRect[] = {
		q.x0 / 1024.0,q.y0 / 700.0, 0,
		q.x1/ 1024.0,q.y0 / 700.0, 0,
		q.x1/ 1024.0,q.y1 / 700.0, 0,
		q.x1/ 1024.0,q.y1 / 700.0, 0,
		q.x0/ 1024.0,q.y0 / 700.0, 0,
		q.x0/ 1024.0,q.y1 / 700.0, 0,
	};

	GLfloat tRect[] = { q.s0, q.t0 ,
		q.s1, q.t0,
		q.s1, q.t1,
		q.s1, q.t1,
		q.s0, q.t0,
		q.s0, q.t1

	};

	//	    printf("x%f y%f x%f y%f \n", q.x0, q.y0, q.x1, q.y1);
	//	    printf("s%f t%f s%f t%f \n", q.s0, q.t0, q.s1, q.t1);

	glGenVertexArrays(1, &vaoID); // Create our Vertex Array Object
	glBindVertexArray(vaoID); // Bind our Vertex Array Object so we can use it

	glGenBuffers(1, &vboID); // Generate our Vertex Buffer Object

	glBindBuffer(GL_ARRAY_BUFFER, vboID); // Bind our Vertex Buffer Object
	glBufferData(GL_ARRAY_BUFFER, sizeof(vRect), vRect, GL_STATIC_DRAW); // Set the size and data of our VBO and set it to STATIC_DRAW
	glEnableVertexAttribArray(SH_VERTEX);
	glVertexAttribPointer(SH_VERTEX, 3, GL_FLOAT, GL_FALSE, 0, 0); // Set up our vertex attributes pointer


	glGenBuffers(1, &vboID); // Generate our Vertex Buffer Object

	glBindBuffer(GL_ARRAY_BUFFER, vboID); // Bind our Vertex Buffer Object
	glBufferData(GL_ARRAY_BUFFER, sizeof(tRect), tRect, GL_STATIC_DRAW); // Set the size and data of our VBO and set it to STATIC_DRAW
	glEnableVertexAttribArray(SH_TEXTURECOORD);
	glVertexAttribPointer(SH_TEXTURECOORD, 2, GL_FLOAT, GL_FALSE, 0, 0); // Set up our vertex attributes pointer


	glEnableVertexAttribArray(0); // Disable our Vertex Array Object
	glBindVertexArray(0); // Disable our Vertex Buffer Object*/
}


void FontGlyph::draw()
{
	glBindVertexArray(vaoID); // Bind our Vertex Array Object
	glDrawArrays(GL_TRIANGLES, 0, 6); // Draw our square
	glBindVertexArray(0); // Unbind our Vertex Array Object
}
