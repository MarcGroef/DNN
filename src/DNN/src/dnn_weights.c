//copyright 2015 (c) Marc Groefsema
#include "../include/dnn_weights.h"

float randf(float bot,float top){
	time_t t;
	
	srand((unsigned) time(&t));
	return bot+((rand()*1.0f)/RAND_MAX)*top;
}

void initWeightsRandom(Layer* layer){
	for(int i=0;i<LAYER_SIZE;i++){
		for(int j=0;j<LAYER_SIZE;j++){
			layer->weightsNext[i][j]=randf(-1.0f,1.0f);
		}
	}
}

void initStackWeightsRandom(LayerStack* ls){
	for(int i=0;i<LAYER_STACK_SIZE-1;i++){  //skip last layer
		initWeightsRandom(&ls->stack[i]);
		printf("set weights of layer %d\n",i);
	}
}