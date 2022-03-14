#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pgmHeaders.h"
#include "pgmRead.h"
#include "pgmWrite.h"
#include "pgmReadBinary.h"
#include "pgmBinWrite.h"
#include "pgmSubImage.h"

char* insertRowAndColToString(char* formatString, int rowint, int colint){
	char* row = (char*) malloc(sizeof(char) * 10);
	char* col = (char*) malloc(sizeof(char) * 10);
	char* outString = (char*) malloc(sizeof(char) * 100);
	if(!row || !col){
		printf("ERROR: Miscellaneous (malloc failed)\n");
                exit(100);
	}
	*outString = '\0';
	strcat(outString, formatString);
	sprintf(row, "%d", rowint);
	sprintf(col, "%d", colint);
	strcat(outString, "_");
	strcat(outString, row);
	strcat(outString, "_");
	strcat(outString, col);
	strcat(outString, ".pgm");
	free(row);
	free(col);
	return outString;
}

int main(int argc, char **argv){
	if(argc == 1){
		printf("Usage: ./pgmTile inputImage.pgm tiling_factor outputImage_<row>_<column>.pgm\n");
		return 0;
	}
	if(argc != 4){
		printf("ERROR: Bad Argument Count");
		return 1;
	}
	char rowcolcmp[] = {'_', '<', 'r', 'o', 'w', '>'};
        char* row_col = strstr(argv[3], rowcolcmp);
        *row_col = '\0';
	
	int* headers;
	//headers[0] is width, [1] is height, [2] is maxGrey [3] is magic num
	headers = getHeaders(argv[1]);
	//check if binary or asci
	float* file;
	if (headers[3] == 2){	
		//if ascii read the ascii file.
		file = readFile(argv[1], headers[0], headers[1], headers[2]);
	}
	else{
		//else its binary so read the binary file
		file = readFileBin(argv[1], headers[0], headers[1], headers[2]);
	}
	//now we need to get the subImages from the file.
	int n = atoi(argv[2]);
	for(int i=0; i < n; i++){
		for(int j=0; j < n; j++){
			//get fileName for this tile
			char* fileOut = insertRowAndColToString(argv[3], i, j);
			//calculate the start and end row and col for this tile
			int startRow, endRow, startCol, endCol;
			startRow = i*headers[0]/n;
			endRow = startRow + headers[0]/n;
			startCol = j*headers[1]/n;
			endCol = startCol + headers[1]/n;
			//get the tile data
			float* outImage = subImage(file, startCol, endCol, startRow, endRow, headers[0]);
			//write the tile data to the file
			if (headers[3] == 2){
				writeFile(fileOut, outImage, endCol - startCol, endRow - startRow, headers[2]);
			}
			else{
				writeBin(fileOut, outImage, endCol - startCol, endRow - startRow, headers[2]);
			}
			free(fileOut);
			free(outImage);
		}
	}
	free(headers);
	free(file);
}
