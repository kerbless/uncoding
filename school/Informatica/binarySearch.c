// TESTING STUFF - CODE NOT FINISHED

#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
	int middle = size/2;
	int pick = middle;
	int picked;
	do {
		picked = arr[pick];
		if (picked > target) pick /= 2;
		else pick = pick/2+middle;
	} while (picked != target);
	return picked;
}

int main() {
	int i, arr[10] = {0,1,2,3,4,5,6,7,8,9}; // init arr
	int size = (sizeof(arr) / sizeof(arr[0])); // arr size
	printf("|"); for (i = 0; i < size; i++) printf("%d|", arr[i]); //print arr
	int target = 7; // number to find	
	printf(binarySearch(arr, size, target));

	return 0;
}
	
	
