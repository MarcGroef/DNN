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
	printf("argv[1]=%s\n",argv[1]);
	DNN_Module dnn;
	addMNIST(argv[1],&dnn.dataset,10);
	
	return 0;
}
