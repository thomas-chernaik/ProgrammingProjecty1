/*FILENAME: pgmEmpty.c
 *FUNCTIONS:
 *	createEmpty
 */

#include <stdio.h>
#include <stdlib.h>
#include "pgmEmpty.h"

//create an array to be used for image data of length width*height
short** createEmpty(int width, int height){
	//create an array of pointers
	short** file = (short**) malloc(height*sizeof(short*));
	//make these pointers point at something
	//go through each pointer
	for(int i=0; i<height; i++)
		{
		//point it to some allocated memory
		file[i] = (short*) malloc(width*sizeof(short));
		}
	if(file == NULL){
		printf("ERROR: Image Malloc Failed\n");
		exit(7);
	}
	return file;
}
