/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
Full Name  : Hla Myint Myat
Student ID#: 185923216
Email      : hmyat1@myseneca.ca
Section    : NRB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;
    int p1_ID = 111, p2_ID = 222 , p3_ID = 111;   //product_ID
    char p1_tax = 'Y', p2_tax = 'N', p3_tax = 'N';  //product_tax
    float p1_price = 111.49 , p2_price =222.99 , p3_price =334.49;  // product_price


printf("Product Information\n");
printf("===================\n");

printf("Product-1 (ID:%d)\n", p1_ID);
printf("  Taxed: %c\n", p1_tax);
printf("  Price: $%.4f\n", p1_price);
printf("\n");

printf("Product-2 (ID:%d)\n", p2_ID);
printf("  Taxed: %c\n", p2_tax);
printf("  Price: $%.4f\n", p2_price);
printf("\n");

printf("Product-3 (ID:%d)\n", p3_ID);
printf("  Taxed: %c\n", p3_tax);
printf("  Price: $%.4f\n", p3_price);
printf("\n");

 float average = (p1_price + p2_price + p3_price)/3;  // calculation for average
printf("The average of all prices is: $%.4f\n" , average);
printf("\n");

printf("About Relational and Logical Expressions!\n");
printf("========================================\n");
printf("1. These expressions evaluate to TRUE or FALSE\n");
printf("2. FALSE: is always represented by integer value 0\n");
printf("3. TRUE : is represented by any integer value other than 0\n");
printf("\n");


printf("Some Data Analysis...\n");
printf("=====================\n");
printf("1. Is product 1 taxable? -> %d\n\n", p1_tax == 'Y');

printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n", p2_tax =='N' && p3_tax == 'N');

printf("3. Is product 3 less than testValue ($330.99)? -> %d\n\n" , p3_price < testValue);

printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", p3_price > p1_price && p3_price > p2_price);

printf("5. Is the price of product 1 equal to or more than the price difference\n");
printf("   of product 3 LESS product 2? ->  %d (price difference: $%.2f)\n\n", p1_price >= (p3_price - p2_price), (p3_price - p2_price) );

printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n" , p2_price >= average);

printf("7. Based on product ID, product 1 is unique -> %d\n\n", p1_ID != p2_ID && p1_ID != p3_ID);

printf("8. Based on product ID, product 2 is unique -> %d\n\n", p2_ID != p1_ID && p2_ID != p3_ID);

printf("9. Based on product ID, product 3 is unique -> %d\n\n", p3_ID != p1_ID && p3_ID != p2_ID);

    return 0;
}




    
