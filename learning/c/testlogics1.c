#include <stdio.h>
#include <stdbool.h>

int main() {
	bool a = false, b = false, c = false, d = false;
	for (bool i = false, i != true, i = a||b||c||d)
	if ((a&&b)||(c&&d) == true) printf("1");
			
	return 0;
	
}
