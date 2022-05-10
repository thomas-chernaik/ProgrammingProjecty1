/*FILENAME: gtopoEcho.c
 *DESCRIPTION: 
 *	clone a gtopofile into another file 
 *	with comprehension of the file structure
*/

#include <stdio.h>
#include <stdlib.h>
#include "gtopoRead.h"
#include "gtopoWrite.h"
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
	int width = atoi(argv[2]);
	int height = atoi(argv[3]);
	short** imageData = readFile(argv[1], width, height);
	writeFile(argv[4], imageData, width, height);
	//free memory
	free(imageData[0]);
	free(imageData);
	printf("ECHOED\n");
	return 0;	
}
