// PREPROCESSOR
#include <stdio.h>
#include <string.h>

// MAIN
int main() {
    /* dichiarazione stringa */
    int maxlenght = 50; 
    char str[maxlenght], str2[maxlenght]; //Q. how to make it dynamic? (heap stuff?)
	
	/* inizializzazione stringa */
	printf("Inserisci una stringa di max %d caratteri: ", maxlenght);
	scanf("%s", &str);
	printf("Inserisci un'altra stringa di max %d caratteri: ", maxlenght);
	scanf("%s", &str2);
	
	/* calcolo lunghezza */
	int lenght = 0, lenght2 = 0;
	while (str[lenght] != '\0') {
		lenght++;
	}
	while (str2[lenght2] != '\0') {
		lenght2++;
	}
	
	/* controllo con funzione di string.h a fini didattici */
	if(lenght != strlen(str) || lenght2 != strlen(str2)) {
		return 100;
	}
	
	/* output */
	printf("\nHai inserito le stringhe: '%s' e '%s'.", str, str2);
	printf("\nLunghe rispettivamente %d e %d caratteri.", lenght, lenght2);
	printf("\nLe stringhe sono ");
	if (strcmp(str, str2) == 0) {
		printf("uguali.");
	}
	else {
		printf("diverse.");
	}
	
    /* end */
    return 0;
}

