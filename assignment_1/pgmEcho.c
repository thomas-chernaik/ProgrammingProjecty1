#include <stdio.h>
#include <stdlib.h>
#include "pgmHeaders.h"
#include "pgmRead.h"
#include "pgmWrite.h"
#include "pgmReadBinary.h"
#include "pgmBinWrite.h"
int main(int argc, char **argv){
	if(argc != 3){
		printf("error: input valid arguments.");
		exit(-5);
	}
	int* headers;
	//headers[0] is width, [1] is height, [2] is maxGrey [3] is magic num
	headers = getHeaders(argv[1]);
	//check if binary or ascii
	if (headers[3] == 2){	
		//if ascii read and write the ascii file.
		float* file = readFile(argv[1], headers[0], headers[1], headers[2]);
		writeFile(argv[2], file, headers[0], headers[1], headers[2]);
		free(file);
	}
	else{
		float* file = readFileBin(argv[1], headers[0], headers[1], headers[2]);
		writeBin(argv[2], file, headers[0], headers[1], headers[2]);
		free(file);
	}	
}
