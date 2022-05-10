/*FILEAME: pgmInsert.c
 *FUNCTIONS:
 *	insert
 */
#include <stdio.h>
#include <stdlib.h>
#include "pgmInsert.h"
//takes an image and an image to Insert and a start row and column and inserts the image.
void insert(short** imageToAdd, short** image, int row, int column, int width, int height, int insertHeight, int insertWidth){
	//goes through the image where the image needs to be inserted
	for(int i=row; i < row+insertHeight; i++){
		for(int j=column; j < column + insertWidth; j++){
			//insert the data at [i-row][j-column](this will be every pixel in imageToAdd) into image[i][j] (this will be only the pixels in image that need the image adding to them)
			image[i][j] = imageToAdd[i-row][j-column];
		}
	}
}
