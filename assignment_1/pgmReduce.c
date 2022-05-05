/*FILENAME: pgmReduce.c
 *DESCRIPTION:
 *	take in a pgm file and a factor to reduce it by and output
 *	a reduced file.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pgmRead.h"
#include "pgmReadBinary.h"
#include "pgmWrite.h"
#include "pgmBinWrite.h"
#include "pgmHeaders.h"
#include "pgmReduceSize.h"

int main(int argc, char** argv){
	//validate the number of arguments
	if(argc == 1){
		printf("Usage: ./pgmReduce inputImage.pgm reduction_factor outputImage.pgm\n");
		return 0;
	}
	if(argc != 4){
		printf("ERROR: Bad Argument Count\n");
		return 1;
	}
	int factor = atoi(argv[2]);
	for(int i=0; i < strlen(argv[2]); i++){
		if(argv[2][i] > '9' || argv[2][i] < '0'){
			printf("ERROR: Miscellaneous (non-numeric scaling factor)\n");
			exit(100);
		}
	}
	if(factor <= 0){
		printf("ERROR: Miscellaneous (negative scaling factor)\n");
		exit(100);
	}
	int* headers;
        //headers[0] is width, [1] is height, [2] is maxGrey [3] is magic num
        headers = getHeaders(argv[1]);
	float** file;
	//read in the file
	//check if ascii
	if(headers[3] == 2){
		file = readFile(argv[1], headers[0], headers[1], headers[2]);
	}
	else{
		file = readFileBin(argv[1], headers[0], headers[1], headers[2]);
	}
	float** reducedFile;
	reducedFile = reduceSize(file, headers[0], headers[1], factor);
	//write out the reduced file
	//check if ascii
	if(headers[3] == 2){
		writeFile(argv[3], reducedFile, (headers[0]%factor != 0) + headers[0]/factor ,(headers[1]%factor != 0) + headers[1]/factor, headers[2]);
	}
	else{
		writeBin(argv[3], reducedFile, (headers[0]%factor != 0) + headers[0]/factor, (headers[1]%factor != 0) + headers[1]/factor, headers[2]);
	}
	free(headers);
	free(file);
	free(reducedFile);
	printf("REDUCED\n");
	return 0;
}
