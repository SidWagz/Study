
#import<stdio.h>
#import<stdlib.h>

#import "dstypes.h"
#import "doubly.h"
	
// Create a new node from the int n
Node* make_node (int n) {
	Node *newnode = (Node*)malloc(sizeof(Node));
	newnode->val = (int*)malloc(sizeof(int));
	*(int*)(newnode->val) = n;
	newnode->prev = NULL;
	newnode->next = NULL;

	return newnode;
}

// Return the int value in the node
int value_of (Node *node) {
	if (node == NULL)
		return -1;
	return *(int*)(node->val);
}

int length_of (Node* ROOT) {

	int length = 0;
	Node *current = ROOT;

	while (current != NULL && ++length)
		current = current->next;

	return length;
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