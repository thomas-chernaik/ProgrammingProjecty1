/*FILENAME: gtopoComp.c
 *DESCRIPTION:
 *	take in two file names and output if they are 
 *	logically identical
 */
#include <stdlib.h>
#include "gtopoRead.h"
#include "gtopoCompare.h"

FILE* other;
FILE* otherRead;
FILE* otherReadB;
short** otherImB;
short** otherIm;
int main(int argc, char **argv){
	//validate argument count
	if(argc == 1){
                printf("Usage: ./gtopoComp firstFile width height secondFile\n");
                return 0;
        }
        if(argc != 5){
                printf("ERROR: Bad Argument Count\n");
                return 1;
        }
	//get width and height
	int width = atoi(argv[2]);
	int height = atoi(argv[3]);
	//intialise the imageData arrays
	short** imageData1;
	short** imageData2;
	//read in the file data of both files
	//point global values at memory that will need to be freed if the read fails.
	imageData1 = readFile(argv[1], width, height);
	otherIm = imageData1;
        imageData2 = readFile(argv[4], width, height);
	//compare contents of the files 
	int result = compareContents(imageData1, imageData2, width, height);
	//free memory
	free(imageData1[0]);
	free(imageData2[0]);
	free(imageData1);
	free(imageData2);
	if(!result){
		printf("DIFFERENT\n");
		return 0;
	}
	printf("IDENTICAL\n");
	return 0;
}
