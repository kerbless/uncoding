/*______________________________________________*/
/*___________ Burroni Blu - III BIA ____________*/
/*________________ 29/03/2021 __________________*/
/*______________________________________________*/

// PREPROCESSOR
#include <stdio.h>

// MAIN
int main() {
	FILE *fp = fopen("numberlist.txt", "r"); // open file to read
	if(fp == NULL) {printf("Error!"); return(1);}; // file not opened sucessfully
	int i, j, tmp, iterations = 0, swaps = 0, size = 1000; // declare iterators and tmp variable, initialize counters and vector size with the number of lines in the file
	int worstIterations = size*size; // calculate worst complexity iterations with vector size
	int worstSwaps = size*size; // calculate worst complexity swaps with vector size
	int vect[size]; // initialize vector
	for(i = 0; i <= size; i++) fscanf(fp,"%d", &vect[i]); // read lines from file into vector
	fclose(fp); // close file
	/* BUBBLE SORT */
	for(i = 0; i < size-1; i++) { // iterates as many times as the lenght of vector - one, because the last time you would iterate 1 item only
		for(j = 0; j < size-i-1; j++) { // iterates trough the unordered vector (vector - all the times you made a "pass" - last item)
			if(vect[j] > vect[j+1]) { // swap items if the next item is smaller, bringing the biggest number to the end of the array
				tmp = vect[j];
				vect[j] = vect[j+1];
				vect[j+1] = tmp;
				swaps++;
			}
			iterations++;
		}	
	}
	printf("Bubble sorted: "); for (i = 0; i < size; i++) printf("\n%-4d", vect[i]); // print result
	printf("\n%-30s%d\n%-30s%d\n%-30s%d\n%-30s%d", "Worst possible iterations: ", worstIterations, "Actual iterations: ", iterations, "Worst possible swaps: ", worstSwaps, "Actual swaps: ", swaps); // print result
	return 0; // exit
}

/* To explain the inner for "-1-i":
Consider this vector (x are already ordered items):
size = 6; i = 3; j = 0
vector = {3, 2, 1, x, x, x};
If you proceed you have:
size = 6; i = 3; j = 1
vector = {2, 3, 1, x, x, x};
You don't need to test the Xs that are already ordered, so the -i is explained.
size = 6; i = 3; j = 2
vector = {2, 1, 3, x, x, x};
Now, you don't need to test 1 and 3, so the -1 is explained.
*/

/* To explain the outer for "-1":
If you consider the previous example, when you reach the last items:
size = 6; i = 4; j = 0
vector = {2, 1, x, x, x, x};
...
size = 6; i = 4; j = 1
vector = {1, 2, x, x, x, x};
Here the vector is ordered, so the last iteration with i = "5" is not useful, so the -1 is explained.
*/