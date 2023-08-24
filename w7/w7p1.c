/*****************************************************************************
<assessment name example: Workshop - #7 (Part-1)>
Full Name : Hla Myint Myat
Student ID#:185923216
Email :hmyat1@myseneca.ca
Section : NRB
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_PATH_LENGTH 70

#include <stdio.h>

struct Playerinfo{
    int lives;    //number of “lives” a player can have for the game
    char symbol;   //character symbol that will be used to represent the player
    int treasures;  //counter to store the number of “treasure’s” found during the game
    int history[MAX_PATH_LENGTH];   //history of all past entered positions entered by the player during the game
};

struct Gameinfo{
    int moves;   //maximum number of “moves” a player can make
    int path_length;  //(number of positions) the game path will have
    int bombs_arr[MAX_PATH_LENGTH];  //an array that represents where bombs are buried along the path 
    int treasures_arr[MAX_PATH_LENGTH];   //an array that represents where treasure is buried along the path
};

int main(void)
{

    struct Playerinfo player;
    struct Gameinfo game;

        printf("================================\n");
        printf("         Treasure Hunt!\n");
        printf("================================\n\n");

    //Player

        printf("PLAYER Configuration\n");
        printf("--------------------\n");   

        printf("Enter a single character to represent the player: ");
        scanf(" %c",&player.symbol);

     
    do{     //do-while loop to check the number of lives 
        printf("Set the number of lives: ");
        scanf("%d", &player.lives);

        if(player.lives < 1 || player.lives > 10){  //if player lives is less than 1 or greater than 10 then 
            printf("     Must be between 1 and 10!\n");    //show this error 
        }else{     //if-not then 
            printf("Player configuration set-up is complete\n\n");  //show this message
        }
    }while(player.lives < 1 || player.lives > 10);  //continue the loop until the condition become false 


    //Game

        printf("GAME Configuration\n");
        printf("------------------\n");

    
    do{     //do-while loop to check the path length
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d",&game.path_length);

        if(game.path_length % 5 != 0 || game.path_length < 10 || game.path_length > 70){   //Must be a multiple of 5 and between 10-70
            printf("     Must be a multiple of 5 and between 10-70!!!\n");      //show this error 
        } 
    }while (game.path_length % 5 != 0 || game.path_length < 10 || game.path_length > 70);  //continue the loop until the condition become false 

    do{     //do-while loop to check the number of moves 
        printf("Set the limit for number of moves allowed: ");
        scanf("%d",&game.moves);

        if(game.moves < 3 || game.moves >26){       //Value must be between 3 and 26
            printf("    Value must be between 3 and 26\n");
        }
    }while (game.moves < 3 || game.moves >26);  //continue the loop until the condition become false 

    //Bomb

        printf("\nBOMB Placement\n");
        printf("--------------\n");
        printf("Enter the bomb positions in sets of 5 where a value\n");
        printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
        printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",game.path_length);

        int count = game.path_length /5;    // 35 / 5 >> 7 lines 
        int previous = 1;    //first part of the position 
        int i;    //for for loop 

    for( i=1 ; i <= count ; i++){

    int row = i * 5;    //second part of the position 

        printf("   Positions [%2d-%2d]: ",previous , row);
        scanf("%d %d %d %d %d",
        &game.bombs_arr[previous-1],    //storing in bomb array
        &game.bombs_arr[previous],
        &game.bombs_arr[previous+1],
        &game.bombs_arr[previous+2],
        &game.bombs_arr[previous+3]);

    previous = row + 1;    //incrementing the first part of the position      
    }

    printf("BOMB placement set\n\n");

    //Treasure 

        printf("TREASURE Placement\n");
        printf("------------------\n");
        printf("Enter the treasure placements in sets of 5 where a value\n");
        printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
        printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",game.path_length);
    
    previous = 1;

    for(i = 1 ; i <= count ;i++){

    int row = i * 5;            //second part of the position 

        printf("   Positions [%2d-%2d]: ",previous , row);                    
        scanf("%d %d %d %d %d",
        &game.treasures_arr[previous-1],  //storing in treasure array 
        &game.treasures_arr[previous],
        &game.treasures_arr[previous+1],
        &game.treasures_arr[previous+2],
        &game.treasures_arr[previous+3]);

        previous = row + 1;         //incrementing the first position 
    }

    printf("TREASURE placement set\n\n");
     
    printf("GAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    
    printf("Player:\n");
    printf("   Symbol     : %c\n",player.symbol);
    printf("   Lives      : %d\n",player.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");
    
    printf("Game:\n");
    printf("   Path Length: %d\n",game.path_length);

    printf("   Bombs      : ");

    int j;
    for(j = 0 ; j < game.path_length ; j++){   //for loop to print bomb array
        printf("%d",game.bombs_arr[j]);
    }

    printf("\n");
    
    printf("   Treasure   : ");
    
    int k;
    for(k = 0 ; k < game.path_length ; k++){   //for loop to print treasure array
        printf("%d",game.treasures_arr[k]);
    }

    printf("\n");
    
    printf("\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n\n");
    
    return 0;
}



