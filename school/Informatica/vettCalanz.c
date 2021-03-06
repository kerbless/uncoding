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
    int description_max_lenght = 0, description_lenght = 0;
	int i;
	
    /* Input */
    for(i = 0; i < 5; i++) {
        system("cls");
        printf("\n\tARTICOLO %d", i+1);
        printf("\nDescrizione: ");
        scanf("%s", &descriptions[i]);
        printf("Quantita': ");
        scanf("%d", &quantity[i]);
        printf("Prezzo: ");
        scanf("%f", &price[i]);
    }

    /* Elaboration */
    for(i = 0; i < 5; i++) {
        i_total[i] = quantity[i] * price[i];
        total +=  i_total[i];
        /*printf("\nmax: %d\nlenght: %d\n", description_max_lenght, description_lenght);
        description_lenght = sizeof(descriptions[i]) / sizeof(descriptions[i][0]); //
        if (description_max_lenght < description_lenght) description_max_lenght = description_lenght; 
    */}

    /* Output */
    //system("cls");
    printf("\n\t| Articolo |            Descrizione            | Quantita' | Prezzo unitario | Prezzo totale |\n");
    for(i = 0; i < 5; i++) {
        printf("\n\t| %-9d| %-34s| %-10d| %-16.2f| %-14.2f|\n", i+1,  descriptions[i], quantity[i], price[i], i_total[i]);
    }
    printf("\nTotale: %.2f", total);


    return 0;
}
