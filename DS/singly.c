
#import<stdio.h>
#import<stdlib.h>

typedef int bool;
#define true 1
#define false 0

// Define new node definition
// Store viod type data
// next is pointer to next node in chain
typedef struct Node Node;
struct Node
{
	void* val;
	Node* next;
};

//Define root of the chain
Node* ROOT = NULL;

//Get new node
Node* new_node(int n) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->val = malloc(sizeof(int));
	*((int*)newnode->val) = n;
	newnode->next = NULL;
	return newnode;
}

//All operations on singly list
void print_list();
int list_length();
void insert_node(int);

//Print the list chain
void print_list() {

	printf("List chain\n");
	Node* current = ROOT;
	while (current != NULL) {
		printf(" -> %d", *(int*)(current->val));
		current = current->next;
	}
	printf("\n\n");
}

//Returns length of list
int list_length() {

	int length = 0;

	Node* current = ROOT;
	while (current != NULL) {
		current = current->next;
		length++;
	}
	return length;
}

//Insert new node to list
void insert_node(int n) {
	Node* newnode = new_node(n);

	if (ROOT == NULL) {
		ROOT = newnode;
		return;
	}

	Node* current = ROOT;
	while (current->next != NULL) {
		current = current->next;
	}

	current->next = newnode;
}

int main() {

	insert_node(1);
	insert_node(2);

	printf("Length of list is %d\n\n", list_length());
	print_list();

	return 0;
}

