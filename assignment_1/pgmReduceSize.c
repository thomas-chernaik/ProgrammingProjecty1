/*FILENAME: pgmReduceSize.c
 *FUNCTIONS: reduceSize
 */
#include <stdio.h>
#include <stdlib.h>
#include "pgmReduceSize.h"
//downize the image data in file by factor factor
unsigned char** reduceSize(unsigned char** file, int oldwidth, int oldheight, int factor){
	//work out the new width and length
	int width = 2+oldwidth / factor;
	int height = 2+oldheight / factor ;
	//initialise the new width
	unsigned char** newFile = (unsigned char**) malloc(sizeof(unsigned char*) * height);
	for(int i=0; i<height; i++){
		newFile[i] = (unsigned char*) malloc(sizeof(unsigned char) * width);
	}
	int pixelIndexi = 0;
	int pixelIndexj = 0;
	//go through the image data
	for(int i=0; i<oldheight; i++){
		if((i)%factor == 0){
			pixelIndexi++;
			pixelIndexj = 0;
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
