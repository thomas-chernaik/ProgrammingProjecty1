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
		printf("Usage: ./gtopoReduce input width height reduction_factor output\n");
		return 0;
	}
	if(argc != 4){
		printf("ERROR: Bad Argument Count\n");
		return 1;
	}
	int factor = atoi(argv[4]);
	for(int i=0; i < strlen(argv[4]); i++){
		if(argv[4][i] > '9' || argv[4][i] < '0'){
			printf("ERROR: Miscellaneous (non-numeric scaling factor)\n");
			exit(100);
		}
	}
	if(factor <= 0){
		printf("ERROR: Miscellaneous (negative scaling factor)\n");
		exit(100);
	}
	//get width and height from args
	int width = atoi(argv[2]);
	int height = atoi(argv[3]);
	//intialise image data pointer
	short** imageData;
	//read in the file
	imageData = readFile(argv[1], width, height);
	//intialise downsized image data pointer
	short** reducedFile;	
	//downsize image data and store it in reduced file
	reducedFile = reduceSize(imageData, width, height, factor);
	//write out the reduced file
	writeFile(argv[5], reducedFile, 1+(width/factor), 1+(height/factor));
	free(imageData[0]);
	free(imageData);
	for(int i=0; i< 1+(height/factor); i++){
		free(reducedFile[i]);
	}
	free(reducedFile);
	printf("REDUCED\n");
	return 0;
}
