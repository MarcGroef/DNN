//copyright 2015 (c) Marc Groefsema

#ifndef DNN_CLASSIFIER_H
#define DNN_CLASSIFIER_H

#include "dnn_layer_stack.h"
#include "dnn_flow.h"
#include "dnn_data.h"
#include "dnn_show.h"


int classify(LayerStack* s,Dataset* d);

#endif