all: disk fileManager myApp
	gcc -Wall disk.o fileManager.o myApp.o -o myApp

disk:
	gcc -g -std=c11 -Wall -c disk.c -o disk.o

fileManager:
	gcc -g -std=c11 -Wall -c fileManager.c -o fileManager.o

myApp:
	gcc -g -std=c11 -Wall -c myApp.c -o myApp.o

clean:
	rm -f *.o myApp mydk
