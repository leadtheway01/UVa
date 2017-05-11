all: test

test: test.o
	gcc -o test test.o -lm -lpthread -std=c99

test.o: test.c
	gcc -c test.c -std=c99 -lm -lpthread

clean:
	rm test *.o


