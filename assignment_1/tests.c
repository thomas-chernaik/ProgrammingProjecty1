#include <stdio.h>
#include <stdlib.h>

#include "tests.h"

#include "pgmCompare.h"
#include "pgmReduceSize.h"
#include "pgma2b.h"
#include "pgmInsert.h"
#include "pgmComp.h"
#include "pgmSubImage.h"
#include "pgmAssemble.h"
#include "pgmReadBinary.h"
#include "pgmEcho.h"
#include "pgmTile.h"
#include "pgmb2a.h"
#include "pgmRead.h"
#include "pgmEmpty.h"
#include "pgmWrite.h"
#include "pgmBinWrite.h"
#include "pgmReduce.h"
#include "pgmHeaders.c"


void printResults(char* function, int passed, int failed){
	printf("%d tests passed and %d tests failed for function %s \n", passed, failed, function);
}
void testHeaders(){
	int passed = 0;
	int failed = 0;
	int* result1;
	result1 = malloc(3*sizeof(int));
	result1 = getHeaders("testfile1.pgm");
	int expectedResult1[] = {2,2,255,2};
	int flagSame = 1;
	for(int i=0; i<3; i++){
		if(result1[i] != expectedResult1[i]){
			flagSame = 0;
		}
	}
	free(result1);
	if (flagSame){
		passed++;
	}
	else{
		failed++;
	}
	printResults("Headers", passed, failed);
}
	
int main(int argc, char *argv[]) {
	testHeaders();
}
	
