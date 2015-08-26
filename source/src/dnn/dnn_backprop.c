//copyright 2015 (c) Marc Groefsema
#include <dnn/dnn_backprop.h>

void allocateDeltas(LayerStack* l,DeltaBuffer* d){
	d->nLayers = l->nLayers;
	d->deltas = malloc(sizeof(float*)*l->nLayers);
	assert(d->deltas!=NULL);
	for(int i=0;i<l->nLayers;i++){
	   d->deltas[i] = malloc(sizeof(float)*l->layerSizes[i]);
	   assert(d->deltas[i]!=NULL);
	}
}

void freeDeltas(DeltaBuffer* d){
	for(int i=0;i<d->nLayers;i++)
		free(d->deltas[i]);
	free(d->deltas);
}


void backpropIndex(LayerStack* layers, Dataset* data,int* targetOutput,int dataIndex,float learningRate){
	
	setInputData(layers,data, dataIndex);
	flowUp(layers);
	int outputSize = layers->layerSizes[layers->nLayers-1];
	DeltaBuffer d;
	//printf("malloc deltas\n");
	allocateDeltas(layers,&d);
	//printf("get first deltas\n");
	for(int i=0;i<outputSize;i++){  //get deltas from output layer
	   float out = layers->layers[layers->nLayers-1][i];
	   d.deltas[d.nLayers-1][i] =  out*(1-out)*(out-targetOutput[i]);	   
	}
	//printf("getting other deltas\n");
	for(int l=layers->nLayers-2;l>0;l--){  //get other deltas
	   for(int i=0;i<layers->layerSizes[l];i++){
	      float out = layers->layers[l][i];
	      float sum=0;
	      for(int j=0;j<layers->layerSizes[l+1];j++){
	         sum += d.deltas[l+1][j]*layers->weights[l][i][j];
	      }
	      d.deltas[l][i] = out * (1 - out) * sum;
	   }
	}//we now have all deltas
	//printf("yay, all deltas. Now edit weights..\n");
	for(int l=0;l<layers->nLayers-1;l++){ //update weights
	   for(int i=0;i<layers->layerSizes[l];i++){
	      for(int j=0;j<layers->layerSizes[l+1];j++){
		      //printf("edit weight from layer %d, neuron %d, to next layer neuron %d\n",l,i,j);
	         layers->weights[l][i][j]-= learningRate * d.deltas[l][i] * layers->layers[l][i];  
	      }
	   }		
	}
	//printf("done\n");
	
	
	

}

void backprop(LayerStack* layers,Dataset* data,int targetSize, float learningRate,int nIterations){
	//prepare targetOutput
	int* targetOutput = malloc(targetSize*sizeof(int));
	assert(targetOutput!=NULL);

	for(int j=0;j<nIterations;j++){
		printf("Backprop iteration %d\n",j);
		for(int i=0;i<data->size;i++){
			//printf("output for target = %d:",data->labels[i]);
			for(int k=0;k<targetSize;k++){
				targetOutput[k] = (k == data->labels[i]?1.0f:0.0f);
				//printf(" %d",targetOutput[k]);
			}
			//putchar('\n');
			backpropIndex(layers,data,targetOutput,i,learningRate);
		}
	}
}