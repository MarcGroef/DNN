//copyright 2015 (c) Marc Groefsema

#include <dnn/dnn_flow.h>

void flowUpUntil(LayerStack *network,int layer){
	//printf("flowup until %d\n",layer);
	for (int l = 1; l <= layer; l++){ //target layer
		//OLD
		/*for (int n = 0; n < LAYER_SIZE; n++){ //target neuron
			network->stack[l]->neurons[n] = 0;
			for (int m = 0; m < LAYER_SIZE; m++){//source neuron
				network->stack[l]->neurons[n] += network->stack[l - 1]->neurons[m] * network->stack[l - 1]->weightsNext[m][n];
			}
			network->stack[l]->neurons[n] = sigmoid(network->stack[l]->neurons[n]);
		}*/
		//printf("flowup to layer %d\n",l);
		for (int n = 0; n < network->layerSizes[l]; n++){ //target neuron
			network->layers[l][n] = 0;
			for (int m = 0; m < network->layerSizes[l-1]; m++){//source neuron
				network->layers[l][n] += network->layers[l - 1][m] * network->weights[l-1][m][n];
			}
			network->layers[l][n] = sigmoid(network->layers[l][n]);
			//printf("layer %d neuron %d: %.3f\n",l,n,network->layers[l][n]);
		}

	}

}

void flowUp(LayerStack *network){
	for (int l = 1; l < network->nLayers; l++){ //target layer
		//OLD
		/*for (int n = 0; n < LAYER_SIZE; n++){ //target neuron
			network->stack[l]->neurons[n] = 0;
			for (int m = 0; m < LAYER_SIZE; m++){//source neuron
				network->stack[l]->neurons[n] += network->stack[l - 1]->neurons[m] * network->stack[l - 1]->weightsNext[m][n];
			}
			network->stack[l]->neurons[n] = sigmoid(network->stack[l]->neurons[n]);
		}*/
		for (int n = 0; n < network->layerSizes[l]; n++){ //target neuron
			network->layers[l][n] = 0;
			for (int m = 0; m < network->layerSizes[l-1]; m++){//source neuron
				network->layers[l][n] += network->layers[l - 1][m] * network->weights[l - 1][m][n];
			}
			network->layers[l][n] = sigmoid(network->layers[l][n]);
		}
		
	}
}

void flowDownFrom(LayerStack* network, int layer){
	for (int l = layer; l > 0; l--){ //run from indicated layer down to second layer and flow down from it
		//OLD
		/*
		for (int n = 0; n < LAYER_SIZE; n++){ //target neuron
			network->stack[l - 1]->neurons[n] = 0;  // l-1 is target layer
			for (int m = 0; m < LAYER_SIZE; m++){//source neuron
				//printf("W%d,%d:%.2f\n",n,m,network->stack[l - 1]->weightsNext[n][m]);
				network->stack[l - 1]->neurons[n] += network->stack[l]->neurons[m] * network->stack[l - 1]->weightsNext[n][m];
			}
			network->stack[l-1]->neurons[n] = sigmoid(network->stack[l-1]->neurons[n]);
			//printf("Neuron %d @Layer %d:%.2f\n",n,l-1,network->stack[l-1]->neurons[n]);
		}*/
		for (int n = 0; n < network->layerSizes[l-1]; n++){ //target neuron
			network->layers[l - 1][n] = 0;  // l-1 is target layer
			for (int m = 0; m < network->layerSizes[l]; m++){//source neuron
				//printf("W%d,%d:%.2f\n",n,m,network->stack[l - 1]->weightsNext[n][m]);
				network->layers[l - 1][n] += network->layers[l][m] * network->weights[l - 1][n][m];
			}
			network->layers[l-1][n] = sigmoid(network->layers[l-1][n]);
			//printf("Neuron %d @Layer %d:%.2f\n",n,l-1,network->stack[l-1]->neurons[n]);
		}
	}
}

void flowDown(LayerStack* stack){
	flowDownFrom(stack, stack->nLayers - 1);
}


void readLayer(LayerStack* layers,int layer){
	for(int j=0;j<layers->layerSizes[layer];j++){
		printf("Neuron %d\n",j);
		for(int i=0;i<layers->layerSizes[layer];i++){
			layers->layers[layer][i] = (i == j ? 1.0f : 0.0f);
			
		}
		flowDownFrom(layers,layer);
		showInputLayer2DImage(layers);
		
	}
}
