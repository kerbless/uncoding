#include <stdio.h>

void system(char * string); //Cross-platform alternative to system("pause");

void system(char * string) {
	if (string == "pause") {
		printf("Press a key to continue . . .");
 		//getchar();
		getchar();
	}
	else {
		printf("\n\nPress a key to continue . . .");
		//getchar();
		getchar();
	}
}
