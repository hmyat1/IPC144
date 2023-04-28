/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
Full Name  : HLA MYINT MYAT
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

#define MIN 500
#define MAX 400000
#define LIMIT 10
#define MIN_COST 100

int main(){
    
    double net_income;
    int items;
    
    //array
    
    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");
    printf("\n");

    
    do{
        printf("Enter your monthly NET income: $");
        scanf("%lf",&net_income);
        
        if(net_income < MIN)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
        }
        
        if(net_income >= MAX)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
        }
        printf("\n");
        
    }while(net_income < MIN || net_income >= MAX);
    
    
    do {
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d",&items);
        
        if(items < 1 || items > LIMIT)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }
        printf("\n");

    }while(items < 1 || items > LIMIT);
    
    double cost[items]; 
    int priority[items];
    char options[items];

    int i;
    for(i = 1 ; i <= items ; i++)
    {
        
        printf("Item-%d Details:\n", i);
        
        
        do{
            printf("   Item cost: $");
            scanf("%lf", &cost[i - 1]);
            
            if(cost[i - 1] < MIN_COST){
                printf("      ERROR: Cost must be at least $100.00\n");
            }
        }while(cost[i - 1] < MIN_COST);

        
        do{
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d",&priority[i - 1]);
            
            if(priority[i - 1] < 1 || priority[i - 1] > 3)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        }while ((priority[i - 1] < 1 || priority[i - 1] > 3));
        
        

         do {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &options[i - 1]);

            if (!(options[i - 1] == 'n' || options[i - 1] == 'y'))
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            } 
        }
        while (!(options[i - 1] == 'n' || options[i - 1] == 'y'));

        
        printf("\n");
        
        
    }
    //table//
    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    
    int j;
    double total = 0;
    for(j = 1 ; j <= items ; j++){
        printf("  %d      %d        %c     %10.2lf\n", j, priority[j - 1],options[j - 1],cost[j - 1]);
        total += cost[j - 1];

    }
    printf("---- -------- -------- -----------\n");
    printf("                      $ %.2lf\n\n",total);
    printf("Best of luck in all your future endeavours!\n\n");
    
    

    return 0;
}



