/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
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

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n");
    printf("\n");
    
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    
    //setting custom datas 
    player.symbol = 'V';
    player.lives = 3;
    game.path_length = 20;
    game.moves = 10; 
    int data_bomb [20] = {1,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0};
    int data_treasure [20] = {0,1,1,0,0,0,0,0,0,0,1,1,0,0,1,0,1,1,1,1};

    int i;
    for( i=0; i < 20 ; i++){
        game.bombs_arr[i] = data_bomb[i];
        game.treasures_arr[i] =data_treasure[i];
    }

    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.symbol);

    do{     //do-while loop for number of lives 
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
    
    do{    //do-while loop for path length 
         printf("Set the path length (a multiple of 5 between 10-70): ");
         scanf("%d",&game.path_length);
        
        if(game.path_length < 10 || game.path_length > 70 || game.path_length % 5 != 0 ){
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }  
    }while(game.path_length < 10 || game.path_length > 70 || game.path_length %5 != 0);
    
     do{    //do-while loop for moves 
         printf("Set the limit for number of moves allowed: ");
         scanf("%d",&game.moves);
        
        if(game.moves < 3 || game.moves > 15){
            printf("    Value must be between 3 and 15\n");
        }  
    }while(game.moves < 3 || game.moves > 15);

    //Bomb Placement 
    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",game.path_length);
    
    //Bomb placement positions 
    int count = game.path_length / 5;
    int previous = 1;

    //for loop for bomb placement
    for(i = 1 ; i <= count ;i++){
        int row = i * 5;   //second part of position          // 10

        printf("   Positions [%2d-%2d]: ",previous , row);   //i = 1  [0]
        scanf("%d %d %d %d %d",
        &game.bombs_arr[previous-1],
        &game.bombs_arr[previous],
        &game.bombs_arr[previous+1],
        &game.bombs_arr[previous+2],
        &game.bombs_arr[previous+3]);

        previous = row + 1;         // 6
    }
    printf("BOMB placement set\n\n");

    //Treasure Placement 
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",game.path_length);
    
    //treasures placement positions
    previous = 1,count = 4;
    
    //for loop for treasure placement 
     for(i = 1 ; i <= count ;i++){
        int row = i * 5;            // 10

        printf("   Positions [%2d-%2d]: ",previous , row);     //i = 1  [0]
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
    int j;      // for loop for displaying bombs
    for(j = 0 ; j < game.path_length ; j++){
        printf("%d",game.bombs_arr[j]);
    }
    printf("\n");

    printf("   Treasure   : ");
    int k;      //for loop for displaying treasures 
    for(k = 0 ; k < game.path_length ; k++){
        printf("%d",game.treasures_arr[k]);
    }
    printf("\n");

    printf("\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n\n");
    
    //Additional Variables 
    int next_move = 0;
    char progress[20];
    int history_index = 0;
    player.treasures = 0;
    
    int l;  //for loop
    for(l = 0 ; l < 20 ; l++)
        progress[l] = '-';

    do{     //do while 
        if(next_move != 0){
            printf("  ");
            //nested for loop 
            for(l = 1 ; l <= 20 ; l++){
                if(next_move == l){
                    printf("%c",player.symbol);
                    break;
                }else{
                    printf(" ");
                }
            }
            printf("\n");
        }
        printf("  ");

        int m;      //nested for loop
        for(m = 0 ;m < 20 ; m++){
            printf("%c",progress[m]);
        }
        printf("\n");

        printf("  |||||||||1|||||||||2\n");
        printf("  12345678901234567890\n");
        
        // Displaying Player Statistics
        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n",player.lives,player.treasures,game.moves);
        printf("+---------------------------------------------------+\n");

        if(player.lives == 0 || game.moves == 0){
            printf("\n##################\n");
            printf("#   Game over!   #\n");
            printf("##################\n\n");
            printf("You should play again and try to beat your score!\n");
            break;
        }
            
        do{     //nested do while 
            printf("Next Move [1-%2d]: ",game.path_length);
            scanf("%d",&next_move);
            
            if(next_move < 1 || next_move > game.path_length){
                printf("  Out of Range!!!\n");
            }

        }while(next_move < 1 || next_move > game.path_length);
        printf("\n");

        int bomb = game.bombs_arr[next_move-1];
        int treasure = game.treasures_arr[next_move-1];
        int notFound = 0;

        int n;//for loop
        for(n = 0 ; n <= history_index ; n++){
            if(player.history[n] == next_move){
                notFound = 1;
            }  
        }
        if(notFound == 0){
            player.history[history_index] = next_move;
            history_index++;

            if(bomb == 0 && treasure == 0){
                printf("===============> [.] ...Nothing found here... [.]\n\n");
                progress[next_move-1] = '.';
            }

            if(bomb == 1 && treasure == 0){
                player.lives--;
                progress[next_move-1] = '!';
                printf("===============> [!] !!! BOOOOOM !!! [!]\n\n");
            }

            if(bomb == 0 && treasure == 1){
                progress[next_move-1] = '$';
                player.treasures++;
                printf("===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
            }

            if(bomb == 1 && treasure ==1){
                progress[next_move-1] = '&';
                player.lives -= 1;
                player.treasures++;
                printf("===============> [&] !!! BOOOOOM !!! [&]\n");
                printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
            }
            game.moves--;

        }else{
            printf("===============> Dope! You've been here before!\n\n");
        }

        if(player.lives == 0 || game.moves == 0){
            printf("No more LIVES remaining!\n\n");
        }

    }while(player.lives != 0 || game.moves != 0);
    
    
    return 0;
}


