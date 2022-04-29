/*FILENAME: gtopoEmpty.c
 *FUNCTIONS:
 *	createEmpty
 */

#include <stdio.h>
#include <stdlib.h>
#include "gtopoEmpty.h"

//create an array to be used for image data of length width*height
short* createEmpty(int width, int height){
	short* file = (short*) malloc(width*height*sizeof(short));
	if(!file){
		printf("ERROR: Image Malloc Failed\n");
		exit(7);
	}
	return file;
}
