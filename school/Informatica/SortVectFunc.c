// PREPROCESSOR
#include <stdio.h>

// FUNCTION PROTOTYPES
/* initializes a int vector from user input and returns a pointer to first element */
int* initVect(int vect[], int vect_size); 

/* prints a vector using a pointer to first element */
void printVect(int* pvect, int vect_size);

/* reorders an int vector from min to max using a pointer to first element */
void sortMinMaxVect(int* pvect, int vect_size);

// MAIN
int main() {
    /* get vector size and create it */
    int vect_size;
    printf("[IN] Insert the integer vector size: "); scanf("%d", &vect_size);
	int vect[vect_size];

    /* initialize vector from user input and get pointer */
    int* pvect = initVect(vect, vect_size);
    printVect(pvect, vect_size); //let's see our new vector

    /* sort vector */
    sortMinMaxVect(pvect, vect_size);
    printf("\n[i] Sorting finished.\n"); 
    printVect(pvect, vect_size); //let's see our vector sorted

    /* end */
    return 0;
}
 
// FUNCTION DEFINITIONS
int* initVect(int vect[], int vect_size) {
	int i; // support for older gcc versions
    for (i = 0; i < vect_size; i++) {
		printf("[IN] Insert the integer indexed [%d]: ", i); scanf("%d", &vect[i]);
	}
    return &vect[0];
}

void printVect(int* pvect, int vect_size) {
	int i; // support for older gcc versions
    printf("[OUT] Vector: |");
	for (i = 0; i < vect_size; i++) {
		printf("%d|", *(pvect + i));
	}
}

void sortMinMaxVect(int* pvect, int vect_size) {
    printf("\n[i] Sorting vector...");
    int i, j; // support for older gcc versions
    for (i = 0; i < vect_size - 1; i++) {
		for (j = i + 1; j < vect_size; j++) {
			if (*(pvect + j) < *(pvect + i)) {
				printf("\n--> [i] Switched element %d indexed %d with element %d indexed %d", *(pvect + i), i, *(pvect + j), j);
                printf(" -> "); printVect(pvect, vect_size);
                int tmp = *(pvect + i);
				*(pvect + i) = *(pvect + j);
				*(pvect + j) = tmp;
			}
		}
	}
}