build:
	gcc main.c binarySearch.c mergesort.c -o benchmark.out

run:
	./benchmark.out

bench:
	./benchmark.out
	cd Benchmark\ Analisis/ && Rscript analisis.r

all: build run
