//copyright 2015 (c) Marc Groefsema

#ifndef DNN_MODULE_H
#define DNN_MODULE_H

//standard includes
#include <stdio.h>
#include <stdlib.h>

//include dependencies 
#include "dnn_layer_stack.h"
#include "dnn_data.h"



typedef struct{
	LayerStack network;
	Dataset dataset;
}DNN_Module;

void initDNNModule(DNN_Module* module);
#endif