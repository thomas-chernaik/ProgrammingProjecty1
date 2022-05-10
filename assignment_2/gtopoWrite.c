/*FILNAME: gtopoWrite.c
 *DESCRIPTION:
 *	take an array of unsigned shorts and write them to a dem file
 */
#include <stdio.h>
#include <stdlib.h>
#include "gtopoWrite.h"

void writeFile(char* filename, short** fileToWrite, int width, int height){
	//open the file to write
	FILE *file;
	file = fopen(filename, "wb+");
	//check file opened successfully
	if(!file){
		printf("ERROR: Output Failed (%s)\n", filename);
		exit(9);
	}
	unsigned char bytes[2];
	//go through each int one by one and write it
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			//we need to make sure we write the values in big endian
			bytes[0] = (unsigned char) (fileToWrite[i][j] >> 8);
			bytes[1] = (unsigned char) fileToWrite[i][j] & 255;
			fwrite(&bytes[0], sizeof(unsigned char), 1, file);
			fwrite(&bytes[1], sizeof(unsigned char), 1, file);
		}
	}
}


