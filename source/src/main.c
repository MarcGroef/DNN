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
	addMNIST(argv[1],&dnn.dataset,1000);
	initStackWeightsRandom(&dnn.network);
	performRBM(&dnn.network, &dnn.dataset,.2,100,4); //learningrate, nIterations per layer,kSteps
	/*for(int i=0;i<10;i++){
		setInputData(&dnn.network,&dnn.dataset,i);
		showInputLayer2DImage(&dnn.network);
	}*/
	readLayer(&dnn.network,dnn.network.nLayers-1);
	
 	freeDNNModule(&dnn);
	return 0;
}
