
#import<stdio.h>
#import<stdlib.h>

// Define boolean types for clarity
typedef int bool;
#define true 1
#define false 0

// Create new struct type Person
typedef struct
{
	char* name;
	int age;
	bool single;
} Person;

// Create new struct type RealPerson
typedef struct RealPerson RealPerson;
struct RealPerson
{
	char* name;
	RealPerson* partner;
};

const char* is_single(Person p) {
	return p.single ? "yes" : "no";
}

int main() {

	// Make person1 using struct
	Person p1;
	p1.name = "Abra";
	p1.age = 21;
	p1.single = true;

	printf("Person p1 - using struct\n");
	printf("name=%s age=%d single=%s\n\n", p1.name, p1.age, is_single(p1));

	// Make person2 using struct pointer
	Person* p2 = (Person*)malloc(sizeof(Person));
	p2->name = "Kadabra";
	p2->age = 22;
	p2->single = false;

	printf("Person p2 - using struct pointer\n");
	printf("name=%s age=%d single=%s\n\n", p2->name, p2->age, is_single(*p2));

	// Make 2 real people who are partners
	RealPerson* rp1 = (RealPerson*)malloc(sizeof(RealPerson));
	rp1->name = "Ying";

	RealPerson* rp2 = (RealPerson*)malloc(sizeof(RealPerson));
	rp2->name = "Yang";

	rp1->partner = rp2;
	rp2->partner = rp1;

	printf("RealPerson1=%s RealPerson2=%s\n", rp1->name, rp2->name);
	printf("Partner of %s=%s\n", rp1->name, rp1->partner->name);
	printf("Partner of %s=%s\n", rp2->name, rp2->partner->name);

	return 0;
}