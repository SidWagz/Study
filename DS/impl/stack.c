
#import <stdio.h>
#import <stdlib.h>

#import "stack.h"

void _push(Node** ROOT, void *n) {
	Node *newnode = n;
	_insert_at_head(ROOT, n);
}

void* _pop(Node** ROOT) {
	if (height(*ROOT) == 0)
		return NULL;
	return _delete_head(ROOT);
}

void* _peek(Node* ROOT) {
	if (height(ROOT) == 0)
		return NULL;
	return ROOT->val;
}

int height(Node* ROOT) {
	int length = 0;
	Node *current = ROOT;
	while (current != NULL && ++length)
		current = current->next;

	return length;
}