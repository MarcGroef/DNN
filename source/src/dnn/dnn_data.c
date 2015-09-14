//copyright 2015 (c) Marc Groefsema
/*
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/
#include <dnn/dnn_data.h>


void datasetAlloc(Dataset* dataset, int size,int nEntries){
	int i;
	dataset->size = nEntries;
	dataset->data = (float**)malloc(nEntries*sizeof(float*));
	assert(dataset->data != NULL);
	for (i = 0; i < nEntries; i++){
		dataset->data[i] =(float*) malloc(size*sizeof(float));
		assert(dataset->data[i] != NULL);
	}
	printf("Allocated dataset: %d bytes\n",(int)(nEntries*sizeof(float*)+size*sizeof(float)));
}


void datasetFree(Dataset* dataset){
	int i;
	for (i = 0; i < dataset->size; i++)
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
