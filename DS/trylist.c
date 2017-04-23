
#import<stdio.h>
#import<stdlib.h>

#import "doubly.h"


int main (int argc, char const *argv[]) {

	printf("\n");

	Node *ROOT = NULL;

	//Create list and print it
	insert(&ROOT, 1);
	insert(&ROOT, 2);
	insert(&ROOT, 3);
	insert(&ROOT, 4);

	printf("Length of list is %d\n\n", length_of(ROOT));
	print_list(ROOT);

	//Delete mid element
	delete(&ROOT, 2);
	printf("Length of list is %d\n\n", length_of(ROOT));
	print_list(ROOT);

	//Delete root element
	delete(&ROOT, 1);
	printf("Length of list is %d\n\n", length_of(ROOT));
	print_list(ROOT);

	//Delete last element
	delete(&ROOT, 4);
	printf("Length of list is %d\n\n", length_of(ROOT));
	print_list(ROOT);

	//Delete element not in list
	delete(&ROOT, 5);
	printf("Length of list is %d\n\n", length_of(ROOT));
	print_list(ROOT);

	//Prepare list for swap
	insert(&ROOT, 1);
	insert(&ROOT, 2);
	insert(&ROOT, 5);
	insert(&ROOT, 4);
	
	printf("Length of list is %d\n\n", length_of(ROOT));
	print_list(ROOT);

	//Swap values 5 and 1 (between)
	swap(&ROOT, 1, 5);
	printf("Length of list is %d\n\n", length_of(ROOT));
	print_list(ROOT);

	//Swap values 5 and 1 (one root)
	swap(&ROOT, 3, 5);
	printf("Length of list is %d\n\n", length_of(ROOT));
	print_list(ROOT);

	//Swap values 5 and 1 (one last)
	swap(&ROOT, 4, 2);
	printf("Length of list is %d\n\n", length_of(ROOT));
	print_list(ROOT);

	//Swap values 2 and 5 (one root and one last)
	swap(&ROOT, 5, 2);
	printf("Length of list is %d\n\n", length_of(ROOT));
	print_list(ROOT);

	//Swap values 1 and 1 (self swap)
	swap(&ROOT, 1, 1);
	printf("Length of list is %d\n\n", length_of(ROOT));
	print_list(ROOT);

	//Swap values 1 and 1 (self swap last)
	swap(&ROOT, 5, 5);
	printf("Length of list is %d\n\n", length_of(ROOT));
	print_list(ROOT);

	//Swap values 1 and 1 (self swap root)
	swap(&ROOT, 2, 2);
	printf("Length of list is %d\n\n", length_of(ROOT));
	print_list(ROOT);

	// Sort the list
	sort(&ROOT);
	printf("Length of list is %d\n\n", length_of(ROOT));
	print_list(ROOT);

	return 0;
}