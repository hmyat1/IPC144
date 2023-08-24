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


// ----------------------------------------------------------------------------
// defines/macros

#define MAX_PRODUCTS 3
#define GRAMS_NUMBER 64
#define LBS_IN_KG 2.20462

// ----------------------------------------------------------------------------
// structures

struct CatFoodInfo
{
    int skuNumber;
    double productPrice;
    int calories;
    double productWeight;
};

struct ReportData
{
    int sku;
    double price;
    int calories;
    double lbs;
    double kg;
    int g;
    double total_serving;
    double cost_ps;
    double calories_ps;
};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

int getIntPositive(int *);


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

double getDoublePositive(double *);


// 3. Opening Message (include the number of products that need entering)

void openingMessage(int);

// 4. Get user input for the details of cat food product

struct CatFoodInfo getCatFoodInfo(int);


// 5. Display the formatted table header

void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data

void displayCatFoodData(int, double *, int, double *);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg

double convertLbsKg(double *lbs, double *result_in_kg);

// 9. convert lbs: g

int convertLbsG(double *lbs, int *result_in_g);

// 10. convert lbs: kg / g

void convertLbs(double *lbs, double *result_in_kg, int *result_in_g);

// 11. calculate: servings based on gPerServ

double calculateServings(int size, int total, double *result);

// 12. calculate: cost per serving

double calculateCostPerServing(double *price, double *total, double *result);

// 13. calculate: cost per calorie

double calculateCostPerCal(double *price, double *total, double *result);

// 14. Derive a reporting detail record based on the cat food product data

struct ReportData calculateReportData(struct CatFoodInfo data, struct ReportData *result);

// 15. Display the formatted table header for the analysis results

void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table

void displayReportData(struct ReportData data, int cheapest_option);

// 17. Display the findings (cheapest)

void displayFinalAnalysis(struct CatFoodInfo data);

// ----------------------------------------------------------------------------

// 7. Logic entry point 

void start(void);
