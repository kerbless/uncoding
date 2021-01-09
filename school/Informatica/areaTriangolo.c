#include <stdio.h>

float areaTriangolo(float, float);

int main(int argc, char *argv[]) {
    float area, base, altezza;
    /* base = 10;
    altezza = 2.5;*/
    printf("inserisci la base del triangolo: ");
    scanf("%f", &base);
    printf("inserisci il altezza del triangolo: ");
    scanf("%f", &altezza);
    area = areaTriangolo(base, altezza);
    printf("l'area del triangolo e': %f", area);
    return 0;
}

float areaTriangolo(float b, float h) {
    /* prende la base (b) e l'altezza (h) di un triangolo (float) e restituisce l'area (float) */
    float a = b * h / 2;
    printf("funzione \"areaTriangolo\" a lavoro...");
    return a;
}