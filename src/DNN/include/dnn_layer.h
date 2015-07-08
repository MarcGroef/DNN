//copyright 2015 (c) Marc Groefsema
#ifndef DNN_LAYER_H
#define DNN_LAYER_H

#include <stdio.h>
#include <stdlib.h>

#ifndef LAYER_SIZE
#define LAYER_SIZE 10
#endif

typedef struct{
	float neurons[LAYER_SIZE];
	float weightsNext[LAYER_SIZE][LAYER_SIZE];
}Layer;


#endif