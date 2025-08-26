build:
	gcc main.c search.c mergesort.c -o benchmark.out

run:
	./benchmark.out

bench:
	./benchmark.out
	cd Benchmark\ Analysis/ && Rscript analysis.r

all: build run
