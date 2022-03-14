#include <stdio.h>
#include <stdlib.h>
#include "pgmEmpty.h"


float* createEmpty(int width, int height){
	float* file = (float*) malloc(width*height*sizeof(float));
	if(!file){
		printf("ERROR: Image Malloc Failed\n");
		exit(7);
	}
	return file;
}
