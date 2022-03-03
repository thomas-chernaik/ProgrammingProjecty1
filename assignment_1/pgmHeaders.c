#include <stdio.h>
#include <stdlib.h>
#include "pgmHeaders.h"

int* getHeaders(char* filename){
	FILE *file;
	//first value is the width, second length, third the magicNumber.
	int* returnValues = (int*) malloc(4 * sizeof(int));
	file = fopen(filename, "r");
	if(file == NULL){
		//exit -1 if file error
		exit(-1);
	}
	fgetc(file);
	char magicNum = fgetc(file);
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
	fscanf(file, " %d %d %d", &returnValues[0], &returnValues[1], &returnValues[2]);
	returnValues[0] = 2;
	returnValues[1] = 2;
	if(returnValues[0] < 0 || returnValues[1] < 0){
		//exit -3 if dimension error
		exit(-3);
	}
	return returnValues;
}
