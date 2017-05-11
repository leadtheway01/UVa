#include <stdio.h>
#define BUFSIZE 12

int main() {
	int i, sum, x;
	char buffer[BUFSIZE];
	x = foo(buffer, BUFSIZE, 5);
	sum = 0;
	for (i = 0; i < BUFSIZE; i++)
		sum += buffer[i];
	printf ("Sum is %d\n", sum);
	return 0;
}

int foo(char vector[], int len, int value) {
        int i;
        for (i = 0; i < len; i++)
        	vector[i] = value;
        return len;
}


