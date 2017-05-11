#include "parsing.h"

void tokenize(){}

// to split input by delimiter
std::vector<std::string> split(std::string str, char delimiter){
	std::vector<std::string> internal;
	std::stringstream ss(str);
	std::string tok;

	while (getline(ss, tok, delimiter)) {
		internal.push_back(tok);
	}
	return internal;
}

// to prompt user
std::string command(){
    std::string input;

    std::cout << "user$: ";
    getline(std::cin, input);

    if( input.length() > 80){
        std::cout << "ERROR: Input > 80 characters." << std::endl;
        return "error";
    }

    return input;
}

// to validate user input (operator & words)                    
bool validate(std::string input){
    return std::regex_match(input, std::regex("[A-Za-z0-9-_.<>| ]*"),std::regex_constants::match_not_null);
}

// validate a token group
bool validatePipeIOPlacement(std::string input){
	// Split the string into the different words
		//Delimiter is a space
	std::vector<std::string> wordlist = split(input, ' ');
	bool validCommand = 0;
	bool validArgs    = 0;
	for (int i = 0; i < wordlist.size(); i++){
		std::string currWord = trim(wordlist[i]);
		//Empty string result of extraneous spaces, ignore
		if (currWord.length() == 0)
			continue;
//		std::cout << "Current word: " << currWord << std::endl;	

//		// Check if operators are isolated at beginning			
//		bool firstCharFlag = std::regex_match(currWord,std::regex("[|<>]*"),std::regex_constants::match_not_null);
//	//	std::cout << firstCharFlag << std::endl;
//		if (firstCharFlag == 1){
//			std::cout << "ERROR: Pipes, IO Redirection can't begin token group" << std::endl;
//			return 0;
//		}
//		std::cout << "No misplaced operators" << std::endl;			

		// Check if operators are part of words
		if(currWord.length()>1 && (currWord.find('|')!=std::string::npos
							   ||  currWord.find('>')!=std::string::npos
							   ||  currWord.find('<')!=std::string::npos))
		{	
			std::cout << "ERROR: Pipes, IO Redirection can't be part of words" << std::endl;
			return 0;
		}
//		std::cout << "No operators as part of words" << std::endl;				

	}
	if (checkPipes(wordlist))
		return 1;
	return 0; // Command and args parsed fine, it's valid token
}

bool checkPipes(std::vector<std::string> wordlist){
	for (int i = 0; i < wordlist.size(); i++){
		std::string word = wordlist[i];
		if (word == "|"){
			if (i == 0 || i == wordlist.size()-1){
				std::cout<<"ERROR: Pipe cannot start or end token group" << std::endl;
				return 0;
			}
			else {
				if (wordlist[i-1] == ">" || wordlist[i-1] == "<" ||
				    wordlist[i+1] == "<" || wordlist[i+1] == ">"){
					std::cout<<"ERROR: File IO operator cannot precede/follow pipe"<<std::endl;
					return 0;
				}
			}
		}
	}	
	return 1;
}

bool validateFileIO(std::vector<std::string> tokenlist){
	int iocounter = 0;
	bool redirOutputFlag = false;
	for (int i = 0; i < tokenlist.size(); i++){
		std::string token = tokenlist[i];
		iocounter = 0; //reset the number of file redirections
		redirOutputFlag = false; //reset it

		std::vector<std::string> words = split(token,' ');
		
		for (int j = 0; j < words.size(); j++){
			std::string word = words[j];
			if (word == ">" || word == "<"){
				iocounter++;

				if (j == 0 || j == words.size() - 1){
					std::cout<<"ERROR: Token cannot have operator at beginning/end"<<std::endl;
					return 0;
				}
				else if (words[j-1] == ">" || words[j-1] == "<" ||
				    words[j+1] == ">" || words[j+1] == ">"){
					std::cout<<"ERROR: File IO operator cannot precede/follow another operator"<<std::endl;
					return 0;
				}

				if (iocounter > 2){
					std::cout<<"ERROR: Cannot have more than two file redirections"<<std::endl;
					return 0;
				}
				else if (iocounter == 2){
					if (word == "<"){
						std::cout<<"ERROR: Second redirection must be output"<<std::endl;
						return 0;
					} else if (redirOutputFlag){
						std::cout<<"ERROR: Cannot have two output redirections"<<std::endl;
						return 0;
					}
				}
				else if (iocounter == 1){
					
					if (word == ">")
						redirOutputFlag = true;
					else{
						if (j+2 < words.size()){
							if (words[j+2] != ">"){
								std::cout<<"ERROR: Invalid follow to file input redirection"<<std::endl;
								return 0;
							}
						}	
					}
				}
				
				if (word == ">" && i != tokenlist.size()-1){
					std::cout<<"ERROR: File output redirection can only happen in ending token"<<std::endl;
					return 0;
				}
			}
		}
	}	
	return 1;
}


// trim string
std::string trim(std::string str){
	if (str.empty())
		return str;
	size_t firstScan = str.find_first_not_of(' ');
	size_t first     = firstScan == std::string::npos ? str.length() : firstScan;
	size_t last      = str.find_last_not_of(' ');
	return str.substr(first, last-first+1);
}
