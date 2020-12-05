#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));   // Inizializza rand con un seed (time(NULL))
    int num = rand() % 10; // Init variable with a pseudo-random number (0-9) for more: (https://stackoverflow.com/questions/822323/how-to-generate-a-random-int-in-c)
    while (num != 0) {
        num = rand() % 10;   
        printf("\nPre: %d", num);
    }
    do {
        num = rand() % 10;   
        printf("\nPost: %d", num);
    } while (num != 0);
}
