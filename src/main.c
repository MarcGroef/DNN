//copyright 2015 (c) Marc Groefsema
#include <stdio.h>
#include <stdlib.h>

#include "DNN/include/dnn.h"
#include "MNIST/include/mnist.h"

int main(int argc, char**argv){
	if(argc!=2){
		printf("argc:%d\n",argc);
		printf("Usage: ./dnn <mnist image directory>\n");
		
		return 0;
	}
	DNN_Module dnn;
	initDNNModule(&dnn);
	addMNIST(argv[1],&dnn.dataset,10);
	initStackWeightsRandom(&dnn.network);
	performRBM(&dnn.network, &dnn.dataset,0.2,10);
	return 0;
}
