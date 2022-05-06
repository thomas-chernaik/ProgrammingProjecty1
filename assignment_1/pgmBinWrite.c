/*FILENAME: pgmBinWrite.c
 *FUNCTIONS:
 *	writeBin
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pgmBinWrite.h"

//write file data and headers to a binary pgm file
void writeBin(char* filename, unsigned char** fileToWrite, int width, int height, int maxGrey){
	//open the file to write
	FILE *file;
	file = fopen(filename, "w+");
	//check the file opened successfully
	if(!file){
		printf("ERROR: Output Failed (%s)\n", filename);
		exit(9);
	}
	//read headers into a string and then write string to file
	char* headers = malloc(sizeof(char)*9);
	sprintf(headers, "P5\n%d %d\n%d\n", width, height, maxGrey);
	fwrite(headers, sizeof(char), strlen(headers), file);
	//go through each pixel data and write iet to the file
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			fwrite(&fileToWrite[i][j], sizeof(unsigned char), 1, file);
		}
	}
	free(headers);
	fclose(file);
}
