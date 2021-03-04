/*______________________________________________*/
/*_____________ C Vector Project _______________*/
/*___________ Burroni Blu - III BIA ____________*/
/*______________________________________________*/

/* MODIFICHE EFFETTUATE:
-cambiato il nome della costante MAX in "max"
-rimossa la funzione ChiediDimensionamento non definita
-aggiunti commenti sulle funzioni
-rimossi commenti con i nomi delle funzioni
-rimossi i "return;" delle funzioni di tipo void
-aggiunta una parentesi mancante nella funzione CaricaVettore
-aggiunto alcuni spazi tra operatori matematici e di assegnazione per preferenza di stile
-aggiunti vari commenti
-rimossa la variabile superflua "j" in FusioneVettore e sostituita con i
-rinominata la funzione StampaVettoreVideo in StampaVettore
-raggruppate le dichiarazioni/definizioni delle variabili dove possibile
-rinominata la variabile risp in user_choice
-modificati alcuni printf per preferenza di stile
-cambiata la condizione di while per preferenza di stile
-inizializzata la variabile user_choice ad 1
*/

// PREPROCESSOR
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 500

// FUNCTION PROTOTYPES
/* all functions work on characters or character vectors */
void CaricaVettore(char v[], char stringa[], int d); /* loads string into vector v */
void FusioneVettore(char v1[], char v2[], char v3[], int d1, int d2, int d3); /* merges v1 and v2 vectors into v3 */
void OrdinaVettore(char v[], int d); /* performs a selection sort on v */
void Scambia(char *a, char *b); /* swaps two chars */
void StampaVettore(char v[], int d); /* prints a char vector */

// MAIN
int main(void) {
    int dim1, dim2, dim3, user_choice = 1; 

    do {
        char stringa1[max], stringa2[max];

        system("clear");
        printf("\nProgetto vettori in C");
        printf("\n______________________\n");

        // vett1
        printf("Inserisci la prima stringa: ");
        scanf("%s", stringa1); /* gets first string */
        dim1 = strlen(stringa1); /* calculates size of first string */
        char vett1[dim1]; /* declare vector with the size just calculated */
        CaricaVettore(vett1, stringa1, dim1); /* loads string into the new vector*/
        OrdinaVettore(vett1, dim1); /* orders the new vector */
        printf("Primo vettore ordinato: ");
        StampaVettore(vett1, dim1); /* prints vector */

        // vett2 (same as vett1)
        printf("Inserisci la seconda stringa: ");
        scanf("%s", stringa2);
        dim2 = strlen(stringa2); 
        char vett2[dim2]; 
        CaricaVettore(vett2, stringa2, dim2);
        OrdinaVettore(vett2, dim2);
        printf("Secondo vettore ordinato: "); 
        StampaVettore(vett2, dim2); 

        // vett3
        dim3 = dim1 + dim2; /* calculates size of third vector */
        char vett3[dim3]; /* declare third vector */
        FusioneVettore(vett1, vett2, vett3, dim1, dim2, dim3); /* merges v1 and v2 vectors into v3 */
        OrdinaVettore(vett3, dim3); /* order third vector */
        printf("Terzo vettore ordinato: ");
        StampaVettore(vett3, dim3); 

        // menu
        printf("Vuoi continuare? (1 = si)(0 = no): ");
        scanf("%d", &user_choice);

    } while (user_choice == 1);

    return 0;
}

// FUNCTION DEFINITIONS
void CaricaVettore(char v[], char stringa[], int d) {
    /* loads string into vector v */
    int i;
    for (i = 0; i < d; i++) {
        v[i] = stringa[i];
    }
}

void FusioneVettore(char v1[], char v2[], char v3[], int d1, int d2, int d3) {
    /* merges v1 and v2 vectors into v3 */
    int i, k = 0; // k keeps track of v3's next free index
    for (i = 0; i < d1; i++) {
        v3[k] = v1[i];
        k++;
    }
    for (i = 0; i < d2; i++) {
        v3[k] = v2[i];
        k++;
    }
}

void OrdinaVettore(char v[], int d) {
    /* performs a selection sort on v */
    int i, j;
    for (i = 0; i < d-1; i++) {
        for (j = i+1; j < d; j++)
            if (v[i] > v[j]) Scambia(&v[i], &v[j]);
    }
}

void Scambia(char *a, char *b) {
    /* swaps two chars */
    char tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void StampaVettore(char v[], int d) {
    /* prints a char vector */
    int i;
    for (i = 0; i < d; i++) {
        printf("%c", v[i]);
    }
    printf("\n");
}