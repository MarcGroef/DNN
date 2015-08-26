//Copyright 2015 (C) Marc Groefsema

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