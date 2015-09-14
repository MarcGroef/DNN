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
#ifndef DNN_SHOW_H
#define DNN_SHOW_H

//include stds

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//include dependencies
#include "dnn_layer_stack.h"


#include<opencv/cxcore.h>
#include<opencv/cvaux.h>
#include<opencv/highgui.h>

#include<opencv/cv.h>


void showLayer(LayerStack* net,int layer);
void showInputLayer2D(LayerStack* net);
void showInputLayer2DImage(LayerStack* stack);
#endif
