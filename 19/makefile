all: run

run: 19.o input.txt
	./19.o < input.txt

%.o: %.cpp
	g++ --std=c++17 -O3 $< -o $@
