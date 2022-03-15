/*FILENAME: pgmReduceSize.c
 *FUNCTIONS: reduceSize
 */
#include <stdio.h>
#include <stdlib.h>
#include "pgmReduceSize.h"
//downize the image data in file by factor factor
float* reduceSize(float* file, int oldwidth, int oldheight, int factor){
	//work out the new width and length
	int width = oldwidth / factor;
	int height = oldheight / factor;
	//initialise the new width
	float* newFile = malloc(sizeof(float) * width * height);
	int pixelIndex = 0;
	//go through the image data
	for(int i=0; i<oldwidth; i++){
		if((i)%factor == 0){
			for(int j=0; j<oldheight; j++){
				//write the image data to the new image data
				//if its data we want.
				if((j)%factor == 0){
					newFile[pixelIndex++] = file[j*width+i];
				}
			}
		}
	}
	return newFile;
}
