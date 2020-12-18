all: run

run: 18.o input.txt
	./18.o < input.txt

%.o: %.cpp
	g++ --std=c++17 -O3 $< -o $@
