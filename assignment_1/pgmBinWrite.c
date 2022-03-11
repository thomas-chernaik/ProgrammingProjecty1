#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pgmBinWrite.h"

void writeBin(char* filename, float* fileToWrite, int width, int height, int maxGrey){
	//open the file to write
	FILE *file;
	file = fopen(filename, "wb+");
	if(!file){
		printf("ERROR: Bad File Name (%s)\n", filename);
		exit(2);
	}
	//read headers into a string and then write string to file
	char* headers = malloc(sizeof(char)*9);
	sprintf(headers, "P5\n%d %d\n%d\n", width, height, maxGrey);
	fwrite(headers, sizeof(char), strlen(headers), file);
	free(headers);
	int numToPut;
	char bytes[2];
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			//we need to do the +0.5f and round down to avoid any floating point errors
			numToPut = (int) (fileToWrite[i*width+j] * maxGrey) + 0.5f;
			bytes[0] = numToPut/256;
			bytes[1] = numToPut%256;
			if(maxGrey > 255){
				fwrite(&bytes[0], sizeof(char), 1, file);
			}
			fwrite(&bytes[1], sizeof(char), 1, file);
		}
	}	
}
