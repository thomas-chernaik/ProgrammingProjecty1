#include <stdio.h>
float* readFileBin(char* filename, int width, int height, int maxGrey);
void readUntilWhitespace(FILE *file);
void readThroughWhitespace(FILE *file);
unsigned int bytesToInt(unsigned char byte1);
void readUntilNewline(FILE *file);
