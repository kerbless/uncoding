//preprocessor
#include <stdio.h>

//main
int main(){
    //variables
    int alunni = 0, assenti = 0, somma = 0;
    float media;

    //input 
    printf("Inserisci il numero di alunni della classe: ");
    scanf("%d", &alunni);
    int eta[alunni]; //inizializza l'array con una dimensione pari al numero di alunni
    for(int i = 0; i < alunni; i++){
        printf("Inserisci l'eta' dell'alunno %d (o 0 se non e' presente): ", (i+1));
        scanf("%d", &eta[i]);
        if (eta[i] == 0) assenti++; //riaggiungo la gestione degli assenti (non presente nell'algoritmo)
    }

    //elaboration
    for(int i = 0; i < alunni; i++){
        /*
        si potrebbe tranquillamente inserire questa istruzione 
        nel ciclo precedente, ma supponiamo che il programma sia 
        pensato per eseguire diversi tipi di operazioni con l'array 
        eta, pertanto separiamo i cicli per chiarire la distanza logica
        tra le due operazioni di input ed elaborazione
        */
        somma += eta[i];
    }
    media = somma / (alunni - assenti);
    //funziona, ma con 0, 6, 5 mi da 5??

    /*
    //debug
    for(int i = 0; i < (sizeof(eta)/sizeof(eta[0])); i++) {
        printf("\nEta[%d]: %d", i, eta[i]);
    }
    printf("\nSomma: %d", somma);
    printf("\nAlunni: %d", alunni);
    printf("\nAssenti: %d", assenti);
    printf("\nMedia: %f", media);
    */
    
    //output
    printf("\nLa classe costituita da %d alunno/i, di cui %d assente/i, ha un'eta' media di: %.2f anni.", alunni, assenti, media);
}

/* OLD VERSION WITHOUT ARRAYS
int main() {
    int alumns = 0, age = 0, age_sum = 0, absents = 0;
    float averAGE;
    printf("Inserisci quanti alunni ci sono in questa classe: ");
    scanf("%d", &alumns);
    for(int i = 1; i <= alumns; i++) {
        printf("Inserisci l'eta' dell'alunno numero %d (o 0 se non e' presente): ", i);
        scanf("%d", &age);
        if (age == 0) absents++;
        age_sum += age; //gift for Calanzone (Was: averAGE += age; //waiting for division)
    }
    averAGE = age_sum / (alumns - absents);
    printf("\nLa classe calcolata ha %d alunni, di cui %d assenti.\nL'eta' media e': %.2f anni.", alumns, absents, averAGE);
    return 0;
}
*/