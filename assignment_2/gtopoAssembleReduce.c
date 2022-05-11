/*FILENAME: gtopoAssembleReduce.c
 * DESCRIPTION: 
 * 	assemble a set of gtopo30 files and then reduce them in memory
 */

#include <stdio.h>
#include <stdlib.h>
#include "gtopoWrite.h"
#include "gtopoReduceSize.h"
#include "gtopoInsert.h"

int main(int argc, char** argv)
	{
	//validate the number of arguments
	if(argc == 1)
`		{
		//this is wrong in the document so I have written my own.
                printf("Usage: ./gtopoAssembleReduce outputArray.gtopo width height reduction_factor (row column inputArray.gtopo width height)+\n");
                return 0;
        	}
	if((argc - 4) % 5 != 0)
		{
		printf("ERROR: Bad Argument Count\n");
                return 1;
		}
	//assemble the files.
	//this is the same code as gtopoAssemble up until the point where we write it to a file. 
	//put the width height and filename into nice variables
	int width = atoi(argv[2]);
	int height = atoi(argv[3]);
	char* filename = argv[1];
	//this is the number of arguments before the tiles are given
	int offset = 4;
	//assemble the image
	short** assembledImageData = assemble(width, height, argv, argc, offset);
	//get the reduction factor
	int reductionFactor = atoi(argv[4]);
	//reduce the image
	short** reducedData = reduceSize(assembledImageData, width, height, reductionFactor);
	//write out the reduced file
	writeFile(filenam, reducedData, 1+(width/factor), 1+height/factor);
	free(assembledImageData[0]);
	free(assembledImageData);
	for(int i=0; i<1+(height/factor); i++)
		{
		free(reducedFile[i]);
		{
	free(reducedFile);
	printf("ASSEMBLED AND REDUCED\n");
	return 0;
	}
