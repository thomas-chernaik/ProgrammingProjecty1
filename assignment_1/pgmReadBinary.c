#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pgmReadBinary.h"


float* readFileBin(char* filename, int width, int height, int maxGrey){
	int numBytesPerValue;//this is 1 if maxGrey is less than 256 otherwise is 2
	if (maxGrey >= 256){
		numBytesPerValue = 2;
	}
	else{
		numBytesPerValue = 1;
	}
	FILE* file;
	file = fopen(filename, "rb");
	//check file opened
	if(!file){
		printf("ERROR: Bad File Name (%s)", filename);
		exit(2);
	}
	//we want to read through the headers until we reach the raster.
	//in order to do this we need to read through some characters followed by whitespace 4 times.
	//read through magic num
	readUntilWhitespace(file);
	readThroughWhitespace(file);
	//read through width
	readUntilWhitespace(file);
	readThroughWhitespace(file);
	//read through height
	readUntilWhitespace(file);
	readThroughWhitespace(file);
	//read though maxGrey
	readUntilWhitespace(file);
	readThroughWhitespace(file);
	//we are now at the raster values and need to read them in.
	float* fileToReturn = (float*) malloc(width*height*sizeof(int));
	int* listOfInts = (int*) malloc(width*height*sizeof(int));
	char* chr1 = malloc(sizeof(char));
	char* chr2 = malloc(sizeof(char));
	if(!fileToReturn || !listOfInts || !chr1 || !chr2){
		printf("ERROR: Image Malloc Failed");
		exit(7);
	}
	*chr1 = 0;
	for(int i=0; i<width*height; i++){
		if(numBytesPerValue==2){
			fread(chr1, sizeof(char), 1, file);
		}
		fread(chr2, sizeof(char), 1, file);
		//convert the bytes to an int
		listOfInts[i] = bytesToInt(*chr1, *chr2);
		//normalise and store in variable
		fileToReturn[i] = (float) listOfInts[i] / (float) maxGrey;
	}
	free(chr1);
	free(chr2);
	free(listOfInts);
	fclose(file);
	return fileToReturn;
		
}

void readUntilWhitespace(FILE *file){
	//read until isspace is true then back up one
	char* chr = malloc(sizeof(char));
	//check if its a comment
	if(*chr == '#'){
		readThroughWhitespace(file);
		readUntilWhitespace(file);
	}

	do{
		fread(chr, sizeof(char), 1, file);
	} while(!isspace(*chr));
	free(chr);
	//back up one
	fseek(file, -1, SEEK_CUR);
}

void readThroughWhitespace(FILE *file){
	//read until isspace is not true then back up one
	char* chr = malloc(sizeof(char));
	do{
		fread(chr, sizeof(char), 1, file);
	} while(isspace(*chr));
	free(chr);
	//back up one
	fseek(file, -1, SEEK_CUR);
}

int bytesToInt(char byte1, char byte2){
	return 255 * (int) byte1 + byte2;
}
