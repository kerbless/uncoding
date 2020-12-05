#include <stdio.h>
#include <time.h>


int main() {
    srand(time(NULL));   // Evita che la sequenza sia uguale ogni volta che il programma viene avviato (initializer)
    int num = -1;     
    while (num =! 0) {
        num = rand() % 10;  // Genera un numero pseudo-randomico da 0 a 9 (https://stackoverflow.com/questions/822323/how-to-generate-a-random-int-in-c)
        printf("Num: %d", num);
    }
}