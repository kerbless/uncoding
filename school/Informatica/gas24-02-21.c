/*
Nel programma è stata AGGIUNTA l'inizializzazione della variabile consumo a -1
ed il ciclo while con i conseguenti if e printf per controllare l'input dell'utente.
*/

// PREPROCESSOR
#include <stdio.h>

// MAIN
int main() {
    /* dichiarazione costanti e variabili */
    int soglia_prezzo = 100;
    float prezzo_base = 2.8, prezzo_soglia = 3.5, consumo = -1, importo;
	
	/* output info */
	printf("\tCALCOLO SPESA GAS"
		   "\nProgramma calcolatore della tua spesa gas."
		   "\nRicorda la tabella dei prezzi:"
		   "\nConsumo > 100mc | Consumo < 100mc\n"
		     "2,8 euro/mc     | 3,5 euro/mc\n");
	
	/* input */
	while(consumo == -1) {
		printf("\nInserisci il tuo consumo: "); scanf("%f", &consumo);
		if (consumo < 0) {
			printf("Il consumo non puo' essere negativo!\n"),
			consumo = -1;
		}
	}
	
	/* elaborazione */
	if (consumo <= soglia_prezzo) { //il consumo non supera la soglia prezzo, usiamo il prezzo base
		importo = consumo * prezzo_base;
		printf("\nImporto (calcolato sul prezzo base): ");
	}
	else { //il consumo supera la soglia prezzo, usiamo il prezzo soglia
		importo = consumo * prezzo_soglia;
		printf("\nImporto (calcolato sul prezzo incrementato): ");
	}
	
	/* oputput */
	printf("%.2f", importo);
	
    /* end */
    return 0;
}

