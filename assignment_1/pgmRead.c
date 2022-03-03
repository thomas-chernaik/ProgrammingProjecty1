float* readFile(char* filename, width, height, maxGrey){
	FILE *file;
	float* fileToReturn = (float*) malloc(width*height*sizeof(int));
	int* listOfInts = (int*) malloc(width*height*sizeof(int));
	file = fopen(filename, "r");
	if(file == NULL){
		//exit -1 if file error
		exit(-1);
	}
	fgetc(file);
	fscanf(file, " %s %d %d %d ", NULL, NULL, NULL, NULL);
	for(int i=0; i<width*height; i++){
		fscanf(file, " %d ", listOfInts[i]);
		fileToReturn[i] = listOfInts[i]/maxGrey;
	}
	return fileToReturn;
}
