all: run

run: 20.o input.txt
	./20.o < input.txt

%.o: %.cpp
	g++ --std=c++17 -O3 $< -o $@
