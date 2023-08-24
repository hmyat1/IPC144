#include<stdio.h>

int main(){


char coffee_1;
char coffee_1_grindsize;
int coffee_1_bagweight;
char coffee_1_cream;
double coffee_1_temp;

char coffee_2;
char coffee_2_grindsize;
int coffee_2_bagweight;
char coffee_2_cream;
double coffee_2_temp;

char coffee_3;
char coffee_3_grindsize;
int coffee_3_bagweight;
char coffee_3_cream;
double coffee_3_temp;

char c_strength;
char c_cream;
int c_daily_servings;
char c_maker;


const double GRAMS_IN_LBS = 453.5924;



printf("Take a Break - Coffee Shop\n");
printf("==========================\n\n");

printf("Enter the coffee product information being sold today...\n\n");

printf("COFFEE-1...\n");
printf("Type ([L]ight,[B]lend): ");
scanf(" %c", &coffee_1);
printf("Grind size ([C]ourse,[F]ine): ");
scanf(" %c", &coffee_1_grindsize);
printf("Bag weight (g): ");
scanf("%d", &coffee_1_bagweight);
printf("Best served with cream ([Y]es,[N]o): ");
scanf(" %c" , &coffee_1_cream);
printf("Ideal serving temperature (Celsius): ");
scanf("%lf" , &coffee_1_temp);
printf("\n");


printf("COFFEE-2...\n");
printf("Type ([L]ight,[B]lend): ");
scanf(" %c", &coffee_2);
printf("Grind size ([C]ourse,[F]ine): ");
scanf(" %c", &coffee_2_grindsize);
printf("Bag weight (g): ");
scanf("%d", &coffee_2_bagweight);
printf("Best served with cream ([Y]es,[N]o): ");
scanf(" %c" , &coffee_2_cream);
printf("Ideal serving temperature (Celsius): ");
scanf("%lf" , &coffee_2_temp);
printf("\n");

printf("COFFEE-3...\n");
printf("Type ([L]ight,[B]lend): ");
scanf(" %c", &coffee_3);
printf("Grind size ([C]ourse,[F]ine): ");
scanf(" %c", &coffee_3_grindsize);
printf("Bag weight (g): ");
scanf("%d", &coffee_3_bagweight);
printf("Best served with cream ([Y]es,[N]o): ");
scanf(" %c" , &coffee_3_cream);
printf("Ideal serving temperature (Celsius): ");
scanf("%lf" , &coffee_3_temp);
printf("\n");





 printf("---+---------------+---------------+---------------+-------+--------------\n");
 printf("   |    Coffee     |    Coffee     |   Packaged    | Best  |   Serving\n");
 printf("   |     Type      |  Grind Size   |  Bag Weight   | Served| Temperature\n");
 printf("   +---------------+---------------+---------------+ With  +--------------\n");
 printf("ID | Light | Blend | Course | Fine |  (G) | Lbs    | Cream |   (C) |   (F)\n");
 printf("---+---------------+---------------+---------------+-------+--------------\n");
 //printf(" 1 |   %d   |   %d  |   %d   | %d   | %4d  | %6.3lf | %d    | %5.1lf| %5.1lf\n", (coffee_1 =='l' || coffee_1 == 'L'), (coffee_1 == 'b' || coffee_1 == 'B'), (coffee_1_grindsize == 'c' || coffee_1_grindsize == 'C'), (coffee_1_grindsize =='f' || coffee_1_grindsize == 'F'), coffee_1_bagweight, (coffee_1_bagweight / GRAMS_IN_LBS), (coffee_1_cream =='Y' || coffee_1_cream =='y'), coffee_1_temp , (coffee_1_temp *9/5)+32 );
 printf(" 1 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n", (coffee_1 =='l' || coffee_1 == 'L'), (coffee_1 == 'b' || coffee_1 == 'B'), (coffee_1_grindsize == 'c' || coffee_1_grindsize == 'C'), (coffee_1_grindsize =='f' || coffee_1_grindsize == 'F'), coffee_1_bagweight, (coffee_1_bagweight / GRAMS_IN_LBS), (coffee_1_cream =='Y' || coffee_1_cream =='y'), coffee_1_temp , (coffee_1_temp *9/5)+32 );
 printf(" 2 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n", (coffee_2 =='l' || coffee_2 == 'L'), (coffee_2 == 'b' || coffee_2 == 'B'), (coffee_2_grindsize == 'c' || coffee_2_grindsize == 'C'), (coffee_2_grindsize =='f' || coffee_2_grindsize == 'F'), coffee_2_bagweight, (coffee_2_bagweight / GRAMS_IN_LBS), (coffee_2_cream =='Y' || coffee_2_cream =='y'), coffee_2_temp , (coffee_2_temp *9/5)+32 );
 printf(" 3 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n", (coffee_3 =='l' || coffee_3 == 'L'), (coffee_3 == 'b' || coffee_3 == 'B'), (coffee_3_grindsize == 'c' || coffee_3_grindsize == 'C'), (coffee_3_grindsize =='f' || coffee_3_grindsize == 'F'), coffee_3_bagweight, (coffee_3_bagweight / GRAMS_IN_LBS), (coffee_3_cream =='Y' || coffee_3_cream =='y'), coffee_3_temp , (coffee_3_temp *9/5)+32 );

printf("\n");

printf("Enter how you like your coffee and the coffee maker equipment you use...\n\n");

printf("Coffee strength ([M]ild,[R]ich): ");
scanf(" %c", &c_strength);


printf("Do you like your coffee with cream ([Y]es,[N]o): ");
scanf(" %c", &c_cream);

printf("Typical number of daily servings: ");
scanf("%d" , &c_daily_servings);

printf("Maker ([R]esidential,[C]ommercial): ");
scanf(" %c", &c_maker );

printf("\n");
printf("The below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+--------------------+-------------+-------+--------------\n");
    printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
    printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
    printf("--+-----------------+--------------------+-------------+-------+--------------\n");    

    printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n", ((coffee_1 == 'L' || coffee_1 == 'l') && (c_strength == 'M' || c_strength == 'm')) || ((coffee_1 == 'B' || coffee_1 == 'b') && (c_strength == 'R' || c_strength == 'r')), ((coffee_1_grindsize == 'C' || coffee_1_grindsize == 'c') && (c_maker == 'R' || c_maker == 'r')) || (((coffee_1_grindsize == 'F' || coffee_1_grindsize == 'f')) && ((c_maker == 'C' || c_maker == 'c'))), ((c_daily_servings >= 1 && c_daily_servings <= 4) && (coffee_1_bagweight >= 0 && coffee_1_bagweight <= 250)) || ((c_daily_servings > 4 && c_daily_servings <= 9) && (coffee_1_bagweight > 250 && coffee_1_bagweight <= 500)) || (c_daily_servings >= 10 && (coffee_1_bagweight > 500 && coffee_1_bagweight <= 1000)), ((coffee_1_cream == 'Y' || coffee_1_cream == 'y') && (c_cream == 'Y' || c_cream == 'y')) || ((coffee_1_cream == 'N' || coffee_1_cream == 'n') && (c_cream == 'N' || c_cream == 'n')), ((c_maker == 'R' || c_maker == 'r') && (coffee_1_temp >= 60.0 && coffee_1_temp <= 69.9)) || ((c_maker == 'C' || c_maker == 'c') && coffee_1_temp >= 70.0));
    printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n", ((coffee_2 == 'L' || coffee_2 == 'l') && (c_strength == 'M' || c_strength == 'm')) || ((coffee_2 == 'B' || coffee_2 == 'b') && (c_strength == 'R' || c_strength == 'r')), ((coffee_2_grindsize == 'C' || coffee_2_grindsize == 'c') && (c_maker == 'R' || c_maker == 'r')) || (((coffee_2_grindsize == 'F' || coffee_2_grindsize == 'f')) && ((c_maker == 'C' || c_maker == 'c'))), ((c_daily_servings >= 1 && c_daily_servings <= 4) && (coffee_2_bagweight >= 0 && coffee_2_bagweight <= 250)) || ((c_daily_servings > 4 && c_daily_servings <= 9) && (coffee_2_bagweight > 250 && coffee_2_bagweight <= 500)) || (c_daily_servings >= 10 && (coffee_2_bagweight > 500 && coffee_2_bagweight <= 1000)), ((coffee_2_cream == 'Y' || coffee_2_cream == 'y') && (c_cream == 'Y' || c_cream == 'y')) || ((coffee_2_cream == 'N' || coffee_2_cream == 'n') && (c_cream == 'N' || c_cream == 'n')), ((c_maker == 'R' || c_maker == 'r') && (coffee_2_temp >= 60.0 && coffee_2_temp <= 69.9)) || ((c_maker == 'C' || c_maker == 'c') && coffee_2_temp >= 70.0));
    printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n", ((coffee_3 == 'L' || coffee_3 == 'l') && (c_strength == 'M' || c_strength == 'm')) || ((coffee_3 == 'B' || coffee_3 == 'b') && (c_strength == 'R' || c_strength == 'r')), ((coffee_3_grindsize == 'C' || coffee_3_grindsize == 'c') && (c_maker == 'R' || c_maker == 'r')) || (((coffee_3_grindsize == 'F' || coffee_3_grindsize == 'f')) && ((c_maker == 'C' || c_maker == 'c'))), ((c_daily_servings >= 1 && c_daily_servings <= 4) && (coffee_3_bagweight >= 0 && coffee_3_bagweight <= 250)) || ((c_daily_servings > 4 && c_daily_servings <= 9) && (coffee_3_bagweight > 250 && coffee_3_bagweight <= 500)) || (c_daily_servings >= 10 && (coffee_3_bagweight > 500 && coffee_3_bagweight <= 1000)), ((coffee_3_cream == 'Y' || coffee_3_cream == 'y') && (c_cream == 'Y' || c_cream == 'y')) || ((coffee_3_cream == 'N' || coffee_3_cream == 'n') && (c_cream == 'N' || c_cream == 'n')), ((c_maker == 'R' || c_maker == 'r') && (coffee_3_temp >= 60.0 && coffee_3_temp <= 69.9)) || ((c_maker == 'C' || c_maker == 'c') && coffee_3_temp >= 70.0));

    printf("\n");

    printf("Enter how you like your coffee and the coffee maker equipment you use...\n\n");

printf("Coffee strength ([M]ild,[R]ich): ");
scanf(" %c", &c_strength);


printf("Do you like your coffee with cream ([Y]es,[N]o): ");
scanf(" %c", &c_cream);

printf("Typical number of daily servings: ");
scanf("%d" , &c_daily_servings);

printf("Maker ([R]esidential,[C]ommercial): ");
scanf(" %c", &c_maker );

printf("\n");
printf("The below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+--------------------+-------------+-------+--------------\n");
    printf("  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n");
    printf("ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n");
    printf("--+-----------------+--------------------+-------------+-------+--------------\n");
    printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n", ((coffee_1 == 'L' || coffee_1 == 'l') && (c_strength == 'M' || c_strength == 'm')) || ((coffee_1 == 'B' || coffee_1 == 'b') && (c_strength == 'R' || c_strength == 'r')), ((coffee_1_grindsize == 'C' || coffee_1_grindsize == 'c') && (c_maker == 'R' || c_maker == 'r')) || (((coffee_1_grindsize == 'F' || coffee_1_grindsize == 'f')) && ((c_maker == 'C' || c_maker == 'c'))), ((c_daily_servings >= 1 && c_daily_servings <= 4) && (coffee_1_bagweight >= 0 && coffee_1_bagweight <= 250)) || ((c_daily_servings > 4 && c_daily_servings <= 9) && (coffee_1_bagweight > 250 && coffee_1_bagweight <= 500)) || (c_daily_servings >= 10 && (coffee_1_bagweight > 500 && coffee_1_bagweight <= 1000)), ((coffee_1_cream == 'Y' || coffee_1_cream == 'y') && (c_cream == 'Y' || c_cream == 'y')) || ((coffee_1_cream == 'N' || coffee_1_cream == 'n') && (c_cream == 'N' || c_cream == 'n')), ((c_maker == 'R' || c_maker == 'r') && (coffee_1_temp >= 60.0 && coffee_1_temp <= 69.9)) || ((c_maker == 'C' || c_maker == 'c') && coffee_1_temp >= 70.0));
    printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n", ((coffee_2 == 'L' || coffee_2 == 'l') && (c_strength == 'M' || c_strength == 'm')) || ((coffee_2 == 'B' || coffee_2 == 'b') && (c_strength == 'R' || c_strength == 'r')), ((coffee_2_grindsize == 'C' || coffee_2_grindsize == 'c') && (c_maker == 'R' || c_maker == 'r')) || (((coffee_2_grindsize == 'F' || coffee_2_grindsize == 'f')) && ((c_maker == 'C' || c_maker == 'c'))), ((c_daily_servings >= 1 && c_daily_servings <= 4) && (coffee_2_bagweight >= 0 && coffee_2_bagweight <= 250)) || ((c_daily_servings > 4 && c_daily_servings <= 9) && (coffee_2_bagweight > 250 && coffee_2_bagweight <= 500)) || (c_daily_servings >= 10 && (coffee_2_bagweight > 500 && coffee_2_bagweight <= 1000)), ((coffee_2_cream == 'Y' || coffee_2_cream == 'y') && (c_cream == 'Y' || c_cream == 'y')) || ((coffee_2_cream == 'N' || coffee_2_cream == 'n') && (c_cream == 'N' || c_cream == 'n')), ((c_maker == 'R' || c_maker == 'r') && (coffee_2_temp >= 60.0 && coffee_2_temp <= 69.9)) || ((c_maker == 'C' || c_maker == 'c') && coffee_2_temp >= 70.0));
    printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n", ((coffee_3 == 'L' || coffee_3 == 'l') && (c_strength == 'M' || c_strength == 'm')) || ((coffee_3 == 'B' || coffee_3 == 'b') && (c_strength == 'R' || c_strength == 'r')), ((coffee_3_grindsize == 'C' || coffee_3_grindsize == 'c') && (c_maker == 'R' || c_maker == 'r')) || (((coffee_3_grindsize == 'F' || coffee_3_grindsize == 'f')) && ((c_maker == 'C' || c_maker == 'c'))), ((c_daily_servings >= 1 && c_daily_servings <= 4) && (coffee_3_bagweight >= 0 && coffee_3_bagweight <= 250)) || ((c_daily_servings > 4 && c_daily_servings <= 9) && (coffee_3_bagweight > 250 && coffee_3_bagweight <= 500)) || (c_daily_servings >= 10 && (coffee_3_bagweight > 500 && coffee_3_bagweight <= 1000)), ((coffee_3_cream == 'Y' || coffee_3_cream == 'y') && (c_cream == 'Y' || c_cream == 'y')) || ((coffee_3_cream == 'N' || coffee_3_cream == 'n') && (c_cream == 'N' || c_cream == 'n')), ((c_maker == 'R' || c_maker == 'r') && (coffee_3_temp >= 60.0 && coffee_3_temp <= 69.9)) || ((c_maker == 'C' || c_maker == 'c') && coffee_3_temp >= 70.0));

    printf("\n");

    printf("Hope you found a product that suits your likes!\n");


    return 0;
}
