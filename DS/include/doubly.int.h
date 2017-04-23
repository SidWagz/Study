
#ifndef DOUBLY_INT_H
#define DOUBLY_INT_H

#import "doubly.h"

/* Definition for 'int' value list */

Node* make_node(int n);
int value_of(Node*);

// Modifying functions
void insert_at_head(Node**, int);
void insert(Node**, int);
void delete(Node**, int);
void swap(Node**, int, int);
void sort(Node**);

#endif