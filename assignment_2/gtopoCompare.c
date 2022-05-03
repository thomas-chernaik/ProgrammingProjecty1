/*FILENAME: gtopoCompare.c
 *FUNCTIONS:
 *	compareContents
 *	compareHeaders
 */

#include <stdio.h>
#include <stdlib.h>
#include "gtopoCompare.h"

//compares two short arrays of length widthlength and checks they are identical
int compareContents(short* file1, short* file2, int widthlength){
	for(int i=0; i<widthlength; i++){
		if(file1[i] != file2[i]){
			return 0;
		}
	}
	return 1;

}
