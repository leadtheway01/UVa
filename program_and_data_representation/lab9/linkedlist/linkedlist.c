//Wright Kim wdk7bj
//linkedlist.c

#include <stdio.h>
#include <stdlib.h>

struct list_item {
	int value;
	struct list_item *next, *prev;
};

int main() {
	int i;
	int numberOfInput;

	//node pointer
	struct list_item *node;
	//to allocate memory
	node = malloc(sizeof(struct list_item));		

	//temp node pointer
	struct list_item *temp;

	// I/O
	printf("Enter how many values to input: ");
	scanf("%d", &numberOfInput);

	// to store values 
	for (i = 0; i < numberOfInput; i++){
		printf("Enter value %d: ", i+1);
		scanf("%d", &(node->value));
		//to allocate temp node memory
		temp = malloc(sizeof(struct list_item));
		node->next = temp;	// node pointing next node
		temp->prev = node;	// next node pointing previous node
		node = temp;		// node is now next node
	}

	// to print values
	for (i = 0; i < numberOfInput; i++) {
		temp = node->prev;	//node is pointing previous node
		node = temp;		//node is now previous node
		free(node->next);
		printf("%d\n", node->value);
	}

	// to free memory
	free(node);									

	return 0;
}