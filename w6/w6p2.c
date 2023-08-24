/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
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

#define MAX_ITEMS 10

int main(void)
{                           
    // variables
    double monthlyIncome;
    double tot_cost = 0;    //total cost

    const double min_cost = 100.00;

    int wishLItems;  //wish list items 
    int selection;
    int i,j;
    int con_loop = 1;

    //Header 
    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");
    printf("\n");

   //NET monthly income

    do {    //do-while loop for net income 

            printf("Enter your monthly NET income: $");     //ask user to enter monthly Net income 
            scanf("%lf", &monthlyIncome);   //store it in monthly income variable

        if (monthlyIncome < 500.00)  //if montly income is less than 500.00 
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n");   //show this error message
        }

        if (monthlyIncome > 400000.00)  // if monthly income is greater than 400000.00
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n"); // show this error message
        }

            printf("\n");   //new line
    }
    while(!(monthlyIncome >= 500.00 && monthlyIncome <= 400000.00));    //continue the loop until the conditon is true



    // wish list items they want to use in the forecast

    do {     //do-while loop for wish list item 

            printf("How many wish list items do you want to forecast?: ");  //ask user to enter the wish list item
            scanf("%d", &wishLItems);   //store it in wishLItems 

        if (!(wishLItems > 0 && wishLItems <= MAX_ITEMS)) //if wishlist item is greater than zero and less than or equL TO Mximum items 10 then 
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");   //show this error 
        }
        printf("\n");   //new line
        
    }
    while(!(wishLItems > 0 && wishLItems <= MAX_ITEMS));    //continue the loop until the conditon is true

        // Arrays
        double cost[wishLItems];
        int priority[wishLItems];
        char finance_opt[wishLItems];

        // display individual item details
        for (i = 1; i <= wishLItems; i++)
        {
            printf("Item-%d Details:\n", i);

        // Cost
        do {
            printf("   Item cost: $");
            scanf("%lf", &cost[i - 1]);

        if (cost[i - 1] < min_cost)
            {
            printf("      ERROR: Cost must be at least $100.00\n");
            } 
        }
        while (cost[i - 1] < min_cost);

        // Priority
        do {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i - 1]);

        if ((priority[i - 1] < 1) || (priority[i - 1] > 3))
            {
            printf("      ERROR: Value must be between 1 and 3\n");
            } 
        }
        while ((priority[i - 1] < 1) || (priority[i - 1] > 3));

        // Financing options
        do {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &finance_opt[i - 1]);

        if (!(finance_opt[i - 1] == 'n' || finance_opt[i - 1] == 'y'))
            {
            printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            } 
        }
        while (!(finance_opt[i - 1] == 'n' || finance_opt[i - 1] == 'y'));

            printf("\n");
        }

    // printing table
        printf("Item Priority Financed        Cost\n");
        printf("---- -------- -------- -----------\n");
    
    // displaying all the details
        for(j = 1; j <= wishLItems; j++)
        {
        printf("  %d      %d        %c     %10.2lf\n", j, priority[j - 1], finance_opt[j - 1], cost[j - 1]);
        tot_cost += cost[j - 1];
        }
        printf("---- -------- -------- -----------\n");
        printf("                      $ %10.2lf\n", tot_cost);
        printf("\n");


    // Displaying menu with three options
        do {
            printf("How do you want to forecast your wish list?\n");
            printf(" 1. All items (no filter)\n");
            printf(" 2. By priority\n");
            printf(" 0. Quit/Exit\n");

            printf("Selection: ");
            scanf("%d", &selection);
            printf("\n");

        // more variables
        int item, note = 0;
        int pFilter, k;
        double cost_of_p_items = 0, years, months, remaining_months;

        if (selection == 0)
        {
            con_loop = 0;
        }

        else if (selection == 1)
        {
            printf("====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%.2lf\n", tot_cost);

            // Calculating years and months
            months = (tot_cost / monthlyIncome) + 0.5; // Applying manual rounding
            years = ((int) months) / 12;
            remaining_months = (months - (years * 12)) + 0.5; // Applying manual rounding

            printf("Forecast: %d years, %d months\n", (int) years, (int) remaining_months);

            // For loop to check whether 'y' exists in finance_options array
            note = 0;
            for (item = 0; item < wishLItems; item++)
                {
                    if (finance_opt[item] == 'y') 
                    {
                    note += 1;
                    }
                }

            if (note != 0)

                {
                    printf("NOTE: Financing options are available on some items.\n      You can likely reduce the estimated months.\n");
                }
                    printf("====================================================\n");
                    printf("\n");
                }

            else if (selection == 2) {
                    printf("What priority do you want to filter by? [1-3]: ");
                    scanf("%d", &pFilter);
                    printf("\n");

                    printf("====================================================\n");
                    printf("Filter:   by priority (%d)\n", pFilter);


            for (k = 0; k < wishLItems; k++)
                {
                    if (priority[k] == pFilter) 
                    {
                    cost_of_p_items += cost[k];
                    }
                }

            //  years and months
            months = (cost_of_p_items / monthlyIncome) + 0.5; // Applying manual rounding
            years = ((int) months) / 12;
            remaining_months = (months - (years * 12)) + 0.5; // Applying manual rounding


            printf("Amount:   $%.2lf\n", cost_of_p_items);
            printf("Forecast: %d years, %d months\n", (int) years, (int) remaining_months);

            // to check whether 'y' exists in finance_options array
            note = 0;
            for (item = 0; item < wishLItems; item++)
            {
                if (finance_opt[item] == 'y' && priority[item] == pFilter) 
                {
                note += 1;
                }
            }
                if (note != 0)
            {
                printf("NOTE: Financing options are available on some items.\n      You can likely reduce the estimated months.\n");
            }
                printf("====================================================\n");
                printf("\n");
        }

            else if (selection < 0 || selection > 2) {
                printf("ERROR: Invalid menu selection.\n");
                printf("\n");
        }

    }
    while(con_loop == 1);

        // Ending
        printf("Best of luck in all your future endeavours!\n");

    return 0;
}
