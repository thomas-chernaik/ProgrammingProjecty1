int compareContents(float* file1, float* file2, int widthlength){
	for(int i=0; i<widthlength; i++){
		if(file1[i] != file2[i]){
			return 0;
		}
	}
	return 1;

}
int compareHeaders(int* headers1, int* headers2){
	return headers1[1] == headers2[1] && headers1[2] == headers2[2] && headers1[0] == headers2[0];
}
