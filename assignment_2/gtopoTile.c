/*FILNAME: gtopoTile.c
 *FUNCTIONS:
 *	insertRowAndColToString
 *DESCRIPTION:
 *	take an input file, an integer factor n and an output 
 *	file name template and divide the input file into
 *	nxn smaller images corresponding to parts of the image.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pgmHeaders.h"
#include "pgmRead.h"
#include "pgmWrite.h"
#include "pgmReadBinary.h"
#include "pgmBinWrite.h"
#include "pgmSubImage.h"
//make the filename to write the tile to 
//from the format string, the row and the column.
ar* insertRowAndColToString(char* formatString, int rowint, int colint){
	char* row = (char*) malloc(sizeof(char) * 10);
	char* col = (char*) malloc(sizeof(char) * 10);
	char* outString = (char*) malloc(sizeof(char) * 100);
	if(!row || !col){
		printf("ERROR: Miscellaneous (malloc failed)\n");
                exit(100);
	}
	//concat together the different parts 
	//of the filename to outString
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
	//validate argument count
	if(argc == 1){
		printf("Usage: ./gtopoTile inputFile width height tiling_factor outputFile_<row>_<column>\n");
		return 0;
	}
	if(argc != 4){
		printf("ERROR: Bad Argument Count\n");
		return 1;
	}
	int width = atoi(argv[2]);
	int height = atoi(argv[3]);
	char rowcolcmp[] = {'_', '<', 'r', 'o', 'w', '>'};
        char* row_col = strstr(argv[5], rowcolcmp);
        *row_col = '\0';
	float* file;
	file = readFile(argv[1], width, height);
	//get subImages
	int n = atoi(argv[4]);
	for(int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			//get fileName for this tile
			char* fileOut = insertRowAndColToString(argv[3], i, j);
			//calculate the start and end row/col for this tile
			int startRow, endRow, startCol, endCol;
			startRow = i*headers[1]/n;
			if(i == n-1){
				endRow = headers[1];
			}
			else{
				endRow = startRow + headers[1]/n;
			}
			startCol = j*headers[0]/n;
			if(j == n-1){
				endCol = headers[0];
			}
			else{
				endCol = startCol + headers[0]/n;
			}
			//get the tile data
			short* outImage = subImage(file, startCol, endCol, startRow, endRow, headers[0]);
			//write the tile data to file
			writeFile(fileOut, outImage, endCol - startCol, endRow - startRow);
			free(fileOut);
			free(outImage);
		}
	}
	free(file);
	printf("TILED\n");
	return 0;
}

