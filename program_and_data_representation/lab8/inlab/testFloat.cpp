

#include <iostream>
using namespace std;

float returnfloat(float f, float g);
float returnFloatRef(float &f, float &g);
int main() {
	float f = 1.0;
	float g = 2.0;
	returnfloat(f, g);		// float f is still 1.0
	//cout << f << endl;	
	returnFloatRef(f, g);	// float f is now changed to 66.0
	//cout << f << endl;
	return 0;
}

float returnfloat(float f, float g){
	return f + g;
}
float returnFloatRef(float &f, float &g) {
	return f + g;
}