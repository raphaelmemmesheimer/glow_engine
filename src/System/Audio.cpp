/*
 * Audio.cpp
 *
 *  Created on: Feb 22, 2011
 *      Author: raphael
 */

#include "Audio.h"
#include <stdio.h>
#include "../System/Messages.h"
#include <stdlib.h>

const char* ModulNameA = "Audio";

Audio::Audio() {
	// TODO Auto-generated constructor stub

}

void Audio::pause()
{
	if(BASS_ChannelPause(this->handle))
		this->state = asPaused;
	msg(ModulNameA,"Pause");
}

void Audio::stop()
{
	//BASS_Stop();
	if(BASS_ChannelStop(this->handle))
		this->state = asStopped;
	//BASS_ChannelSetPosition();
	msg(ModulNameA,"Stop");
}

void Audio::play()
{
	if(BASS_ChannelPlay(this->handle,false))
		this->state = asPlaying;
	msg(ModulNameA,"Play");

//	else
//	{
//		printf("%s","[ERROR]: Audio Engine, Can't open stream");
//	}
}

Audio::Audio(const char *filename)
{
	this->filename = filename;
	// check the correct BASS was loaded
	if (HIWORD(BASS_GetVersion())!=BASSVERSION) {
		printf("An incorrect version of BASS was loaded");
		//return 0;
	}

	// initialize default output device
	if (!BASS_Init(-1,44100,0,0,0)) {
		printf("Can't initialize device");
		//return 0;
	}

	init();
}

const char* Audio::getFilename() const
{
    return this->filename;
}

void Audio::setFilename(const char* filename)
{
    this->filename = filename;
}

Audio::~Audio() {
	BASS_Stop();
	BASS_Free();
}

float* Audio::getBuffer()
{
	float *buffer;
	BASS_CHANNELINFO channelInfo;
	BASS_ChannelGetInfo(handle,&channelInfo);
	int size = channelInfo.chans*1024*sizeof(float);
	buffer = (float*) malloc(size);
	BASS_ChannelGetData(handle,buffer,size|BASS_DATA_FLOAT);
	return buffer;
}

AudioState Audio::getState()
{
	return this->state;
}

void Audio::init()
{
	if (this->handle = BASS_StreamCreateFile(FALSE,this->filename,0,0,0))
	{

	}
	else
	{
		printf("%s","[ERROR]: Audio Engine, Can't open stream");
	}
}

float Audio::getFreq(){
	return BASS_ChannelGetLevel(this->handle);
}

float Audio::getPeak(){
	return BASS_ChannelGetLevel(this->handle)/1000000000.0;
}


