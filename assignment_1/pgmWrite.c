#include <stdio.h>
#include <stdlib.h>
void writeFile(char* filename, float* fileToWrite, int width, int height, int maxGrey){
	FILE *file;
	file = fopen(filename, "w+");
	char* headers = malloc(sizeof(char)*9);
	sprintf(headers, "P2\n%d %d\n%d\n", width, height, maxGrey);
	fputs(headers, file);
	int numToPut;
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			numToPut = (int) (fileToWrite[i*width+j] * maxGrey)+0.5f;
			numToPut += '0';
			fputc(numToPut, file);
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
