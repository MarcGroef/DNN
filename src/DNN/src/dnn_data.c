#include "../include/dnn_data.h"

void datasetAlloc(Dataset* dataset, int size){
	dataset->size = size;
	dataset->data = (float**)malloc(size*sizeof(float*));
	assert(dataset->data != NULL);
	for (int i = 0; i < size; i++){
		dataset->data[i] = malloc(LAYER_SIZE*sizeof(float));
		assert(dataset->data[i] != NULL);
	}
}


void datasetFree(Dataset* dataset){
	for (int i = 0; i < dataset->size; i++)
		free(dataset->data[i]);
	free(dataset->data);
}