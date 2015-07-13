//copyright 2015 (c) Marc Groefsema
#include <dnn/dnn_math.h>

const double e = 2.718281828459045;

float sigmoid(float x){
	float s = (1.0f / (1 + pow(e, x*-1)));
	//printf("sigmoid : %.4f\n",s);
	return s;
}