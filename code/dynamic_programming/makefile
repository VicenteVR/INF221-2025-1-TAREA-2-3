all: run

build:
	g++ -O2 -std=c++17 dynamic_programming.cpp -o dynamic_programming

run: build
	./dynamic_programming < data/dynamic_programming_input/a.txt > data/dynamic_programming_output/a.txt

clean:
	rm -f dynamic_programming
	rm -f data/dynamic_programming_output/a.txt
