//Quiz version # 1:
// * ----------------
// *
// * Write a short program that presents a user with a menu of 4
// * food options: burger, hotdog, veggie wrap, soda. When the user
// * selects one, print off the caloric contents of said food. Loop
// * until the user enters 0. Note: the caloric contents of your menu
// * items are up to you.
// *
// * Example of a single loop:
// * >>> Please choose from the following options:
// * >>> 1 - Burger
// * >>> 2 - Hotdog
// * >>> 3 - Veggie Wrap
// * >>> 4 - Soda
// * >>> 0 - Quite
// * 2
// * >>> The caloric content of the Hotdog is 200 calories.
// *
// ******/

//Name :Hla Myint Myat 
//Student ID : 185923216

#include <stdio.h>

int main(){

    int food_choice;

    do{

    printf("Please choose from the following options:\n\n");

    printf("1 - Burger\n");
    printf("2 - Hotdog\n");
    printf("3 - Veggie Wrap\n");
    printf("4 - Soda\n");
    printf("0 - Quite\n");

    scanf("%d" , &food_choice);

        switch(food_choice) {

        case 0:
        printf("Exit...\n");
        break;

        case 1:
        printf("The caloric content of the Burger is 350 calories.\n");
        break;

        case 2:
        printf("The caloric content of the Hotdog is 100 calories.\n");
        break;

        case 3:
        printf("The caloric content of the Veggie Wrap is 50 calories.\n");
        break;

        case 4:
        printf("The caloric content of the Soda is 10 calories.\n");
        break;

        default:
        printf("Invalide Food Choice!\n");
        break;

        }

    }while (food_choice != 0);

    return 0;
}
