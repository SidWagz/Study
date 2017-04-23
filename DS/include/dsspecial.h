
#ifndef DSSPECIAL_H
#define DSSPECIAL_H

char* repr(Node*);
void repr_format(Node*, char*);
void repr_sfunc(Node*, void (*func)(char*));

char* val_repr(void*);

void val_format2(void *val1, void *val2, char *format) {
	char *t1 = val_repr(val1);
	char *t2 = val_repr(val2);
	printf(format, t1, t2);
	free(t1);
	free(t2);
}

void val_format(void *val, char *format) {
	char *t = val_repr(val);
	printf(format, t);
	free(t);
}

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