
#ifndef PROCESSING_H
#define PROCESSING_H

#include "parsing.h"
#include <stdio.h>
#include <cctype>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <iostream>
#include <fcntl.h>

void processSingleToken(std::vector<std::string> token);
void processTokens(std::vector<std::string> tokens);
void processTokensV2(std::vector<std::string> tokens, bool isOriginalParent);
void processTokensIteratively(std::vector<std::string> tokens, bool isOriginalParent);

void makePipe(int* fd);
char** getCStrCommand(std::string token);
pid_t startNewProcess(std::vector<std::string> tokens, int* fd);
int readBuffer(char* buffer, int fd);
#endif
