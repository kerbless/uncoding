/*
Trying to understand better application memory, allocation etc.
*/

#include <stdio.h>
#include <stdlib.h>

//int global_int = 3; //this is allocated in the global memory, it not dynamic at all
void printf_variables();

int function(int x){
    x = x + 3; //the x LOCAL variable will be allocated in the STACK, when the funcion is called, under "function" block of allocation
    return x;
}

int main() {

    // _______IN C syntaxt_______
    int a = 0; //this goes on the stack, under "main" block of allocation
    int *p; //declared a pointer, the pointer value will be allocated on the stack, under "main" block of allocation
    p =  (int*)malloc(sizeof(int)); 
    /*
    this asks for an allocation in the heap in bytes, 
    it returns a pointer to the starting address of the allocated memory.
    So the int *p pointer now stores the address of the new memory, 
    the (int*) cast is needed because malloc returns a void pointer 
    (can't I just declare the pointer p void?)
    (no because we want to use the new memory as an integer, if *p is declared as void, we can't do *p = 33)
    */
    *p = 33;
    printf("performed operations: *p = 33;\n");
    printf("a value: %d\n", a);
    printf("a address: %d\n", &a);
    printf("p value: %d\n", *p);
    printf("p address: %d\n", &p);
    printf("________________\n");

    free(p);
    printf("performed operations: free(p);\n");
    printf("a value: %d\n", a);
    printf("a address: %d\n", &a);
    printf("p value: %d\n", *p);
    printf("p address: %d\n", &p);
    printf("________________\n");

    p =  (int*)malloc(sizeof(int)); //we are overwriting the heap address, before this you need to clear the old memory
    free(p);
    p =  (int*)malloc(5*sizeof(int)); // this allocates more memory, you can then use it like an array because p[0] = *p and p[1] = *(p+1)
    free(p);

    // _______IN C++ syntaxt_______
    int a2;
    int *p2;

    p2 = new int; //the new operator is type safe, not like the malloc func.
    *p2 = 10;
    delete p2;

    p2 = new int[20];
    delete[] p2; //note the square brackets
}