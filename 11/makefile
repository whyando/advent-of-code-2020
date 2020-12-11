all: run

run: 11.o input.txt
	./11.o < input.txt

%.o: %.cpp
	g++ --std=c++17 -O3 $< -o $@
