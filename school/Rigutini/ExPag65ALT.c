//Includes
#include <stdio.h>

//Constants
const float PriceBN = 0.10, 
PriceC = 0.70, 
PriceR = 1.30;

//Variables
int BNPhotos = 0, 
CPhotos = 0, 
TotPhotos = 0;

float BNCost = 0, 
CCost = 0, 
TotCost = 0;

//___MAIN___
int main() { //skipping arguments
    printf("\nPlease insert how many photocopies you want (int): "); scanf("%d", &TotPhotos);
    printf("Please insert how many of them you want colored (int): "); scanf("%d", &CPhotos);
    BNPhotos = TotPhotos - CPhotos;
    BNCost = TotPhotos * PriceBN; //REMEMEBR! Multipling an int and a float returns a float, passing it to printf makes it a double: https://stackoverflow.com/questions/17057679/how-to-multiply-float-with-integers-in-c
    CCost = CPhotos * PriceC;
    TotCost = CCost + BNCost + PriceR;
    printf("\nTotPhotos: %d", TotPhotos);
    printf("\nBNCost: %.2f", BNCost); //the double thing (see line 23)
    printf("\nCCost: %.2f", CCost);
    printf("\nTotCost: %.2f", TotCost);
    return 0;
}