#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void display(FILE *f);
int main(int argc, char **argv) {
  FILE *f = NULL;
  
  char *buff;
  char *FileName;

  buff = (char*)malloc(16);
  FileName = (char*)malloc(16);

  strcpy(buff, "");
  strcpy(FileName, "harmless.txt");

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

