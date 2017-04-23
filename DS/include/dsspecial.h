
#ifndef DSSPECIAL_H
#define DSSPECIAL_H

char* repr(Node*);
void repr_format(Node*, char*);
void repr_sfunc(Node*, void (*func)(char*));

inline void repr_format(Node *node, char *format) {
	char *t = repr(node);
	printf(format, t);
	free(t);
}

inline void repr_sfunc(Node *node, void (*func)(char *s)) {
	char *t = repr(node);
	func(t);
	free(t);
}

#endif