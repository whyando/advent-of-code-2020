all: run

run: 22.o input.txt
	./22.o < input.txt

%.o: %.cpp
	g++ --std=c++17 -O3 $< -o $@
