/*FILENAME: pgmReduceSize.c
 *FUNCTIONS: reduceSize
 */
#include <stdio.h>
#include <stdlib.h>
#include "pgmReduceSize.h"
//downize the image data in file by factor factor
float** reduceSize(float** file, int oldwidth, int oldheight, int factor){
	//work out the new width and length
	int width = 1+oldwidth / factor;
	int height = 1+oldheight / factor ;
	//initialise the new width
	float** newFile = (float**) malloc(sizeof(float) * height);
	for(int i=0; i<height; i++){
		newFile[i] = (float*) malloc(sizeof(float) * width);
	}
	int pixelIndexi = 0;
	int pixelIndexj = 0;
	//go through the image data
	for(int i=0; i<oldheight; i++){
		if((i)%factor == 0){
			pixelIndexi++;
			for(int j=0; j<oldwidth; j++){
			
				//write the image data to the new image data
				//if its data we want.
				if((j)%factor == 0){
					newFile[pixelIndexi][pixelIndexj++] = file[i][j];
				}
			}
		}
	}
	return newFile;
}
