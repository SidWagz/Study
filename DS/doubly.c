
#import<stdio.h>
#import<stdlib.h>

// Import all common stored types
#import "dstypes.h"

// Define generic name for node
typedef DoubleNode Node;
	
// Create a new node from the int n
Node* make_node (int n) {
	Node *newnode = (Node*)malloc(sizeof(Node));
	newnode->val = (int*)malloc(sizeof(int));
	*(int*)(newnode->val) = n;
	newnode->prev = NULL;
	newnode->next = NULL;

	return newnode;
}

// Declare all methods for the list
int value_of (Node *node);
Node* make_node (int n);
void print_list (Node*);
void insert (Node**, int);

// Return the int value in the node
int value_of (Node *node) {
	if (node == NULL)
		return -1;
	return *(int*)(node->val);
}

// Print the whole list chain
void print_list (Node *ROOT) {
	Node *current = ROOT;

	printf("Current list:\n");
	while (current != NULL) {
		printf("-> %d ", value_of(current));
		current = current->next;
	}
	printf("\n\n");
}

// Insert function for list
void insert (Node **ROOT, int n) {
	Node *newnode = make_node(n);

	Node *current = *ROOT;

	while (current != NULL && current->next != NULL)
		current = current->next;

	if (current == NULL)
		*ROOT = newnode;
	else {
		current->next = newnode;
		newnode->prev = current;
	}
}


int main () {
	// Define root of chain
	Node *ROOT = NULL;

	printf("\n");

	// Insert some elements in list
	insert(&ROOT, 1);
	insert(&ROOT, 2);
	insert(&ROOT, 3);

	print_list(ROOT);
}
