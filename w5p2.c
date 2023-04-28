


/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
Full Name  :Hla Myint Myat 
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
#define LOG_DAYS 3

int main(void)
{
    const int JAN = 1;
    const int DEC = 12;
    
    printf("General Well-being Log\n");
    printf("======================\n");
    
    int yyyy;
    int mm;
    int error_count;
    int initial_day;
    
    double m1,e1,m2,e2,m3,e3,total_m = 0.0,total_e = 0.0,avg_m = 0.0 ,avg_e = 0.0;

    
    do{ 
        initial_day = 0;
        
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
            
            
            for(initial_day = 1; initial_day <= LOG_DAYS ; initial_day++){
                
                printf("%d-",yyyy);
            
            
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
                    
                printf("-0%d\n",initial_day);
                
                double m;
                double e;
                
                do{
                    printf("   Morning rating (0.0-5.0): ");
                    scanf("%lf",&m);
                    
                    if(m < 0.0 || m > 5.0)
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                
                }while(m < 0.0 || m > 5.0);
                
                do{
                    printf("   Evening rating (0.0-5.0): ");
                    scanf("%lf",&e);
                    
                    if(e < 0.0 || e > 5.0)
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    
                }while(e < 0.0 || e > 5.0);
                
                if(initial_day == 1)
                    m1 = m,e1 = e;
                else if(initial_day == 2)
                    m2 = m,e2 = e;
                else 
                    m3 = m,e3 = e;
                
                printf("\n");
                
            }
            
            
        }
        
    }while(error_count > 0);
    
    // caculate summary
    
    total_m = m1 + m2 + m3;
    total_e = e1 + e2 + e3;
    
    printf("Summary\n");
    printf("=======\n");
    printf("Morning total rating: %.3lf\n",total_m);
    printf("Evening total rating:  %.3lf\n",total_e);
    printf("----------------------------\n");
    printf("Overall total rating: %.3lf\n\n",total_m + total_e);
    avg_m = total_m / 3;
    avg_e = total_e / 3;
    printf("Average morning rating:  %.1lf\n",avg_m);
    printf("Average evening rating:  %.1lf\n",avg_e);
    printf("----------------------------\n");
    printf("Average overall rating:  %.1lf",(avg_m + avg_e)/2);
    printf("\n");
    
    return 0;
}



