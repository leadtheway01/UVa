#include "processing.h"
#include <iostream>
#include <fstream>
#include <string>
int readBuffer(char* buffer, int fd)
{
//	std::cout << "Reading Buffer" << std::endl;
	while (1)
	{
		ssize_t cnt = read(fd,buffer,4096);//sizeof(buffer));
//		printf("Number chars read is %d\n", cnt);
		if (cnt == -1)
		{
			if (errno == EINTR)
			{
				continue;
//				exit(1);
			} 
			else
			{
				perror("Pipe Read Error");
				return -1;//exit(1);
			}
		} 
		else if (cnt == 0)
		{
			break;
		}
		else
		{
			break;
		} 	
	}
//	std::cout << "Done reading into buffer" << std::endl;
}

//char** getCStrCommand(std::string token)
//{
//	//std::cout << "Converting " << token << std::endl;
//	//Split the token into the individual words
//	
//	char* cmd[128];
//	int ind = 0;;
//	std::vector<std::string> words = split(token,' ');
//	//std::vector<char *> c_vector;
//	for (int i = 0; i < words.size(); i++)
//	{
//		char* tmp = (char*)words[i].c_str();
//		//if ((unsigned)strlen(tmp) > 0)
//		//{
//		printf("Pushing -%s- into array.\n", tmp);
//		cmd[ind] = tmp;
//		ind = ind + strlen(tmp);	
//		//c_vector.push_back((char*)words[i].c_str());
//		//}
//		//printf("-%s-",c_vector[i]);
//	}//end of for
//	cmd[ind] = NULL;
//	printf("C String is %s\n", &cmd[0]);
//	
////	c_vector.push_back(NULL);
//	//std::cout << "Converted" << std::endl;
//	return &cmd[0];	
//}

void makePipe(int* fd)
{
//	std::cout << "Making pipe" << std::endl;
	if (pipe(fd) == -1)
	{
		perror("pipe error");
		exit(1);
	}
//	std::cout << "Made pipe" << std::endl;
	return;
}

//pid_t startNewProcess(std::vector<std::string> tokens, int* fd)
//{
//	std::cout << "Starting new process" << std::endl;
//	//Set up the file descriptors
//	//Generate int array for file descriptors
//	makePipe(fd);	
//	pid_t pid = fork(); //Make child process
//	if (pid == 0)
//	{
//		processTokens(tokens);
//	}
//	std::cout << "Made new process" << std::endl;
//	return pid;
//}
//
//void processTokens(std::vector<std::string> tokens)
//{
//	std::string token;
//	pid_t pid;
//	int fd[2];
//	bool doneWithTokensFlag = false;
//
//	token = tokens[tokens.size()-1];
//	if (tokens.size() == 1)
//	{
//		doneWithTokensFlag = true;
//	}	
////	else
////		tokens.erase(tokens.end());	
//	char **command = getCStrCommand(token);
////	makePipe(fd);
//	//fflush(stdout);
//
//	if (pipe(fd) == -1)
//	{
//		perror("pipe error");
//		exit(1);
//	}
//	pid = fork();//startNewProcess(tokens, fd);
//	
//	if (pid == -1)
//	{
//		perror("fork failed");
//		exit(1);
//	} 
//	else if (pid == 0)
//	{
////		int x = dup(0);
////		int y = dup(1);
////		std::cout<<"Setting up child " << token << std::endl;
////		close(0);
////		std::cout<<"Closing 0 Done" << std::endl;
////		close(1);
//////		fclose(stdout);
////		std::cout<<"Closing 1 Done" << std::endl;
////		close(fd[0]);
////		std::cout << "Closed fd[0]" << std::endl;
//		//while loop in case operation interrupted by signal
//		dup2(fd[1],1);
//	//	while (dup2(fd[1],1)==-1 && errno==EINTR) {
//	//		std::cout << "Waiting for dup2 to function" << std::endl;
//	//	}//copy fd[1] to stdout of chil			
//		std::cout << "About to process more tokens";
////		close(fd[1]);
//		std::cout << "About to process more tokens";
//		printf("%d\n", doneWithTokensFlag);
//		if (!doneWithTokensFlag)
//			processTokens(tokens);		
////		close(fd[1]); // it's copied, so we don't need it anymore
//		std::cout<<"About to execute " <<token << std::endl;
//		execvp(command[0], command);
//	} 
//	else 
//	{
////		close(fd[1]);
//		dup2(fd[0],0);
//		//while (dup2(fd[0],0)==-1 && errno==EINTR) {}//copy fd[1] to stdout of chil			
//		std::cout << "Current token is " << token << std::endl;
//		char buffer[4096];
////		close(fd[0]);
//		readBuffer(&buffer[0], STDIN_FILENO);	
//		std::cout << "Reading done, waiting for child terminate" << std::endl;
//		//std::cout<<buffer<<std::endl;	
//		if(waitpid(pid,NULL,WCONTINUED) < 0)	
//		{ //error checking, wait
//			perror("wait failed");
//		}
//		std::cout << "Child terminated" <<std::endl;
////		std::cout<<"Writing to the STDIN to be used" << std::endl;
////		write(STDIN_FILENO, buffer, 4096+1);
//		std::cout<<buffer<<std::endl;	
//	}
//}


void processTokensIteratively(std::vector<std::string> tokens, bool isOriginalParent)
{
		std::string token;
		pid_t pid;
		int fd[2];
		bool doneWithTokensFlag = false;
		char buffer[4096] = {};
		
		for (int i = 0; i < tokens.size(); i++)
		{
			//Extract the specific thing we need to do
			token = tokens[i];
			
			//Convert to C String for execution
			std::vector<std::string> words = split(token,' ');
			std::vector<char *> c_vector;
			for (int j = 0; j < words.size(); j++)
			{
				char* tmp = (char*)words[j].c_str();
				if (strlen(tmp) > 0)
				{
			//		printf("Pushing -%s- into array.\n", tmp);
					c_vector.push_back(tmp);
				}
			}//end of for
			c_vector.push_back('\0');
			//printf("C String is %s\n", c_vector[0]);

			//Create a pipe
			if (pipe(fd) == -1)
			{
				perror ("Pipe Error");
				exit(1);
			}

			//Run the process
			pid = fork();
			if (pid < 0)
			{
				perror ("fork wrong");
				printf("Fork went awry\n");
				exit(1);
			}						
			if (pid == 0) //Child Process
			{
				//if "<" or ">" is not found from the token
				if (token.find(">") != std::string::npos || token.find("<") != std::string::npos)
				{
					c_vector.pop_back(); // Get rid of NULL
					const char*  filename = c_vector.back();
					c_vector.pop_back();
					c_vector.push_back('\0'); // Add NULL back
					int fout = open(filename, O_CREAT);
					dup2(fout, 1);
				}
				else //if < or >
					{
					dup2(fd[1],4);
					close(fd[1]);
					close(fd[0]);
				}

				if (i != 0)
				{
//					write(0,buffer,sizeof(buffer));	
					//FILE* buf;
					//fputs(buffer, buf);
					dup2(5,0);//Pass the contents
					fflush(stdin);
				} 
				
				execvp(c_vector[0],&c_vector[0]);
				printf("EXEC WRONG\n");
				perror("exec");
				exit(1);
			}
			else //Parent Process
			{
				dup2(fd[0],5);
				close(fd[0]);
				close(fd[1]);
				
				if (i == tokens.size()-1)	
				{
					readBuffer(buffer,5);
					std::cout << buffer << std::endl;
				}
//				printf("Waiting for child %d\n", pid);
				waitpid(pid,NULL,WCONTINUED);
//				printf("Child %d finished\n", pid);				
			}
		}
}
//void processTokensV2(std::vector<std::string> tokens, bool isOriginalParent)
//{
//		std::string token;
//		pid_t pid;
//		int fd[2];
//		bool doneWithTokensFlag = false;
//	
//		token = tokens[0];
//		if (tokens.size() == 1)
//		{
//			doneWithTokensFlag = true;
//		}	
//		else
//			tokens.erase(tokens.begin());	
//
//		std::vector<std::string> words = split(token,' ');
//		std::vector<char *> c_vector;
//		for (int i = 0; i < words.size(); i++)
//		{
//			char* tmp = (char*)words[i].c_str();
//			if (strlen(tmp) > 0)
//			{
//				printf("Pushing -%s- into array.\n", tmp);
//				c_vector.push_back(tmp);
//			}
//		}//end of for
//		c_vector.push_back('\0');
//		printf("C String is %s\n", c_vector[0]);
//		
//	
//		if (pipe(fd) == -1)
//		{
//			perror ("Pipe Error");
//			exit(1);
//		}
//		
//		pid = fork();
//		
//		if (pid < 0)
//		{
//			perror ("Bad fork");
//			exit(1);
//		}		
//		if (pid == 0)
//		{		
//			dup2(fd[1],4);
//			close(fd[1]);
//			close(fd[0]);
//			execvp(c_vector[0],&c_vector[0]);
//			printf("EXECVP SCREWED UP");
//			perror("execvp");
//			exit(1);
//		}	
//		else 
//		{
//			printf("PID Currently is %d\n", getpid());
//			printf("Original Parent: %d\n", isOriginalParent);
//			printf("pid = %d\n", pid);
//			
//			dup2(fd[0],5);
//			close(fd[0]);
//			close(fd[1]);
//			
//			char buffer[4096];
//			readBuffer(buffer,5);
//			printf("Waiting for child %d\n", pid);
//			waitpid(pid,NULL,WCONTINUED);
//			printf("Child %d finished\n", pid);
//			
//
//
//			std::cout<<buffer<<std::endl;
//			printf("Command to run: %s\nOriginal Parent %d\nFork Flag %d\n", 
//				c_vector[0],isOriginalParent,forkFlag);
//			if (!doneWithTokensFlag)
//				processTokensV2(tokens,false);
//			if (forkFlag == 0)			
//			{
//				printf("Not original parent: %d\n", isOriginalParent);
////				c_vector.pop_back(); // Remove ending NULL
////				c_vector.push_back(&buffer[0]); // Add to args
////				c_vector.push_back('\0'); // Terminate array
//				write(0,buffer,sizeof(buffer));
//				printf("Command to run: %s\n", c_vector[0]);
//				execvp(c_vector[0],&c_vector[0]);
//				printf("EXECVP PARENT SCREWED UP\n");
//				perror("execvp");
//				exit(1);
//			}
			//write(4,buffer,sizeof(buffer));
//		pid_t pid2 = -10;
//		int forkFlag;
//		if (!doneWithTokensFlag)
//		{
//			forkFlag = 0;
//			pid2 = fork();
//			printf("pid2 has value %d\n", pid2);
//			if (pid != 0)
//			{
//				forkFlag = 1;
//				pid = fork();
//			}
//			if (pid == 0 || pid2 == 0)
//				isOriginalParent = false;
//		}
////		else
////		{
////			forkFlag = 1;	
////			pid = fork();
////			isOriginalParent = false;
////		}
//
//		if (pid < 0)
//		{
//			perror ("Bad fork");
//			exit(1);
//		}		
//		if (pid == 0 && forkFlag == 1)
//		{
//			
//			dup2(fd[1],4);
//			close(fd[1]);
//			close(fd[0]);
//			if (!doneWithTokensFlag)
//				processTokensV2(tokens,false);
//			execvp(c_vector[0],&c_vector[0]);
//			printf("EXECVP SCREWED UP");
//			perror("execvp");
//			exit(1);
//		}	
//		else 
//		{
//			if (!isOriginalParent && forkFlag == 1)
//				exit(0);
//
//			printf("PID Currently is %d\n", getpid());
//			printf("Original Parent: %d\n", isOriginalParent);
//			printf("pid = %d ; pid2 = %d\n", pid, pid2);
//			printf("forkFlag = = %di\n\n", forkFlag);
//			dup2(fd[0],5);
//			close(fd[0]);
//			close(fd[1]);
//			char buffer[4096];
//			readBuffer(buffer,5);
//			printf("Waiting for child %d\n", pid);
//			waitpid(pid,NULL,WCONTINUED);
//			if (isOriginalParent)
//				waitpid(pid2,NULL,WCONTINUED);
//			printf("Child %d finished\n", pid);
//			std::cout<<buffer<<std::endl;
//			printf("Command to run: %s\nOriginal Parent %d\nFork Flag %d\n", 
//				c_vector[0],isOriginalParent,forkFlag);
//			if (forkFlag == 0)			
//			{
//				printf("Not original parent: %d\n", isOriginalParent);
////				c_vector.pop_back(); // Remove ending NULL
////				c_vector.push_back(&buffer[0]); // Add to args
////				c_vector.push_back('\0'); // Terminate array
//				write(0,buffer,sizeof(buffer));
//				printf("Command to run: %s\n", c_vector[0]);
//				execvp(c_vector[0],&c_vector[0]);
//				printf("EXECVP PARENT SCREWED UP\n");
//				perror("execvp");
//				exit(1);
//			}
			//write(4,buffer,sizeof(buffer));
		//}	
//}
