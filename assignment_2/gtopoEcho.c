/*FILNAME: gtopoEcho.c
 * DESCRIPTION:
 * 	clone a dem file into another file
 * 	with comprehension of the file structure
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
	short*  file = readFile(argv[1], atoi(argv[2]), atoi(argv[3]));
	writeFile(argv[4], file, atoi(argv[2]), atoi(argv[3]));
	free(file);
	printf("ECHOED\n");
	return 0;
}
