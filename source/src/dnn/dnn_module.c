//copyright 2015 (c) Marc Groefsema
#include <dnn/dnn_module.h>

void initDNNModule(DNNModule* module){
	initLayerStack(&module->network);
	//allocLayerStack(&module->network);
	module->dataset.data=NULL;
	
}

void freeDNNModule(DNNModule* m){
	datasetFree(&m->dataset);
	freeLayerStack(&m->network);
	
}
