/*FILENAME: gtopoPrintLand.c
 * DESCRIPTION:
 * 	take a single gtopo30 file and 
 * 	output it in a very simple
 * 	text format
 */

#include <stdio.h>
#include <stdlib.h>
#include "gtopoRead.h"
#include "gtopoPrint.h"

int main(int argc, char **argv){
        //validate the argument count
        if(argc == 1){
                printf("Usage: ./gtopoPrintLand inputFile width height outputFile sea hill mountain\n");
                return 0;
        }
        if(argc != 8){
                printf("ERROR: Bad Argument Count\n");
                return 1;
        }
	//get width and height
	int width = atoi(argv[2]);
        int height = atoi(argv[3]);
	//read in the data
        short** imageData = readFile(argv[1], width, height);
	//write out the data 
	printFile(imageData, width, height, argv[4], atoi(argv[5]), atoi(argv[6]), atoi(argv[7]));
	//free memory
	free(imageData[0]);
	free(imageData);
	return 0;
}
