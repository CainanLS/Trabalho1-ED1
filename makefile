build:
	gcc main.c search.c mergesort.c -o benchmark.out

run:
	./benchmark.out

bench:
	./benchmark.out
	cd Benchmark\ Analisis/ && Rscript analysis.r

all: build run
