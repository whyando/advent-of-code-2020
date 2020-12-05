all: run

run: 03.o input.txt
	./03.o < input.txt

%.o: %.cpp
	g++ --std=c++17 -O3 $< -o $@
