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
                printf("Usage: ./gtopoEcho inputFile width height outputFile\n");
                return 0;
        }
        if(argc != 5){
                printf("ERROR: Bad Argument Count\n");
                return 1;
        }
	//get width and height
	int width = atoi(argv[2]);
        int height = atoi(argv[3]);
        short** imageData = readFile(argv[1], width, height);
	printFile(imageData, argv[4]);
	return 0;
}
