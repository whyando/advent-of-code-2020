all: run

run: 23.o input.txt
	./23.o < input.txt

%.o: %.cpp
	g++ --std=c++17 -O3 $< -o $@
