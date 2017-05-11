#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <semaphore.h>

//threads can access global variables
//declare global variables
//=====================================================================
int h1[4096] = {0};
int h2[4096] = {0};

int arraySize;			//total number of integers
int numOfRounds;		//number of rounds
//int pick;				//if 1, write to  h1;if 2, write to h2
unsigned threadCount;
int num;
int end;
int count;
FILE* fp1;
char output[1024];
pthread_mutex_t m;
pthread_cond_t cv;
pthread_t tid[2048];
sem_t s;
pthread_mutex_t m1;
int pick = 2;
//struct Barrier barrier;

//==========================================================================
//function prototypes
void *compare(void* index);	//to compare two integers and write back to array
void barrier_wait();				//to wait until all threads are executed
void barrier_broadcast();

//==========================================================================
int main(int argc, char *argv[]){
	if (argc != 2){
		fprintf(stderr, "need command line argument\n");
		return -1;
	}
	arraySize = 0;
	numOfRounds = 0;
	
	strcpy(output, argv[1]);
	//strcat(output, ".txt");
	
	fp1 = fopen(output, "r");
	//fp2 = fopen(output, "w+");
	
	char str[1024];
	while(fgets(str, 1024, fp1) != NULL){
         h1[arraySize] = atoi(str);
         arraySize++;
        }//end of while

	
	pthread_mutex_init(&m, NULL);
	pthread_cond_init(&cv, NULL);
	
	//log base 2 of arraySize = num of rounds
	//think I don't need this
	numOfRounds = log((double)arraySize)/log(2);

	if(arraySize == 0){
		printf("There is no integer in the file ");
	}
	else if(arraySize == 1){
		printf("%s %d\n", "The highest integer is ",h1[0] );
	}
	else if(arraySize > 1){
		while(1){
			threadCount = arraySize / 2;    //number of threads to create is half of the array size
            count = threadCount;    //count used in barrier for count--
			if(threadCount < 1){//no more rounds
				end = 1;
				break;
			}
			else if(threadCount >= 1){
				//printf("%s %d\n", "thread count ", threadCount);
				int a[2046] = {0};
				for(int i = 0; i < threadCount; i++){//create multiple threads needed
					a[i] = i;					
					//create threadCount threads
					//printf("%d\n", i);
					//pthread_mutex_lock(&m1); 
					pthread_create(&tid[i], NULL, compare, &a[i]);
					//pthread_mutex_unlock(&m1);
					//printf("%d\n", tid[i]);
				}//end of for
				sem_wait(&s);	//block all worker threads
				arraySize = threadCount; //arraySize will be 1 when done
				if (pick == 1){
					//printf("%d\n", pick);
					pick = 2;
				}
				else if(pick == 2){
					//printf("%d\n", pick);
					pick = 1;
				}
			}//end of else if
		}//end of while
	}//end of else if(arraySize > 1)
	//printf("%d\n", pick);
	if(pick == 1 && end){
		printf("%s %d\n", "The highest integer is ",h2[0] );
	}//end of if
	else if(pick == 2 && end){
		printf("%s %d\n", "The highest integer is ",h1[0]);
	}//end of else if
	/*
	int i;
	for(i=0;i<8;i++)
		printf("%d\n", h1[i]);
	printf("=======================\n");
	for(i=0;i<8;i++)
		printf("%d\n", h2[i]);
	*/
	fclose(fp1);
	return 0;
}//end of main

void *compare(void* index){
	//pthread_mutex_lock(&m1);
	int i = *((int *)index); //convert void pointer to int
	//i = i-1;
	int j;
	//printf("%s %d\n", "i" , i);
		j = i*2;
		//printf("%s %d\n", "j " , j);
		if(pick == 2){
			if(h1[j] >= h1[j+1]){
				h2[j/2] = h1[j];
				//printf("%s %d\n", "h2[j/2] ", h2[j/2]);
			}
			else if(h1[j] < h1[j+1]){
				h2[j/2] = h1[j+1];
				//printf("%s %d\n", "h2[j/2] ", h2[j/2]);
			}
		}
		else if(pick == 1){
			if(h2[j] >= h2[j+1]){
            	h1[j/2] = h2[j];
	 			//printf("%s %d\n", "h1[j/2] ", h1[j/2]);
			}
        	else if(h2[j] < h2[j+1]){
            	h1[j/2] = h2[j+1];
				//printf("%s %d\n", "h1[j/2] ", h1[j/2]);
			}
		}
//	}//end of for
	//pthread_mutex_unlock(&m1);
	barrier_wait();
	//barrier_siganl();
	pthread_exit(0);	
}//end of compare

void barrier_wait(){
	pthread_mutex_lock(&m);
	count--;
	if(count != 0){
		pthread_cond_wait(&cv, &m);
	}
	else if(count == 0)
		barrier_broadcast();
	pthread_mutex_unlock(&m);
}

void barrier_broadcast(){
	//if(barrier.count == 0)
	pthread_cond_broadcast(&cv);
	sem_post(&s);
}





























































