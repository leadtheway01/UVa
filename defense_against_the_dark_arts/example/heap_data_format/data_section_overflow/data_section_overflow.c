#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void display(FILE *f);
int main(int argc, char **argv) {
  int c = 0, i = 0;
  FILE *f = NULL;
  
  static char *FileName = "harmless.txt";
  static char buff[16] = "xxx";

  gets(buff);
  printf("Your input is %s\n", buff);
  printf("Now reading file %s\n", FileName);

  f = fopen(FileName, "r");
  display(f);
  fclose(f);
  return 0;
}

void display(FILE *f) {
   int c;
   c = fgetc(f);
   while (c != EOF) {
      putchar(c);
      c = fgetc(f);
   }
   return;
}

