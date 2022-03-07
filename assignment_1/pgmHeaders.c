#include <stdio.h>
#include <stdlib.h>
#include "pgmHeaders.h"
int* getHeaders(char* filename){
	FILE *file;
	//first value is the width, second length, third the maximum grey value, fourth the magic number .
	int* returnValues = (int*) malloc(5 * sizeof(int));
	file = fopen(filename, "r");
	if(file == NULL){
		//exit -1 if file error
		exit(-1);
	}
	//clear the P from the magic number
	fgetc(file);
	skipCommenth(file);
	//read the magic number it should be the next value in the file
	char magicNum = fgetc(file);
	skipCommenth(file);
	if(magicNum == '2'){
		returnValues[3] = 2;
	}
	else if(magicNum == '5'){
		returnValues[3] = 5;
	}
	else{
		//exit -2 if magicNum error
		fclose(file);
		exit(-2);
	
	}
	int num=0;
	//read in the width height and maxgrey values
	fscanf(file, " %d", &returnValues[0]);
	skipCommenth(file);
	fscanf(file, " %d", &returnValues[1]);
	skipCommenth(file);
	fscanf(file, " %d", &returnValues[2]);
	skipCommenth(file);
	//verify the width and height are valid
	if(returnValues[0] < 0 || returnValues[1] < 0){
		//exit -3 if dimension error
		fclose(file);
		exit(-3);
	}
	//close the file.
	fclose(file);
	return returnValues;
}

void skipCommenth(FILE* file){
	char* chr = malloc(sizeof(char));
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
