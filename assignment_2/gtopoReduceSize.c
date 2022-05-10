/*FILENAME: pgmReduceSize.c
 *FUNCTIONS: reduceSize
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//downize the image data in file by factor factor
short** reduceSize(short** file, int oldwidth, int oldheight, int factor){
	//work out the new width and length
	int width = 1+(oldwidth / factor);
	int height = 1+(oldheight / factor);
	//initialise the new width
	short** newFile = (short**) malloc(sizeof(short*) * height);
	for(int i=0; i<height; i++){
		newFile[i] = (short*) malloc(sizeof(short) * width);
	}
	int pixelIndexi = 0;
	int pixelIndexj = 0;
	//go through the image data
	for(int i=0; i<oldheight; i++){
		if((i)%factor == 0){
			pixelIndexj = 0;
			for(int j=0; j<oldwidth; j++){
			
				//write the image data to the new image data
				//if its data we want.
				if((j)%factor == 0){
					newFile[pixelIndexi][pixelIndexj++] = file[i][j];
				}
			}
			pixelIndexi++;
		}
	}
	return newFile;
}
