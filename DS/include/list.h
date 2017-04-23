
#ifndef LIST_H
#define LIST_H

// Declaration for all generic 'list' function

// Non-modifying functions
void print_list (Node*);
int length_of (Node*);

// Modifying functions
void insert_at_head (Node** HEAD);
void insert (Node**, int);
void delete (Node**, int);
void swap (Node**, int, int);
void sort(Node**);

#endif