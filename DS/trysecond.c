
#import<stdio.h>
#import<stdlib.h>

#import "conutil.h"
#import "stack.int.h"

void print_with_height(Node *ROOT) {
	printf("Height of stack is %d\n", height(ROOT));
	printf("Top element is %d\n\n", peek(ROOT));
}

int main (int argc, char const *argv[]) {

	printf("\n");

	Node *ROOT = NULL;

	// Push 1, 2, 3, 4 to stack
	push(&ROOT, 1);
	print_with_height(ROOT);
	push(&ROOT, 2);
	print_with_height(ROOT);
	push(&ROOT, 3);
	print_with_height(ROOT);
	push(&ROOT, 4);
	print_with_height(ROOT);

	// Pop 4 elements
	pop(&ROOT);
	print_with_height(ROOT);
	pop(&ROOT);
	print_with_height(ROOT);
	pop(&ROOT);
	print_with_height(ROOT);
	pop(&ROOT);
	print_with_height(ROOT);
}