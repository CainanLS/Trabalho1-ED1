build:
	gcc main.c search.c utils.c -o benchmark

run:
	./benchmark

bench:
	cd Results && Rscript analysis.r && Rscript analysisBest.r && Rscript analysisWorst.r

all: build run bench
