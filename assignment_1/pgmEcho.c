#include <stdio.h>
#include <stdlib.h>
#include "pgmHeaders.h"
#include "pgmRead.h"
#include "pgmWrite.h"

int main(int argc, char **argv){
	if(argc != 3){
		printf("error: input valid arguments.");
		exit(-5);
	}
	int* headers;
	//headers[0] is width, [1] is height, [2] is maxGrey
	headers = getHeaders(argv[1]);
	//TODO: check if binary or ascii
	float* file = readFile(argv[1], headers[0], headers[1], headers[2]);
	writeFile(argv[2], file, headers[0], headers[1], headers[2]);
	//TODO: binary implementation
}
