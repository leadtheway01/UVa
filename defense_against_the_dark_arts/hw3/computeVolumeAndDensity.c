#include <stdio.h>

int a[2];

int VolumeAndDensity(int len, int width, int height, int mass){
	a[0] = len * width * height;
	a[1] = mass / a[0];
	return a;
}



