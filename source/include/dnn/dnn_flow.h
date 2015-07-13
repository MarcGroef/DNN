//copyright 2015 (c) Marc Groefsema
#ifndef DNN_FLOW_H
#define DNN_FLOW_H

//standard includes
#include <stdio.h>
#include <stdlib.h>

//include dependencies
#include "dnn_layer_stack.h"
#include "dnn_data.h"
#include "dnn_math.h"
#include "dnn_show.h"

//TODO. Use SIMD for flow calculations. Calcs batches instead of scalars at once.
//should in future be in https://github.com/jobtalle/ccVector to fork.

void flowUpUntil(LayerStack* stack, int layer);  //runs activity up to indicated layer
void flowUp(LayerStack* stack);
void flowDownFrom(LayerStack* network, int layer);//runs activity down from indicated layer
void flowDown(LayerStack* stack);
void readNeuron(LayerStack* layers,int layer,int nNeurons);

#endif
