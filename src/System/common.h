/*
 * common.h
 *
 *  Created on: May 5, 2011
 *      Author: raphael
 */

#ifndef COMMON_H_
#define COMMON_H_

#include<iostream>
#include<fstream>
#include<cstring>
#include <stdio.h>

#include <stdlib.h>
#include <dirent.h>
#include <vector>

// Platform-dependent sleep routines.
#if defined(__WINDOWS_MM__)
  #include <windows.h>
  #define SLEEP( milliseconds ) Sleep( (DWORD) milliseconds )
#else // Unix variants
  #include <unistd.h>
  #define SLEEP( milliseconds ) usleep( (unsigned long) (milliseconds * 1000.0) )
#endif

static char* textFileRead(std::string fileName) {
    char* text;
    if (fileName.c_str() != NULL) {
        FILE *file = fopen(fileName.c_str(), "rt");

        if (file != NULL) {
            fseek(file, 0, SEEK_END);
            int count = ftell(file);
            rewind(file);

            if (count > 0) {
                text = (char*)calloc(count+1,sizeof(char));//(char*)malloc(sizeof(char) * (count + 1)); // the malloc routine has an error
                count = fread(text, sizeof(char), count, file);
                text[count] = ' ';
            }
            fclose(file);
        }
    }
    return text;
}

static bool textFileWrite(std::string fileName, std::string text) {
	if (fileName.c_str() != NULL) {
		FILE *file = fopen(fileName.c_str(), "w");
		if (file != NULL) {
			fputs(text.c_str(),file);
			fclose(file);
			return true;
		}
	}
	return false;
}

//source http://stackoverflow.com/questions/612097/how-can-i-get-a-list-of-files-in-a-directory-using-c-or-c
static std::vector<std::string> getFilesInDir(std::string dirName)
{

	std::vector<std::string> result;
	DIR *dir;
 	struct dirent *ent;
 	dir = opendir (dirName.c_str());
 	if (dir != NULL) {
 	  /* print all the files and directories within directory */
 	  while ((ent = readdir (dir)) != NULL) {
 		  result.push_back(ent->d_name);
 	  }
 	  closedir(dir);
 	} else {
 	  /* could not open directory */
 	  return result;
 	}
 	return result;
}

static float randFloat(){
	return (float)rand()/(float)RAND_MAX;
}



#endif /* COMMON_H_ */
