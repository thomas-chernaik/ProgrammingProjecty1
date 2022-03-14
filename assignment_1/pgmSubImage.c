#include <stdio.h>
#include <stdlib.h>
#include "pgmSubImage.h"

float* subImage(float* file, int startRow, int endRow, int startCol, int endCol, int width){
	float* fileOut = (float*) malloc(sizeof(float) * (endRow - startRow) * (endCol - startCol));
	if(!file){
		printf("ERROR: Image Malloc Failed\n");
		exit(7);
	}
	int count = 0;
	for(int i=startCol; i < endCol; i++){
		for(int j= startRow; j < endRow; j++){
			fileOut[count++] = file[i*width+j];
		}
	}
	return fileOut;
}
