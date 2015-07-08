//copyright 2015 (c) Marc Groefsema
#include "../include/dnn_pretrainer.h"

//copy a float array like a neuron layer:
// memcpy(source,target,LAYER_SIZE*sizeof(float))

void performRBM(LayerStack* layers,Dataset* dataset,float learningRate){
	int datasetSize = dataset->size;
	//iterate through layer stack
	for (int layer = 0; layer < LAYER_STACK_SIZE; layer++){
		for (int dataLayer = 0; dataLayer < datasetSize; dataLayer++){
			setInputData(layers, dataset, dataLayer);
			flowUpUntil(layers,layer); // get next layer activation
			flowDownFrom(layers, layer); // get k=1 gibbs sample

			//adapt weights
			for (int source = 0; source < LAYER_SIZE; source++){
				for (int target = 0; target < LAYER_SIZE; target++){
					layers->stack[layer].weightsNext[source][target] +=  //TODO needs checking
						learningRate*((dataset->data[dataLayer][source] * layers->stack[layer + 1].neurons[target]) - 
						(layers->stack[layer].neurons[source]*layers->stack[layer + 1].neurons[target]));

				}
			}
			
		}
	}
}