all: run

run: 04.o input.txt
	./04.o < input.txt

%.o: %.cpp
	g++ --std=c++2a -O3 $< -o $@
