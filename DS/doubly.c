
#import<stdio.h>
#import<stdlib.h>

typedef int bool;
#define true 1
#define false 0

// Define new node struct type
// with void value type
// for two way access on list
typedef struct Node Node;
struct Node
{
	void *val;
	Node *prev;
	Node *next;
};

// Define root of chain
Node *ROOT = NULL;

// Declare all methods for the list
int value_of (Node *node);
Node* make_node (int n);
void print_list ();
void insert (int);

// Return the int value in the node
int value_of (Node *node) {
	return *(int*)(node->val);
}

// Create a new node from the int n
Node* make_node (int n) {
	Node *newnode = (Node*)malloc(sizeof(Node));
	newnode->val = (int*)malloc(sizeof(int));
	*(int*)(newnode->val) = n;
	newnode->prev = NULL;
	newnode->next = NULL;

	return newnode;
}

// Print the whole list chain
void print_list () {
	Node *current = ROOT;

	printf("Current list:\n");
	while (current != NULL) {
		printf("-> %d ", value_of(current));
		current = current->next;
	}
	printf("\n\n");
}

// Insert function for list
void insert (int n) {
	Node *newnode = make_node(n);

	Node *current = ROOT;

	while (current != NULL && current->next != NULL)
		current = current->next;

	if (current == NULL)
		ROOT = newnode;
	else {
		current->next = newnode;
		newnode->prev = current;
	}
}


int main () {

	printf("\n");

	// Insert some elements in list
	insert(1);
	insert(2);
	insert(3);

	print_list();
}
