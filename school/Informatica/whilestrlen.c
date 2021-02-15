// PREPROCESSOR
#include <stdio.h>

// MAIN
int main() {
    /* dichiarazione stringa */
    int maxlenght = 50; 
    char str[maxlenght]; //Q. how to make it dynamic? (heap stuff?)
	
	/* inizializzazione stringa */
	printf("Inserisci una stringa di max %d caratteri: ", maxlenght);
	scanf("%s", str);
	
	/* calcolo lunghezza */
	int lenght = 0;
	while (str[lenght] != '\0') {
		lenght++;
	}
	
	/* output */
	printf("Hai inserito la stringa: %s", str);
	printf("\nLa stringa e' lunga %d caratteri.", lenght);
	
    /* end */
    return 0;
}
