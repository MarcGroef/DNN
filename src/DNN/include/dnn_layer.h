//copyright 2015 (c) Marc Groefsema
#ifndef DNN_LAYER_H
#define DNN_LAYER_H

#include <stdio.h>
#include <stdlib.h>
#include "dnn_constants.h"




typedef struct{
	float neurons[LAYER_SIZE];
	float weightsNext[LAYER_SIZE][LAYER_SIZE];
}Layer;


#endif