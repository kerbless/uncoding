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
	cout << "Insert b: ";
	cin >> b;
	cout << "Insert c: ";
	cin >> c;
	delta = b*b-4*a*c;
	cout << "Delta is: " << delta;
	if(delta >= 0) {
		if(delta > 0) {
			x1 = (-b+sqrt(delta))/(2*a);
			x2 = (-b-sqrt(delta))/(2*a);	
		}
		else {
			x1 = 0;
			x2 = -b/(2*a);
		}
		cout << "\nSolutions are, x1 = " << x1 << " and x2 = " << x2;
	}
	else {cout << "There are no real solutions.";}
}
