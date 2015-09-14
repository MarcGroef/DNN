//copyright 2015 (c) Marc Groefsema
/*
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/
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
void initLayerStack(LayerStack* net,int nLayers,int* layerSizes);
void setInputData(LayerStack* net, Dataset* data, int index);
void freeLayerStack(LayerStack* ls);
#endif
