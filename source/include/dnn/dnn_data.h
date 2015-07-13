//copyright 2015 (c) Marc Groefsema
#ifndef DNN_DATA_H
#define DNN_DATA_H


//standard includes
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//include dependencies
#include "dnn_constants.h"
#include <MNIST/mnist.h>


typedef struct{
	int size;
	float** data;
}Dataset;

void datasetAlloc(Dataset* dataset,int size);
void datasetFree(Dataset* dataset);
void addMNIST(char* mnist_dir,Dataset* dataset,int size);


#endif

