/*FILENAME: gtopoPrint.c
 * DESCRIPTION: print image data to a txt file
 */

#include <stdio.h>
#include <stdlib.h>
#include "gtopoPrint.h"

void printFile(short** imageData, int width, int height, char* filename, int sea, int hill, int mountain)
	{
	//open the file to write to
	FILE* file = fopen(filename, "w");
	//check the file opened successfully
	if(!file){
                printf("ERROR: Output Failed (%s)\n", filename);
                exit(9);
        }
	//go through each pixel
	for(int i=0; i<height; i++)
		{
		for(int j=0; j<width; j++)
			{
			//write the pixel to the file
			//see if its below sea level
			if(imageData[i][j] < sea)
				{
				fputs(" ", file);
				}
			//see if its below hill level
			else if (imageData[i][j] < hill)
				{
				fputs(".", file);
				}
			//see if its below mountain level
			else if (imageData[i][j] < mountain)
				{
				fputs("^", file);
				}
			//then its a mountain
			else
				{
				fputs("A", file);
				}
			}
		fputs("\n", file);
		}	
	//close the file
	fclose(file);
}
