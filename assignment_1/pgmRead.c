#include <stdio.h>
#include <stdlib.h>

float* readFile(char* filename, int width, int height, int maxGrey){
	//initialise and malloc our needed variables
	FILE *file;
	float* fileToReturn = (float*) malloc(width*height*sizeof(int));
	int* listOfInts = (int*) malloc(width*height*sizeof(int));
	file = fopen(filename, "r");
	if(file == NULL){
		//exit -1 if file error
		exit(-1);
	}
	//read out the magic number
	fgetc(file);
	fgetc(file);
	int* i = malloc(sizeof(int));
	int* j = malloc(sizeof(int));
	int* k = malloc(sizeof(int));
	//I think we have to have valid memory here even though we don't care about their values
	//scan out the headers we already know those.
	fscanf(file, " %d %d %d", i, j, k);
	free(i);
	free(j);
	free(k);
	//read out each pixel
	for(int i=0; i<width*height; i++){
		fscanf(file, "%d", &listOfInts[i]);
		//normalise the pixel and store in variable
		fileToReturn[i] = (float) listOfInts[i] / (float) maxGrey;
	}
	fclose(file);
	free(listOfInts);
	return fileToReturn;
}
