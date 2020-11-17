#include <iostream>
using namespace std;

int ArrayMax(int *p, int arrayLenght) {
  /* using this implementation just because we needed an exercise with pointers */
  int maxval = *p;
  for(int i = 1; i < arrayLenght; i++) { //we start from one because the first value is "checked" initializing maxval to *p (so the start of the)
    if (maxval < *(p+i)) maxval = *(p+i);
  }
  return(maxval);
}

int ArrayMax(char *p, int arrayLenght) {
  cout << "PORCODDIO"; //this is not excecuted because *p passed to the funcion is NOT char
  char chr = 'c';
  *p = chr;
  return(arrayLenght);
}

/*Why sizeof(in_array) returns int*? cpp automatically takes in values as pointers in functions?
int ArrayMax_no_pointer(int in_array[]) {
  // this would be the simpler implementation
  int arrayLenght = (int(sizeof(in_array))/sizeof(in_array[0])); //divide size of the array for the size of one item = number of items
  int maxval = in_array[0]; //first element
  for(int i = 1; i < arrayLenght; i++) { //we start from one because the first value is "checked" initializing maxval to *p (so to the first value)
    if (maxval < in_array[i]) maxval = in_array[i]; //"one instruction" if instructions don't need brackets
  }
  return(maxval);
}
*/
s
int main() {
  int myArray[] {5, 8, 98, 77};
  int *p = myArray; // same as int*p = myArray[0] NOT the same as int var = myArray[0]
  int arrayLenght = (sizeof(myArray)/sizeof(myArray[0])); //divide size of the array for the size of one item = number of items
  cout << ArrayMax(p, arrayLenght);
  cout << ArrayMax_no_pointer(myArray);
  return 0;
}
