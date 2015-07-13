//copyright 2015 (c) Marc Groefsema
#include <dnn/dnn_pretrainer.h>



float** allocViHj(){
	float** d = malloc(LAYER_SIZE*sizeof(float*));
	assert(d!=NULL);
	for(int i=0;i<LAYER_SIZE;i++){
		d[i] = malloc(LAYER_SIZE*sizeof(float));
		assert(d[i]!=NULL);
	}
	return d;
}

void freeViHj(float** d){
	for(int i=0;i<LAYER_SIZE;i++){
		free(d[i]);
	}
	free(d);
	
}

void computeViHj(LayerStack* l,int layer,float** civj){
	if(layer==0)printf("dnn_pretrainer:computeCiVj: int layer should not be 0! It cannot downflow from that");
	for(int i=0;i<LAYER_SIZE;i++){
		for(int j=0;j<LAYER_SIZE;j++){
			civj[i][j]=l->stack[layer-1]->neurons[i]*l->stack[layer]->neurons[j];
		}
	}
}

void performRBM(LayerStack* layers,Dataset* dataset,float learningRate,int nIterations,int kSteps){
	int datasetSize = dataset->size;
	float** vihjData = allocViHj();
	float** vihjModel = allocViHj();
	//iterate through layer stack
	for (int layer = 0; layer < LAYER_STACK_SIZE-1; layer++){
	
		for (int it=0;it<nIterations;it++){
			printf("RBM iteration %d at layer %d\n",it+1,layer);
			for (int dataLayer = 0; dataLayer < datasetSize; dataLayer++){
				setInputData(layers, dataset, dataLayer);
				flowUpUntil(layers,layer); // get next layer activation
				computeViHj(layers,layer+1,vihjData);
				
				for(int k=1;k<kSteps;k++){// get  gibbs sample
					flowDownFrom(layers, layer);
					flowUpUntil(layers,layer);
					
				}
				computeViHj(layers,layer+1,vihjModel);
				//adapt weights
				for (int source = 0; source < LAYER_SIZE; source++){
					for (int target = 0; target < LAYER_SIZE; target++){
						layers->stack[layer]->weightsNext[source][target] +=  //TODO needs checking
							learningRate*(vihjData[source][target]-vihjModel[source][target]);

					}
				}
				
			}
		}
	}
	freeViHj(vihjData);
	freeViHj(vihjModel);
}
