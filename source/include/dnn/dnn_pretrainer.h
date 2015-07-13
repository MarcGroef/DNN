//copyright 2015 (c) Marc Groefsema
#ifndef DNN_PRETRAINER_H
#define DNN_PRETRAINER_H

//standard includes
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//include dependencies
#include "dnn_layer_stack.h"
#include "dnn_data.h"
#include "dnn_flow.h"

void performRBM(LayerStack* layers, Dataset* dataset,float learningRate,int nIterations,int kSteps);
float** allocViHj(int vSize,int hSize);
void freeViHj(float** d,int vSize);

#endif