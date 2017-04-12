
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
int get_val(Node*);
int list_length();
void insert_node(int);
void delete_node(int);

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

//Get value from Node
int get_val(Node* node) {
	return *(int*)(node->val);
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

//Delete a node from list
void delete_node(int n) {

	Node* prev = NULL, *current = ROOT;
	while (current->next != NULL 
				&& get_val(current) != n) {
		prev = current;
		current = current->next;
	}

	if (current == NULL)
		printf("Cannot find node %d - List is empty\n\n", n);
	
	else if (get_val(current) != n)
		printf("Cannot find node %d - Not in list\n\n", n);
	
	else {
		Node* t = current;
		if (prev == NULL) {
			ROOT = current->next;
		}
		else {
			prev->next = current->next;
		}
		free(t);
	}
}

int main() {

	//Create list and print it
	insert_node(1);
	insert_node(2);
	insert_node(3);
	insert_node(4);

	printf("Length of list is %d\n\n", list_length());
	print_list();

	//Delete mid element
	delete_node(2);
	printf("Length of list is %d\n\n", list_length());
	print_list();

	//Delete root element
	delete_node(1);
	printf("Length of list is %d\n\n", list_length());
	print_list();

	//Delete last element
	delete_node(4);
	printf("Length of list is %d\n\n", list_length());
	print_list();

	//Delete element not in list
	delete_node(5);
	printf("Length of list is %d\n\n", list_length());
	print_list();

	return 0;
}

