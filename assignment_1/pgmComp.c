#include <stdlib.h>
#include "pgmHeaders.h"
#include "pgmRead.h"
#include "pgmReadBinary.h"
#include "pgmCompare.h"

int main(int argc, char **argv){
	if(argc == 1){
                printf("Usage: ./pgmComp inputImage.pgm inputImage.pgm");
                return 0;
        }
        if(argc != 3){
                perror("ERROR: Bad Argument Count");
                return 1;
        }
	int* headers1;
	int* headers2;
	headers1 = getHeaders(argv[1]);
	headers2 = getHeaders(argv[2]);
	//check headers match
	int result;
	result = compareHeaders(headers1, headers2);
	if(!result){
		free(headers1);
		free(headers2);
		printf("DIFFERENT");
		return 0;
	}
	float* file1;
	float* file2;
	if(headers1[3] == 2){
		file1 = readFile(argv[1], headers1[0], headers1[1], headers1[2]);
	}
	else{
		file1 = readFileBin(argv[1], headers1[0], headers1[1], headers1[2]);
	}
	if(headers2[3] == 2){
                file2 = readFile(argv[1], headers2[0], headers2[1], headers2[2]);
        }
        else{
                file2 = readFileBin(argv[1], headers2[0], headers2[1], headers2[2]);
        }
	result = compareContents(file1, file2, headers2[0] * headers2[1]);
	free(file1);
	free(file2);
	free(headers1);
	free(headers2);
	if(!result){
		printf("DIFFERENT");
		return 0;
	}
	printf("IDENTICAL");
	return 0;
}
