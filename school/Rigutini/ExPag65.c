//Includes
#include <stdio.h>

//Constants
const float PriceBN = 0.10,
PriceC = 0.80,
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
    printf("\nPlease insert how many BLACK AND WHITE photocopies you want (int): "); scanf("%d", &BNPhotos);
    printf("Please insert how many COLORED photocopies you want (int): "); scanf("%d", &CPhotos);
    TotPhotos = BNPhotos + CPhotos;
    BNCost = BNPhotos * PriceBN;
    CCost = CPhotos * PriceC;
    TotCost = CCost + BNCost + PriceR;
    printf("\nTotPhotos: %d", TotPhotos);
    printf("\nBNCost: %.2f", BNCost);
    printf("\nCCost: %.2f", CCost);
    printf("\nTotCost: %.2f", TotCost);
    return 0;
}
