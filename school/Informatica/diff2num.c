#include <stdio.h>

int bring_up(int *high, int *low); //prototype (declaration)

int main() {
    //variables
    int a, b, cycles;

    //input
    printf("Inserisci il primo numero: "); scanf("%d", &a);
    printf("Inserisci il secondo numero: "); scanf("%d", &b);
    
    //elaboration
    if (a > b) {
        cycles = bring_up(&a, &b);
    }
    else {
    	cycles = bring_up(&b, &a);
	}

    //output
    printf("\nPrimo numero: %d", a);
    printf("\nSecondo numero: %d", b);
    printf("\nIncremento effettuato: +%d", cycles);
    
    //exit
    printf("\n\nPremi invio per uscire");
    getch();
    return 0;
}

int bring_up(int *high, int *low) {//implementation (definition)
	int i = 0;
	printf("\n_________bring up_________");
    while(*high > *low) {
        *low = *low + 1;
        i++;
        printf("\n[%d] low = %d", i, *low);
    }
    printf("\n__________________________\n");
    return i;
	}
