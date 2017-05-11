
#ifndef PARSING_H
#define PARSING_H

#include <string.h>
#include <iostream>
#include <cstdlib>
#include <regex>
#include <vector>
#include <sstream>

void tokenize();
std::vector<std::string> split(std::string str, char delimiter);
std::string command();
bool validate(std::string input);
std::string trim(std::string str);
bool validatePipeIOPlacement(std::string input);
bool checkPipes(std::vector<std::string> wordlist);
bool validateFileIO(std::vector<std::string> wordlist);

#endif
