/*FILENAME: pgmb2a.c
 *DESCRIPTION:
 *	converts a pgmbinary file to a 
 *	pgmAscii file.
 */

#include <stdio.h>
#include <stdlib.h>
#include "pgmHeaders.h"
#include "pgmReadBinary.h"
#include "pgmWrite.h"
int main(int argc, char **argv){
	//validate the argument count
	if(argc == 1){
		printf("Usage: ./pgmb2a inputImage.pgm outputImage.pgm\n");
                return 0;
        }
        if(argc != 3){
                printf("ERROR: Bad Argument Count\n");
                return 1;
        }
        int* headers;
	//headers[0] is width, [1] is height, [2] is maxGrey [3] is magic num
		headers = getHeaders(argv[1]);
	//check is binary
	if(headers[3] != 5){
		printf("ERROR: Bad File Name (%s)\n", argv[1]);
                return 2;
        }
	//read in the pgm binary file
	float* file = readFileBin(argv[1], headers[0], headers[1], headers[2]);
	//write out the file data to a pgm ascii file
	writeFile(argv[2], file, headers[0], headers[1], headers[2]);
        free(file);
        free(headers);
        printf("CONVERTED\n");
        return 0;
}
