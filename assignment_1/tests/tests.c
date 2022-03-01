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
#include "pgmHeaders.h"


void printResults(char* function, int passed, int failed){
	printf("%d tests passed and %d tests failed for function %s", passed, failed, function);
}

void testHeaders(){
	int passed = 0;
	int failed = 0;
	int* result1 = getHeaders("testfile1.pgm");
	int[3] expectedResult1 = {2,2,2};
	if (result1 == expectedResult1){
		passed++;
	}
	else{
		failed++;
	}
	
}
	
	
	
