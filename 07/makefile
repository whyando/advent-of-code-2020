all: run

run: 07.o input.txt
	./07.o < input.txt

%.o: %.cpp
	g++ --std=c++2a -O3 $< -o $@
