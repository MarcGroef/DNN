#include <dnn_classifier.h>

int classify(LayerStack* s,Dataset* d,int index){
	for(int i=0;i<d->size;i++){
		setInputData(s, d, index);
		flowUp();
		showLayer(s,s->nLayers-1);
		printf("target value: %d\n",d->labels[i]);
		getchar();
	}
}