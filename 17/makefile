all: run

run: 17.o input.txt
	./17.o < input.txt

%.o: %.cpp
	g++ --std=c++17 -O3 $< -o $@
