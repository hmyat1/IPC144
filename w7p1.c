/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
Full Name  : Hla Myint Myat
Student ID#: 185923216
Email      : hmyat1@myseneca.ca
Section    : NFF

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_PATH_LENGTH 70

#include <stdio.h>


struct PlayerInfo{
    int lives;
    char symbol;
    int treasures;
    int history[MAX_PATH_LENGTH];
};

struct GameInfo{
    int moves;
    int path_length;
    int bombs_arr[MAX_PATH_LENGTH];
    int treasures_arr[MAX_PATH_LENGTH];
};

int main(void)
{
    struct PlayerInfo player;
    struct GameInfo game;
    
    int i, j, k;
   
   
    
    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");
    
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c",&player.symbol);
    
    do{
        printf("Set the number of lives: ");
        scanf("%d",&player.lives);
        
        if(player.lives < 1 || player.lives > 10){
            printf("     Must be between 1 and 10!\n");
        }else{
            printf("Player configuration set-up is complete\n\n");
        }
        
    }while(player.lives < 1 || player.lives > 10);
    
    
    printf("GAME Configuration\n");
    printf("------------------\n");
    
    do{
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d",&game.path_length);
        
        if(game.path_length < 10 || game.path_length > 70 || game.path_length % 5 != 0 ){
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
        
    }while(game.path_length < 10 || game.path_length > 70 || game.path_length %5 != 0);
    
    do{
        printf("Set the limit for number of moves allowed: ");
        scanf("%d",&game.moves);
        
        if(game.moves < 3 || game.moves > 26){
            printf("    Value must be between 3 and 26\n");
        }
        
    }while(game.moves < 3 || game.moves > 26);
    
    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",game.path_length);
    

    int count = game.path_length / 5;
    int previous = 1;

    for(i = 1 ; i <= count ;i++){
        int row = i * 5;            // 10
        printf("   Positions [%2d-%2d]: ",previous , row);
                                    //i = 1  [0]          
        scanf("%d %d %d %d %d",
        &game.bombs_arr[previous-1],
        &game.bombs_arr[previous],
        &game.bombs_arr[previous+1],
        &game.bombs_arr[previous+2],
        &game.bombs_arr[previous+3]);

        previous = row + 1;         // 6
    }
    
    printf("BOMB placement set\n\n");
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",game.path_length);
    
    previous = 1;

    for(i = 1 ; i <= count ;i++){
        int row = i * 5;            // 10
        printf("   Positions [%2d-%2d]: ",previous , row);
                                    //i = 1  [0]          
        scanf("%d %d %d %d %d",
        &game.treasures_arr[previous-1],
        &game.treasures_arr[previous],
        &game.treasures_arr[previous+1],
        &game.treasures_arr[previous+2],
        &game.treasures_arr[previous+3]);

        previous = row + 1;         // 6
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
    
    
    for(j = 0 ; j < game.path_length ; j++){
        printf("%d",game.bombs_arr[j]);
    }
    printf("\n");
    
    printf("   Treasure   : ");
    
    
    for(k = 0 ; k < game.path_length ; k++){
        printf("%d",game.treasures_arr[k]);
    }
    printf("\n");
    
    printf("\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n\n");
    

    return 0;
}


