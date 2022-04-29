/*FILENAME: gtopoRead.c
 * FUNCTIONS:
 * 	readFile
 * DESCRIPTION:
 * 	Read in a file to an int array.
 */

#include <stdio.h>
#include <stdlib.h>
#include "gtopoRead.h"

unsigned short* readFile(char* filename, int width, int height){
	//init and malloc needed variables
	FILE *file;
	unsigned short* fileToReturn  = (unsigned short*) malloc(width*height*sizeof(unsigned short));
	if(!fileToReturn){
		printf("ERROR: Image Malloc Failed\n");
		exit(7);
	}
	file = fopen(filename, "rb");
	//check the file opened correctly
	if (file == NULL){
		printf("ERROR: Bad File Name (%s)\n", filename);
		exit(2);
	}
	//read in the data from the file
	for(int i=0; i<width*height; i++){
		fileToReturn[i] = readInt(file);
	}
	int c = getc(file);
	fclose(file);
	if(c != EOF){
		free(fileToReturn);
		printf("ERROR: Bad Data (%s)\n", filename);
                exit(8);
	}

}

unsigned short readInt(FILE* file){
	unsigned char* chr1 = malloc(sizeof(char)*2);
	int scanCount = fread(chr1, 2,1,file);
	if(scanCount != 2){
		free(chr1);
		fclose(file);
		printf("ERROR: Bad Data (%s)\n", filename);
                exit(8);
	}
	unsigned short returnNum = chr1[0] << 8 | chr1[1];
	return returnNum;
}

