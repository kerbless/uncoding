#include <stdio.h>

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