#include <iostream>
using namespace std;

long int powerx(long int num,long int power) {
	for (int i = 1; i < power; i++) {
		num = num*num;
		//cout << num << endl;
	}
	return num;
}

int main(int argc, char* argv[]) {
	long int power, num;

	cout << "\tCALCULATE POWER OF AN INTEGER";
	cout << "\nInsert the integer: ";
	cin >> num;
	cout << "Insert the power: ";
	cin >> power;
	
	if (power == 0) {
		if (num == 0) {return 1;}
		else {num = 1;}
	}
	else if (power < 0) {return 1;}
	else {
		num = powerx(num, power);
	}
	
	cout << "\nResult: " << num;
	return 0;
}
