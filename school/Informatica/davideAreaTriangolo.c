#include <stdio.h>


float AreaTriangolo(float bt, float ht){
	printf("\nAll'interno di AreaTriangolo()\n");
	printf("bt = %.3f\n", bt);
	printf("ht = %.3f\n", ht);
	float areat;
	printf("Area dichiarata\n");
	areat = bt * ht / 2;
	printf("Area calcolata: %.3f\n", areat);
	return areat;
	printf("Valore di ritorno di AreaTriangolo()\n\n"); // Dopo il return si interrompe la procedura
}


int main(void){
	float area, b, h;
	// b = 5;
	printf("Inserisci la base:\n> ");
	scanf("%f", &b);
	// h = 10;
printf("Inserisci l'altezza:\n> ");
	scanf("%f", &h);
	// area = b * h / 2;
  area = AreaTriangolo(b, h);
	printf("\nL'area del triangolo risulta uguale a %4.2f", area);
  return 0;
}