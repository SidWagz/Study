
#ifndef DOUBLY_H
#define DOUBLY_H

#import "dstypes.h"

// Define generic name for node
typedef DoubleNode Node;

// Declare all methods for the list
void print_list (Node*);
int value_of (Node*);
int length_of (Node*);
void insert (Node**, int);
void delete (Node**, int);
void swap (Node**, int, int);
void sort(Node**);

#endif