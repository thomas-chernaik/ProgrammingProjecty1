/*FILEAME: gtopoInsert.c
 *FUNCTIONS:
 *	insert
 *	assemble
 */
#include <stdio.h>
#include <stdlib.h>
#include "gtopoInsert.h"
#include "gtopoRead.h"
#include "gtopoEmpty.h"
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
short** assemble(int width, int height, char** argv, int argc, int offset)
        {
        //create the image to paste the other images onto
        short** imageData = createEmpty(width, height);
        //now we have to loop through all the different images to put on it
        for(int i=offset; i < (argc - offset)/5; i++)
                {
                //get the row number and header number from the argv
                int row = atoi(argv[i*5+1]);
                int col = atoi(argv[i*5+2]);
                //get the format string from the argv
                char* fileNamei = argv[i*5+3];
                int imWidth = atoi(argv[i*5+4]);
                int imHeight = atoi(argv[i*5+5]);
                short** fileToInsert;
                fileToInsert = readFile(fileNamei, imWidth, imHeight);
                //add the file data to the big file in the right place
                insert(fileToInsert, imageData, row, col, width, height, width, height);
                //free memory
                free(fileToInsert[0]);
                free(fileToInsert);
                free(fileNamei);
                }
        return imageData;
        }

