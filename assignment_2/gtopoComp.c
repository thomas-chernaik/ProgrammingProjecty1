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
	FILE* file1 = openFile(argv[1]);
	//initialise the header pointers
	int* headers1;
	//get the headers and store them where the pointers point
	headers1 = getHeaders(argv[1], file1);
	other = file1;
	//open file 2
	FILE* file2 = openFile(argv[2]);
	//init headers 2
	int* headers2;
	headers2 = getHeaders(argv[2], file2);

	//check headers match
	int result;
	result = compareHeaders(headers1, headers2);
	if(!result){
		free(headers1);
		free(headers2);
		printf("DIFFERENT\n");
		return 0;
	}
	//intialise the imageData arrays
	short** imageData1;
	short** imageData2;
	//read in the file data of both files
	//point global values at memory that will need to be freed if the read fails.
	if(headers1[3] == 2){
		otherRead = file2;
		imageData1 = readFile(file1, argv[1], headers1[0], headers1[1]);
	}
	else{
		
		otherReadB = file2;
		imageData1 = readFileBin(file1, argv[1], headers1[0], headers1[1]);
	}
	if(headers2[3] == 2){
		otherIm = imageData1;
		otherRead = file1;
                imageData2 = readFile(file2, argv[2], headers2[0], headers2[1]);
        }
        else{
		otherImB = imageData1;
		otherReadB = file1;
                imageData2 = readFileBin(file2, argv[2], headers2[0], headers2[1]);
        }
	//compare contents of the files 
	result = compareContents(imageData1, imageData2, headers2[0], headers2[1]);
	//free memory
	free(imageData1[0]);
	free(imageData2[0]);
	free(imageData1);
	free(imageData2);
	free(headers1);
	free(headers2);
	if(!result){
		printf("DIFFERENT\n");
		return 0;
	}
	printf("IDENTICAL\n");
	return 0;
}
