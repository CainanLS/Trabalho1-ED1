.PHONY: build run all

build:
	gcc main.c search.c utils.c -o benchmark

run:
	./benchmark

bench:
	cd Results/RandomCase && Rscript analysisRandom.r 
	cd Results/BestCase && Rscript analysisBest.r 
	cd Results/WorstCase && Rscript analysisWorst.r

all: build run bench
