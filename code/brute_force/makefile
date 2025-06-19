all: run

build:
	g++ -O2 -std=c++17 brute_force.cpp -o brute_force

run: build
	./brute_force < data/brute_force_input/a.txt > data/brute_force_output/a.txt

clean:
	rm -f brute_force
	rm -f data/brute_force_output/a.txt
