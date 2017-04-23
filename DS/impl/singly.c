
#import<stdio.h>
#import<stdlib.h>

#import "singly.h"
#import "dsspecial.h"

/* List methods implemented */

// Print the list chain
void print_list(Node *ROOT) {

	printf("List chain\n");
	Node *current = ROOT;
	while (current != NULL) {
		repr_format(current, " -> %s");
		current = current->next;
	}
	printf("\n\n");
}

// Returns length of list
int length_of(Node *ROOT) {

	int length = 0;

	Node *current = ROOT;
	while (current != NULL) {
		current = current->next;
		length++;
	}
	return length;
}

// Insert new node to list
void _insert(Node **ROOT, void *n) {
	Node *newnode = (Node*)n;

	if (*ROOT == NULL) {
		*ROOT = newnode;
		return;
	}

	Node *current = *ROOT;
	while (current->next != NULL)
		current = current->next;

	current->next = newnode;
}

// Delete a node from list
void _delete(Node **ROOT, void *n) {

	Node *prev = NULL, *current = *ROOT;

	if (current == NULL) {
		val_format(n, "Cannot find node %d - List is empty\n\n");
		return;
	}

	while (current->next != NULL 
				&& check_value(current, n) != true) {
		prev = current;
		current = current->next;
	}
	
	if (check_value(current, n) != true) {
		val_format(n, "Cannot find node %d - Not in list\n\n");
		return;
	}
	
	Node *t = current;
	if (prev == NULL)
		*ROOT = current->next;
	else
		prev->next = current->next;

	t->next = NULL;
	free(t);
}

// Swap the two nodes if both node values exist in the list
void _swap(Node **ROOT, void *a, void *b) {

	if (*ROOT == NULL) {
		val_format2(a, b, "Cannot find nodes %d and %d - List is empty\n\n");
		return;
	}

	Node *prev_a = NULL, *curr_a = *ROOT;
	Node *prev_b = NULL, *curr_b = *ROOT;

	while (curr_a->next != NULL
				&& check_value(curr_a, a) != true) {
		prev_a = curr_a;
		curr_a = curr_a->next;
	}

	while (curr_b->next != NULL
				&& check_value(curr_b, b) != true) {
		prev_b = curr_b;
		curr_b = curr_b->next;
	}

	if (check_value(curr_a, a) != true) {
		val_format(a, "Cannot find node %d = Not in List\n\n");
		return;
	}
	else if (check_value(curr_b, b) != true) {
		val_format(b, "Cannot find node %d = Not in List\n\n");
		return;
	}

	if (prev_a == NULL)
		*ROOT = curr_b;
	else
		prev_a->next = curr_b;
	
	if (prev_b == NULL)
		*ROOT = curr_a;
	else
		prev_b->next = curr_a;

	Node *t = curr_a->next;
	curr_a->next = curr_b->next;
	curr_b->next = t;

	return;
}

//Declare sorting helper functions
Node* _recur_sort(Node*);
Node* _sort_merge(Node*, Node*);

//Sort list using merge sort
void _sort(Node **ROOT) {

	*ROOT = _recur_sort(*ROOT);
}

//Actual sorting funtion
Node* _recur_sort(Node* ROOT) {

	if (ROOT == NULL)
		return NULL;
	
	Node *start = ROOT;
	Node *veryslow = NULL, *slow = start, *fast = start;

	while (fast->next != NULL) {
		fast = fast->next;
		veryslow = slow;
		slow = slow->next;
		if (fast->next != NULL)
			fast = fast->next;
	}

	if (veryslow == NULL) {
		start->next = NULL;
		return start;
	}
	else {
		veryslow->next = NULL;
		Node *left = _recur_sort(start), *right = _recur_sort(slow);
		return _sort_merge(left, right);
	}
}

//Merge for sort
Node* _sort_merge(Node *left, Node *right) {

	Node *list = NULL, *end;
	if (compare(left, right) <= 0) {
		list = left;
		left = left->next;
	}
	else {
		list = right;
		right = right->next;
	}
	end = list;

	while (left != NULL && right != NULL) {
		if (compare(left, right) <= 0) {
			end->next = left;
			left = left->next;
		}
		else {
			end->next = right;
			right = right->next;
		}
		end = end->next;
	}

	while (left != NULL) {
		end->next = left;
		left = left->next;
		end = end->next;
	}

	while (right != NULL) {
		end->next = right;
		right = right->next;
		end = end->next;
	}

	return list;
}
