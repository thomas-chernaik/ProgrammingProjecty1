#include <stdio.h>
#include <stdlib.h>
#include "pgmEmpty.h"


float* createEmpty(int width, int height){
	float* file = (float*) malloc(width*height*sizeof(float));
	return file;
}
