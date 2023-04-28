/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)
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

#define MIN_YEAR 2012
#define MAX_YEAR 2022

int main(void)
{
    const int JAN = 1;
    const int DEC = 12;
    
    printf("General Well-being Log\n");
    printf("======================\n");
    
    int yyyy;
    int mm;
    int error_count;
    
    do{
        error_count = 0;
        
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d",&yyyy,&mm);
        
        //          2012   || 2022
        

                
        if(yyyy < MIN_YEAR || yyyy > MAX_YEAR){
            
            error_count++;
            
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }
        
        if(mm < JAN || mm > DEC){
            
            error_count++;
            
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
        
        if(error_count == 0){
            printf("\n*** Log date set! ***\n\n");
            
            printf("Log starting date: %d-",yyyy);
            if(mm == 1)
                printf("JAN");
            else if(mm == 2)
                printf("FEB");
            else if(mm == 3)
                printf("MAR");
            else if(mm == 4)
                printf("APR");
            else if(mm == 5)
                printf("MAY");
            else if(mm == 6)
                printf("JUN");
            else if(mm == 7)
                printf("JUL");
            else if(mm == 8)
                printf("AUG");
            else if(mm == 9)
                printf("SEP");
            else if(mm == 10)
                printf("OCT");
            else if(mm == 11)
                printf("NOV");
            else 
                printf("DEC");
                
            printf("-01\n\n");

        }

    }while(error_count > 0);
 
    return 0;

}

