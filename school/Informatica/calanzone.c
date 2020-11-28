#include <stdio.h>

int main() {
    float importo, iva, qt, prezzo, p_iva, p_vendita;
    printf("inserisci la quantita': "); scanf("%f", &qt);
    printf("inserisci il prezzo: "); scanf("%f", &prezzo);
    printf("inserisci l'iva in percentuale: "); scanf("%f", &p_iva);
    importo = qt * prezzo;
    iva = importo * p_iva / 100;
    p_vendita = importo + iva;
    printf("\nImporto senza iva: %.2f", importo);
    printf("\nIva: %.2f", iva);
    printf("\nImporto con iva: %.2f", p_vendita);
    return 0;
}