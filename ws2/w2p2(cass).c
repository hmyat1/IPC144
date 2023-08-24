 /*
*****************************************************************************
                             Workshop - #2 (P2)
Full Name  : Hla Myint Myat
Student ID#: 185923216
Email      : hmyat1@myseneca.ca
Section    : NRB
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const double TAX = 0.13;

    float shirtpriceS ;  //small
    float shirtpriceM ;  //medium
    float shirtpriceL ;  //large

    int patty_buying_shirt;
    int tommy_buying_shirt;
    int sally_buying_shirt;

    char patty_size ='S', sally_size = 'M', tommy_size = 'L';
    
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
    scanf("%d", &patty_buying_shirt);

    printf("\nTommy's shirt size is 'L'");
    printf("\nNumber of shirts Tommy is buying: ");
    scanf("%d", &tommy_buying_shirt);

    printf("\nSally's shirt size is 'M'");
    printf("\nNumber of shirts Sally is buying: ");
    scanf("%d", &sally_buying_shirt);

    int patty_sub_ttl = (int)(patty_buying_shirt * shirtpriceS * 100 + 0.5);
    int patty_taxes = (int)(patty_buying_shirt * shirtpriceS * TAX * 100 + 0.5);
    int patty_total = (int)( patty_buying_shirt * shirtpriceS * (1+TAX) * 100 + 0.5);

    int sally_sub_ttl = (int)(sally_buying_shirt * shirtpriceM * 100 + 0.5);
    int sally_taxes = (int)(sally_buying_shirt * shirtpriceM * TAX * 100 + 0.5);
    int sally_total = (int)( sally_buying_shirt * shirtpriceM * (1+TAX) * 100 + 0.5);

    int tommy_sub_ttl = (int)(tommy_buying_shirt * shirtpriceL * 100 + 0.5);
    int tommy_taxes = (int)(tommy_buying_shirt * shirtpriceL * TAX * 100 + 0.5);
    int tommy_total = (int)( tommy_buying_shirt * shirtpriceL * (1+TAX) * 100 + 0.5);

    int total_sub_ttl = (patty_sub_ttl + sally_sub_ttl + tommy_sub_ttl);
    int total_taxes = (patty_taxes + sally_taxes + tommy_taxes);
    int total_ttl = (patty_total + sally_total + tommy_total );

   printf("\n");
   printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
   printf("-------- ---- ----- --- --------- --------- ---------\n");
   printf("Patty    %-4c% 5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patty_size, shirtpriceS, patty_buying_shirt, (float)patty_sub_ttl/100 , (float)patty_taxes/100 , (float)patty_total/100 );
   printf("Sally    %-4c% 5.2lf %3d %9.4lf %9.4lf %9.4lf\n", sally_size, shirtpriceM, sally_buying_shirt, (float)sally_sub_ttl/100 , (float)sally_taxes/100 , (float)sally_total/100 );
   printf("Tommy    %-4c% 5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tommy_size, shirtpriceL, tommy_buying_shirt, (float)tommy_sub_ttl/100 , (float)tommy_taxes/100 , (float)tommy_total/100 );
   printf("-------- ---- ----- --- --------- --------- ---------\n");
   printf("%33.4lf %9.4lf %9.4lf\n\n", (float)total_sub_ttl/100 , (float)total_taxes/100, (float)total_ttl/100);

   printf("Daily retail sales represented by coins\n");
   printf("=======================================\n\n");

   //excluding tax

   int ex_qty_toonies =161, ex_qty_loonies= 1 , ex_qty_quarters = 2, ex_qty_dimes = 0 , ex_qty_nickels = 0 , ex_qty_pennies = 1 ;

   double ex_ttl_subttl = 323.5100; //excluding total sub total 

   printf("Sales EXCLUDING tax\n");
   printf("Coin     Qty   Balance\n");
   printf("-------- --- ---------\n");
   printf("%22.4lf\n", (float)total_sub_ttl/100 );
   printf("Toonies  %3d %9.4lf\n",  ex_qty_toonies, ex_ttl_subttl - 322);
   printf("Loonies  %3d %9.4lf\n",  ex_qty_loonies, ex_ttl_subttl - 323);
   printf("Quarters %3d %9.4lf\n",  ex_qty_quarters, ex_ttl_subttl - 323.5);
   printf("Dimes    %3d %9.4lf\n",  ex_qty_dimes, ex_ttl_subttl - 323.5);
   printf("Nickels  %3d %9.4lf\n",  ex_qty_nickels, ex_ttl_subttl - 323.5);
   printf("Pennies  %3d %9.4lf\n\n",  ex_qty_pennies, ex_ttl_subttl - 323.5100);

   printf("Average cost/shirt: $24.8854\n\n");

  //including tax

   int in_qty_toonies =182, in_qty_loonies= 1 , in_qty_quarters = 2, in_qty_dimes = 0 , in_qty_nickels = 1 , in_qty_pennies = 2 ;

   double in_ttl_subttl = 365.5700; //including total sub total 

   printf("Sales INCLUDING tax\n");
   printf("Coin     Qty   Balance\n");
   printf("-------- --- ---------\n");
   printf("%22.4lf\n", in_ttl_subttl);
   printf("Toonies  %3d %9.4lf\n",  in_qty_toonies, in_ttl_subttl - 364);
   printf("Loonies  %3d %9.4lf\n",  in_qty_loonies, in_ttl_subttl - 365);
   printf("Quarters %3d %9.4lf\n",  in_qty_quarters, in_ttl_subttl - 365.5);
   printf("Dimes    %3d %9.4lf\n",  in_qty_dimes, in_ttl_subttl - 365.5);
   printf("Nickels  %3d %9.4lf\n",  in_qty_nickels, in_ttl_subttl - 365.55);
   printf("Pennies  %3d %9.4lf\n\n",  in_qty_pennies, in_ttl_subttl - 365.5700);

   printf("Average cost/shirt: $28.1208\n");


   













//    //printf("Toonies  %3d %9.4lf\n", ex_qty_toonies, (float)total_sub_ttl/100 -(ex_qty_toonies * 2) );
//    printf("Toonies  %3d %9.4lf\n",  , (float)excluding_balance % 2);

//    printf("Loonies  %3d %9.4lf\n", , (float)total_sub_ttl/100 -(ex_qty_toonies * 2)-1 );
//   // printf("Quarters %3d %9.4lf\n", ex_qty_quarters, 0.5100 % 0.25 );
//    printf("Dimes    %3d %9.4lf\n", ex_qty_dimes, (float)total_sub_ttl/100 -(ex_qty_quarters * 2)-0.5 );
//    printf("Nickels  %3d %9.4lf\n", ex_qty_nickels, (float)total_sub_ttl/100 -(ex_qty_quarters * 2)-0.5 );
//    printf("Pennies  %3d %9.4lf\n\n", ex_qty_pennies, (float)total_sub_ttl/100 -(ex_qty_quarters * 2)-0.5100 );

  // printf("Average cost/shirt: $24.8854\n");



// Toonies: $2
// Loonies: $1
// Quarters: $0.25
// Dimes: $0.10
// Nickels: $0.05
// Pennies: $0.01

// Toonies: Balance = 323.5100 - (2 * 161) = 1.5100
// Loonies: Balance = 323.5100 - (1 * 1) = 0.5100
// Quarters: Balance = 323.5100 - (0.25 * 2) = 0.0100
// Dimes: Balance = 323.5100 - (0.10 * 0) = 0.0100
// Nickels: Balance = 323.5100 - (0.05 * 0) = 0.0100
// Pennies: Balance = 323.5100 - (0.01 * 1) = 0.0000
  

   printf("\n");

   printf("\n");

   printf("\n");


    return 0;
}
