//copyright 2015 (c) Marc Groefsema
#include <dnn/dnn_layer.h>

Layer* allocLayer(Layer* l){
	l = (Layer*) malloc(sizeof(Layer));
	assert(l!=NULL);
	
	l->neurons=calloc(LAYER_SIZE,sizeof(float));
	assert(l->neurons!=NULL);
	l->weightsNext = malloc(LAYER_SIZE*sizeof(float*));
	assert(l->weightsNext!=NULL);
	for(int i=0;i<LAYER_SIZE;i++){
		l->weightsNext[i] = malloc(LAYER_SIZE*sizeof(float));
		assert(l->weightsNext[i]!=NULL);
	}
	return l;
}

void freeLayer(Layer* l){
	for(int i=0;i<LAYER_SIZE;i++){
		free(l->weightsNext[i]);
	}
	free(l->weightsNext);
	free(l->neurons);
	free(l);
}