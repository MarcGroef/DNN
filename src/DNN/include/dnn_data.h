#ifndef DNN_DATA_H
#define DNN_DATA_H


//standard includes
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//include dependencies



#ifndef LAYER_SIZE
#define LAYER_SIZE 10
#endif

typedef struct{
	int size;
	float** data;
}Dataset;

void datasetAlloc(Dataset* dataset,int size);
void datasetFree(Dataset* dataset);

#endif

