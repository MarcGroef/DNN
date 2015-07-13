cmake_minimum_required (VERSION 2.6)
project (DeepNet)



add_executable (
DeepNet
src/main.c 

src/dnn/dnn_backprop.c
src/dnn/dnn_data.c
src/dnn/dnn_flow.c
src/dnn/dnn_layer.c
src/dnn/dnn_layer_stack.c
src/dnn/dnn_math.c
src/dnn/dnn_module.c
src/dnn/dnn_pretrainer.c
src/dnn/dnn_show.c
src/dnn/dnn_weights.c

src/MNIST/hex_lib.c
src/MNIST/mnist_image_parser.c
src/MNIST/mnist_label_parser.c
)


 find_package(OpenCV 3.0.0 EXACT REQUIRED NO_MODULE)


include_directories(${OpenCV_INCLUDE_DIR} "include/" )

set_target_properties(DeepNet PROPERTIES RUNTIME_OUTPUT_DIRECTORY "../build/debug")
add_definitions("-std=gnu99 -g ")
target_link_libraries (DeepNet ${OpenCV_LIBS} -lm)
