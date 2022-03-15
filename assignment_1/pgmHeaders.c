/*FILENAME: pgmHeaders.c
 *FUNCTIONS:
 *	getHeaders
 *	skipCommenth
 */

#include <stdio.h>
#include <stdlib.h>
#include "pgmHeaders.h"
//gets the headers from a pgm file
int* getHeaders(char* filename){
	FILE *file;
	//first value is the width, second length, third the maximum grey value, fourth the magic number .
	int* returnValues = (int*) malloc(5 * sizeof(int));
	file = fopen(filename, "r");
	//validate the file opened
	if(file == NULL){
		printf("ERROR: Bad File Name (%s)\n", filename);
		exit(2);
	}
	//clear the P from the magic number
	fgetc(file);
	skipCommenth(file);
	//read the magic number it should be the next value in the file
	char magicNum = fgetc(file);
	skipCommenth(file);
	//convert the magic number from a string to an int
	//at first glance this seems to be an inefficient way of doing
	//it but we have to validate the magicNum anyways so it is 
	//actually an efficient method.
	if(magicNum == '2'){
		returnValues[3] = 2;
	}
	else if(magicNum == '5'){
		returnValues[3] = 5;
	}
	else{
		fclose(file);
		printf("ERROR: Bad Magic Number (%s)\n", filename);
		exit(3);
	
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
		fclose(file);
		printf("ERROR: Bad Dimensions (%s)\n", filename);
		exit(5);
	}
	//verify that the maxgrey value is valid
	if(returnValues[2] < 0 || returnValues[2] >= 65536){
		fclose(file);
		printf("ERROR: Bad Max Gray Value (%s)\n", filename);
		exit(6);
	}
	//close the file.
	fclose(file);
	return returnValues;
}

//skips a line in a pgm file if its a comment.
void skipCommenth(FILE* file){
	//assign pointers
	char* chr = malloc(sizeof(char));
	char* str = malloc(sizeof(char) * 90);//hope the comment line isn't longer than 90 chars.
	fscanf(file, " %c", chr);
	//check if the first character on the line is a #
	if(*chr == '#'){
		//read to the end of the line
		fgets(str, 90, file);
	}
	else{
		//go back one byte in the file because that wasn't a comment
		fseek(file, -1, SEEK_CUR);
	}
	free(str);
	free(chr);
}
