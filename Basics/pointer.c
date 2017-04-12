
#import<stdio.h>

void swap_num (int, int);

void swap_ptr (int*, int*);

void swap_num (int a, int b) {

	int temp = a;
	a = b;
	b = temp;
	printf("Inside swap_num\n");
	printf("a=%d b=%d\n", a, b);
} 

void swap_ptr (int* a, int* b) {

	int temp = *a;
	*a = *b;
	*b = temp;
	printf("Inside swap_ptr\n");
	printf("a=%d b=%d\n", *a, *b);
}

int main () {

	// Define two nums to be swapped
	int a = 10, b = 20;
	printf("Start with\n");
	printf("a=%d b=%d\n\n", a, b);

	// Swap using temp variable
	int temp = a;
	a = b;
	b = temp;
	printf("After temp swap\n");
	printf("a=%d b=%d\n\n", a, b);

	a = 10, b = 20;
	// Swap using xor
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("After xor swap\n");
	printf("a=%d b=%d\n\n", a, b);

	a = 10, b = 20;
	// Swap using swap_num
	swap_num(a, b);
	printf("Outside swap_num\n");
	printf("a=%d b=%d\n\n", a, b);

	a = 10, b = 20;
	// Swap using swap_ptr
	swap_ptr(&a, &b);
	printf("Outside swap_ptr\n");
	printf("a=%d b=%d\n\n", a, b);

	return 0;
}