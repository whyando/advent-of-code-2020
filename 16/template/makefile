all: run

run: 16.o input.txt
	./16.o < input.txt

%.o: %.cpp
	g++ --std=c++17 -O3 $< -o $@
