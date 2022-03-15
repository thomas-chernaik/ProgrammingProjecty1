/*FILENAME: pgmSubImage.c
 *FUNCTIONS:
 *	subImage
 */
#include <stdio.h>
#include <stdlib.h>
#include "pgmSubImage.h"

//take in an array of image data and output the image data between the values specified by the parameters
float* subImage(float* file, int startCol, int endCol, int startRow, int endRow, int width){
	float* fileOut = (float*) malloc(sizeof(float) * (endRow - startRow) * (endCol - startCol));
	if(!file){
		printf("ERROR: Image Malloc Failed\n");
		exit(7);
	}
	int count = 0;
	//go through the pixels between start and end row and col
	//and put them into the out file
	for(int i=startCol; i < endCol; i++){
		for(int j= startRow; j < endRow; j++){
			fileOut[count++] = file[j*width+i];
		}
	}
	return fileOut;
}
