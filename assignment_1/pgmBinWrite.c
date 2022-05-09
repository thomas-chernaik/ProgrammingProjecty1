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
	//init headers and allocate memory
	char* headers = malloc(sizeof(char)*9);
	//write the header data into the header memory
	sprintf(headers, "P5\n%d %d\n%d\n", width, height, maxGrey);
	//write the header data to the file
	fwrite(headers, sizeof(char), strlen(headers), file);
	//go through each pixel data and write iet to the file
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			//write the pixel at [i][j] to the file
			fwrite(&fileToWrite[i][j], sizeof(unsigned char), 1, file);
		}
	}
	free(headers);
	fclose(file);
}
