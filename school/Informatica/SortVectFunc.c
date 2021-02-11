#include <stdio.h>

int* initVect(int vect_size); // Creates a vector from user input with determined size
void printVect(int* vect, int vect_size); // Prints a vector using a pointer to first element
int* sortMinMaxVect(int* vect, int vect_size); // Reorders an int vector from min to max

int main() {
	int vect_size;
    int* pvect;

    /* get vector size */
    printf("Inserisci il numero di elementi interi da salvare: "); scanf("%d", &vect_size);
	int vect[vect_size];

    pvect = initVect(vect_size);

	printf("\nOrdinato: "); printVect(vect, vect_size);
	return 0;
}

int* initVect(int vect_size) {
    int i, vect[];
    for (i = 0; i < vect_size; i++) {
		printf("Inserisci l'elemento di indice [%d]: ", i); scanf("%d", &vect[i]);
	}
}

void printVect(int* pvect, int vect_size); {
	/* Gets an int vector and it's size and prints it's values in line*/
	int i; // Support for older gcc versions
    printf("Vettore: |");
	for (i = 0; i < vect_size; i++) {
		printf("%d|", *(pvect + i));
	}
}

int* sortMinMaxVect(int* vect, int vect_size) {
    for (i = 0; i < vect_size - 1; i++) {
		for (j = i + 1; j < vect_size; j++) {
			/*printf("\n\n_____debug_____");
			printf("\n1. vect[%d] %d", i, vect[i]);
			printf("\n2. vect[%d]: %d", j,  vect[j]);
			printf("\nConfronto: %d < %d", vect[j], vect[i]);*/
			if (vect[j] < vect[i]) {
				//printf("\nConfronto VERO"); // still debug stuff
				int tmp = vect[i];
				vect[i] = vect[j];
				vect[j] = tmp;
			}
		}
	}
}
