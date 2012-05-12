/*
 * Audio.h
 *
 *  Created on: Feb 22, 2011
 *      Author: raphael
 */

#ifndef AUDIO_H_
#define AUDIO_H_

#include <bass.h>

enum AudioState {asPlaying, asPaused, asStopped};


class Audio {
private:
    AudioState state;
	const char* filename;
	HSTREAM handle;

public:

	Audio();
	Audio(const char* filename);
	void init();
	void play();
	void pause();
	void stop();

	float* getBuffer();
	//float[1024] getfftBuffer();
	virtual ~Audio();
    const char * getFilename() const;
    void setFilename(const char *filename);
    AudioState getState();
    float getFreq();
    float getPeak();
};

#endif /* AUDIO_H_ */
