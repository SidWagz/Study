#import<stdio.h>
#import<stdlib.h>

#import "stack.int.h"

// Push new node on top of stack
void push(Node **ROOT, int n) {
	Node *newnode = make_node(n);
	_push(ROOT, newnode);
}

// Pop the top node of stack
int pop(Node **ROOT) {
	Node *t = _pop(ROOT);
	if (t == NULL)
		return -1;
	return *(int*)t;
}

// Peek at the top node of stack
int peek(Node *ROOT) {
	Node *t = _peek(ROOT);
	if (t == NULL)
		return -1;
	return *(int*)t;
}
