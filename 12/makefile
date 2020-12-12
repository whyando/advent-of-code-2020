all: run

run: 12.o input.txt
	./12.o < input.txt

%.o: %.cpp
	g++ --std=c++17 -O3 $< -o $@
