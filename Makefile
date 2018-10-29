output: bin/out/main.o bin/out/quicksort.o bin/out/parallelQuicksort.o
	gcc bin/out/main.o bin/out/quicksort.o bin/out/parallelQuicksort.o -o bin/output -fopenmp -lm

bin/out/main.o: src/main.c
	gcc -c src/main.c -o bin/out/main.o -fopenmp -lm

bin/out/quicksort.o: src/QuickSort/quicksort.c
	gcc -c src/QuickSort/quicksort.c -o bin/out/quicksort.o -fopenmp -lm

bin/out/parallelQuicksort.o: src/QuickSort/parallelQuicksort.c
	gcc -c src/QuickSort/parallelQuicksort.c -o bin/out/parallelQuicksort.o -fopenmp -lm

debug:
	gcc -c src/main.c -o bin/out/main.o -fopenmp -lm
	gcc -c src/QuickSort/quicksort.c -o bin/out/quicksort.o -fopenmp -lm
	gcc -c src/QuickSort/parallelQuicksort.c -o bin/out/parallelQuicksort.o -fopenmp -lm
	gcc -g bin/out/main.o bin/out/quicksort.o bin/out/parallelQuicksort.o -o bin/debug -fopenmp -lm

clear:
	rm -f bin/out/*.o bin/output bin/debug