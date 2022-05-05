/*FILENAME: pgmBinWrite.c
 *FUNCTIONS:
 *	writeBin
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pgmBinWrite.h"

//write file data and headers to a binary pgm file
void writeBin(char* filename, float** fileToWrite, int width, int height, int maxGrey){
	//open the file to write
	FILE *file;
	file = fopen(filename, "wb+");
	//check the file opened successfully
	if(!file){
		printf("ERROR: Output Failed (%s)\n", filename);
		exit(9);
	}
	//read headers into a string and then write string to file
	char* headers = malloc(sizeof(char)*9);
	sprintf(headers, "P5\n%d %d\n%d\n", width, height, maxGrey);
	fwrite(headers, sizeof(char), strlen(headers), file);
	int numToPut;
	char bytes[2];
	//go through each pixel data and write iet to the file
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			//we need to do the +0.5f and round down
			//to avoid any floating point errors
			numToPut = (int) (fileToWrite[i][j] * maxGrey) + 0.5f;
			bytes[0] = numToPut/256;
			bytes[1] = numToPut%256;
			if(maxGrey > 255){
				fwrite(&bytes[0], sizeof(char), 1, file);
			}
			fwrite(&bytes[1], sizeof(char), 1, file);
		}
	}
}
