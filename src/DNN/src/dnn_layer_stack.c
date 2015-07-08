#include "../include/dnn_layer_stack.h"

void setInputData(LayerStack* net,Dataset* data, int index){
	for (int i = 0; i < LAYER_SIZE; i++){
		net->stack[0].neurons[i] = data->data[index][i];
	}
}