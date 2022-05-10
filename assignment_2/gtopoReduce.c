/*FILENAME: gtopoReduce.c
 *DESCRIPTION:
 *	take in a gtopo file and a factor to reduce it by and output
 *	a reduced file.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gtopoRead.h"
#include "gtopoWrite.h"
#include "gtopoReduceSize.h"

int main(int argc, char** argv){
	//validate the number of arguments
	if(argc == 1){
		printf("Usage: ./gtopoReduce inputImage.gtopo reduction_factor outputImage.gtopo\n");
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
	//open file
	FILE* file = openFile(argv[1]);
	//initialise headers pointer
	int* headers;
        //headers[0] is width, [1] is height, [2] is maxGrey [3] is magic num
        headers = getHeaders(argv[1], file);
	//intialise image data pointer
	short** imageData;
	//read in the file
	//check if ascii
	if(headers[3] == 2){
		imageData = readFile(file, argv[1], headers[0], headers[1]);
	}
	else{
		imageData = readFileBin(file, argv[1], headers[0], headers[1]);
	}
	//intialise downsized image data pointer
	short** reducedFile;	
	//downsize image data and store it in reduced file
	reducedFile = reduceSize(imageData, headers[0], headers[1], factor);
	//write out the reduced file
	//check if ascii
	if(headers[3] == 2){
		writeFile(argv[3], reducedFile, 1+(headers[0]/factor), 1+(headers[1]/factor), headers[2]);
	}
	else{
		writeBin(argv[3], reducedFile, 1+(headers[0]/factor), 1+(headers[1]/factor), headers[2]);
	}
	free(imageData[0]);
	free(imageData);
	for(int i=0; i< 1+(headers[1]/factor); i++){
		free(reducedFile[i]);
	}
	free(headers);
	free(reducedFile);
	printf("REDUCED\n");
	return 0;
}
