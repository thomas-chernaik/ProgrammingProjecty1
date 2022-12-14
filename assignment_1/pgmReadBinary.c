/*FILENAME: pgmReadBinary.c
 *FUNCTIONS: 
 *	readFileBin
 *	readUntilWhitespace
 *	readThroughWhitespace
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pgmReadBinary.h"
FILE* otherReadB = NULL;
unsigned char** otherImB = NULL;
//read in a binary pgm file into an array of unsigned chars
unsigned char** readFileBin(FILE* file, char* filename, int width, int height){
	//initialise and malloc our needed variables
	//creating an array of pointers to a unsigned char
	//1. allocate memory for the data
	//1a. compute how much memory we need for the image data
	int memoryNeeded = height*width*sizeof(unsigned char);
	//1b. call malloc to allocate it
	//1c. store it somwhere
	unsigned char* imageData = (unsigned char*) malloc(memoryNeeded);
	//1d. check whether it worked
	if(imageData == NULL)
                {
		fclose(file);
		if(otherImB != NULL)
			{
			free(otherImB[0]);
			free(otherImB);
			}
		if(otherReadB != NULL)
			fclose(otherReadB);
                printf("ERROR: Image Malloc Failed\n");
                exit(7);
                }
	//2.allocate memory for the row pointers
	//2a. compute memory we need for malloc
        memoryNeeded = height*sizeof(unsigned char*);
        //2b. call malloc to allocate them
        unsigned char** rowsOfImageData = (unsigned char**) malloc(memoryNeeded);
	//2c. store them somewhere
	//2d. check it worked
	if(rowsOfImageData == NULL)
                {
			fclose(file);
			if(otherImB != NULL)
				{
				free(otherImB[0]);
				free(otherImB);
			}
			if(otherReadB != NULL)
	                        fclose(otherReadB);
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
	//loop through each row and column.
	for(int i=0; i<height; i++){
                for(int j=0; j<width; j++){
                        //read the data for this pixel
                        int scanCount = fread(&rowsOfImageData[i][j], sizeof(char), 1, file);
                     	//check stuff was read
                     	if((rowsOfImageData[i][j] == EOF || scanCount != 1) || (rowsOfImageData[i][j] < 0) || (rowsOfImageData[i][j] > 255)){
                                free(rowsOfImageData);
                                fclose(file);
				if(otherImB != NULL)
					{
					free(otherImB[0]);
					free(otherImB);
					}
				if(otherReadB != NULL)
        		                fclose(otherReadB);
                                printf("ERROR: Bad Data (%s)", filename);
                                exit(8);
                        }
                }
        }
        //check we are at the end of the file
	int* c = malloc(sizeof(int));
        //scan out any whitespace at the end of the file
	fscanf(file, " ");
        //check we are at the EOF character
	*c = getc(file);
        if(*c != EOF){
                free(rowsOfImageData);
		if(otherImB != NULL)
			{
			free(otherImB[0]);
			free(otherImB);
			}
                fclose(file);
		if(otherReadB != NULL)
                        fclose(otherReadB);
                printf("ERROR: Bad Data (%s)", filename);
                exit(8);
        }
	free(c);
        fclose(file);
        return rowsOfImageData;
}
