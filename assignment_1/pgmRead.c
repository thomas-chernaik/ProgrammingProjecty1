#include <stdio.h>
#include <stdlib.h>

float* readFile(char* filename, int width, int height, int maxGrey){
	FILE *file;
	float* fileToReturn = (float*) malloc(width*height*sizeof(int));
	int* listOfInts = (int*) malloc(width*height*sizeof(int));
	file = fopen(filename, "r");
	if(file == NULL){
		//exit -1 if file error
		exit(-1);
	}
	fgetc(file);
	fgetc(file);
	int* i = malloc(sizeof(int));
	int* j = malloc(sizeof(int));
	int* k = malloc(sizeof(int));
	
	fscanf(file, " %d %d %d", i, j, k);
	for(int i=0; i<width*height; i++){
		fscanf(file, "%d", &listOfInts[i]);
		fileToReturn[i] = (float) listOfInts[i] / (float) maxGrey;
	}
	fclose(file);
	return fileToReturn;
}
