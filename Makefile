debug:

	gcc -Wall -std=gnu99 src/DNN/src/*.c src/MNIST/src/*.c -o build/debug/dnn -lm 


release:

	gcc -Wall -std=gnu99 src/DNN/src/*.c src/MNIST/src/*.c -o build/release/dnn -lm 

clean:
	rm -r -f build/release/*
	rm -r -f build/debug/*

	
run_debug:
	./build/debug

