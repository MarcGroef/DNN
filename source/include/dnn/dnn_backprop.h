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