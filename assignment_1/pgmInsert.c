/*FILEAME: pgmInsert.c
 *FUNCTIONS:
 *	insert
 */
#include <stdio.h>
#include <stdlib.h>
#include "pgmInsert.h"
//takes an image and an image to Insert and a start row and column and inserts the image.
void insert(float* imageToAdd, float* image, int row, int column, int width, int height, int insertHeight, int insertWidth){
	//goes through the image where the image needs to be inserted
	int count=0;
	for(int i=row; i < row+insertHeight; i++){
		for(int j=column; j < column + insertWidth; j++){
			image[i*width+j] = imageToAdd[count++];
		}
	}
}
