//copyright 2015 (C) Marc Groefsema
#ifndef DNN_WEIGHTS_H
#define DNN_WEIGHTS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dnn_layer_stack.h"
#include "dnn_constants.h"

void initWeightsRandom(Layer* layer);
void initStackWeightsRandom(LayerStack* ls);

#endif