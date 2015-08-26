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

void initWeightsRandom(LayerStack* ls,int layer){
	for(int i=0;i<ls->layerSizes[layer];i++){
		for(int j=0;j<ls->layerSizes[layer+1];j++){
			ls->weights[layer][i][j]=randf(-.2f,.2f);
		}
	}
}

void initStackWeightsRandom(LayerStack* ls){
	for(int i=0;i<ls->nLayers-1;i++){  //skip last layer
		initWeightsRandom(ls,i);
		//printf("set weights of layer %d\n",i);
	}
}
