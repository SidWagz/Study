
#import<stdio.h>
#import<stdlib.h>

#import "singly.h"

//Definition for 'int' value list
Node* make_node(int n);
int value_of (Node*);

//Get new node
Node* make_node(int n) {
	Node *newnode = (Node*)malloc(sizeof(Node));
	newnode->val = malloc(sizeof(int));
	*((int*)newnode->val) = n;
	newnode->next = NULL;
	return newnode;
}

//Get value from Node
int value_of(Node *node) {
	if (node == NULL)
		return -1;
	return *(int*)(node->val);
}

// Singly methods implemented

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
	while (current->next != NULL)
		current = current->next;

	current->next = newnode;
}

//Delete a node from list
void delete(Node **ROOT, int n) {

	Node *prev = NULL, *current = *ROOT;

	if (current == NULL) {
		printf("Cannot find node %d - List is empty\n\n", n);
		return;
	}

	while (current->next != NULL 
				&& value_of(current) != n) {
		prev = current;
		current = current->next;
	}
	
	if (value_of(current) != n) {
		printf("Cannot find node %d - Not in list\n\n", n);
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

//Swap the two nodes if both node values exist in the list
void swap(Node **ROOT, int a, int b) {

	if (*ROOT == NULL) {
		printf("Cannot find nodes %d and %d - List is empty\n\n", a, b);
		return;
	}

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

	if (value_of(curr_a) != a) {
		printf("Cannot find node %d = Not in List\n\n", a);
		return;
	}
	else if (value_of(curr_b) != b) {
		printf("Cannot find node %d = Not in List\n\n", b);
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
Node* _sort(Node*);
Node* _sort_merge(Node*, Node*);

//Sort list using merge sort
void sort(Node **ROOT) {

	*ROOT = _sort(*ROOT);
}

//Actual sorting funtion
Node* _sort(Node* ROOT) {

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
		Node *left = _sort(start), *right = _sort(slow);
		return _sort_merge(left, right);
	}
}

//Merge for sort
Node* _sort_merge(Node *left, Node *right) {

	Node *list = NULL, *end;
	if (value_of(left) <= value_of(right)) {
		list = left;
		left = left->next;
	}
	else {
		list = right;
		right = right->next;
	}
	end = list;

	while (left != NULL && right != NULL) {
		if (value_of(left) < value_of(right)) {
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
