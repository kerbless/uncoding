#include <stdio.h>

unsigned long factorial(unsigned long n) {
	if (n != 0) return n * factorial(n - 1);
	else return 1;
}

int main() {
	unsigned long num;
	do {
		printf("Inserisci un numero naturale minore di 34: ");
		scanf("%lu", &num);
		if (num < 0 || num > 33) printf("Il numero non e' compreso tra 0 e 34!\n");
	} while (num < 0 || num > 33);
	printf("Il fattoriale di %lu e' %lu\n", num, factorial(num));
	return 0;
}
