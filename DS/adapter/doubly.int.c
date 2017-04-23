
#import<stdio.h>
#import<stdlib.h>

#import "doubly.int.h"

// Get new node
Node* make_node(int n) {
	Node *newnode = (Node*)malloc(sizeof(Node));
	newnode->val = malloc(sizeof(int));
	*((int*)newnode->val) = n;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

// Get value from Node
int value_of(Node *node) {
	if (node == NULL)
		return -1;
	return *(int*)(node->val);
}

// Check rogue value with node
int check_value(Node *a, void *b) {
	int _b = *(int*)b;
	if (a == NULL)
		return 0;
	else
		if (value_of(a) == _b)
			return 1;
		else
			return 0;
}

// Compare values of nodes
int compare(Node *a, Node *b) {
	if (a == NULL && b == NULL)
		return 0;
	else if (a == NULL)
		return -1;
	else if (b == NULL)
		return 1;
	else {
		int _A = value_of(a), _B = value_of(b);
		if (_A > _B)
			return 1;
		else if (_A < _B)
			return -1;
		else
			return 0;
	}
}

// Equal values of nodes
int equal(Node *a, Node *b) {
	if (a == NULL && b == NULL)
		return 1;
	else if (a == NULL || b == NULL)
		return 0;
	else
		if (value_of(a) == value_of(b))
			return 1;
		else
			return 0;
}

// String value
char* val_repr(void *val) {
	int len = snprintf(NULL, 0, "%d", *(int*)val);
	char *s = (char*)malloc(len+1);
	sprintf(s, "%d", *(int*)val);
	return s;
}

// Get string value of the 'int' type node
char* repr(Node *node) {
	int len = snprintf(NULL, 0, "%d", value_of(node));
	char *s = (char*)malloc(len+1);
	sprintf(s, "%d", value_of(node));
	return s;
}

void insert(Node **ROOT, int n) {
	Node *newnode = make_node(n);
	_insert(ROOT, newnode);
}

void delete(Node **ROOT, int n) {
	_delete(ROOT, &n);
}

void swap(Node **ROOT, int a, int b) {
	_swap(ROOT, &a, &b);
}

void sort(Node **ROOT) {
	_sort(ROOT);
}

