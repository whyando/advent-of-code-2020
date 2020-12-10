all: run

run: 10.o input.txt
	./10.o < input.txt

%.o: %.cpp
	g++ --std=c++17 -O3 $< -o $@
