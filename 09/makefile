all: run

run: 09.o input.txt
	./09.o < input.txt

%.o: %.cpp
	g++ --std=c++17 -O3 $< -o $@
