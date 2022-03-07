#include <stdio.h>
#include <stdlib.h>
void writeFile(char* filename, float* fileToWrite, int width, int height, int maxGrey){
	//open the file to write
	FILE *file;
	file = fopen(filename, "w+");
	//read headers into a string and then write string to file
	char* headers = malloc(sizeof(char)*9);
	sprintf(headers, "P2\n%d %d\n%d\n", width, height, maxGrey);
	fputs(headers, file);
	free(headers);
	int numToPut;
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			//we need to do the +0.5f and round down to avoid any floating point errors because we don't want those
			numToPut = (int) (fileToWrite[i*width+j] * maxGrey)+0.5f;
			numToPut += '0';//this converts an int to an ascii equiv
			fputc(numToPut, file);
			//put some whitespace in
			if(j!=width-1){
				fputc(' ', file);
			}
			else{
				fputc('\n', file);
			}
		}
	}
	fclose(file);
}
