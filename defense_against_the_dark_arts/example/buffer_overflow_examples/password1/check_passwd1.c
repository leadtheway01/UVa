#include <stdio.h>
#include <string.h>

int main(void) {
  char buff[4];
  int pass = 0;

  printf("Enter the pin: ");
  gets(buff);

  if (strcmp(buff, "000")) {
    printf("Wrong password\n");
  } else {
    printf("Correct password\n");
    pass = 1;
  }

  if (pass) {
    /* now give root privilege */
    printf ("Correct pin! You are root!\n");
  }

  return 0;
}
