/*FILENAME: gtopoTile.c
 *FUNCTONS:
 *	insertRowAndColToString
 *DESCRIPTION:
 *	take 3 arguments, an input
 *	file (either ASCII or binary),
 *	an integer factor n, 
 *	and an output file name template. 
 *	It should divide the input file 
 *	into nxn smaller images corresponding 
 *	to parts of the image
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gtopoRead.h"
#include "gtopoWrite.h"
#include "gtopoSubImage.h"

//make the filename to write the tile to 
//from the format string, the row and the column.
char* insertRowAndColToString(char* formatString, int rowint, int colint){
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
	strcat(outString, ".gtopo");
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
	if(argc != 6){
		printf("ERROR: Bad Argument Count\n");
		return 1;
	}
	//create a variable with our format string in
	char rowcolcmp[] = {'_', '<', 'r', 'o', 'w', '>', '_', '<','c','o','l','\0'};
	//find where this string is in our template
        char* row_col = strstr(argv[5], rowcolcmp);
	//check it existed 
	if(row_col == NULL)
		{
		//print error
		printf("ERROR: Miscellaneous (bad template)\n");
		return 100;
		}
        *row_col = '\0';
	//get widht and height from args
	int width = atoi(argv[2]);
	int height = atoi(argv[3]);
	short** imageData;
	imageData = readFile(argv[1], width, height);
	//now we need to get the subImages from the file.
	int n = atoi(argv[4]);
	for(int i=0; i < n; i++){
		for(int j=0; j < n; j++){
			//get fileName for this tile
			char* fileOut = insertRowAndColToString(argv[5], i, j);
			//calculate the start and end row and col for this tile
			int startRow, endRow, startCol, endCol;
			startRow = i*height/n;
			if(i == n-1){
				endRow = height;
			}
			else{
				endRow = startRow + height/n;
			}
			startCol = j*width/n;
			if(j == n-1){
				endCol = width;
			}
			else{
				endCol = startCol + width/n;
			}
			//get the tile data
			short** outImage = subImage(imageData, startCol, endCol, startRow, endRow, width);
			//write the tile data to the file
			writeFile(fileOut, outImage, endCol - startCol, endRow - startRow);
			free(fileOut);
			free(outImage);
		}
	}
	free(imageData[0]);
	free(imageData);
	printf("TILED\n");
	return 0;
}
