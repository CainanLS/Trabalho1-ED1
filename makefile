build:
	gcc main.c binarySearch.c mergesort.c -o benchmark.out

run:
	./benchmark.out

all: build run
