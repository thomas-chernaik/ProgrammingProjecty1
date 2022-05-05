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
	int width = atoi(argv[2]);
	int height = atoi(argv[3]);
	int maxGrey = 255;
	int type = 2;
	char* filename = argv[1];
	//create the image to paste the other images onto
	float** file = createEmpty(width, height);
	//now we have to loop through all the different images to put on it
	for(int i=1; i < (argc-1)/3; i++){
		int row = atoi(argv[i*3+1]);
		int col = atoi(argv[i*3+2]);
		char* fileNamei = argv[i*3+3];
		//open the file
		int* headers;
		//assigne the maxGrey and type variables
		maxGrey = headers[2];
		type = headers[3];
		float** fileToInsert;
		headers = getHeaders(fileNamei);
		//read the file in
		if(headers[3] == 2){
			fileToInsert = readFile(fileNamei, headers[0], headers[1], headers[2]);
		}
		else{
			fileToInsert = readFileBin(fileNamei, headers[0], headers[1], headers[2]);
		}
		//add the file data to the big file in the right place
		insert(fileToInsert, file, row, col, width, height, headers[0], headers[1]);
		free(headers);
		free(fileToInsert);
	}
	//write out the big file
	if(type == 2){
		writeFile(filename, file, width, height, maxGrey);
	}
	else{
		writeBin(filename, file, width, height, maxGrey);
	}
	free(file);
	printf("ASSEMBLED\n");
	return 0;
}
