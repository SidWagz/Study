
#ifndef SINGLY_H
#define SINGLY_H

#import "dstypes.h"

// Define generic name for node
typedef SingleNode Node;

//All operations on singly list
void print_list (Node*);
int value_of (Node*);
int length_of (Node*);
void insert (Node**, int);
void delete (Node**, int);
void swap (Node**, int, int);
void sort(Node**);

#endif