#include <stdio.h>
#include <string.h>

int check_password(){
  char buff[4];
	  
  gets(buff);

  if (strcmp(buff, "0000")) 
    return 0;
  else 
    return 1;
  
}

int main(void) {
  int pass = 0;

  printf("Enter the pin: ");
  pass = check_password();
  if (!pass) {
    puts("Access denied");
    return 1;
  }
  
  /* now give root privilege */
  puts("Correct pin! You are the root!");
  puts("Let do something fun!");

  return 0;
}
