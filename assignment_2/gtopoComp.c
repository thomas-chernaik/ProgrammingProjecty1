/*FILENAME: gtopoComp.c
 * DESCRIPTION
 * 	take in two file names and output if they are logically identical
 */
#include <stdlib.h>
#include <stdio.h>
#include "gtopoRead.h"
#include "gtopoWrite.h"
#include "gtopoCompare.h"

int main(int argc, char **argv){
	//validate arg count
	if(argc == 1){
		printf("Usage: ./gtopoComp firstFile width height secondFile\n");
		return 0;
	}
	if(argc != 5){
		printf("ERROR: Bad Argument Count\n");
                return 1;
	}
	short* file1;
	short* file2;
	file1 = readFile(argv[1], atoi(argv[2]), atoi(argv[3]));
	file2 = readFile(argv[4], atoi(argv[2]), atoi(argv[3]));
	int result = compareContents(file1, file2, atoi(argv[2]) * atoi(argv[3]));
	free(file1);
	free(file2);
	if(!result){
		printf("DIFFERENT\n");
		return 0;
	}
	printf("IDENTICAL\n");
	return 0;
}


