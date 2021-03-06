// PREPROCESSOR
#include <stdio.h>
#define m_size 10 //https://stackoverflow.com/questions/4024318/why-do-most-c-developers-use-define-instead-of-const

// MAIN
int main() {
    /* dichiarazione matrice */
    int pythagorean_table[m_size][m_size], i, j, tot_row[m_size], tot_column[m_size];

	/* inizializzazione matrice */
	for (i = 0; i < m_size; i++) {
		for (j = 0; j < m_size; j++) {
			pythagorean_table[i][j] = (j+1)*(i+1);
		}
	}

	/* calcolo totali per colonna e per riga */
	for (i = 0; i < m_size; i++) {
		tot_column[i] = 0; //init
		tot_row[i] = 0; //init
		for (j = 0; j < m_size; j++) {
			tot_column[i] += pythagorean_table[i][j];
			tot_row[i] += pythagorean_table[j][i];
		}
	}


	/* output */
	printf("%37s", "TABELLA PITAGORICA"); //32 = lunghezza stringa (18) + lunghezza tab (8) + (lunghezza tabella pitagorica - lunghezza stringa) / 2
	for (i = 0; i < m_size; i++) {
		printf("\n\t");
		for (j = 0; j < m_size; j++) {
			printf("%-4d", pythagorean_table[i][j]);
		}
		printf("= %3d", tot_row[i]);
	}
	printf("\n\t");
	for (i = 0; i < m_size; i++) {
		printf("____");
	}
	printf("\n\t");
	for (i = 0; i < m_size; i++) {
		printf("%-4d", tot_column[i]);
	}	

    /* end */
    return 0;
}

