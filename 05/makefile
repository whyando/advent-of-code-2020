all: run

run: 05.o input.txt
	./05.o < input.txt

%.o: %.cpp
	g++ --std=c++17 -O3 $< -o $@
