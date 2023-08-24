/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
Full Name  : Hla Myint Myat
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

//unmodifiable variables 
#define MIN 500     //minimum montly income 
#define MAX 400000  //maximum monthly income
#define LIMIT 10    //maximum number of items 
#define MIN_COST 100    //the entered value (cost)

int main(){
    
    double net_income;  //MONTHLY NET INCOME 
    int items;
    
    //Header
    
        printf("+--------------------------+\n");
        printf("+   Wish List Forecaster   |\n");
        printf("+--------------------------+\n");
        printf("\n");

    
    do{     //do-while loop for net income 

            printf("Enter your monthly NET income: $"); //ask user to enter monthly Net income 
            scanf("%lf",&net_income);   //store it in net_income variable
        
        if(net_income < MIN)    //if net income is less than min which is 500 then
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n");   //show this error message
        }
        
        if(net_income >= MAX)   //if net income is greater than or equal max which is 400000 then
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n"); //show this error
        }
            printf("\n");   //new line
        
    }while(net_income < MIN || net_income >= MAX);  //keep asking the user until the entered value is less than min 500 or greater than or equal max 400000
    
    
    do {    //do-while loop for wish list item 

            printf("How many wish list items do you want to forecast?: ");  //ask user to enter the wish list item
            scanf("%d",&items); //store it in item variable
        
        if(items < 1 || items > LIMIT)  //if the value entered is less than 1 or more than limit which is 10 then
            {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");   //display this error
            }
            printf("\n");   //new line

    }while(items < 1 || items > LIMIT); //ask user until the value entered is less than 1 or more than limit which is 10
    
    //Arrays  
    double cost[items]; 
    int priority[items];
    char options[items];

    int i; 
    for(i = 1 ; i <= items ; i++)    // for loop which starts from 1 to the number of items user entered and incremented by 1   
        {
            printf("Item-%d Details:\n", i);    //header 
        
        //nested do-while loop for item cost
        do{
            printf("   Item cost: $");  //asking user to enter item cost
            scanf("%lf", &cost[i - 1]); //storing it in the cost array at index 0 (which is i - 1)
            

        if(cost[i - 1] < MIN_COST)  //if the value of the index 0 is less than min cost (100)
            { 
            printf("      ERROR: Cost must be at least $100.00\n"); //show this error message 
            }

        }while(cost[i - 1] < MIN_COST); // continue the loop until the condition is true 

        //nested do-while loop for priority
        do{
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");//asking user to enter the number according to thier importance 
            scanf("%d",&priority[i - 1]);   //storing it in the priority array at index 0 (which is i - 1)
            
        if(priority[i - 1] < 1 || priority[i - 1] > 3)  //if the value of the index 0 is less than 1 or greater than 3 then 
            {
            printf("      ERROR: Value must be between 1 and 3\n"); //show this error message 
            }
        }while ((priority[i - 1] < 1 || priority[i - 1] > 3));  //continue the loop until the condition is true 

        //nested do-while loop for financing option  

         do {

            printf("   Does this item have financing options? [y/n]: ");    //asking user to enter yes or no for financing option 
            scanf(" %c", &options[i - 1]);  //storing it in the options array at index 0 (which is i - 1)

        if (!(options[i - 1] == 'n' || options[i - 1] == 'y'))  //checking the entered value is not equal to 'n' or 'y'
            {
            printf("      ERROR: Must be a lowercase 'y' or 'n'\n");    //show this error message 
            } 
        }while (!(options[i - 1] == 'n' || options[i - 1] == 'y')); //continue the loop until the condition is true 

            printf("\n");
            
    }
        //table//
            printf("Item Priority Financed        Cost\n");
            printf("---- -------- -------- -----------\n");
    
            int j;  //variable for for-loop
            double total = 0;   //variable for total and initialized zero 

            for(j = 1 ; j <= items ; j++)   //variable is initialized with 1 and it will continue until the variable is less than or equal items and incremented by 1 
            {
            printf("  %d      %d        %c     %10.2lf\n", j, priority[j - 1],options[j - 1],cost[j - 1]);  //printing the details of each items
            total += cost[j - 1];   //adding the cost of the current item to the total variable 
            }

            printf("---- -------- -------- -----------\n");
            printf("                      $ %.2lf\n\n",total);  //printing total value 
            printf("Best of luck in all your future endeavours!\n\n");
    
    return 0;
}


