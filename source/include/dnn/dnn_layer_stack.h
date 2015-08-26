//copyright 2015 (c) Marc Groefsema
#ifndef DNN_LAYER_STACK_H
#define DNN_LAYER_STACK_H


//standard includes
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//these should be defined by dnn.h


//include dependancies
#include "dnn_data.h"
#include "dnn_constants.h"
//typedefs

typedef struct {
	int* layerSizes;
	int nLayers;
	float** layers;
	float*** weights;  //[source layer][source index][target index]
	
	//float output_weights[LAYER_SIZE][OUTPUT_LAYER_SIZE];
	//float output_layer[OUTPUT_LAYER_SIZE];
}LayerStack;

//functions
void initLayerStack(LayerStack* net);
void setInputData(LayerStack* net, Dataset* data, int index);
void allocLayerStack(LayerStack* ls);
void freeLayerStack(LayerStack* ls);
#endif