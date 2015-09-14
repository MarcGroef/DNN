//copyright 2015 (c) Marc Groefsema
/*
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include <dnn/dnn_flow.h>

void flowUpUntil(LayerStack *network,int layer){
	//printf("flowup until %d\n",layer);
        int l,n,m;
	for ( l = 1; l <= layer; l++){ //target layer
		//OLD
		/*for (int n = 0; n < LAYER_SIZE; n++){ //target neuron
			network->stack[l]->neurons[n] = 0;
			for (int m = 0; m < LAYER_SIZE; m++){//source neuron
				network->stack[l]->neurons[n] += network->stack[l - 1]->neurons[m] * network->stack[l - 1]->weightsNext[m][n];
			}
			network->stack[l]->neurons[n] = sigmoid(network->stack[l]->neurons[n]);
		}*/
		//printf("flowup to layer %d\n",l);
		for (n = 0; n < network->layerSizes[l]; n++){ //target neuron
			network->layers[l][n] = 0;
			for (m = 0; m < network->layerSizes[l-1]; m++){//source neuron
				network->layers[l][n] += network->layers[l - 1][m] * network->weights[l-1][m][n];
			}
			network->layers[l][n] = sigmoid(network->layers[l][n]);
			//printf("layer %d neuron %d: %.3f\n",l,n,network->layers[l][n]);
		}

	}

}

void flowUp(LayerStack *network){
	int l,n;
	for (int l = 1; l < network->nLayers; l++){ //target layer
		//OLD
		/*for (int n = 0; n < LAYER_SIZE; n++){ //target neuron
			network->stack[l]->neurons[n] = 0;
			for (int m = 0; m < LAYER_SIZE; m++){//source neuron
				network->stack[l]->neurons[n] += network->stack[l - 1]->neurons[m] * network->stack[l - 1]->weightsNext[m][n];
			}
			network->stack[l]->neurons[n] = sigmoid(network->stack[l]->neurons[n]);
		}*/
		for (n = 0; n < network->layerSizes[l]; n++){ //target neuron
			network->layers[l][n] = 0;
			for (m = 0; m < network->layerSizes[l-1]; m++){//source neuron
				network->layers[l][n] += network->layers[l - 1][m] * network->weights[l - 1][m][n];
			}
			network->layers[l][n] = sigmoid(network->layers[l][n]);
		}
		
	}
}

void flowDownFrom(LayerStack* network, int layer){
	int l,n,m;
	for (l = layer; l > 0; l--){ //run from indicated layer down to second layer and flow down from it
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
		for (n = 0; n < network->layerSizes[l-1]; n++){ //target neuron
			network->layers[l - 1][n] = 0;  // l-1 is target layer
			for (m = 0; m < network->layerSizes[l]; m++){//source neuron
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
	int i,j;
	for(j=0;j<layers->layerSizes[layer];j++){
		printf("Neuron %d\n",j);
		for(i=0;i<layers->layerSizes[layer];i++){
			layers->layers[layer][i] = (i == j ? 1.0f : 0.0f);
			
		}
		flowDownFrom(layers,layer);
		showInputLayer2DImage(layers);
		
	}
}
