all: run

run: 13.o input.txt
	./13.o < input.txt

%.o: %.cpp
	g++ --std=c++17 -O3 $< -o $@
