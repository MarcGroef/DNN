#include <dnn/dnn_classifier.h>

int classify(LayerStack* s,Dataset* d){
	for(int i=0;i<d->size;i++){
		setInputData(s, d, i);
		flowUp(s);
		showLayer(s,s->nLayers-1);
		printf("target value: %d\n",d->labels[i]);
		getchar();
	}
}