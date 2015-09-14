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
#include <dnn/dnn_layer_stack.h>

void initLayerStack(LayerStack* net,int nLayers,int* layerSizes){
	
	net->nLayers = nLayers; 
	
	net->layers = malloc(net->nLayers*sizeof(float*)); //alloc layers
	assert(net->layers!=NULL);
	net->layerSizes = malloc(net->nLayers*sizeof(int));
	assert(net->layerSizes!=NULL);
	for(int i=0;i<net->nLayers;i++){
		net->layers[i] = malloc(layerSizes[i]*sizeof(float));
		assert(net->layers[i]!=NULL);
		net->layerSizes[i] = layerSizes[i];
		printf("layersizes[%d] = %d\n",i,layerSizes[i]);
	}
	net->weights = malloc((net->nLayers-1)*sizeof(float**));
	assert(net->weights!=NULL);
	
	for(int i=0;i<net->nLayers-1;i++){
		net->weights[i] = malloc(net->layerSizes[i]*sizeof(float*));
		assert(net->weights[i]!=NULL);
		for(int j=0;j<net->layerSizes[i];j++){
			net->weights[i][j] = malloc(net->layerSizes[i+1]*sizeof(float));
			assert(net->weights!=NULL);
		}
	}
	
}

void setInputData(LayerStack* net,Dataset* data, int index){
	//printf("setInputData %d\n",index);
	for(int i=0;i<net->layerSizes[0];i++){
		//printf("setting neuron %d to %.2f\n",i,data->data[index][i]);
		net->layers[0][i]=(float)data->data[index][i]/255.0;
	}
	
}



void freeLayerStack(LayerStack* ls){
	
	for(int i=0;i<ls->nLayers-1;i++){
		for(int j=0;j<ls->layerSizes[i];j++){
			free(ls->weights[i][j]);
		}
		free(ls->weights[i]);
	}
	free(ls->weights);
	
	for(int i=0;i<ls->nLayers;i++){
		free(ls->layers[i]);
	}
	free(ls->layers);
	free(ls->layerSizes);
	
}
