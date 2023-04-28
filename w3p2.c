/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
Full Name  : Hla Myint Myat
Student ID#: 185923216
Email      : hmyat1@mysenecacollege.ca
Section    : NFF
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h> 

char type1,type2,type3;
int weight1,weight2,weight3;
char served1,served2,served3;

char c_strength1,c_strength2;
char c_cream1, c_cream2;
int daily_serving1, daily_serving2;

const double GRAMS_IN_LBS = 453.5924;


int main(void)
{
    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n");
    printf("\nEnter the coffee product information being sold today...\n");
    
    printf("\nCOFFEE-1...\n");
    
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c",&type1);
    
    printf("Bag weight (g): ");
    scanf("%d",&weight1);
    
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c",&served1);
    
     printf("\nCOFFEE-2...\n");
    
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c",&type2);
    
    printf("Bag weight (g): ");
    scanf("%d",&weight2);
    
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c",&served2);
    
    printf("\nCOFFEE-3...\n");
    
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c",&type3);
    
    printf("Bag weight (g): ");
    scanf("%d",&weight3);
    
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c",&served3);
    
    
    type1 = tolower(type1);
    type2 = tolower(type2);
    type3 = tolower(type3);
    
    served1 = tolower(served1);
    served2 = tolower(served2);
    served3 = tolower(served3);
    
        printf("\n");
        printf("---+------------------------+---------------+-------+\n");
        printf("   |    Coffee              |   Packaged    | Best  |\n");
        printf("   |     Type               |  Bag Weight   | Served|\n");
        printf("   +------------------------+---------------+ With  |\n");
        printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
        printf("---+------------------------+---------------+-------|\n");
        printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", type1 == 'l' || type1 == 'L',type1 == 'm' || type1 == 'M' , type1 == 'r' || type1 == 'R',weight1,weight1/GRAMS_IN_LBS,served1 == 'y' || served1 == 'Y');
        printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", type2 == 'l' || type2 == 'L',type2 == 'm' || type2 == 'M' , type2 == 'r' || type2 == 'R',weight2,weight2/GRAMS_IN_LBS,served2 == 'y' || served2 == 'Y');
        printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", type3 == 'l' || type3 == 'L',type3 == 'm' || type3 == 'M' , type3 == 'r' || type3 == 'R',weight3,weight3/GRAMS_IN_LBS,served3 == 'y' || served3 == 'Y');
                                                     

  printf("\nEnter how you like your coffee...\n\n");

  printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
  scanf(" %c", &c_strength1);

  printf("Do you like your coffee with cream ([Y]es,[N]o): ");
  scanf(" %c", &c_cream1);

  printf("Typical number of daily servings: ");
  scanf("%d", &daily_serving1);

  printf("\nThe below table shows how your preferences align to the available products:\n\n");
    
    c_strength1 = tolower(c_strength1);
    c_cream1 = tolower(c_cream1);

    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", c_strength1==type1, c_strength1= =type1 && c_cream1==served1 ,c_cream1==served1);
    printf(" 2|       %d         |      %d      |   %d   |\n", c_strength1==type2, c_strength1==type2 && c_cream1==served2 ,c_cream1==served2);
    printf(" 3|       %d         |      %d      |   %d   |\n", c_strength1==type3, c_strength1==type3 && c_cream1==served3 ,c_cream1==served3);

  printf("\nEnter how you like your coffee...\n\n");

  printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
  scanf(" %c", &c_strength2);

  printf("Do you like your coffee with cream ([Y]es,[N]o): ");
  scanf(" %c", &c_cream2);

  printf("Typical number of daily servings: ");
  scanf("%d", &daily_serving2);

  printf("\nThe below table shows how your preferences align to the available products:\n\n");
    
    c_strength2 = tolower(c_strength2);
    c_cream2 = tolower(c_cream2);
    
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", c_strength2==type1, c_strength2==type1 && c_cream2==served1 ,c_cream2==served1);
    printf(" 2|       %d         |      %d      |   %d   |\n", c_strength2==type2, c_strength2==type2 && c_cream2==served2 ,c_cream2==served2);
    printf(" 3|       %d         |      %d      |   %d   |\n", c_strength2==type3, c_strength2==type3 && c_cream2==served3 ,c_cream2==served3);
      


  printf("\nHope you found a product that suits your likes!\n");

    return 0;
}


/*
Provided formatting parts for printf statements:
As described in step-7
======================
printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
As described in step-10
=======================
printf(" 1|       %d         |      %d      |   %d   |\n",
*/
