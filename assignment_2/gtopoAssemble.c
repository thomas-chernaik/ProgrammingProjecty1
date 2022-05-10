/*FILENAME: pgmAssemble.c
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
#include "pgmHeaders.h"
#include "pgmRead.h"
#include "pgmWrite.h"
#include "pgmReadBinary.h"
#include "pgmBinWrite.h"
#include "pgmEmpty.h"
#include "pgmInsert.h"

int main(int argc, char **argv){
	//validate the number of arguments
	if(argc == 1){
		printf("Usage: ./pgmAssemble outputImage.pgm width height (row column inputImage.pgm)+\n");
		return 0;
	}
	if((argc-1) % 3 != 0){
		printf("ERROR: Bad Argument Count\n");
		return 1;
	}
	//put the command line args into variables for formatting
	//convert the width and height to ints from strings
	int width = atoi(argv[2]);
	int height = atoi(argv[3]);
	//set default values for maxGrey and type
	int maxGrey = 255;
	int type = 2;
	//set a pointer to the filename with a readable name
	char* filename = argv[1];
	//create the image to paste the other images onto
	short** imageData = createEmpty(width, height);
	//now we have to loop through all the different images to put on it
	for(int i=1; i < (argc-1)/3; i++){
		//get the row number and header number from the argv
		int row = atoi(argv[i*3+1]);
		int col = atoi(argv[i*3+2]);
		//get the format string from the argv
		char* fileNamei = argv[i*3+3];
		//open the file
		//init headers and fileToInsert
		int* headers;
		short** fileToInsert;
		//open the file
		FILE* file = openFile(fileNamei);
		//get the headers for the file
		headers = getHeaders(fileNamei, file);
		//store the type of this file in type
		type = headers[3];
		//read the file in
		//if ascii read as ascii
		if(headers[3] == 2){
			fileToInsert = readFile(file, fileNamei, headers[0], headers[1]);
		}
		//otherwise read as bin
		else{
			fileToInsert = readFileBin(file, fileNamei, headers[0], headers[1]);
		}
		//add the file data to the big file in the right place
		insert(fileToInsert, imageData, row, col, width, height, headers[0], headers[1]);
		//free memory
		free(headers);
		free(fileToInsert[0]);
		free(fileToInsert);
	}
	//write out the big file
	//if the last type was ascii write as ascii
	if(type == 2){
		writeFile(filename, imageData, width, height, maxGrey);
	}
	//otherwise write as bin
	else{
		writeBin(filename, imageData, width, height, maxGrey);
	}
	//free the image data row by row
	for(int i=0; i<height; i++)
		{
		free(imageData[i]);
		}
	free(imageData);
	printf("ASSEMBLED\n");
	return 0;
}
