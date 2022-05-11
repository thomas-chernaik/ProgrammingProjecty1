/*FILENAME: gtopoAssemble.c
 *DESCRIPTION:
 *	assemble
 *	a large image from smaller ones. It should take
 *	3n+3 arguments of which the first three are:
 *	1. an output file name
 *	2. width of the output image
 *	3. height of the output image
 *	and the remainder are the layout: triples of:
 *	3i+1. row at which the subimage starts
 *	3i+2. column at which the subimage starts
 *	3i+3. The subimage to insert at that location
 */ 
#include <stdio.h>
#include <stdlib.h>
#include "gtopoWrite.h"
#include "gtopoInsert.h"


int main(int argc, char **argv){
	//validate the number of arguments
	if(argc == 1){
		printf("Usage: ./gtopoAssemble outputFile width height (row column inputFile width height)+\n");
		return 0;
	}
	if((argc-4) % 5 != 0){
		printf("ERROR: Bad Argument Count\n");
		return 1;
	}
	//put the command line args into variables for formatting
	//convert the width and height to ints from strings
	int width = atoi(argv[2]);
	int height = atoi(argv[3]);
	//set a pointer to the filename with a readable name
	char* filename = argv[1];
	short** imageData = assemble(width, height, argv, argc, 4);
	//write out the big file
	writeFile(filename, imageData, width, height);
	//free the image data row by row
	for(int i=0; i<height; i++)
		{
		free(imageData[i]);
		}
	free(imageData);
	printf("ASSEMBLED\n");
	return 0;
}
