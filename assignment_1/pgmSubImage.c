/*FILENAME: pgmSubImage.c
 *FUNCTIONS:
 *	subImage
 */
#include <stdio.h>
#include <stdlib.h>
#include "pgmSubImage.h"

//take in an array of image data and output the image data between the values specified by the parameters
unsigned char** subImage(unsigned char** file, int startCol, int endCol, int startRow, int endRow, int width){
	unsigned char** fileOut = (unsigned char**) malloc(sizeof(unsigned char) * (endCol - startCol));
	for(int i=0; i<endCol-startCol; i++){
		fileOut[i] = (unsigned char*) malloc(sizeof(unsigned char) * (endRow-startRow));
	}
	if(!file){
		printf("ERROR: Image Malloc Failed\n");
		exit(7);
	}
	int counti=0;
	int countj=0;
	//go through the pixels between start and end row and col
	//and put them into the out file
	for(int i=startRow; i < endRow; i++){
		counti++;
		for(int j= startCol; j < endCol; j++){
			fileOut[counti][countj++] = file[i][j];
		}
	}
	return fileOut;
}
