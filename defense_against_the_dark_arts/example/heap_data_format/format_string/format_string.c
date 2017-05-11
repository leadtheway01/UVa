#include <stdio.h>
#include <string.h>

char *secret = "This is a secret\n";
int i = 0;

int main(int argc, char *argv[]) {
   char buff[256] = "";  /* allocate buffer */

   if (2 == argc)
      /* copy command line */
      strncpy(buff, argv[1], 255);

   printf(buff); /* Bad; good: printf("%s", buff) */
   printf("i is %d\n", i);

   return 0;
}
