/*______________________________________________*/
/*___________ Burroni Blu - III BIA ____________*/
/*________________ 29/03/2021 __________________*/
/*______________________________________________*/

// PREPROCESSOR
#include <stdio.h>

// FUNCTION PROTOTYPES
void bubbleSort(int vect[]);
void printVect(int vect[]);

// GLOBAL VARIABLES
int vector[10] = {1,3,4,6,2,5,9,7,7,8};
int size = sizeof(vector) / sizeof(vector[0]);

// MAIN
int main() {
	printf("%-16s", "Initial vector: "); printVect(vector);
	bubbleSort(vector);
	printf("\n%-16s", "Bubble sorted: "); printVect(vector);
	
	/* end */
	return 0;
}


// FUNCTION DEFINITIONS
void printVect(int vect[]) { /* gets an int vector and prints it's values in line */
	int i; /* Support for older gcc versions */
	
	printf("|");
	for (i = 0; i < size; i++) {
		printf("%d|", vect[i]);
	}
}

void bubbleSort(int vect[]) { /* sorts a vector with the bubble sort algorithm */
	int i, j, k, tmp, swap = -1, step = 0;
	for(i = 0; i < size-1; i++) {
		for(j = 0; j < size-i-1; j++) {
			if(vect[j] > vect[j+1]) {
				tmp = vect[j];
				vect[j] = vect[j+1];
				vect[j+1] = tmp;
				swap = j;
			}
		}
	}
}