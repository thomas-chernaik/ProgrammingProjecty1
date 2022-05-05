/*FILENAME: pgmWrite.c
 *DESCRIPTION:
 *	take an array of floats, header values, and a filename and write
 *	a pgmFile with the provided data to the file "filename"
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void writeFile(char* filename, float** fileToWrite, int width, int height, int maxGrey){
	//open the file to write
	FILE *file;
	file = fopen(filename, "w+");
	//check the file opened correctly
	if(!file){
		printf("ERROR: Output Failed (%s)\n", filename);
		exit(9);
	}
	//read headers into a string and then write string to file
	char* headers = malloc(sizeof(char)*9);
	if(!headers){
		printf("ERROR: Miscellaneous (malloc failed)\n");
		exit(100);
	}
	//put the headers into a string for easy writing to a file then
	//write them to the file
	sprintf(headers, "P2\n%d %d\n%d\n", width, height, maxGrey);
	fputs(headers, file);
	free(headers);
	char* stringToPut = malloc(sizeof(char) * 5);
	if(!stringToPut){
                printf("ERROR: Miscellaneous (malloc failed)\n");
                exit(100);
	}
	int numToPut;
	int lineLength = 0;
	//go through the data and write it all to the file
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			//we need to do the +0.5f and round down to avoid any floating point errors because we don't want those
			numToPut = (int) (fileToWrite[i][j] * maxGrey)+0.5f;
			sprintf(stringToPut, "%d", numToPut);
			fputs(stringToPut, file);
			lineLength += strlen(stringToPut);
			//put some whitespace in
			if(lineLength < 67){//going with 67 as my line limit because why not
				fputc(' ', file);
				lineLength ++;
			}
			else{
				lineLength = 0;
				fputc('\n', file);
			}
		}
	}
	fclose(file);
}
