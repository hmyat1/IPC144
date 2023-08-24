/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
Full Name  : HLa Myint Myat 
Student ID#: 185923216
Email      : hmyat1@myseneca.ca
Section    : NRB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
    char coffee_type_1, coffee_type_2, coffee_type_3 ; //type of coffees
    int bag_weight_1, bag_weight_2,bag_weight_3; //weight of the coffee
    char best_cream_1, best_cream_2, best_cream_3; // best served with cream

printf("Take a Break - Coffee Shop\n");
printf("==========================\n\n");

printf("Enter the coffee product information being sold today...\n\n");

printf("COFFEE-1...\n");
printf("Type ([L]ight,[M]edium,[R]ich): ");
scanf("%c" , &coffee_type_1 );
printf("Bag weight (g): ");
scanf("%d", &bag_weight_1);
printf("Best served with cream ([Y]es,[N]o): ");
scanf(" %c" , &best_cream_1);
printf("\n");

printf("COFFEE-2...\n");
printf("Type ([L]ight,[M]edium,[R]ich): ");
scanf(" %c" , &coffee_type_2 );
printf("Bag weight (g): ");
scanf("%d", &bag_weight_2);
printf("Best served with cream ([Y]es,[N]o): ");
scanf(" %c" , &best_cream_2);
printf("\n");

printf("COFFEE-3...\n");
printf("Type ([L]ight,[M]edium,[R]ich): ");
scanf(" %c" , &coffee_type_3 );
printf("Bag weight (g): ");
scanf("%d", &bag_weight_3);
printf("Best served with cream ([Y]es,[N]o): ");
scanf(" %c" , &best_cream_3);
printf("\n");

printf("---+------------------------+---------------+-------+\n");
printf("   |    Coffee              |   Packaged    | Best  |\n");
printf("   |     Type               |  Bag Weight   | Served|\n");
printf("   +------------------------+---------------+ With  |\n");
printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
printf("---+------------------------+---------------+-------|\n");
printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", coffee_type_1 == 'l' || coffee_type_1 == 'L' , coffee_type_1 == 'm'|| coffee_type_1 == 'M' , coffee_type_1 == 'r' || coffee_type_1 =='R' , bag_weight_1 , bag_weight_1/GRAMS_IN_LBS , best_cream_1 =='y' || best_cream_1 == 'Y');
printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", coffee_type_2 == 'l' || coffee_type_2 == 'L' , coffee_type_2 == 'm'|| coffee_type_2 == 'M' , coffee_type_2 == 'r' || coffee_type_2 =='R' , bag_weight_2 , bag_weight_2/GRAMS_IN_LBS , best_cream_2 =='y' || best_cream_2 == 'Y');
printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", coffee_type_3 == 'l' || coffee_type_3 == 'L' , coffee_type_3 == 'm'|| coffee_type_3 == 'M' , coffee_type_3 == 'r' || coffee_type_3 =='R' , bag_weight_3 , bag_weight_3/GRAMS_IN_LBS , best_cream_3 =='y' || best_cream_3 == 'Y');
printf("\n");

printf("Enter how you like your coffee...\n");
printf("\n");

char coffee_strength_1; // strength of the coffee (Large,Medium,Rich)
char cream_1; // coffee with cream (yes or no)
int daily_servings_1; // (Typical number of daily servings)

printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
scanf(" %c", &coffee_strength_1);
printf("Do you like your coffee with cream ([Y]es,[N]o): ");
scanf(" %c", &cream_1);
printf("Typical number of daily servings: ");
scanf("%d", &daily_servings_1);
printf("\n");

printf("The below table shows how your preferences align to the available products:\n\n");

printf("--------------------+-------------+-------+\n");
printf("  |     Coffee      |  Packaged   | With  |\n");
printf("ID|      Type       | Bag Weight  | Cream |\n");
printf("--+-----------------+-------------+-------+\n");
printf(" 1|       %d         |      %d      |   %d   |\n", coffee_strength_1== 'L', coffee_strength_1== 'L' ,cream_1==best_cream_1);
printf(" 2|       %d         |      %d      |   %d   |\n", coffee_strength_1==coffee_type_2, coffee_strength_1==coffee_type_2 && cream_1==best_cream_2 ,cream_1==best_cream_2);
printf(" 3|       %d         |      %d      |   %d   |\n", coffee_strength_1==coffee_type_3, coffee_strength_1==coffee_type_3 && cream_1==best_cream_3 ,cream_1==best_cream_3);
printf("\n");

printf("Enter how you like your coffee...\n\n");    

char coffee_strength_2; // strength of the coffee (Large,Medium,Rich)
char cream_2; // coffee with cream (yes or no)
int daily_servings_2; // (Typical number of daily servings)

printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
scanf(" %c", &coffee_strength_2);
printf("Do you like your coffee with cream ([Y]es,[N]o): ");
scanf(" %c", &cream_2);
printf("Typical number of daily servings: ");
scanf("%d", &daily_servings_2);
printf("\n");

printf("The below table shows how your preferences align to the available products:\n\n");

printf("--------------------+-------------+-------+\n");
printf("  |     Coffee      |  Packaged   | With  |\n");
printf("ID|      Type       | Bag Weight  | Cream |\n");
printf("--+-----------------+-------------+-------+\n");
printf(" 1|       %d         |      %d      |   %d   |\n", coffee_strength_2==coffee_type_1, coffee_strength_2==coffee_type_1 && cream_2==best_cream_1 ,cream_2==best_cream_1);
printf(" 2|       %d         |      %d      |   %d   |\n", coffee_strength_2==coffee_type_2, coffee_strength_2==coffee_type_2 && cream_2==best_cream_2 ,coffee_strength_2== 'M');
printf(" 3|       %d         |      %d      |   %d   |\n", coffee_strength_2== 'M', coffee_strength_2== 'M'  ,cream_2==best_cream_3);
printf("\n");

printf("Hope you found a product that suits your likes!\n");

    return 0;
}
