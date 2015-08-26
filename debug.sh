#!/bin/bash
#Script to run the dnn project
cd source/
make
cd ..
echo "starting executing DNN..."


#call program
valgrind -v ./build/debug/DeepNet devel/MNIST_dataset/t10k-images.idx3-ubyte devel/MNIST_dataset/t10k-labels.idx1-ubyte
