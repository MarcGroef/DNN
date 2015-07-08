#include "../include/dnn_flow.h"

void flowUpUntil(LayerStack *network,int layer){
	for (int l = 1; l < layer; l++){ //target layer
		for (int n = 0; n < LAYER_SIZE; n++){ //target neuron
			network->stack[l].neurons[n] = 0;
				for (int m = 0; m < LAYER_SIZE; m++){//source neuron
					network->stack[l].neurons[n] += network->stack[l - 1].neurons[m] * network->stack[l - 1].weightsNext[m][n];
				}
				network->stack[l].neurons[n] = sigmoid(network->stack[l].neurons[n]);
		}

	}

}

void flowUp(LayerStack *network){
	for (int l = 1; l < LAYER_SIZE; l++){ //target layer
		for (int n = 0; n < LAYER_SIZE; n++){ //target neuron
			network->stack[l].neurons[n] = 0;
			for (int m = 0; m < LAYER_SIZE; m++){//source neuron
				network->stack[l].neurons[n] += network->stack[l - 1].neurons[m] * network->stack[l - 1].weightsNext[m][n];
			}
			network->stack[l].neurons[n] = sigmoid(network->stack[l].neurons[n]);
		}
	}
}

void flowDownFrom(LayerStack* network, int layer){
	for (int l = layer; l > 0; l--){ //run from indicated layer down to second layer and flow down from it
		for (int n = 0; n < LAYER_SIZE; n++){ //target neuron
			network->stack[l - 1].neurons[n] = 0;  // l-1 is target layer
			for (int m = 0; m < LAYER_SIZE; m++){//source neuron
				network->stack[l - 1].neurons[n] += network->stack[l].neurons[m] * network->stack[l - 1].weightsNext[n][m];
			}
			network->stack[l-1].neurons[n] = sigmoid(network->stack[l-1].neurons[n]);
		}
	}
}

void flowDown(LayerStack* stack){
	flowDownFrom(stack, LAYER_SIZE - 1);
}