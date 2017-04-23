
#ifndef LIST_H
#define LIST_H

// Declaration for all generic 'list' function

// Compare functions
int check_value(Node*, void*);
int compare(Node*, Node*);
int equal(Node*, Node*);

// Access functions
char* repr(Node*);

// Non-modifying functions
void print_list(Node*);
int length_of(Node*);

// Modifying functions
void _insert_at_head(Node**, void*);
void _insert(Node**, void*);
void* _delete_head(Node**);
void _delete(Node**, void*);
void _swap(Node**, void*, void*);
void _sort(Node**);

#endif