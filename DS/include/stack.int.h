
#ifndef STACK_INT_H
#define STACK_INT_H

#import "stack.h"

Node* make_node(int n);

void push(Node**, int);
int pop(Node**);
int peek(Node*);

#endif