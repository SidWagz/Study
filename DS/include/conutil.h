
#ifndef CONUTIL_H
#define CONUTIL_H

void printboldln(char*);

inline void printboldln (char *s) {
	printf("%s%s%s\n", "\033[1m", s, "\033[0m");
}

#endif