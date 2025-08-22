build:
	gcc main.c binarySearch.c -o benchmark.out

run:
	./benchmark.out

all: build run
