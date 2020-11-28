#include <stdio.h>

main() {
	float num1, num2, sum; //not initializing, waiting for some kind of input check
	printf("Inserisci due numeri separati da uno spazio e premi invio: "); 
	scanf("%f %f", &num1, &num2);
	sum = num1 + num2;
	printf("La sommma di %f e %f e': %f", num1, num2, sum);
	return 0;
}
