#!/bin/bash
#Script to run the dnn project

echo "starting executing DNN..."


#call program
./build/debug/dnn devel/MNIST_dataset/t10k-images.idx3-ubyte
