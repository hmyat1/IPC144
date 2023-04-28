/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
Full Name  : Hla Myint Myat
Student ID#: 185923216
Email      : hmyat1@myseneca.ca
Section    : NFF
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const double TAX = 0.13;

    float shirtpriceS ;
    float shirtpriceM ;
    float shirtpriceL ;
    int bS;
   

    printf("Set Shirt Prices\n");
    printf("================\n");

    printf("Enter the price for a SMALL shirt: $");
    scanf("%f", &shirtpriceS);

    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%f", &shirtpriceM);

    printf("Enter the price for a LARGE shirt: $");
    scanf("%f", &shirtpriceL);

    printf("\nShirt Store Price List\n");
    printf("======================\n");

    printf("SMALL  : $%5.2f\n",  shirtpriceS);
    printf("MEDIUM : $%5.2f\n",  shirtpriceM);
    printf("LARGE  : $%5.2f\n", shirtpriceL);

    printf("\nPatty's shirt size is 'S'");
    printf("\nNumber of shirts Patty is buying: ");
    scanf("%d", &bS);

    printf("\nPatty's shopping cart...\n");
    printf("Contains : %d shirts", bS);
    int rSb =(int)(shirtpriceS * bS * 100 + 0.5);
    int rTx =(int)(shirtpriceS * bS * TAX * 100 + 0.5);
    int rTl =(int)(shirtpriceS * bS * (1+TAX) * 100 + 0.5);

    printf("\nSub-total: $%8.4f", (float)rSb / 100);
    printf("\nTaxes    : $%8.4f", (float)rTx / 100);
    printf("\nTotal    : $%8.4f\n",(float)rTl /100);

    return 0;
}
