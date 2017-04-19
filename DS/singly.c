
#import<stdio.h>
#import<stdlib.h>

#import "dstypes.h"

// Define generic name for node
typedef SingleNode Node;

//Get new node
Node* make_node(int n) {
	Node *newnode = (Node*)malloc(sizeof(Node));
	newnode->val = malloc(sizeof(int));
	*((int*)newnode->val) = n;
	newnode->next = NULL;
	return newnode;
}

//All operations on singly list
void print_list(Node*);
int value_of(Node*);
int length_of(Node*);
void insert(Node**, int);
void delete(Node**, int);
void swap(Node**, int, int);

//Print the list chain
void print_list(Node *ROOT) {

	printf("List chain\n");
	Node *current = ROOT;
	while (current != NULL) {
		printf(" -> %d", *(int*)(current->val));
		current = current->next;
	}
	printf("\n\n");
}

//Get value from Node
int value_of(Node *node) {
	if (node == NULL)
		return -1;
	return *(int*)(node->val);
}

//Returns length of list
int length_of(Node *ROOT) {

	int length = 0;

	Node *current = ROOT;
	while (current != NULL) {
		current = current->next;
		length++;
	}
	return length;
}

//Insert new node to list
void insert(Node **ROOT, int n) {
	Node *newnode = make_node(n);

	if (*ROOT == NULL) {
		*ROOT = newnode;
		return;
	}

	Node *current = *ROOT;
	while (current->next != NULL) {
		current = current->next;
	}

	current->next = newnode;
}

//Delete a node from list
void delete(Node **ROOT, int n) {

	Node *prev = NULL, *current = *ROOT;
	while (current->next != NULL 
				&& value_of(current) != n) {
		prev = current;
		current = current->next;
	}

	if (current == NULL) {
		printf("Cannot find node %d - List is empty\n\n", n);
		return;
	}
	
	if (value_of(current) != n) {
		printf("Cannot find node %d - Not in list\n\n", n);
		return;
	}
	
	Node *t = current;
	if (prev == NULL) {
		*ROOT = current->next;
	}
	else {
		prev->next = current->next;
	}	
}

//Swap the two nodes if both node values exist in the list
void swap(Node **ROOT, int a, int b) {
	Node *prev_a = NULL, *curr_a = *ROOT;
	Node *prev_b = NULL, *curr_b = *ROOT;

	while (curr_a->next != NULL
				&& value_of(curr_a) != a) {
		prev_a = curr_a;
		curr_a = curr_a->next;
	}

	while (curr_b->next != NULL
				&& value_of(curr_b) != b) {
		prev_b = curr_b;
		curr_b = curr_b->next;
	}

	if (curr_a == NULL || curr_b == NULL) {
		printf("Cannot find nodes %d and %d - List is empty\n\n", a, b);
		return;
	}

	if (value_of(curr_a) != a) {
		printf("Cannot find node %d = Not in List\n\n", a);
		return;
	}
	else if (value_of(curr_b) != b) {
		printf("Cannot find node %d = Not in List\n\n", b);
		return;
	}

	if (prev_a == NULL) {
		*ROOT = curr_b;
	}
	else {
		prev_a->next = curr_b;
	}
	
	if (prev_b == NULL) {
		*ROOT = curr_a;
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

	//Define root of the chain
	Node *ROOT = NULL;

	//Create list and print it
	insert(&ROOT, 1);
	insert(&ROOT, 2);
	insert(&ROOT, 3);
	insert(&ROOT, 4);

	printf("Length of list is %d\n\n", length_of(ROOT));
	print_list(ROOT);

	//Delete mid element
	delete(&ROOT, 2);
	printf("Length of list is %d\n\n", length_of(ROOT));
	print_list(ROOT);

	//Delete root element
	delete(&ROOT, 1);
	printf("Length of list is %d\n\n", length_of(ROOT));
	print_list(ROOT);

	//Delete last element
	delete(&ROOT, 4);
	printf("Length of list is %d\n\n", length_of(ROOT));
	print_list(ROOT);

	//Delete element not in list
	delete(&ROOT, 5);
	printf("Length of list is %d\n\n", length_of(ROOT));
	print_list(ROOT);

	//Prepare list for swap
	insert(&ROOT, 1);
	insert(&ROOT, 2);
	insert(&ROOT, 5);
	insert(&ROOT, 4);
	
	printf("Length of list is %d\n\n", length_of(ROOT));
	print_list(ROOT);

	//Swap values 5 and 1 (between)
	swap(&ROOT, 1, 5);
	printf("Length of list is %d\n\n", length_of(ROOT));
	print_list(ROOT);

	//Swap values 5 and 1 (one root)
	swap(&ROOT, 3, 5);
	printf("Length of list is %d\n\n", length_of(ROOT));
	print_list(ROOT);

	//Swap values 5 and 1 (one last)
	swap(&ROOT, 4, 2);
	printf("Length of list is %d\n\n", length_of(ROOT));
	print_list(ROOT);

	//Swap values 2 and 5 (one root and one last)
	swap(&ROOT, 5, 2);
	printf("Length of list is %d\n\n", length_of(ROOT));
	print_list(ROOT);

	//Swap values 1 and 1 (self swap)
	swap(&ROOT, 1, 1);
	printf("Length of list is %d\n\n", length_of(ROOT));
	print_list(ROOT);

	//Swap values 1 and 1 (self swap last)
	swap(&ROOT, 5, 5);
	printf("Length of list is %d\n\n", length_of(ROOT));
	print_list(ROOT);

	//Swap values 1 and 1 (self swap root)
	swap(&ROOT, 2, 2);
	printf("Length of list is %d\n\n", length_of(ROOT));
	print_list(ROOT);

	return 0;
}

