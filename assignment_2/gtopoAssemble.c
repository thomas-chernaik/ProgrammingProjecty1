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
#include "gtopoRead.h"
#include "gtopoWrite.h"
#include "gtopoEmpty.h"
#include "gtopoInsert.h"

int main(int argc, char **argv){
	//validate the number of arguments
	if(argc == 1){
		printf("Usage: ./gtopoAssemble outputFile width height (row column inputFile width height)+\n");
		return 0;
	}
	if((argc-3) % 5 != 0){
		printf("ERROR: Bad Argument Count\n");
		return 1;
	}
	//put the command line args into variables for formatting
	//convert the width and height to ints from strings
	int width = atoi(argv[2]);
	int height = atoi(argv[3]);
	//set default values for maxGrey and type
	int maxGrey = 255;
	//set a pointer to the filename with a readable name
	char* filename = argv[1];
	//create the image to paste the other images onto
	short** imageData = createEmpty(width, height);
	//now we have to loop through all the different images to put on it
	for(int i=3; i < (argc-3)/5; i++){
		//get the row number and header number from the argv
		int row = atoi(argv[i*5+1]);
		int col = atoi(argv[i*5+2]);
		//get the format string from the argv
		char* fileNamei = argv[i*5+3];
		int imWidth = argv[i*5+4];
		int imHeight = argv[i*5+5];
		//open the file
		short** fileToInsert;
		//open the file
		FILE* file = openFile(fileNamei);
		//read the file in
		//if ascii read as ascii
		fileToInsert = readFile(file, fileNamei, imWidth, imHeight);
		//add the file data to the big file in the right place
		insert(fileToInsert, imageData, row, col, width, height, headers[0], headers[1]);
		//free memory
		free(headers);
		free(fileToInsert[0]);
		free(fileToInsert);
		free(fileNamei);
	}
	//write out the big file
	writeFile(filename, imageData, width, height, maxGrey);
	//free the image data row by row
	for(int i=0; i<height; i++)
		{
		free(imageData[i]);
		}
	free(imageData);
	printf("ASSEMBLED\n");
	return 0;
}
