//copyright 2015 (c) Marc Groefsema
#include <dnn/dnn_weights.h>

int randset = 0;
float randf(float bot,float top){
	time_t t;
	float ret ;	
	if(!randset){	
		srand((unsigned) time(&t));
		++randset;
	}
	ret = bot+(float)rand()/((float)RAND_MAX/(top-bot));
//	printf("%.2f\n", ret);
	return ret;
}

void initWeightsRandom(Layer* layer){
	for(int i=0;i<LAYER_SIZE;i++){
		for(int j=0;j<LAYER_SIZE;j++){
			layer->weightsNext[i][j]=randf(-.01f,.01f);
		}
	}
}

void initStackWeightsRandom(LayerStack* ls){
	for(int i=0;i<LAYER_STACK_SIZE-1;i++){  //skip last layer
		initWeightsRandom(ls->stack[i]);
		printf("set weights of layer %d\n",i);
	}
}
