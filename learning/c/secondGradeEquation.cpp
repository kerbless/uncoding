#include <iostream>
#include <math.h>
using namespace std;

//main
int main() {
	//variables
	double a,b,c,x1,x2,delta;

	//functions
	
	//instructions
	cout << "\tSOLVE A SECOND GRADE EQUATION";
	cout << "\nPlease insert a,b,c like in (ax^2+bx+c=0)";
	cout << "\nInsert a: ";
	cin >> a;
	cout << "\nInsert b: ";
	cin >> b;
	cout << "\nInsert c: ";
	cin >> c;
	delta = b*b-4*a*c;
	cout << "\nDelta is: " << delta;
		
}
