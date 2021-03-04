/*______________________________________________*/
/*_____________ C Vector Project _______________*/
/*___________ Burroni Blu - III BIA ____________*/
/*______________________________________________*/

// PREPROCESSOR
#include <stdio.h>
#include <string.h>
#define max 500

// FUNCTION PROTOTYPES
/* all functions work on characters or character vectors */
void printv(char vect[], int size); /* prints a char vector */
void load(char vect[], char str[], int size); /* loads string into vector vect */
void selectionSort(char vect[], int size); /* performs a reversed selection sort on vect */
void merge(char vect1[], char vect2[], char vect3[], int size1, int size2, int size3); /* merges two vectors into another */
void swap(char *a, char *b); /* swaps two chars */


// MAIN
int main(void) {
    int str_dim1, str_dim2, str_dim3, user_choice = 1; 

    do {
        char string1[max], string2[max];

        system("clear");
        printf("\nC Vector Project");
        printf("\n______________________\n");
        
        // vett1
        printf("Insert the first string: ");
        scanf("%s", string1); /* gets first string */
        str_dim1 = strlen(string1); /* calculates size of first string */
        char vett1[str_dim1]; /* declare vector with the size just calculated */
        load(vett1, string1, str_dim1); /* loads string into the new vector*/
        selectionSort(vett1, str_dim1); /* orders the new vector */
        printf("First vector ordered: ");
        printv(vett1, str_dim1); /* prints vector */

        // vett2 (same as vett1)
        printf("Insert the second string: ");
        scanf("%s", string2);
        str_dim2 = strlen(string2); 
        char vett2[str_dim2]; 
        load(vett2, string2, str_dim2);
        selectionSort(vett2, str_dim2);
        printf("Second vector ordered: "); 
        printv(vett2, str_dim2); 

        // vett3
        str_dim3 = str_dim1 + str_dim2; /* calculates size of third vector */
        char vett3[str_dim3]; /* declare third vector */
        merge(vett1, vett2, vett3, str_dim1, str_dim2, str_dim3); /* merges v1 and v2 vectors into v3 */
        selectionSort(vett3, str_dim3); /* order third vector */
        printf("Third vector ordered: ");
        printv(vett3, str_dim3); 

        // menu
        printf("Do you want to continue? (1 = yes)(0 = no): ");
        scanf("%d", &user_choice);

    } while (user_choice == 1);

    return 0;
}

// FUNCTION DEFINITIONS

void printv(char vect[], int size) {
    /* prints a char vector */
    int i;
    for (i = 0; i < size; i++) {
        printf("%c", vect[i]);
    }
    printf("\n");
}

void load(char vect[], char str[], int size) {
    /* loads string into vectector vect */
    int i;
    for (i = 0; i < size; i++) {
        vect[i] = str[i];
    }
}

void selectionSort(char vect[], int size) {
    /* performs a reverse selection sort on vect */
    int i, j;
    for (i = 0; i < size-1; i++) {
        for (j = i+1; j < size; j++)
            if (vect[i] < vect[j]) swap(&vect[i], &vect[j]);
    }
}

void merge(char vect1[], char vect2[], char vect3[], int size1, int size2, int size3) {
    /* merges v1 and v2 vectors into v3 */
    int i, k = 0; // k keeps track of v3's next free index
    for (i = 0; i < size1; i++) {
        vect3[k] = vect1[i];
        k++;
    }
    for (i = 0; i < size2; i++) {
        vect3[k] = vect2[i];
        k++;
    }
}

void swap(char *a, char *b) {
    /* swaps two chars */
    char tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}