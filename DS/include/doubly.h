
#ifndef DOUBLY_H
#define DOUBLY_H

#import "dstypes.h"

// Define generic name for node
typedef DoubleNode Node;

// Declare all methods for the list
int value_of (Node *node);
void print_list (Node*);
void insert (Node**, int);
int length_of (Node*);

#endif