all: run

run: 24.o input.txt
	./24.o < input.txt

%.o: %.cpp
	g++ --std=c++17 -O3 $< -o $@
