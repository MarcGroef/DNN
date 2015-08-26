//copyright 2015 (c) Marc Groefsema
#include <dnn/dnn_data.h>


void datasetAlloc(Dataset* dataset, int size){
	dataset->size = size;
	dataset->data = (float**)malloc(size*sizeof(float*));
	assert(dataset->data != NULL);
	for (int i = 0; i < size; i++){
		dataset->data[i] =(float*) malloc(INPUT_LAYER_SIZE*sizeof(float));
		assert(dataset->data[i] != NULL);
	}
	printf("Allocated dataset: %d bytes\n",(int)(size*sizeof(float*)+INPUT_LAYER_SIZE*sizeof(float)));
}


void datasetFree(Dataset* dataset){
	for (int i = 0; i < dataset->size; i++)
		free(dataset->data[i]);
	free(dataset->data);
	free(dataset->labels);
}

void addMNIST(char* mnist_image_dir,char* mnist_label_dir,Dataset* dataset,int size){
	int parseSucces;
	if(dataset->data==NULL)
		datasetAlloc(dataset,size);
	parseSucces = parseImage(mnist_image_dir,size,dataset->data);
	dataset->labels=parseLabel(mnist_label_dir);
	printf("labels parsed!\n");
}
