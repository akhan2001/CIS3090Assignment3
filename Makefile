all: maze.o mazep.o

maze.o: maze.c
	gcc maze.c -o maze

mazep.o: mazep.c
	gcc -g -Wall -fopenmp -o mazep mazep.c

clean:
	rm maze mazep