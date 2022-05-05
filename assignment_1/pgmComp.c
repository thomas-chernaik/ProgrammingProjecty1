/*FILENAME: pgmComp.c
 *DESCRIPTION:
 *	take in two file names and output if they are 
 *	logically identical
 */
#include <stdlib.h>
#include "pgmHeaders.h"
#include "pgmRead.h"
#include "pgmReadBinary.h"
#include "pgmCompare.h"

int main(int argc, char **argv){
	//validate argument count
	if(argc == 1){
                printf("Usage: ./pgmComp inputImage.pgm inputImage.pgm\n");
                return 0;
        }
        if(argc != 3){
                printf("ERROR: Bad Argument Count\n");
                return 1;
        }
	FILE* file1 = openFile(argv[1]);
	FILE* file2 = openFile(argv[2]);
	int* headers1;
	int* headers2;
	headers1 = getHeaders(argv[1], file1);
	headers2 = getHeaders(argv[2], file2);
	//check headers match
	int result;
	result = compareHeaders(headers1, headers2);
	if(!result){
		free(headers1);
		free(headers2);
		printf("DIFFERENT\n");
		return 0;
	}
	unsigned char** imageData1;
	unsigned char** imageData2;
	//read in the file data of both files
	if(headers1[3] == 2){
		imageData1 = readFile(file1, argv[1], headers1[0], headers1[1]);
	}
	else{
		imageData1 = readFileBin(file1, argv[1], headers1[0], headers1[1]);
	}
	if(headers2[3] == 2){
                imageData2 = readFile(file2, argv[2], headers2[0], headers2[1]);
        }
        else{
                imageData2 = readFileBin(file2, argv[2], headers2[0], headers2[1]);
        }
	//compare contents of the files 
	result = compareContents(imageData1, imageData2, headers2[0], headers2[1]);
	free(imageData1);
	free(imageData2);
	free(headers1);
	free(headers2);
	if(!result){
		printf("DIFFERENT\n");
		return 0;
	}
	printf("IDENTICAL\n");
	return 0;
}
