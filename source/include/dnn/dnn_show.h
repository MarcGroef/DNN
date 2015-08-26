// Copyright 2015 (C) Marc Groefsema
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
