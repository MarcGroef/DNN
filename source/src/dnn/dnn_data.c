//copyright 2015 (c) Marc Groefsema
#include <dnn/dnn_data.h>


void datasetAlloc(Dataset* dataset, int size){
	dataset->size = size;
	dataset->data = (float**)malloc(size*sizeof(float*));
	assert(dataset->data != NULL);
	for (int i = 0; i < size; i++){
		dataset->data[i] =(float*) malloc(LAYER_SIZE*sizeof(float));
		assert(dataset->data[i] != NULL);
	}
	printf("Allocated dataset: %d bytes\n",(int)(size*sizeof(float*)+LAYER_SIZE*sizeof(float)));
}


void datasetFree(Dataset* dataset){
	for (int i = 0; i < dataset->size; i++)
		free(dataset->data[i]);
	free(dataset->data);
}

void addMNIST(char* mnist_dir,Dataset* dataset,int size){
	int parseSucces;
	if(dataset->data==NULL)
		datasetAlloc(dataset,size);
	parseSucces = parseImage(mnist_dir,size,dataset->data);
	
}
