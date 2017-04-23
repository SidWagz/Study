
#import<stdio.h>
#import<stdlib.h>

#import "conutil.h"
#import "singly.h"

void print_with_length(Node *ROOT) {
	printf("Length of list is %d\n", length_of(ROOT));
	print_list(ROOT);
}

int main (int argc, char const *argv[]) {

	printf("\n");

	Node *ROOT = NULL;

	//Create list and print it
	printboldln("Insert 1, 2, 3, 4");
	insert(&ROOT, 1);
	insert(&ROOT, 2);
	insert(&ROOT, 3);
	insert(&ROOT, 4);
	print_with_length(ROOT);

	//Delete mid element
	printboldln("Delete 2");
	delete(&ROOT, 2);
	print_with_length(ROOT);

	//Delete root element
	printboldln("Delete 1");
	delete(&ROOT, 1);
	print_with_length(ROOT);

	//Delete last element
	printboldln("Delete 4");
	delete(&ROOT, 4);
	print_with_length(ROOT);

	//Delete element not in list
	printboldln("Delete 5");
	delete(&ROOT, 5);
	print_with_length(ROOT);

	//Prepare list for swap
	printboldln("Insert 1, 2, 5, 4");
	insert(&ROOT, 1);
	insert(&ROOT, 2);
	insert(&ROOT, 5);
	insert(&ROOT, 4);
	print_with_length(ROOT);

	//Swap values 5 and 1 (between)
	printboldln("Swap 1 and 5");
	swap(&ROOT, 1, 5);
	print_with_length(ROOT);

	//Swap values 5 and 1 (one root)
	printboldln("Swap 3 and 5");
	swap(&ROOT, 3, 5);
	print_with_length(ROOT);

	//Swap values 5 and 1 (one last)
	printboldln("Swap 4 and 2");
	swap(&ROOT, 4, 2);
	print_with_length(ROOT);

	//Swap values 2 and 5 (one root and one last)
	printboldln("Swap 5 and 2");
	swap(&ROOT, 5, 2);
	print_with_length(ROOT);

	//Swap values 1 and 1 (self swap)
	printboldln("Swap 1 and 1");
	swap(&ROOT, 1, 1);
	print_with_length(ROOT);

	//Swap values 1 and 1 (self swap last)
	printboldln("Swap 5 and 5");
	swap(&ROOT, 5, 5);
	print_with_length(ROOT);

	//Swap values 1 and 1 (self swap root)
	printboldln("Swap 2 and 2");
	swap(&ROOT, 2, 2);
	print_with_length(ROOT);

	// Sort the list
	printboldln("Sort");
	sort(&ROOT);
	print_with_length(ROOT);

	return 0;
}