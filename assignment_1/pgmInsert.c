#include <stdio.h>
#include <stdlib.h>
#include "pgmInsert.h"

void insert(float* imageToAdd, float* image, int row, int column, int width, int height, int insertHeight, int insertWidth){
	for(int i=row; i < row+insertHeight; i++){
		for(int j=column; j < column + insertWidth; j++){
			image[i*width+j] = imageToAdd[(i-row)*insertWidth + j - column];
		}
	}
}
