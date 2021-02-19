// PREPROCESSOR 
#include <stdio.h>

// FUNCTIONS
void printVect(int vect[], int vect_size) {
	/* Gets an int vector and it's size and prints it's values in line*/
	int i; // Support for older gcc versions
	printf("|");
	for (i = 0; i < vect_size; i++) {
		printf("%d|", vect[i]);
	}
}

// MAIN
int main() {
	/* variables */
	int size = 10;
	int vect[size], i;
	
	/* input */
	for(i = 0; i < size; i++) {
		printf("Inserisci l'elemento %d del vettore: ", i); scanf("%d", &vect[i]);
	}
	
	/* output */
	printf("\nHai inserito: "); printVect(vect, size);
	
	/* end */
	return 0;
}
