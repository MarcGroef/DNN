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
#ifndef DNN_PRETRAINER_H
#define DNN_PRETRAINER_H

//standard includes
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
//include dependencies
#include "dnn_layer_stack.h"
#include "dnn_data.h"
#include "dnn_flow.h"

void performRBM(LayerStack* layers, Dataset* dataset,float learningRate,int nIterations,int kSteps);
float** allocViHj(int vSize,int hSize);
void freeViHj(float** d,int vSize);

#endif