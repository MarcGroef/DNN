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
#include <dnn/dnn_weights.h>

int randset = 0;
float randf(float bot,float top){
	time_t t;
	float ret ;	
	if(!randset){	
		srand((unsigned) time(&t));
		++randset;
	}
	ret = bot+(float)rand()/((float)RAND_MAX/(top-bot));
//	printf("%.2f\n", ret);
	return ret;
}

void initWeightsRandom(LayerStack* ls,int layer){
	int i,j;
	for(i=0;i<ls->layerSizes[layer];i++){
		for(j=0;j<ls->layerSizes[layer+1];j++){
			ls->weights[layer][i][j]=randf(-.2f,.2f);
		}
	}
}

void initStackWeightsRandom(LayerStack* ls){
	int i;
	for(i=0;i<ls->nLayers-1;i++){  //skip last layer
		initWeightsRandom(ls,i);
		//printf("set weights of layer %d\n",i);
	}
}
