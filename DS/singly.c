
#import<stdio.h>
#import<stdlib.h>

typedef int bool;
#define true 1
#define false 0

// Define new node definition
// Store void type data
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
void swap_nodes(int, int);

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
	if (node == NULL)
		return -1;
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

	if (current == NULL) {
		printf("Cannot find node %d - List is empty\n\n", n);
		return;
	}
	
	if (get_val(current) != n) {
		printf("Cannot find node %d - Not in list\n\n", n);
		return;
	}
	
	Node* t = current;
	if (prev == NULL) {
		ROOT = current->next;
	}
	else {
		prev->next = current->next;
	}	
}

//Swap the two nodes if both node values exist in the list
void swap_nodes(int a, int b) {
	Node *prev_a = NULL, *curr_a = ROOT;
	Node *prev_b = NULL, *curr_b = ROOT;

	while (curr_a->next != NULL
				&& get_val(curr_a) != a) {
		prev_a = curr_a;
		curr_a = curr_a->next;
	}

	while (curr_b->next != NULL
				&& get_val(curr_b) != b) {
		prev_b = curr_b;
		curr_b = curr_b->next;
	}

	if (curr_a == NULL || curr_b == NULL) {
		printf("Cannot find nodes %d and %d - List is empty\n\n", a, b);
		return;
	}

	if (get_val(curr_a) != a) {
		printf("Cannot find node %d = Not in List\n\n", a);
		return;
	}
	else if (get_val(curr_b) != b) {
		printf("Cannot find node %d = Not in List\n\n", b);
		return;
	}

	if (prev_a == NULL) {
		ROOT = curr_b;
	}
	else {
		prev_a->next = curr_b;
	}
	
	if (prev_b == NULL) {
		ROOT = curr_a;
	}
	else {
		prev_b->next = curr_a;
	}

	Node *t = curr_a->next;
	curr_a->next = curr_b->next;
	curr_b->next = t;

	return;
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

	//Prepare list for swap
	insert_node(1);
	insert_node(2);
	insert_node(5);
	insert_node(4);
	
	printf("Length of list is %d\n\n", list_length());
	print_list();

	//Swap values 5 and 1 (between)
	swap_nodes(1, 5);
	printf("Length of list is %d\n\n", list_length());
	print_list();

	//Swap values 5 and 1 (one root)
	swap_nodes(3, 5);
	printf("Length of list is %d\n\n", list_length());
	print_list();

	//Swap values 5 and 1 (one last)
	swap_nodes(4, 2);
	printf("Length of list is %d\n\n", list_length());
	print_list();

	//Swap values 2 and 5 (one root and one last)
	swap_nodes(5, 2);
	printf("Length of list is %d\n\n", list_length());
	print_list();

	//Swap values 1 and 1 (self swap)
	swap_nodes(1, 1);
	printf("Length of list is %d\n\n", list_length());
	print_list();

	//Swap values 1 and 1 (self swap last)
	swap_nodes(5, 5);
	printf("Length of list is %d\n\n", list_length());
	print_list();

	//Swap values 1 and 1 (self swap root)
	swap_nodes(2, 2);
	printf("Length of list is %d\n\n", list_length());
	print_list();

	return 0;
}

