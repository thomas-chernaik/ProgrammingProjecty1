/*FILENAME: pgmRead.c
 *FUNCTIONS:
 *	readFile
 *	skipComment
 */

#include <stdio.h>
#include <stdlib.h>
#include "pgmRead.h"

//read in the file filename with the provided header data to a float array
float* readFile(char* filename, int width, int height, int maxGrey){
	//initialise and malloc our needed variables
	FILE *file;
	float* fileToReturn = (float*) malloc(width*height*sizeof(float));
	int* listOfInts = (int*) malloc(width*height*sizeof(int));
	if(!fileToReturn || !listOfInts){//check malloc succeeded
		printf("ERROR: Image Malloc Failed\n");
		exit(7);
	}
	file = fopen(filename, "r");
	//check the file opened correctly
	if(file == NULL){
		printf("ERROR: Bad File Name (%s)\n", filename);
		exit(2);
	}
	//read out the magic number, skipping any comments
	skipComment(file);
	fgetc(file);
	skipComment(file);
	fgetc(file);
	int* i = malloc(sizeof(int));
	int* j = malloc(sizeof(int));
	int* k = malloc(sizeof(int));
	//I think we have to have valid memory here 
	//even though we don't care about their values
	//scan out the headers we already know those,
	//skipping any comments.
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
		int scanCount = fscanf(file, "%d", &listOfInts[i]);
		//check stuff was read
		if((listOfInts[i] == EOF || scanCount != 1) || (listOfInts[i] < 0) || (listOfInts[i] > 255)){
			free(listOfInts);
			fclose(file);
			printf("ERROR: Bad Data (%s)", filename);
			exit(8);
		}
		//normalise the pixel and store in variable
		fileToReturn[i] = (float) listOfInts[i] / (float) maxGrey;
	}
	int* c = malloc(sizeof(int));
	fscanf(file, " ", c);
	*c = getc(file);
	if(*c != EOF){
		free(listOfInts);
                fclose(file);
                printf("ERROR: Bad Data (%s)", filename);
                exit(8);
	}
	fclose(file);
	free(listOfInts);
	return fileToReturn;
}
//skip the line in the file if its a comment
void skipComment(FILE* file){
	char *chr = malloc(sizeof(char));
	char* str = malloc(sizeof(char) * 90);
	fscanf(file, " %c", chr);
	if(*chr == '#'){
		//reads to the end of the line
		fgets(str, 90, file);
	}
	else{
		//undoes the read that wasn't a #
		fseek(file, -1, SEEK_CUR);
	}
	free(str);
	free(chr);
}
