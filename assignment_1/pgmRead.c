#include <stdio.h>
#include <stdlib.h>
#include "pgmRead.h"
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
	skipComment(file);
	fgetc(file);
	skipComment(file);
	fgetc(file);
	int* i = malloc(sizeof(int));
	int* j = malloc(sizeof(int));
	int* k = malloc(sizeof(int));
	//I think we have to have valid memory here even though we don't care about their values
	//scan out the headers we already know those.
	skipComment(file);
	fscanf(file, " %d", i); 
	skipComment(file);
	fscanf(file, " %d", j);
	skipComment(file);
	fscanf(file, " %d", k);
	skipComment(file);
	free(i);
	free(j);
	free(k);
	//read out each pixel
	for(int i=0; i<width*height; i++){
		//skipComment(file);
		fscanf(file, "%d", &listOfInts[i]);
		//normalise the pixel and store in variable
		fileToReturn[i] = (float) listOfInts[i] / (float) maxGrey;
	}
	fclose(file);
	free(listOfInts);
	return fileToReturn;
}
void skipComment(FILE* file){
	char *chr = malloc(sizeof(char));
	char* str = malloc(sizeof(char) * 90);
	fscanf(file, " %c", chr);
	if(*chr == '#'){
		fgets(str, 90, file);
	}
	else{
		fseek(file, -1, SEEK_CUR);
	}
	free(str);
	free(chr);
}
