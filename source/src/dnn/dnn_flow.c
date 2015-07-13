//copyright 2015 (c) Marc Groefsema

#include <dnn/dnn_flow.h>

void flowUpUntil(LayerStack *network,int layer){
	for (int l = 1; l < layer; l++){ //target layer
		for (int n = 0; n < LAYER_SIZE; n++){ //target neuron
			network->stack[l]->neurons[n] = 0;
			for (int m = 0; m < LAYER_SIZE; m++){//source neuron
				network->stack[l]->neurons[n] += network->stack[l - 1]->neurons[m] * network->stack[l - 1]->weightsNext[m][n];
			}
			network->stack[l]->neurons[n] = sigmoid(network->stack[l]->neurons[n]);
		}

	}

}

void flowUp(LayerStack *network){
	for (int l = 1; l < LAYER_SIZE; l++){ //target layer
		for (int n = 0; n < LAYER_SIZE; n++){ //target neuron
			network->stack[l]->neurons[n] = 0;
			for (int m = 0; m < LAYER_SIZE; m++){//source neuron
				network->stack[l]->neurons[n] += network->stack[l - 1]->neurons[m] * network->stack[l - 1]->weightsNext[m][n];
			}
			network->stack[l]->neurons[n] = sigmoid(network->stack[l]->neurons[n]);
		}
	}
}

void flowDownFrom(LayerStack* network, int layer){
	for (int l = layer; l > 0; l--){ //run from indicated layer down to second layer and flow down from it
		for (int n = 0; n < LAYER_SIZE; n++){ //target neuron
			network->stack[l - 1]->neurons[n] = 0;  // l-1 is target layer
			for (int m = 0; m < LAYER_SIZE; m++){//source neuron
				//printf("W%d,%d:%.2f\n",n,m,network->stack[l - 1]->weightsNext[n][m]);
				network->stack[l - 1]->neurons[n] += network->stack[l]->neurons[m] * network->stack[l - 1]->weightsNext[n][m];
			}
			network->stack[l-1]->neurons[n] = sigmoid(network->stack[l-1]->neurons[n]);
			//printf("Neuron %d @Layer %d:%.2f\n",n,l-1,network->stack[l-1]->neurons[n]);
		}
	}
}

void flowDown(LayerStack* stack){
	flowDownFrom(stack, LAYER_SIZE - 1);
}


void readNeuron(LayerStack* layers,int layer,int nNeurons){
	for(int j=0;j<nNeurons&&j<LAYER_SIZE;j++){
		printf("Neuron %d\n",j);
		for(int i=0;i<LAYER_SIZE;i++){
			layers->stack[layer]->neurons[i] = (i == j ? 1.0f : 0.0f);
			
		}
		flowDownFrom(layers,layer);
		showInputLayer2DImage(layers);
		
	}
}
