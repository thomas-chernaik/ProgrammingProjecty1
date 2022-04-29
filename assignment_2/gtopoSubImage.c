/*FILENAME: gtopoSubImage.c
 *FUNCTIONS:
 *	subImage
 */
#include <stdio.h>
#include <stdlib.h>
#include "gtopoSubImage.h"

//take in an array of image data and output the image data between the values specified by the parameters
short* subImage(short* file, int startCol, int endCol, int startRow, int endRow, int width){
	short* fileOut = (short*) malloc(sizeof(short) * (endRow - startRow) * (endCol - startCol));
	if(!file){
		printf("ERROR: Image Malloc Failed\n");
		exit(7);
	}
	int count = 0;
	//go through the pixels between start and end row and col
	//and put them into the out file
	for(int i=startRow; i < endRow; i++){
		for(int j= startCol; j < endCol; j++){
			fileOut[count++] = file[i*width+j];
		}
	}
	return fileOut;
}
