
#import<stdio.h>
#import<stdlib.h>

#import "doubly.h"
#import "dsspecial.h"

/* List methods implemented */

// Print the whole list chain
void print_list (Node *ROOT) {
	Node *current = ROOT;

	printf("Current list:\n");
	while (current != NULL) {
		repr_format(current, "-> %s ");
		current = current->next;
	}
	printf("\n\n");
}

// Returns length of list
int length_of (Node* ROOT) {

	int length = 0;
	Node *current = ROOT;

	while (current != NULL && ++length)
		current = current->next;

	return length;
}

// Insert new node to head oflist
void _insert_at_head (Node **ROOT, void *n) {
	Node *newnode = (Node*)n;

	if (*ROOT == NULL)
		*ROOT = newnode;
	else {
		newnode->next = *ROOT;
		(*ROOT)->prev = newnode;
		*ROOT = newnode;
	}
}

// Insert function for list
void _insert (Node **ROOT, void *n) {
	Node *newnode = (Node*)n;

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
void _delete (Node **ROOT, void *n) {

	Node *current = *ROOT;

	if (current == NULL) {
		val_format(n, "Cannot find node %s - List is empty\n");
		return;
	}

	while (current != NULL 
				&& check_value(current, n) != true)
		current = current->next;

	if (current == NULL) {
		val_format(n, "Cannot find node %s - Not present in list\n");
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
void _swap (Node **ROOT, void *a, void *b) {

	if (*ROOT == NULL) {
		val_format2(a, b, "Cannot find nodes %s and %s - List is empty\n");
		return;
	}

	Node *prev_a = NULL, *curr_a = *ROOT;
	Node *prev_b = NULL, *curr_b = *ROOT;

	while (curr_a != NULL && check_value(curr_a, a) != true) {
		prev_a = curr_a;
		curr_a = curr_a->next;
	}

	while (curr_b != NULL && check_value(curr_b, b) != true) {
		prev_b = curr_b;
		curr_b = curr_b->next;
	}

	if (curr_a == NULL) {
		val_format(a, "Cannot find node %s - Not present in list\n");
		return;
	}
	
	if (curr_b == NULL) {
		val_format(b, "Cannot find node %s - Not present in list\n");
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
Node* _recur_sort(Node*);
Node* _merge_sort(Node*, Node*);

void _sort(Node** ROOT) {
	*ROOT = _recur_sort(*ROOT);
}

Node* _recur_sort (Node *ROOT) {

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
		Node *left = _recur_sort(start), *right = _recur_sort(slow);
		return _merge_sort(left, right);
	}
}

Node* _merge_sort (Node *left, Node *right) {

	Node *newstart;

	if (compare(left, right) <= 0) {
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
		if (compare(left, right) <= 0) {
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
