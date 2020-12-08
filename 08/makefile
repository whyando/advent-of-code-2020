all: run

run: 08.o input.txt
	./08.o < input.txt

%.o: %.cpp
	g++ --std=c++17 -O3 $< -o $@
