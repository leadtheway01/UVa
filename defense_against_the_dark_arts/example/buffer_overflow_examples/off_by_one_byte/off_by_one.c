#include <stdio.h>

#define SIZE 256

int echo_name()
{

	char buff[SIZE];
   	int i = 0; 
   	int c;

   	for (i = 0; i <= SIZE ; i++){
      		c = getchar();
      		if ((c == EOF) || (c == '\n')){
   			buff[i] = '\0';	
         		break;
		}
      		buff[i] = c;
   	}

   	printf("Hello, %s.\n",  buff);

   	return 0;
}

int main(){
	
	printf("Please enter your name: ");
	echo_name();

	return 0;
}
