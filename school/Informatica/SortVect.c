#include <stdio.h>

void printVect(int vect[], int vect_size) {
	/* Gets an int vector and it's size and prints it's values in line*/
	int i; // Support for older gcc versions
	printf("|");
	for (i = 0; i < vect_size; i++) {
		printf("%d|", vect[i]);
	}
}

int main() {
	/* Variables Gets an int vector and it's size and prints it's values in line*/
	int vect_size, i, j; 
	
	printf("Inserisci il numero di elementi interi da salvare: "); scanf("%d", &vect_size);
	int vect[vect_size];
	for (i = 0; i < vect_size; i++) {
		printf("Inserisci l'elemento di indice [%d]: ", i); scanf("%d", &vect[i]);
	}
	printf("Vettore:  "); printVect(vect, vect_size);
	
	/* Reorder */
	for (i = 0; i < vect_size - 1; i++) {
		for (j = i + 1; j < vect_size; j++) {
			/*printf("\n\n_____debug_____");
			printf("\n1. vect[%d] %d", i, vect[i]);
			printf("\n2. vect[%d]: %d", j,  vect[j]);
			printf("\nConfronto: %d < %d", vect[j], vect[i]);*/
			if (vect[j] < vect[i]) {
				printf("\nConfronto VERO");
				int tmp = vect[i];
				vect[i] = vect[j];
				vect[j] = tmp;
			}
		}
	}
	
	printf("\nOrdinato: "); printVect(vect, vect_size);
	return 0;
}


