// main.c : Defines the entry point for the console application.
// use "gcc -m32 -o a.out main.c ComputeVolumeAndDensity.s" to compile
#include <stdio.h>

int *VolumeAndDensity(int length, int width, int height, int mass);
int main() {
	int *p;
        int length, width, height, mass;
	printf("Enter length, width, height, and mass\n");
	scanf("%d %d %d %d", &length, &width, &height, &mass);

	p = VolumeAndDensity(length, width, height, mass);
	printf ("Object dimensions: %d x %d x %d. Mass: %d\n",
         length, width, height, mass);
        printf ("Volume is %d\n", *p);
	printf ("Density is %d\n", *(p+1));
	return 0;
}

