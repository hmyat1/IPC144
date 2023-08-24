/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
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

// System Libraries

#include <stdio.h>

// User-Defined Libraries

#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

int getIntPositive(int *int_ptr)
{
    int input;
    int flag = 1;

    do
    {
        scanf("%d", &input);
        if (input <= 0)
        {
        printf("ERROR: Enter a positive value: ");
        }
        else
        {
        flag = 0;
        }
    } while (flag);

    if (int_ptr != NULL)
    {
    *int_ptr = input;
    }
    return input;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

double getDoublePositive(double *double_ptr)
{
    double input;
    int flag = 1;

    do
    {
        scanf("%lf", &input);
        if (input <= 0)
        {
        printf("ERROR: Enter a positive value: ");
        }
        else
        {
        flag = 0;
        }
    } while (flag);

    if (double_ptr != NULL)
    {
    *double_ptr = input;
    }
    return input;
}

// 3. Opening Message (include the number of products that need entering)

void openingMessage(const int seq_number)
{

    printf("Cat Food Cost Analysis\n");
    printf("======================\n");
    printf("\n");

    printf("Enter the details for %d dry food bags of product data for analysis.\n", MAX_PRODUCTS);
    printf("NOTE: A 'serving' is %dg\n", GRAMS_NUMBER);
    printf("\n");
}


// 4. Get user input for the details of cat food product

struct CatFoodInfo getCatFoodInfo(const int seq_number)
{
    struct CatFoodInfo cfi;
    int flag;
    printf("Cat Food Product #%d\n", seq_number + 1);
    printf("--------------------\n");
    flag = 1;

    // SKU
    printf("SKU           : ");
    flag = 1;
    do
    {
        scanf("%d", &cfi.skuNumber);
        if (cfi.skuNumber <= 0)
        {
        printf("ERROR: Enter a positive value: ");
        }
        else
        {
        flag = 0;
        }
    } while (flag);

    // Price
    printf("PRICE         : $");
    flag = 1;
    do
    {
        scanf("%lf", &cfi.productPrice);
        if (cfi.productPrice <= 0)
        {
        printf("ERROR: Enter a positive value: ");
        }
        else
        {
        flag = 0;
        }
    } while (flag);

    // Weight
    printf("WEIGHT (LBS)  : ");
    flag = 1;
    do
    {
        scanf("%lf", &cfi.productWeight);
        if (cfi.productWeight <= 0)
        {
        printf("ERROR: Enter a positive value: ");
        }
        else
        {
        flag = 0;
        }
    } while (flag);

    // Calories
    printf("CALORIES/SERV.: ");
    flag = 1;
    do
    {
        scanf("%d", &cfi.calories);
        if (cfi.calories <= 0)
        {
        printf("ERROR: Enter a positive value: ");
        }
        else
        {
        flag = 0;
        }
    } while (flag);

    printf("\n");

    // Returning the struct
    return cfi;
}

// 5. Display the formatted table header

void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data

void displayCatFoodData(int sku_number, double *product_price, int calorie_per_serving, double *product_weight_lbs)
{
printf("%07d %10.2lf %10.1lf %8d\n", sku_number, *product_price, *product_weight_lbs, calorie_per_serving);
}

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)

double convertLbsKg(double *lbs, double *result_in_kg)
{
    double result = *lbs / LBS_IN_KG;

    if (result_in_kg != NULL)
    {
    *result_in_kg = result;
    }

    return result;
}

// 9. convert lbs: g (call convertKG, then * 1000)

int convertLbsG(double *lbs, int *result_in_g)
{
    int result = convertLbsKg(lbs, NULL) * 1000;

    if (result_in_g != NULL)
    {
    *result_in_g = result;
    }

    return result;
}

// 10. convert lbs: kg and g

void convertLbs(double *lbs, double *result_in_kg, int *result_in_g)
{
    convertLbsKg(lbs, result_in_kg);
    convertLbsG(lbs, result_in_g);
}

// 11. calculate: servings based on gPerServ

double calculateServings(int size, int total, double *result)
{
    double rt = (double)total / size;

    if (result != NULL)
    {
    *result = rt;
    }

    return rt;
}
// 12. calculate: cost per serving

double calculateCostPerServing(double *price, double *total, double *result)
{
    double rt = *price / *total;

    if (result != NULL)
    {
    *result = rt;
    }
    return rt;
}

// 13. calculate: cost per calorie

double calculateCostPerCal(double *price, double *total, double *result)
{
    double rt = *price / *total;
    if (result != NULL)
    {
    *result = rt;
    }
    return rt;
}

// 14. Derive a reporting detail record based on the cat food product data

struct ReportData calculateReportData(struct CatFoodInfo data, struct ReportData *result)
{

    struct ReportData rp_data;
    rp_data.sku = data.skuNumber;
    rp_data.price = data.productPrice;
    rp_data.calories = data.calories;
    rp_data.lbs = data.productWeight;

    rp_data.kg = convertLbsKg(&data.productWeight, NULL);
    rp_data.g = convertLbsG(&data.productWeight, NULL);

    rp_data.total_serving = calculateServings(GRAMS_NUMBER, rp_data.g, NULL);
    double total_calories = rp_data.total_serving * rp_data.calories;
    rp_data.cost_ps = calculateCostPerServing(&data.productPrice, &rp_data.total_serving, NULL);
    rp_data.calories_ps = calculateCostPerCal(&data.productPrice, &total_calories, NULL);

    if (result != NULL)
    {
    *result = rp_data;
    }
    return rp_data;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", GRAMS_NUMBER);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table

void displayReportData(struct ReportData data, int cheapest_option)
{
    printf(
        "%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf",
        data.sku, data.price, data.lbs, data.kg, data.g, data.calories, data.total_serving, data.cost_ps, data.calories_ps);
    if (cheapest_option < 1)
        printf(" ***"); 

    printf("\n");
}


// 17. Display the findings (cheapest)

void displayFinalAnalysis(struct CatFoodInfo data)
{
    printf("Final Analysis\n");
    printf("--------------\n");
    printf("Based on the comparison data, the PURRR-fect economical option is:\n");
    printf("SKU:%07d Price: $%4.2lf\n\n", data.skuNumber, data.productPrice);
    printf("Happy shopping!\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point

void start(void)
{
    int i;

    struct CatFoodInfo cfi[MAX_PRODUCTS] = {{0}};
   
    openingMessage(MAX_PRODUCTS);

    for (i = 0; i < MAX_PRODUCTS; i++)
    {
        cfi[i] = getCatFoodInfo(i);
    }

    displayCatFoodHeader();

    for (i = 0; i < MAX_PRODUCTS; i++)
    {
        displayCatFoodData(cfi[i].skuNumber, &cfi[i].productPrice, cfi[i].calories, &cfi[i].productWeight);
    }
    printf("\n");
    displayReportHeader();

    for (i = 0; i < MAX_PRODUCTS; i++)
    {
        struct ReportData data = calculateReportData(cfi[i], NULL);
        displayReportData(data, data.cost_ps);
    }

    printf("\n");
    displayFinalAnalysis(cfi[1]);
}


