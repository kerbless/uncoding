#include <stdio.h>

int main() {
    float oper1, oper2;
    printf("inserisci il primo operando della somma/moltiplicazione: "); scanf("%f", &oper1);
    printf("inserisci il secondo operando della somma/moltiplicazione: "); scanf("%f", &oper2);
    printf("\nSomma: %.3f", oper1 + oper2);
    printf("\nMoltiplicazione: %.3f", oper1 * oper2);
    return 0;
}