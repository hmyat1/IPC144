/*
	==================================================
	Workshop #8 (Part-1):
	==================================================

	+------------------------------------------------+
					   IMPORTANT
					   =========
			 *** DO NOT MODIFY THIS FILE ***
	+------------------------------------------------+
*/

#include <stdio.h>

#include "w8p1.h"

#define TEST_NEG    -1
#define TEST_ZERO    0
#define TEST_INT    24
#define TEST_DBL    82.5


int testIntFunction(void);
int testDoubleFunction(void);


int main(void)
{
    int preTestFailed = 0;

    printf("============================\n");
    printf("Pre-testing Helper Functions\n");
    printf("============================\n\n");
    
    preTestFailed += testIntFunction();
    preTestFailed += testDoubleFunction();

    if (preTestFailed)
    {
        printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
        printf("  Pretesting revealed ERRORS in the helper functions.\n");
        printf("  Review where the tests failed and fix these errors\n");
        printf("  before continuing.\n");
        printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n");
    }
    else
    {
        printf("===========================\n");
        printf("Starting Main Program Logic\n");
        printf("===========================\n\n");

        
        start();
    }

    return 0;
}


int testIntFunction(void)
{
    int intA = 0, intB = 0, fail=0;

    printf("------------------------\n");
    printf("Function: getIntPositive\n");
    printf("------------------------\n");
    printf("For each of these tests, enter the following\n");
    printf("three values (space delimited):  %d %d %d\n\n", TEST_NEG, TEST_ZERO, TEST_INT);

    
    printf("TEST-1: ");
    intB = getIntPositive(&intA);
    if (intA == intB && intA == TEST_INT)
    {
        printf("<PASSED>\n");
    }
    else
    {
        printf("<!!! FAILED !!!>\n");
        fail++;
    }

    
    intA = intB = 0;
    printf("TEST-2: ");
    intA = getIntPositive(NULL);
    if (intA == TEST_INT)
    {
        printf("<PASSED>\n");
    }
    else
    {
        printf("<!!! FAILED !!!>\n");
        fail++;
    }

    
    intA = intB = 0;
    printf("TEST-3: ");
    getIntPositive(&intA);
    if (intA == TEST_INT)
    {
        printf("<PASSED>\n\n");
    }
    else
    {
        printf("<!!! FAILED !!!>\n");
        fail++;
    }
    
    return fail;
}

int testDoubleFunction(void)
{
    double dblA = 0.0, dblB = 0.0;
    int fail = 0;

    printf("---------------------------\n");
    printf("Function: getDoublePositive\n");
    printf("---------------------------\n");
    printf("For each of these tests, enter the following\n");
    printf("three values (space delimited):  %d %d %.1lf\n\n", TEST_NEG, TEST_ZERO, TEST_DBL);

    
    printf("TEST-1: ");
    dblB = getDoublePositive(&dblA);
    if (dblA == dblB && dblA == TEST_DBL)
    {
        printf("<PASSED>\n");
    }
    else
    {
        printf("<!!! FAILED !!!>\n");
        fail++;
    }

    
    dblA = dblB = 0.0;
    printf("TEST-2: ");
    dblA = getDoublePositive(NULL);
    if (dblA == TEST_DBL)
    {
        printf("<PASSED>\n");
    }
    else
    {
        printf("<!!! FAILED !!!>\n");
        fail++;
    }

    
    dblA = dblB = 0.0;
    printf("TEST-3: ");
    getDoublePositive(&dblA);
    if (dblA == TEST_DBL)
    {
        printf("<PASSED>\n\n");
    }
    else
    {
        printf("<!!! FAILED !!!>\n\n");
        fail++;
    }
    
    return fail;
}
