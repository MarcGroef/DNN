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
void readLayer(LayerStack* layers,int layer);

#endif
