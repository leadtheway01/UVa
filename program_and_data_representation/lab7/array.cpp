
#include <iostream>
using namespace std;

int main() {
	int array[5] = {1, 2, 20, 50, 10};
	int i = 0;
	int max = 0;

	for(i = 0; i < 4; i++){
		if(array[i] >= array[i+1]){
			max = array[i];
		}
	}
	cout << max <<endl;
	return 0;
}