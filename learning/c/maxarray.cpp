#include <iostream>
using namespace std;

int ArrayMax(int *p, int arrayLenght) {
  int maxval = *p;
  for(int i = 1; i < arrayLenght; i++) {
    if (maxval < *(p+i)) maxval = *(p+i);
  }
  return(maxval);
}

int ArrayMax(char *p, int arrayLenght) {
  cout << "PORCODDIO"; //this is not excecuted because *p passed to the funcion is NOT char
}

int main() {
  int myArray[] {5, 8, 98, 77};
  int *p = myArray; // same as int*p = myArray[0]
  int arrayLenght = (sizeof(myArray)/sizeof(myArray[0]));
  cout << ArrayMax(p, arrayLenght);
  return 0;
}
