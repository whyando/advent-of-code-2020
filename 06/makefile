all: run

run: 06.o input.txt
	./06.o < input.txt

%.o: %.cpp
	g++ --std=c++17 -O3 $< -o $@
