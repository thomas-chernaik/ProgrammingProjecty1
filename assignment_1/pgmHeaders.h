#include <stdio.h>
FILE* openFile(char* filename);
int* getHeaders(char* filename, FILE* file);
int* getHeaders2(char* filename, FILE* file, int* otherHeaders);
void skipCommenth(FILE* file, char* filename);
