/*FILENAME: pgmRead.c
 *FUNCTIONS:
 *	readFile
 *	skipComment
 */

#include <stdio.h>
#include <stdlib.h>
#include "pgmRead.h"

FILE* otherRead = NULL;
unsigned char** otherIm = NULL;
//read in the file filename with the provided header data to a unsigned char array
unsigned char** readFile(FILE* file, char* filename, int width, int height){
	//initialise and malloc our needed variables
	//creating an array of pointers to a unsigned char
	//1. allocate memory for the data
	//1a. compute how much memory we need for the image data
	int memoryNeeded = height*width*sizeof(unsigned char);
	//1b. call malloc to allocate it
	//1c. store it somewhere.
	unsigned char* imageData = (unsigned char*) malloc(memoryNeeded);
	//1d. check whether it didn't work
	if(imageData == NULL)
		{
		fclose(file);
		if(otherIm != NULL)
			{
			free(otherIm[0]);
			free(otherIm);
			}
		if(otherRead != NULL)
			fclose(otherRead);
		printf("ERROR: Image Malloc Failed\n");
                exit(7);
		}

	//2. allocate memory for the row pointers
	//2a. compute memory we need for malloc
	memoryNeeded = height*sizeof(unsigned char*);
	//2b. call malloc to allocate them
	unsigned char** rowsOfImageData = (unsigned char**) malloc(memoryNeeded);
	//2c. store them somewhere
	//2d. check it worked
	if(rowsOfImageData == NULL)
		{
			fclose(file);
			if(otherIm != NULL)
				{
				free(otherIm[0]);
				free(otherIm);
				}
			if(otherRead != NULL)
	                        fclose(otherRead);

			printf("ERROR: Image Malloc Failed\n");
	                exit(7);
		}
	//3. set each row pointer to point to the correct place in the data
	//3a. loop through the rows(height)
	for(int i=0; i<height; i++)
		{
		
		//3b. compute the location of this row in the base data.
		unsigned char* location = &imageData[i*width];
		//3c. store it in the correct row pointer.
		rowsOfImageData[i] = location;
		}
	//read out each pixel
	//loop through each row and column
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			//read the data for this pixel
			int scanCount = fscanf(file, "%hhu", &rowsOfImageData[i][j]);
			//check stuff was read
			if((rowsOfImageData[i][j] == EOF || scanCount != 1) || (rowsOfImageData[i][j] < 0) || (rowsOfImageData[i][j] > 255)){
				free(rowsOfImageData);
				fclose(file);
				if(otherIm != NULL)
					{
					free(otherIm[0]);
					free(otherIm);
					}	
				if(otherRead != NULL)
		                        fclose(otherRead);
				printf("ERROR: Bad Data (%s)", filename);
				exit(8);
			}
		}
	}
	//check we are at the end of the file
	int* c = malloc(sizeof(int));
	//scan out any whitespace at the end of the file
	fscanf(file, " ");
	//get next character
	*c = getc(file);
	//check we are at the EOF character
	if(*c != EOF){
		free(rowsOfImageData);
                fclose(file);
		free(c);
		if(otherIm != NULL)
			{
			free(otherIm[0]);
			free(otherIm);
			}
		if(otherRead != NULL)
                        fclose(otherRead);
                printf("ERROR: Bad Data (%s)", filename);
                exit(8);
	}
	free(c);
	fclose(file);
	return rowsOfImageData;
}
