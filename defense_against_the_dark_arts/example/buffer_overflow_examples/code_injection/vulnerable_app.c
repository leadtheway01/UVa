#include <stdio.h>

int vulnerable_function(){	
	char buff[4];
	
	printf("Please input your string:");
	/* read into un-protected buffer */
	gets(buff);

	printf("%p\n", buff);

	return 0;
}

int main(int argc, char *argv[]){

	vulnerable_function();

	return 0;
}
