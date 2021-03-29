THIS CODE DOES NOT WORK AND WAS NOT FINISHED

// PREPROCESSOR
#include <stdio.h>

// MAIN
int main() {

	// VARIABLES
	int vect[10] = {1,3,4,6,2,5,9,7,7,8}, 
	size = sizeof(vect) / sizeof(vect[0]),
	step = 0,
	swap = -1,
	i, j, k, tmp;
	
	// PRINT VECTOR
	printf("\n[step %-2d] >> ", step); printf("|"); for (k = 0; k < size; k++) printf("%d|", vect[i]);
	
	// BUBBLE SORT WITH LOGGING
	for(i = 0; i < size-1; i++) {
		for(j = 0; j < size-i-1; j++) {
			if(vect[j] > vect[j+1]) {
				tmp = vect[j];
				vect[j] = vect[j+1];
				vect[j+1] = tmp;
				swap = j;
			}
			step++;
			
			/* logging steps */
			printf("\n[step %-2d] >> ", step);
			printf("|");
			for (k = 0; k < size; k++) { // print vector, same as printVect()
				if (k == j || k == j+1) { // numbers being considered by the inner cicle of the bubble sort
					if (k == swap || k == swap + 1) { // swapped numbers
						printf("\033[0;31m%d\033[0m|", vect[k]); 
						swap = -1;
					}
					else printf("\033[0;32m%d\033[0m|", vect[k]);
				}
				else printf("%d|", vect[k]);
			}
			
		}
		printf("\n");	
	}
	/* end */
	return 0;
}
	
	
