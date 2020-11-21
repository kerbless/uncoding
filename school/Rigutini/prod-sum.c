#include <stdio.h>

int main() {
    float oper1, oper2, somma, prodotto;
    printf("inserisci il primo operando della somma/moltiplicazione: "); scanf("%f", &oper1);
    printf("inserisci il secondo operando della somma/moltiplicazione: "); scanf("%f", &oper2);
    somma = oper1 + oper2;
    prodotto = oper1 * oper2;
    printf("\nSomma di: %.3f", somma);
    printf("\nMoltiplicazione: %.3f", prodotto);
    return 0;
}