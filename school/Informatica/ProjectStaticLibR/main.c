#include <stdio.h>
#include <math.h>

/* User defined libs */
#include <deltalib.h> // <> are used to fetch default compiler folders ("C:\Program Files (x86)\Dev-Cpp\MinGW64\x86_64-w64-mingw32\include")
//#include "deltalib.h" // "" are used to fetch workspace folder (./) 
//https://stackoverflow.com/questions/21593/what-is-the-difference-between-include-filename-and-include-filename

//main
int main() {
	//variables
	double a,b,c,x1,x2,delta;
	
	//instructions
	printf("\tSOLVE A SECOND GRADE EQUATION");
	printf("\nPlease insert a,b,c like in (ax^2+bx+c=0)");
	printf("\nInsert a: ");
	scanf("%lf", &a);
	printf("Insert b: ");
	scanf("%lf", &b);
	printf("Insert c: ");
	scanf("%lf", &c);
	delta = calc_delta(a,b,c);
	printf("\nDelta is: %.3lf", delta); //.3 is the decimal approx.
	if(delta >= 0) {
		if(delta > 0) {
			x1 = (-b+sqrt(delta))/(2*a);
			x2 = (-b-sqrt(delta))/(2*a);	
		}
		else {
			x1 = 0;
			x2 = -b/(2*a);
		}
	printf("\nSolutions are, x1 = %.3lf and x2 = %.3lf", x1, x2);	
	}
	else { printf("\nThere are no real solutions.");}
}
