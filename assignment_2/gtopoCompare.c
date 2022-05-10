/*FILENAME: pgmCompare.c
 *FUNCTIONS:
 *	compareContents
 *	compareHeaders
 */

#include <stdio.h>
#include <stdlib.h>
#include "pgmCompare.h"

//compares two short arrays of length widthlength and checks they are identical
int compareContents(short** file1, short** file2, int width, int height){
	//go through each pixel by width and height
	for(int i=0; i<width; i++){
		for(int j=0; j<height; j++){
			//check if the corresponding pixels from the two files match
			if(file1[j][i] != file2[j][i]){
				return 0;
			}
		}
	}
	return 1;

}
//compares two int arrays and checks the first 3 values are the same
int compareHeaders(int* headers1, int* headers2){
	return headers1[1] == headers2[1] && headers1[2] == headers2[2] && headers1[0] == headers2[0];
}
