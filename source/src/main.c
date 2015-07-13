//copyright 2015 (c) Marc Groefsema
#include <stdio.h>
#include <stdlib.h>

#include <dnn/dnn.h>
#include <MNIST/mnist.h>

int main(int argc, char**argv){
	if(argc!=2){
		printf("argc:%d\n",argc);
		printf("Usage: ./dnn <mnist image directory>\n");
		
		return 0;
	}
	DNNModule dnn;
	initDNNModule(&dnn);
	addMNIST(argv[1],&dnn.dataset,1);
	initStackWeightsRandom(&dnn.network);
	performRBM(&dnn.network, &dnn.dataset,.9,100,1);
	/*for(int i=0;i<100;i++){
		setInputData(&dnn.network,&dnn.dataset,i);
		showInputLayer2DImage(&dnn.network);
	}*/
	readNeuron(&dnn.network,LAYER_STACK_SIZE-1,LAYER_SIZE);
	
 	freeDNNModule(&dnn);
	return 0;
}
