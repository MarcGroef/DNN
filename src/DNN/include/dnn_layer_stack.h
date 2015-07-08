#ifndef DNN_LAYER_STACK_H
#define DNN_LAYER_STACK_H


//standard includes
#include <stdio.h>
#include <stdlib.h>

//these should be defined by dnn.h
#ifndef LAYER_STACK_SIZE
#define LAYER_STACK_SIZE 10
#endif

#ifndef OUTPUT_LAYER_SIZE 
#define OUTPUT_LAYER_SIZE 6
#endif

//include dependancies
#include "dnn_layer.h"
#include "dnn_data.h"

//typedefs

typedef struct {
	Layer stack[LAYER_STACK_SIZE];
	float output_weights[LAYER_SIZE][OUTPUT_LAYER_SIZE];
	float output_layer[OUTPUT_LAYER_SIZE];
}LayerStack;

//functions

void setInputData(LayerStack* net, Dataset* data, int index);

#endif