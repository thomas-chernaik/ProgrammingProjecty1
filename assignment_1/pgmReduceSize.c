#include <stdio.h>
#include <stdlib.h>
#include "pgmReduceSize.h"

float* reduceSize(float* file, int oldwidth, int oldheight, int factor){
	int width = oldwidth / factor;
	int height = oldheight / factor;
	float* newFile = malloc(sizeof(float) * width * height);
	int pixelIndex = 0;
	for(int i=0; i<oldwidth; i++){
		if((i+1)%factor == 0){
			for(int j=0; j<oldheight; j++){
				if((j+1)%factor == 0){
					newFile[pixelIndex++] = file[j*width+i];
				}
			}
		}
	}
	return newFile;
}
