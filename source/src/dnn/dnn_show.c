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

#include <dnn/dnn_show.h>


void showLayer(LayerStack* stack,int layer){
	for(int i=0;i<stack->layerSizes[layer];i++){
		printf("%c",(stack->layers[layer][i]<0.5f?'.':'*'));
	}
}

void showInputLayer2D(LayerStack* stack){
	int width = (int)sqrt(stack->layerSizes[0]);
	char c;
	printf("-----------------------------------------\n");
	for(int i=0;i<width;i++){
		for(int j=0;j<width;j++){
			//printf("%c",(stack->stack[0]->neurons[width*i+j]<0.5f?' ':'*'));
			if(stack->layers[0][width*i+j]<.25f)
				c=' ';
			else if(stack->layers[0][width*i+j]<0.5f)
				c='.';
			else if(stack->layers[0][width*i+j]<.75f)
				c='*';
			else 
				c='x';
			printf("%c ",c);
//			printf("%.2f ",stack->stack[0].neurons[width*i+j]);
		}
		printf("\n");
	}
}

void showInputLayer2DImage(LayerStack* stack){
	//printf("show image\n");
	int scale = 10;
	CvMat* image;
	int width = sqrt(stack->layerSizes[0]);
	image =cvCreateMat(width*scale,width*scale,CV_8UC1);
	//upscaled =cvCreateMat(width*scale,width*scale,CV_8UC1);
	unsigned char* data = malloc((width*width*scale*scale)*sizeof(unsigned char));
	assert(data!=NULL);
	for(int i=0;i<width*scale;i++){
		for(int j=0;j<width*scale;j++){
			//printf("to %d from %d\n",i*width*scale+j,(i/scale)*width+j/scale);
			data[i*width*scale+j] = 255-(stack->layers[0][(i/scale)*width+j/scale]*255);
			//printf("neuron: %.3f, pixel: %d \n",stack->stack[0]->neurons[i],data[i]);
		}
	}
	cvSetData(image,data,width*scale);

	

	
	cvNamedWindow("NeuroOutput",CV_WINDOW_AUTOSIZE);
	cvShowImage("NeuroOutput",image);
	cvWaitKey(0);
	
	cvReleaseMat(&image);
	free(data);
	//cvReleaseMat(&upscaled);
}