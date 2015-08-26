//copyright 2015 (c) Marc Groefsema
#include <stdio.h>
#include <stdlib.h>

#include <dnn/dnn.h>
#include <MNIST/mnist.h>

int main(int argc, char**argv){
	if(argc!=3){
		printf("argc:%d\n",argc);
		printf("Usage: ./dnn <mnist image directory> <mnist label directory>\n");
		
		return 0;
	}
	DNNModule dnn;
	initDNNModule(&dnn);
	addMNIST(argv[1],argv[2],&dnn.dataset,200);
	initStackWeightsRandom(&dnn.network);
	//
	performRBM(&dnn.network, &dnn.dataset,LEARNING_RATE,20,5); //learningrate, nIterations per layer,kSteps
	/*for(int i=0;i<10;i++){
		setInputData(&dnn.network,&dnn.dataset,i);
		showInputLayer2DImage(&dnn.network);
	}*/
	backprop(&dnn.network, &dnn.dataset,10,LEARNING_RATE,500);
	readLayer(&dnn.network,dnn.network.nLayers-1);
	classify(&dnn.network,&dnn.dataset);
 	freeDNNModule(&dnn);
	return 0;
}
