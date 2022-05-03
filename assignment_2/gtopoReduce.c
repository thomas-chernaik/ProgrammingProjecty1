/*FILENAME: gtopoReduce.c
 *DESCRIPTION:
 *	take in a dem file and a factor to reduce it by and
 *	 output a reduced file.
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
	if(argc != 6){
		printf("ERROR: Bad Argument Count\n");
		return 1;
	}
	int width = atoi(argv[2]);
	int height = atoi(argv[3]);
	int factor = atoi(argv[4]);
	for(int i=0; i<strlen(argv[2]); i++){
		if(argv[2][i] > '9' || argv[2][i] < '0'){
			printf("ERROR: Miscellaneous (non-numeric scaling factor)\n");
			exit(100);
		}
	}
	if(factor <= 0){
		printf("ERROR: Miscellaneous (negative scaling factor)\n");
		exit(100);
	}
	
	short* file = readFile(argv[1], width, height);
	short* reducedFile;
	reducedFile = reduceSize(file, width, height, factor);
	writeFile(argv[5], reducedFile, width, height);
	free(file);
	free(reducedFile);
	printf("REDUCED\n");
	return 0;
}

