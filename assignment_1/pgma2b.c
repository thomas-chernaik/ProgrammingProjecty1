/*FILENAME: pgma2b.c
 *DESCRIPTION:
 *	Convert a pgmascii file to a pgmbinary file
 */

#include <stdio.h>
#include <stdlib.h>
#include "pgmHeaders.h"
#include "pgmRead.h"
#include "pgmBinWrite.h"
int main(int argc, char **argv){
	//validate the argument numbers
        if(argc == 1){
                printf("Usage: ./pgma2b inputImage.pgm outputImage.pgm\n");
                return 0;
        }
        if(argc != 3){
                printf("ERROR: Bad Argument Count\n");
                return 1;
        }
	//init the headers pointer
        int* headers;
	//headers[0] is width, [1] is height, [2] is maxGrey [3] is magic num
	//open the file and point to it with file
	FILE* file = openFile(argv[1]);
	//get the headers and store them in the address of teh headers pointer
        headers = getHeaders(argv[1], file);
	//check is ascii
	if(headers[3] != 2){
		//free memory and close files
		fclose(file);
		free(headers);
		printf("ERROR: Bad Magic Number (%s)\n", argv[1]);
		return 3;
	}
	//read in the pgmascii file to an array
        unsigned char** imageData = readFile(file, argv[1], headers[0], headers[1]);
	//write out the array to a pgmbinary file
        writeBin(argv[2], imageData, headers[0], headers[1], headers[2]);
	//free memory
	free(imageData[0]);
	free(imageData);
	free(headers);
	printf("CONVERTED\n");
	return 0;
}
