
#import<stdio.h>
#import<stdlib.h>

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

// Delete a node from the list
void delete (Node **ROOT, int n) {

	Node *current = *ROOT;

	if (current == NULL) {
		printf("Cannot find node %d - List is empty\n", n);
		return;
	}

	while (current != NULL && value_of(current) != n)
		current = current->next;

	if (current == NULL) {
		printf("Cannot find node %d - Not present in list\n", n);
		return;
	}

	Node *temp = current, *prev = current->prev, *next = current->next;

	if (prev == NULL)
		*ROOT = next;
	else
		prev->next = next;

	if (next != NULL)
		next->prev = prev;
	

	temp->next = NULL;
	temp->prev = NULL;
	free(temp);
}

// Swap two nodes from the list
void swap (Node **ROOT, int a, int b) {

	if (*ROOT == NULL) {
		printf("Cannot find nodes %d and %d - List is empty\n", a, b);
		return;
	}

	Node *prev_a = NULL, *curr_a = *ROOT;
	Node *prev_b = NULL, *curr_b = *ROOT;

	while (curr_a != NULL && value_of(curr_a) != a) {
		prev_a = curr_a;
		curr_a = curr_a->next;
	}

	while (curr_b != NULL && value_of(curr_b) != b) {
		prev_b = curr_b;
		curr_b = curr_b->next;
	}

	if (curr_a == NULL) {
		printf("Cannot find node %d - Not present in list\n", a);
		return;
	}
	
	if (curr_b == NULL) {
		printf("Cannot find node %d - Not present in list\n", b);
		return;
	}

	Node *newprev_a, *newprev_b, *next_a = curr_a->next, *next_b = curr_b->next;

	if (prev_a == NULL)
		*ROOT = curr_b;
	else
		prev_a->next = curr_b;

	if (prev_b == NULL)
		*ROOT = curr_a;
	else
		prev_b->next = curr_a;
	
	if (prev_a == curr_b)
		newprev_b = curr_a;
	else
		newprev_b = prev_a;

	if (prev_b == curr_a)
		newprev_a = curr_b;
	else
		newprev_a = prev_b;

	if (next_a != NULL)
		next_a->prev = curr_b;

	if (next_b != NULL)
		next_b->prev = curr_a;

	Node *t = curr_a->next;
	curr_a->next = curr_b->next;
	curr_b->next = t;
	curr_a->prev = newprev_a;
	curr_b->prev = newprev_b;
}

// Helper functions for list merge sort
Node* _sort(Node*);
Node* _merge_sort(Node*, Node*);

void sort (Node **ROOT) {

	*ROOT = _sort(*ROOT);
}

Node* _sort (Node *ROOT) {

	if (ROOT == NULL)
		return NULL;

	Node *start = ROOT;
	Node *veryslow = NULL, *slow = start, *fast = start;

	while (fast->next != NULL) {
		veryslow = slow;
		slow = slow->next;
		fast = fast->next;
		if (fast->next != NULL)
			fast = fast->next;
	}

	if (veryslow == NULL) {
		start->next = NULL;
		start->prev = NULL;
		return start;
	}
	else {
		veryslow->next = NULL;
		Node *left = _sort(start), *right = _sort(slow);
		return _merge_sort(left, right);
	}
}

Node* _merge_sort (Node *left, Node *right) {

	Node *newstart;

	if (value_of(left) <= value_of(right)) {
		newstart = left;
		left->prev = NULL;
		left = left->next;
	}
	else {
		newstart = right;
		right->prev = NULL;
		right = right->next;
	}

	Node *newend = newstart;

	while (left != NULL && right != NULL) {
		if (value_of(left) <= value_of(right)) {
			newend->next = left;
			left->prev = newend;
			left = left->next;
		}
		else {
			newend->next = right;
			right->prev = newend;
			right = right->next;
		}
		newend = newend->next;
	}

	while (left != NULL) {
		newend->next = left;
		left->prev = newend;
		left = left->next;
		newend = newend->next;
	}

	while (right != NULL) {
		newend->next = right;
		right->prev = newend;
		right = right->next;
		newend = newend->next;
	}

	return newstart;
}
