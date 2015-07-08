debug:

	gcc -Wall -std=gnu99 src/DNN/src/*.c src/MNIST/src/*.c -o build/debug/dnn -lm 


release:

	gcc -Wall -std=gnu99 src/DNN/src/*.c src/MNIST/src/*.c -o build/release/dnn -lm 

clean:
	rm build/release/dnn/*
	rm build/debug/dnn/*
