//copyright 2015 (c) Marc Groefsema

#ifndef DNN_CONSTANTS_H
#define DNN_CONSTANTS_H

//dnn settings
/*OLD
#define LAYER_SIZE 28*28  //specified for MNIST at the moment
#define LAYER_STACK_SIZE 2  //inputlayer+hidden layers = 1 +nHiddenLayers
#define OUTPUT_LAYER_SIZE 3

*/

#define LAYER_STACK_SIZE 4
#define LAYER_SIZES {28*28,200,200,10}
#define INPUT_LAYER_SIZE 28*28

#define LEARNING_RATE 0.2 //should be 0<=alpha<=1




#endif