//copyright 2015 (c) Marc Groefsema
#include <dnn/dnn_pretrainer.h>



float** allocViHj(int vSize,int hSize){
	printf("alloc vihj: %dx%d\n",vSize,hSize);
	float** d = malloc(vSize*sizeof(float*));
	assert(d!=NULL);
	for(int i=0;i<vSize;i++){
		d[i] = malloc(hSize*sizeof(float));
		assert(d[i]!=NULL);
	}
	return d;
}

void freeViHj(float** d,int vSize){
	for(int i=0;i<vSize;i++){
		free(d[i]);
	}
	free(d);
	
}

void computeViHj(LayerStack* l,int layer,float** civj){  //layer should be layer j
	if(layer==0)printf("dnn_pretrainer:computeCiVj: int layer should not be 0! It cannot downflow from that");
	for(int i=0;i<l->layerSizes[layer-1];i++){
		for(int j=0;j<l->layerSizes[layer];j++){
			civj[i][j]=l->layers[layer-1][i]*l->layers[layer][j];
		
			//printf("c%dv%d : %.3f!\n",i,j,l->layers[layer-1][i]*l->layers[layer][j]);
			//printf("hiddenlayer[%d] = %.3f\tvisLayer[%d] = %.3f\t vihj  = %.3f stored as %.3f\n\n",j,l->layers[layer][j],i,l->layers[layer-1][i],l->layers[layer-1][i]*l->layers[layer][j],civj[i][j]);
			
		}
	}
}

void performRBM(LayerStack* layers,Dataset* dataset,float learningRate,int nIterations,int kSteps){
	int datasetSize = dataset->size;
	float** vihjData;
	float** vihjModel;
	float learnStep;
	//iterate through layer stack
	for (int layer = 0; layer <layers->nLayers-1; layer++){ //layer i
		vihjData = allocViHj(layers->layerSizes[layer],layers->layerSizes[layer+1]);
		vihjModel = allocViHj(layers->layerSizes[layer],layers->layerSizes[layer+1]);
		for (int it=0;it<nIterations;it++){
			printf("RBM iteration %d at layer %d\n",it+1,layer);
			for (int dataLayer = 0; dataLayer < datasetSize; dataLayer++){
				setInputData(layers, dataset, dataLayer);
				flowUpUntil(layers,layer+1); // get next layer activation
				//showInputLayer2DImage(layers);
				computeViHj(layers,layer+1,vihjData);
				
				for(int k=1;k<kSteps;k++){// get  gibbs sample
					flowDownFrom(layers, layer+1);
					flowUpUntil(layers,layer+1);
					
				}
				computeViHj(layers,layer+1,vihjModel);
				//adapt weights
				for (int source = 0; source < layers->layerSizes[layer]; source++){
					for (int target = 0; target < layers->layerSizes[layer+1]; target++){
						
						
						learnStep = learningRate*(vihjData[source][target]-vihjModel[source][target]);
						layers->weights[layer][source][target] += learnStep;
						//printf("learnstep:%.3f\n",learnStep);
					}
				}
				
			}
		}
		freeViHj(vihjData,layers->layerSizes[layer]);
		freeViHj(vihjModel,layers->layerSizes[layer]);
	}

}
