
#ifndef STACK_H
#define STACK_H

#import "singly.h"

void _push(Node**, void*);
void* _pop(Node**);
void* _peek(Node*);
int height(Node*);

#endif