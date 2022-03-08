#include <stdio.h>
#include <stdlib.h>
#include "pgmHeaders.h"
#include "pgmRead.h"
#include "pgmBinWrite.h"
int main(int argc, char **argv){
        if(argc == 1){
                printf("Usage: ./pgma2b inputImage.pgm outputImage.pgm");
                return 0;
        }
        if(argc != 3){
                printf("ERROR: Bad Argument Count");
                return 1;
        }
        int* headers;
	//headers[0] is width, [1] is height, [2] is maxGrey [3] is magic num
        headers = getHeaders(argv[1]);
	//check is ascii
	if(headers[3] != 2){
		printf("ERROR: Bad File Name (%s)", argv[1]);
		return 2;
	}
        float* file = readFile(argv[1], headers[0], headers[1], headers[2]);
        writeBin(argv[2], file, headers[0], headers[1], headers[2]);
	free(file);
	free(headers);
	printf("CONVERTED");
	return 0;
}
