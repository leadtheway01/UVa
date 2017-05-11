#include <stdio.h>
#include <stdlib.h>

#define input "infected-target.exe"
#define output "output.txt"
int main()
{	
	FILE *fp1, *stream;
	FILE *fp2;
	char *str;
	scanf("%s", str);
	fp1 = freopen("output.txt", "r+b", stdin);
	fclose(fp1);
	return 0;
}
