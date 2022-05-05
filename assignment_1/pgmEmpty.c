/*FILENAME: pgmEmpty.c
 *FUNCTIONS:
 *	createEmpty
 */

#include <stdio.h>
#include <stdlib.h>
#include "pgmEmpty.h"

//create an array to be used for image data of length width*height
unsigned char** createEmpty(int width, int height){
	unsigned char** file = (unsigned char**) malloc(width*height*sizeof(unsigned char));
	if(!file){
		printf("ERROR: Image Malloc Failed\n");
		exit(7);
	}
	return file;
}
