//Libs
#include <stdio.h>

//Main
int main(int argc, char* argv[]){
	//Vars
	float i_price = 0.0, total = 0.0, i_quantity = 0;
        int base_discount = 5, upgraded_discount = 10, finished = 0;

	while(0 == 0){ //infinite, will wait for finished = 1 to break (like a do-while)
		printf("\n\tADD PRODUCTS TO CART\nInstert product price: ");
		scanf("%f", &i_price);
		printf("Insert product quantity: ");
		scanf("%f", &i_quantity);
		total += i_price * i_quantity;
		printf("Insert 0 to continue or 1 to calculate total: ");
		scanf("%d", &finished);
	if(finished == 1){break;} //exit when finished = 1
	}

	printf("Total: %.3f", total);
	if(total >= 20){total = total-total/100*upgraded_discount;} //apply upgraded discount
	else{total = total-total/100*base_discount;} //apply base discount
	printf("\nTotal + discount: %.3f", total);
}
