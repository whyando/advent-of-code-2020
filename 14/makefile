all: run

run: 14.o input.txt
	./14.o < input.txt

%.o: %.cpp
	g++ --std=c++17 -O3 $< -o $@
