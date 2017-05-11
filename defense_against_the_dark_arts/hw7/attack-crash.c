#include <stdio.h>
#include <string.h>

// seg fault after 113 bytes
char attackString[] = "Wright Kim"; // 10 bytes

int main(){
	int i;
	char *p = attackString;
	for(i = 0; i < sizeof(attackString); i++){
		putchar(*p);
		p++;
	}
	
	// need to place 103 bytes more
	return 1;
}
