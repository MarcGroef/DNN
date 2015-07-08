#ifndef DNN_PRETRAINER_H
#define DNN_PRETRAINER_H

//standard includes
#include <stdio.h>
#include <stdlib.h>

//include dependencies
#include "dnn_layer_stack.h"
#include "dnn_data.h"
#include "dnn_flow.h"

void performRBM(LayerStack* layers, Dataset* dataset,float learningRate);



#endif