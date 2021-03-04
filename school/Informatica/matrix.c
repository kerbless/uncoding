// PREPROCESSOR
#include <stdio.h>
#define m_size 10 //https://stackoverflow.com/questions/4024318/why-do-most-c-developers-use-define-instead-of-const

// MAIN
int main() {
    /* dichiarazione matrice */
    int pythagorean_table[m_size][m_size], i, j;
    
	/* inizializzazione matrice */
	for (i = 0; i < m_size; i++) {
		for (j = 0; j < m_size; j++) {
			pythagorean_table[i][j] = (j+1)*(i+1);
		}
	}
	
	/* output */
	printf("%32s", "TABELLA PITAGORICA"); //32 = lunghezza stringa (18) + lunghezza tab (8) + (lunghezza tavola pitagola - lunghezza stringa) / 2
	for (i = 0; i < m_size; i++) {
		printf("\n\t");
		for (j = 0; j < m_size; j++) {
			printf("%-3d", pythagorean_table[i][j]);
		}
	}
	
    /* end */
    return 0;
}

