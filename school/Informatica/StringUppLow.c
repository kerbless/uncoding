// PREPROCESSOR
#include <stdio.h>
#include <string.h>

// MAIN
int main() {
	/* string initialization */
	int maxlenght; 
	printf("Inserisci il numero di caratteri da salvare: "); scanf("%d", &maxlenght);
	char str[maxlenght];
	printf("Inserisci i (%d) caratteri da salvare: ", maxlenght); scanf("%s", &str);
	printf("\nHai inserito: %s", str);
	
	/* string alteration */
	int i;
	for (i = 0; i < maxlenght; i++) {
		if (i % 2 == 0) {
			str[i] = toupper(str[i]);
		}
		else {
			str[i] = tolower(str[i]);
		}
	}
	
	/* output */
	printf("\nE' diventata: %s", str);
	
	/* end */
    return 0;
}
