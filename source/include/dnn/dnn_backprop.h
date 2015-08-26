//copyright 2015 (c) Marc Groefsema
#ifndef DNN_BACKPROP
#define DNN_BACKPROP



//include dependencies
#include "dnn_layer_stack.h"
#include "dnn_flow.h"

#include <stdlib.h>
#include <assert.h>

typedef struct{
	int nLayers;
	float** deltas;
}DeltaBuffer;

void allocateDeltas(LayerStack* l,DeltaBuffer* d);
void backpropIndex(LayerStack* layers, Dataset* data,int* targetOutput, int dataIndex,float learningRate);
void backprop(LayerStack* layers,Dataset* data,int targetSize, float learningRate,int nIterations);


#endif