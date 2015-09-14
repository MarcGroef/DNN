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
#include <dnn/dnn_pretrainer.h>



float** allocViHj(int vSize,int hSize){
	int i;
	printf("alloc vihj: %dx%d\n",vSize,hSize);
	float** d = malloc(vSize*sizeof(float*));
	assert(d!=NULL);
	for(i=0;i<vSize;i++){
		d[i] = malloc(hSize*sizeof(float));
		assert(d[i]!=NULL);
	}
	return d;
}

void freeViHj(float** d,int vSize){
	int i;
	for(i=0;i<vSize;i++){
		free(d[i]);
	}
	free(d);
	
}

void computeViHj(LayerStack* l,int layer,float** civj){  //layer should be layer j
	int i,j;
	if(layer==0)printf("dnn_pretrainer:computeCiVj: int layer should not be 0! It cannot downflow from that");
	for(i=0;i<l->layerSizes[layer-1];i++){
		for(j=0;j<l->layerSizes[layer];j++){
			civj[i][j]=l->layers[layer-1][i]*l->layers[layer][j];
		
			//printf("c%dv%d : %.3f!\n",i,j,l->layers[layer-1][i]*l->layers[layer][j]);
			//printf("hiddenlayer[%d] = %.3f\tvisLayer[%d] = %.3f\t vihj  = %.3f stored as %.3f\n\n",j,l->layers[layer][j],i,l->layers[layer-1][i],l->layers[layer-1][i]*l->layers[layer][j],civj[i][j]);
			
		}
	}
}

void performRBM(LayerStack* layers,Dataset* dataset,float learningRate,int nIterations,int kSteps){
	int layer,it,dataLayer,k,source,target;
	int datasetSize = dataset->size;
	float** vihjData;
	float** vihjModel;
	float learnStep;
	float totalLearned=0;
	float prevTotalLearned=0;
	float preprevTotalLearned=0;
	float diffThreshold=0.00000001;
	int it=0;
	//iterate through layer stack
	for (layer = 0; layer <layers->nLayers-2; layer++){ //layer i
		vihjData = allocViHj(layers->layerSizes[layer],layers->layerSizes[layer+1]);
		vihjModel = allocViHj(layers->layerSizes[layer],layers->layerSizes[layer+1]);
		//for (int it=0;it<nIterations;it++){
		printf("%f\n",fabs(totalLearned-((prevTotalLearned+preprevTotalLearned+totalLearned)/3)));
		for(it=0;it<3||fabs(totalLearned-((prevTotalLearned+preprevTotalLearned+totalLearned)/3))>diffThreshold;it++){
			//printf("RBM iteration %d at layer %d\n",it+1,layer);
			totalLearned=0;
			for (dataLayer = 0; dataLayer < datasetSize; dataLayer++){
				
				setInputData(layers, dataset, dataLayer);
				flowUpUntil(layers,layer+1); // get next layer activation
				//showInputLayer2DImage(layers);
				computeViHj(layers,layer+1,vihjData);
				
				for(k=1;k<kSteps;k++){// get  gibbs sample
					flowDownFrom(layers, layer+1);
					flowUpUntil(layers,layer+1);
					
				}
				computeViHj(layers,layer+1,vihjModel);
				//adapt weights
				for (source = 0; source < layers->layerSizes[layer]; source++){
					for (target = 0; target < layers->layerSizes[layer+1]; target++){
						
						
						learnStep = learningRate*(vihjData[source][target]-vihjModel[source][target]);
						layers->weights[layer][source][target] += learnStep;
						totalLearned+=fabs(learnStep);
						//printf("learnstep:%.3f\n",learnStep);
					}
				}
				
				
			}
			totalLearned/=datasetSize*layers->layerSizes[layer]*layers->layerSizes[layer+1];
			preprevTotalLearned = prevTotalLearned;
			prevTotalLearned = totalLearned;
			
			
			float var = fabs(totalLearned-((prevTotalLearned+preprevTotalLearned+totalLearned)/3));
			printf("totalWeight edit @ %d: dW:%f w:%f\n",it,var,totalLearned);
			
		}
		freeViHj(vihjData,layers->layerSizes[layer]);
		freeViHj(vihjModel,layers->layerSizes[layer]);
	}

}
