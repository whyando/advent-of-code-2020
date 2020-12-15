all: run

run: 15.o input.txt
	./15.o < input.txt

%.o: %.cpp
	g++ --std=c++17 -O3 $< -o $@
