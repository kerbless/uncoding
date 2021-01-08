/* INCLUDES */
#include <stdio.h>

/* Data Structures */
typedef float fvect[5];
typedef int ivect[5];
typedef char cmatrix[5][50];

/* MAIN */
int main() {
    
    /* Variables */
    fvect price, i_total;
    ivect quantity;
    cmatrix descriptions;
    float total = 0;

    /* Input */
    for(int i = 0; i < 5; i++) {
        printf("\n\tARTICOLO %d", i+1);
        printf("\nDescrizione: ");
        scanf("%s", &descriptions[i]);
        printf("Quantita': ");
        scanf("%d", &quantity[i]);
        printf("Prezzo: ");
        scanf("%f", &price[i]); 
    }

    /* Elaboration */
    for(int i = 0; i < 5; i++) {
        i_total[i] = quantity[i] * price[i];
        total +=  i_total[i];
    }

    /* Output */
    printf("\n\tArticolo | Quantita' | Prezzo unitario | Prezzo totale | Descrizione\n");
    for(int i = 0; i < 5; i++) {
        printf("\n\t%d\t | %d\t     | %.2f\t       | %.2f        | %s", i+1, quantity[i], price[i], i_total[i], descriptions[i]);
    }
    printf("\nTotale: %.2f", total);

    return 0;
}
