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
*/

// PREPROCESSOR
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 500

// FUNCTION PROTOTYPES
void CaricaVettore(char v[], char stringa[], int d); /* loads string into v */
void FusioneVettore(char v1[], char v2[], char v3[], int d1, int d2, int d3); /* merges v1 and v2 vectors into v3 */
void OrdinaVettore(char v[], int d); /* performs a selection sort on v */
void Scambia(char *a, char *b); /* swaps two chars */
void StampaVettore(char v[], int d); /* prints a vector */
/* WORK LINE */



/* funzione principale */
int main(void) {
    int dim1, dim2, dim3, user_choice;
    do {
        char stringa1[max], stringa2[max];
        system("clear");
        printf("______________________\n");
        printf(" Progetto vettori in C\n");
        printf("______________________\n");
        printf("Inserimento prima stringa: ");
        scanf("%s", stringa1);
        /* Calcola lunghezza stringa per dimensione 1Â° vettore */
        dim1 = strlen(stringa1);
        char vett1[dim1];
        /* Chiamata alla funzione per il caricamento del 1Â° vettore */
        CaricaVettore(vett1,stringa1,dim1);
        /* Chiamata alla funzione per l'ordinamento del 1Â° vettore */
        OrdinaVettore(vett1,dim1);
        printf("Visualizzazione 1Â° vettore ordinato: ");
        /* Visualizzazione primo vettore ordinato */
        StampaVettore(vett1,dim1);
        printf("Inserimento seconda stringa: ");
        scanf("%s", stringa2);
        /* Calcola lunghezza stringa per dimensione 2Â° vettore */
        dim2 = strlen(stringa2);
        char vett2[dim2];
        /* Chiamata alla funzione per il caricamento del 2Â° vettore */
        CaricaVettore(vett2,stringa2,dim2);
        /* Chiamata alla funzione per l'ordinamento del 2Â° vettore */
        OrdinaVettore(vett2,dim2);
        printf("Visualizzazione 2Â° vettore ordinato____:");
        /* Visualizzazione secondo vettore ordinato */
        StampaVettore(vett2,dim2);
        printf("======================================================\n");
        /* Dimensione terzo vettore */
        dim3 = dim1 + dim2;
        char vett3[dim3];
        /* Fusione dei due vettori ordinati in un terzo vettore */
        FusioneVettore(vett1,vett2,vett3,dim1,dim2,dim3);
        /* Ordinamento Terzo Vettore */
        OrdinaVettore(vett3,dim3);
        printf("Visualizzazione 3Â° vettore ordinato____:");
        /* Stampa su video del terzo vettore */
        StampaVettore(vett3,dim3);
        printf("======================================================\n");
        printf("Vuoi continuare (1 = si) or (0 = no) :");
        scanf("%d", &user_choice);
    } while (user_choice>0);
    return 0;
}

// FUNCTION DEFINITIONS
void CaricaVettore(char v[],char stringa[], int d) { 
    int i;
    for (i = 0; i < d; i++) {
        v[i] = stringa[i];
    }
}

void FusioneVettore(char v1[], char v2[], char v3[], int d1, int d2, int d3) {
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
    int i, j;
    for (i = 0; i < d-1; i++) {
        for (j = i+1; j < d; j++)
            if (v[i] > v[j]) Scambia(&v[i], &v[j]);
    }
}

void Scambia( char *a, char *b) {
    char comodo;
    comodo = *a;
    *a = *b;
    *b = comodo;
}

void StampaVettore(char v[], int d) {
    int i;
    for (i=0; i<d; i++) {
    printf("%c", v[i]);
    }
    printf("\n");
}