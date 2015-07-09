//copyright 2015 (c) Marc Groefsema

#ifndef MNIST_H
#define MNIST_H

#include "hex_lib.h"
#include "macros.h"

int parseImage(char* input_file,int nImages,float** data);
int parseLabel(int argc, char** argv);

#endif
