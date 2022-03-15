/*FILENAME: pgmReadBinary.c
 *FUNCTIONS: 
 *	readFileBin
 *	readUntilWhitespace
 *	readThroughWhitespace
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pgmReadBinary.h"

//read in a binary pgm file into an array of floats
float* readFileBin(char* filename, int width, int height, int maxGrey){
	int numBytesPerValue;//this is 1 if maxGrey is less than 256 otherwise is 2
	FILE* file;
	file = fopen(filename, "rb");
	//check file opened
	if(!file){
		printf("ERROR: Bad File Name (%s)\n", filename);
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
	float* fileToReturn = (float*) malloc(width*height*sizeof(float));
	unsigned int* listOfInts = (unsigned int*) malloc(width*height*sizeof(int));
	unsigned char* chr1 = malloc(sizeof(char));
	if(!fileToReturn || !listOfInts || !chr1){
		printf("ERROR: Image Malloc Failedi\n");
		exit(7);
	}
	//read in each byte of data
	for(int i=0; i<width*height; i++){
		int scanCount = fread(chr1, sizeof(char), 1, file);
		if(scanCount != 1){
			free(chr1);
			free(listOfInts);
			fclose(file);
			printf("ERROR: Bad Data (%s)\n", filename);
                        exit(8);
                }
			
		//convert the bytes to an int
		listOfInts[i] = bytesToInt(*chr1);

		if((listOfInts[i] < 0) || (listOfInts[i] > 255)){
			free(chr1);
                        free(listOfInts);
                        fclose(file);
                        printf("ERROR: Bad Data (%s)\n", filename);
                        exit(8);
		}
		//normalise and store in variable
		fileToReturn[i] = (float) listOfInts[i] / (float) maxGrey;
	}
	free(chr1);
	free(listOfInts);
	fclose(file);
	return fileToReturn;
		
}
//read through the file until it encounteres whitespace
void readUntilWhitespace(FILE *file){
	//read until isspace is true then back up one
	char* chr = malloc(sizeof(char));
	//check if its a comment
	if(*chr == '#'){
		readUntilNewline(file);
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
//read through the file until it encounters non whitespace 
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
//read through the file until it encounters a newline character
void readUntilNewline(FILE *file){
	char* chr = malloc(sizeof(char));
	do{
		fread(chr, sizeof(char), 1, file);
	} while(*chr != '\n');
	free(chr);
	//back up one
	fseek(file, -1, SEEK_CUR);
}
unsigned int bytesToInt(unsigned char byte1){
	return (unsigned int) byte1;
}
