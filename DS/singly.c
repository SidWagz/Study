
#import<stdio.h>
#import<stdlib.h>

#import "dstypes.h"
#import "singly.h"

//Get new node
Node* make_node(int n) {
	Node *newnode = (Node*)malloc(sizeof(Node));
	newnode->val = malloc(sizeof(int));
	*((int*)newnode->val) = n;
	newnode->next = NULL;
	return newnode;
}

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

