/*______________________________________________*/
/*___________ Burroni Blu - III BIA ____________*/
/*________________ 31/03/2021 __________________*/
/*______________________________________________*/

// PREPROCESSOR
#include <stdio.h>
#define MAX 1000

// FUNCTION PROTOTYPES
int* initVect(int vect[], int vect_size); /* initializes a int vector from user input and returns a pointer to first element */
void insertionSort(int *unsorted); /* sorts a vector with the insertion sort algorithm */
void printVect(int *vect, int size);  /* gets a vector pointer and size and prints it's values in line */

// MAIN
int main() {
	/* get vector size and create it */
    int vect_size; 
	printf("Insert the integer vector size: "); scanf("%d", &vect_size);
	int vect[vect_size]; 
	int *vecp = initVect(vect, vect_size);
	]
	
	
	/* end */
	return 0;
}


// FUNCTION DEFINITIONS
int* initVect(int vect[], int vect_size) {
	int i; // support for older gcc versions
    for (i = 0; i < vect_size; i++) {
		printf("Insert the integer indexed [%d]: ", i); scanf("%d", &vect[i]);
	}
    return &vect[0];
}

void printVect(int *vect, int size) {
	int i; /* Support for older gcc versions */
	printf("|");
	for (i = 0; i < size; i++) {
		printf("%d|", *(vect+i));
	}
	return;
}

void insertionSort(int *unsorted) { 
	return;
}
