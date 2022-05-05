#include <stdio.h>
FILE* openFile(char* filename);
int* getHeaders(char* filename, FILE* file);
void skipCommenth(FILE* file);
