// Wright Kim
// wdk7bj

#include <stdio.h>

int main()
{	
	int stream;
	FILE *fp;
	// reads binary from stdin 
	fp = freopen(NULL, "r+b", stdin);
	while ((stream = fgetc(fp)) != EOF)
	{	
		// %02x to have leading zeros
		printf("%02x", stream);
	}

	return 0;
}
