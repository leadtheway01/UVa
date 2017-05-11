#include <stdio.h>
#include <string.h>
char Name[255];
/*
 * vulnerable - vulnerable function
 */
void vulnerable(char *buffer) {
  int i = 0;
  printf (buffer);
  return;
}

int main(int argc, char *argv[]) {
  int grade = 'D';
  char buf[256] = "";
  fgets(buf, 200, stdin);
  fgets(Name, 200, stdin);
  Name[strlen(Name) - 1] = '\0';
  vulnerable(buf);
  printf("Thank you, %s.\n", Name);
  printf("I recommend that you get a grade of %c on this assignment.\n", grade);

  return 0;

}
