//copyright 2015 (c) Marc Groefsema
#include <dnn/dnn_layer_stack.h>

void initLayerStack(LayerStack* net){
	for(int i=0;i<LAYER_STACK_SIZE;i++)
		net->stack[i]=NULL;
}

void setInputData(LayerStack* net,Dataset* data, int index){
	for (int i = 0; i < LAYER_SIZE; i++){
		net->stack[0]->neurons[i] = (float)data->data[index][i]/255.0;
	}
}

void allocLayerStack(LayerStack* ls){
	ls->stack = (Layer**)malloc(LAYER_STACK_SIZE*sizeof(Layer));
	assert(ls->stack!=NULL);
	for(int i=0;i<LAYER_STACK_SIZE;i++){
		ls->stack[i]=allocLayer(ls->stack[i]);
		//
	}
	ls->input_layer = malloc(INPUT_LAYER_SIZE*sizeof(float));
	assert(ls->input_layer!=NULL);
	ls->input_weights = malloc(INPUT_LAYER_SIZE*sizeof(float*));
	assert(ls->input_layer!=NULL);
	for(int i=0;i<INPUT_LAYER_SIZE;i++){
		ls->input_weights[i] = malloc(LAYER_SIZE*sizeof(float));
		assert(ls->input_weights[i]!=NULL);
	}
}

void freeLayerStack(LayerStack* ls){
	for(int i=0;i<LAYER_STACK_SIZE;i++){
		freeLayer(ls->stack[i]);
	}
	free(ls->stack);
	free(ls->input_layer);
	for(int i=0;i<INPUT_LAYER_SIZE;i++){
		free(ls->input_weights[i]);
	}
	free(ls->input_weights);
}
