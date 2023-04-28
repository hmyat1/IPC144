/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
Full Name  : Hla Myint Myat
Student ID#: 185923216
Email      : hmyat12myseneca.ca
Section    : NFF
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    //const double testValue = 330.99;

    int pdt1ID =111;
    int pdt2ID =222; 
    int pdt3ID =111;

    float priceP1 =111.49;
    float priceP2 =222.99;
    float priceP3 =334.49;

    char taxP1 = 'Y';
    char taxP2 = 'N';
    char taxP3 = 'N';

    float avePrice;
    avePrice=(priceP1+priceP2+priceP3)/3;

    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n",pdt1ID);

    printf("  Taxed: %c\n",taxP1);

    printf("  Price: $%.4f\n\n",priceP1);
    
    printf("Product-2 (ID:%d)\n",pdt2ID);

    printf("  Taxed: %c\n",taxP2);

    printf("  Price: $%.4f\n\n",priceP2);
   
    printf("Product-3 (ID:%d)\n",pdt3ID);

    printf("  Taxed: %c\n",taxP3);

    printf("  Price: $%.4f\n\n",priceP3);
    
    printf("The average of all prices is: $%.4f\n\n" ,avePrice);
    
    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n\n");
    printf("Some Data Analysis...\n");
    printf("=====================\n");

    printf("1. Is product 1 taxable? -> %d\n\n", taxP1=='Y');
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n", taxP2=='N'&& taxP3=='N');
    printf("3. Is product 3 less than testValue ($330.99)? -> %d\n\n", priceP3<330.99);
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", priceP3>priceP1 && priceP3>priceP2);
    printf("5. Is the price of product 1 equal to or more than the price difference\n   of product 3 LESS product 2? ->  %d (price difference: $%.2f)\n\n", priceP1 >= (priceP3-priceP2),(priceP3-priceP2));
   
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n", priceP2>=avePrice);
    printf("7. Based on product ID, product 1 is unique -> %d\n\n",pdt1ID != pdt2ID && pdt1ID!=pdt3ID);
    printf("8. Based on product ID, product 2 is unique -> %d\n\n",pdt2ID != pdt1ID && pdt2ID!=pdt3ID);
    printf("9. Based on product ID, product 3 is unique -> %d\n\n",pdt3ID != pdt1ID && pdt3ID!=pdt2ID);

    return 0;
}