all: run

run: 21.o input.txt
	./21.o < input.txt

%.o: %.cpp
	g++ --std=c++17 -O3 $< -o $@
