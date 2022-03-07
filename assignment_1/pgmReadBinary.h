#include <stdio.h>
float* readFileBin(char* filename, int width, int height, int maxGrey);
void readUntilWhitespace(FILE *file);
void readThroughWhitespace(FILE *file);
int bytesToInt(char byte1, char byte2);
