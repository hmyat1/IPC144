 /*
*****************************************************************************
                             Workshop - #2 (P1)
Full Name  : 
Student ID#: 
Email      : 
Section    : 
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#include<stdio.h>

int main(){

const double testValue = 330.99;

const int p1_ID = 111;
const int p2_ID = 222;
const int p3_ID = 333;

const double p1_price = 111.49;
const double p2_price = 222.99;
const double p3_price = 334.49;

const char p1_tax = 'Y';
const char p2_tax = 'N';
const char p3_tax = 'N';

double avarage_price = (p1_price + p2_price + p3_price) / 3;

    printf("Product Information\n");
    printf("===================\n");

    printf("Product-1 (ID:%d)\n", p1_ID);
    printf("Taxed: %c\n", p1_tax);
    printf("Price: $%.4lf\n\n", p1_price);


    printf("Product-2 (ID:%d)\n", p2_ID);
    printf("Taxed: %c\n", p2_tax);
    printf("Price: $%.4lf\n\n", p2_price);

    printf("Product-3 (ID:%d)\n", p3_ID);
    printf("Taxed: %c\n", p3_tax);
    printf("Price: $%.4lf\n\n", p3_price);

    printf("The avarage of all prices is: $%.4lf\n\n", avarage_price);


    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n\n");

    printf("Some Data Analysis...\n");
    printf("=====================\n");

    printf("1. Is product 1 taxable? -> %d\n\n", p1_tax =='Y');
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n", p1_tax && p2_tax != 'Y' );
    printf("3. Is product 3 less than testValue ($%lf)? -> %d\n\n" , testValue , p3_price < testValue);
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n" , p3_price > p1_price && p2_price );
    printf("5. Is the price of product 1 equal to or more than the price difference\n");
    printf("   of product 3 LESS product 2? -> %d (price difference: $%.2lf)\n\n" , p1_price >= p3_price - p2_price, p3_price - p2_price);
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n" , p2_price >= avarage_price );
    printf("7. Based on product ID, product 1 is unique -> %d\n\n", p1_ID == 222);
    printf("8. Based on product ID, product 2 is unique -> %d\n\n", p2_ID == 222);
    printf("9. Based on product ID, product 3 is unique -> %d\n\n", p3_ID == 111);
   
    return 0;

}

