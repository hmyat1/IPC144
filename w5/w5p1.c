/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)
Full Name  : Hla Myint Myat
Student ID#: 185923216
Email      : hmyt1@myseneca.ca
Section    : NRB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS  //preprocessor to suppress warnings

#include <stdio.h>  // standard input/output 

#define MIN_YEAR 2012  //minimum year allowed
#define MAX_YEAR 2022  //maxximum year allowed

int main(void){

    const int JAN = 1;  //unmodifiable variable
    const int DEC = 12; //unmodifiable variable

    int yyyy; //year
    int mm;  //month
    int error_count;  // to count error 

    printf("General Well-being Log\n"); //Hearder
    printf("======================\n");

    do{  //do/while loop to ask user to enter the year and month 
            error_count = 0;

                printf("Set the year and month for the well-being log (YYYY MM): ");
                scanf("%d %d", &yyyy, &mm); //2012 - 2022

        if (yyyy < MIN_YEAR || yyyy > MAX_YEAR){ //if the entered year is less than the minimum year or greater than maximum year 

            error_count ++;

                printf("   ERROR: The year must be between 2012 and 2022 inclusive\n"); //display error 

        }

        if ( mm < JAN || mm > DEC ){  //if the entered month is less than JAN or greater than DEC 

            error_count ++;

                printf("   ERROR: Jan.(1) - Dec.(12)\n"); //display error

        }

        if (error_count == 0){  //if there is no error 

                printf("\n*** Log date set! ***\n\n");  //display this 

                printf("Log starting date: %d-",yyyy); //display the log starting date 

        if (mm == 1)
                printf("JAN");

            else if (mm == 2)
                printf("FEB");

            else if (mm == 3)
                printf("MAR");

            else if (mm == 4)
                printf("APR");

            else if (mm == 5)
                printf("MAY");

            else if (mm == 6)
                printf("JUN");

            else if (mm == 7)
                printf("JUL");

            else if (mm == 8)
                printf("AUG");

            else if (mm == 9)
                printf("SEP");

            else if (mm == 10)
                printf("OCT");

            else if (mm == 11)
                printf("NOV");

            else 
            printf("DEC");

            printf("-01\n\n");

        }

    }while (error_count > 0); // stop the loop when the condition is met 

    return 0;

}