#include "parsing.h"
#include "processing.h"
using namespace std;

int main() {
	
	string input;
	while(1){
		input = command();		
		if (input == "error"){
			cout << "Retry entry" << std::endl;
			continue;
		}
	
		// validate words [A-Za-z0-9-._<>| ]
		bool b = validate(input);
		//cout << b << endl;
		if(b == 0){
			cout << "ERROR: invalid character" << endl;
			continue;
		}
		if (input == "exit"){
			exit(0);
		}

		//if no invalid chars, then check placement of |<>
		if (validatePipeIOPlacement(input) == 0)
		{
			continue;
		}

		// split input by space and store in the vector sep
		vector<string> tokens = split(input, '|');
		// to check if input was splited and pushed into the vector
		if (validateFileIO(tokens) == 0){
			continue;
		}
		processTokensIteratively(tokens, true);		
		

	}//end of while
	return 0; //exited smoothly
}//end of main
