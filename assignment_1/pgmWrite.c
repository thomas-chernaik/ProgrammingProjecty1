#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void writeFile(char* filename, float* fileToWrite, int width, int height, int maxGrey){
	//open the file to write
	FILE *file;
	file = fopen(filename, "w+");
	//read headers into a string and then write string to file
	char* headers = malloc(sizeof(char)*9);
	sprintf(headers, "P2\n%d %d\n%d\n", width, height, maxGrey);
	fputs(headers, file);
	free(headers);
	char* stringToPut = malloc(sizeof(char) * 5);
	int numToPut;
	int lineLength = 0;
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			//we need to do the +0.5f and round down to avoid any floating point errors because we don't want those
			numToPut = (int) (fileToWrite[i*width+j] * maxGrey)+0.5f;
			sprintf(stringToPut, "%d", numToPut);
			fputs(stringToPut, file);
			lineLength += strlen(stringToPut);
			//put some whitespace in
			if(lineLength < 67){
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
