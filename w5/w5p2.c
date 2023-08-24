/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
Full Name  : Hla Myint Myat
Student ID#: 185923216
Email      : hmyat1@myseneca.ca
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
#define LOG_DAYS 3 //3 days are allowed 

int main(void){

    const int JAN = 1;  //unmodifiable variable
    const int DEC = 12; //unmodifiable variable

    int yyyy; //year
    int mm;  //month
    int error_count;  // to count error 
    int initial_day; //initial day

    double morning_1,evening_1;    //additional variables for p2
    double morning_2,evening_2;
    double morning_3,evening_3;

    double total_morning = 0.0, total_evening = 0.0;   //for total
    double average_morning = 0.0, average_evening = 0.0;    //for average

    double morning, evening;

    printf("General Well-being Log\n"); //Hearder
    printf("======================\n");

    do{  //do/while loop to ask user to enter the year and month 
            error_count = 0;

            initial_day = 0;

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

            for (initial_day = 1; initial_day <= LOG_DAYS; initial_day++){

                printf("%d-",yyyy);

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

            printf("-0%d\n",initial_day);  

            do{                  //do while loop for morning
                    printf("   Morning rating (0.0-5.0): ");
                    scanf("%lf",&morning);
                    
                if(morning < 0.0 || morning > 5.0)
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                
            }while(morning < 0.0 || morning > 5.0);
                
            do{                //do while loop for evening
                    printf("   Evening rating (0.0-5.0): ");
                    scanf("%lf",&evening);
                    
                if(evening < 0.0 || evening > 5.0)
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    
            }while(evening < 0.0 || evening > 5.0);
                
                if(initial_day == 1)
                    morning_1 = morning,evening_1 = evening;

                else if(initial_day == 2)
                    morning_2 = morning,evening_2 = evening;

                else 
                    morning_3 = morning,evening_3 = evening;
                
                printf("\n");

            }

        }

    }while(error_count > 0);
    
        // caculate summary
    
        total_morning = morning_1 + morning_2 + morning_3;
        total_evening = evening_1 + evening_2 + evening_3;
    
                printf("Summary\n");
                printf("=======\n");

                //total calculation
    
                printf("Morning total rating: %.3lf\n",total_morning);
                printf("Evening total rating:  %.3lf\n",total_evening);

                printf("----------------------------\n");
                printf("Overall total rating: %.3lf\n\n",total_morning + total_evening);

        average_morning = total_morning / 3;
        average_evening = total_evening / 3;

                //average calculation
    
                printf("Average morning rating:  %.1lf\n",average_morning);
                printf("Average evening rating:  %.1lf\n",average_evening);
                
                printf("----------------------------\n");
                printf("Average overall rating:  %.1lf",(average_morning + average_evening)/2);
                printf("\n");
    
    return 0;

}


