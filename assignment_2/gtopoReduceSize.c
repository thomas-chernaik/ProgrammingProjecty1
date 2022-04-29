/*FILENAME: gtopoReduceSize.c
 *FUNCTIONS: reduceSize
 */
#include <stdio.h>
#include <stdlib.h>
#include "gtopoReduceSize.h"
//downize the image data in file by factor factor
short* reduceSize(short* file, int oldwidth, int oldheight, int factor){
	//work out the new width and length
	int width = 1+oldwidth / factor;
	int height = 1+oldheight / factor ;
	//initialise the new width
	short* newFile = malloc(sizeof(short) * width * height);
	int pixelIndex = 0;
	//go through the image data
	for(int i=0; i<oldheight; i++){
		if((i)%factor == 0){
			for(int j=0; j<oldwidth; j++){
				//write the image data to the new image data
				//if its data we want.
				if((j)%factor == 0){
					newFile[pixelIndex++] = file[i*oldwidth+j];
				}
			}
		}
	}
	return newFile;
}
