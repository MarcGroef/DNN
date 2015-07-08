#include "../include/dnn_math.h"


float sigmoid(float x){
	return (float)(1.0f / (1 + pow(DNN_EULER, x)));
}