/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Hla myint Myat
Student ID#: 185923216
Email      : hmyat1@myseneca.ca
Section    : NRB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
    int apples,oranges,pears,tomatos,cabbages,pick,another_shop;
    
    do{ //do loop for grocery shopping 

                printf("Grocery Shopping\n");
                printf("================\n");
    
        do{ //nested loop for apple

                printf("How many APPLES do you need? : ");
                scanf("%d",&apples);
        
            if(apples < 0){ // if apple is less than zero then display error
                printf("ERROR: Value must be 0 or more.\n");
        }
        
        }while(apples < 0); //stop the loop when apple is less than 0
    
    printf("\n");
    
        do{ //nested loop for oranges 

                printf("How many ORANGES do you need? : ");
                scanf("%d",&oranges);
        
            if(oranges < 0){ // if orange is less than zero then display error
                printf("ERROR: Value must be 0 or more.\n");
        }
        
        }while(oranges < 0); //stop the loop when orange is less than 0
    
    printf("\n");
    
        do{ //nested loop for pears

                printf("How many PEARS do you need? : ");
                scanf("%d",&pears);
        
            if(pears < 0){ // if pear is less than zero then display error
                printf("ERROR: Value must be 0 or more.\n");
        }
        
        }while(pears < 0); //stop the loop when pear is less than 0
    
    printf("\n");
     
        do{ //nested loop for tomoto

                printf("How many TOMATOES do you need? : "); 
                scanf("%d",&tomatos);
        
            if(tomatos < 0){ // if tomato is less than zero then display error
                printf("ERROR: Value must be 0 or more.\n");
        }
        
        }while(tomatos < 0); //stop the loop when tomato is less than 0
    
    printf("\n");
     
        do{ //nested loop for cabbage

                printf("How many CABBAGES do you need? : ");
                scanf("%d",&cabbages);
        
            if(cabbages < 0){ // if cabbage is less than zero then display error
                printf("ERROR: Value must be 0 or more.\n");
        }
        
        }while(cabbages < 0); //stop the loop when cabbage is less than 0
    
    
    printf("\n");


    printf("--------------------------\n");
    printf("Time to pick the products!\n");
    printf("--------------------------\n");
    printf("\n");

    //apples

    if(apples > 0)
        
        do{ // do loop for apples
        
                    printf("Pick some APPLES... how many did you pick? : ");
                    scanf("%d",&pick);

            if(pick <= 0){
                    printf("ERROR: You must pick at least 1!\n");

                }else if(pick > apples){
                    printf("You picked too many... only %d more APPLE(S) are needed.\n",apples);

            }else{
                apples -= pick;
                
                if(apples == 0) //nested if
                    printf("Great, that's the apples done!\n\n");

                else
                    printf("Looks like we still need some APPLES...\n");
            }
            
        }while(apples != 0);
        
        
        //oranges
        
    if(oranges > 0)
        
        do{  //do loop for oranges
            
                    printf("Pick some ORANGES... how many did you pick? : ");
                    scanf("%d",&pick);

            if(pick <= 0){
                    printf("ERROR: You must pick at least 1!\n");

                }else if(pick > oranges){
                    printf("You picked too many... only %d more ORANGE(S) are needed.\n",oranges);

            }else{
                    oranges -= pick;
                    
                    if(oranges == 0) //nested if
                    printf("Great, that's the oranges done!\n\n");

                    else
                    printf("Looks like we still need some ORANGES...\n");
            }
                
        }while(oranges != 0);
        
        // pears
        
    if(pears > 0)
        
        do{ //do loop for pears
            
                    printf("Pick some PEARS... how many did you pick? : ");
                    scanf("%d",&pick);

            if(pick <= 0){
                    printf("ERROR: You must pick at least 1!\n");

                }else if(pick > pears){
                    printf("You picked too many... only %d more PEAR(S) are needed.\n",pears);

            }else{
                    pears -= pick;
                    
                    if(pears == 0) //nested if
                    printf("Great, that's the pears done!\n\n");

                    else
                    printf("Looks like we still need some PEARS...\n");
            }
                
        }while(pears != 0);
        
        //tomatos
        
    if(tomatos > 0)
        
        do{ //do loop for tomatoes
            
                    printf("Pick some TOMATOES... how many did you pick? : ");
                    scanf("%d",&pick);

            if(pick <= 0){
                    printf("ERROR: You must pick at least 1!\n");

                }else if(pick > tomatos){
                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n",tomatos);

            }else{
                    tomatos -= pick;
                    
                    if(tomatos == 0) //nested if
                        printf("Great, that's the tomatoes done!\n\n");

                    else
                        printf("Looks like we still need some TOMATOES...\n");
            }
                
        }while(tomatos != 0);
        
        //cabbages

    if(cabbages > 0)
        
        do{ //do loop for cabbages
            
                    printf("Pick some CABBAGES... how many did you pick? : ");
                    scanf("%d",&pick);
            if(pick <= 0){
                    printf("ERROR: You must pick at least 1!\n");

                }else if(pick > cabbages){
                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n",cabbages);

            }else{
                    cabbages -= pick;
                    
                    if(cabbages == 0) // nested if
                        printf("Great, that's the cabbages done!\n\n");

                    else
                        printf("Looks like we still need some CABBAGES...\n");
                }
                
        }while(cabbages != 0);
        
       
        printf("All the items are picked!\n\n");
        
        printf("Do another shopping? (0=NO): ");
        scanf("%d",&another_shop);

        printf("\n");
        
        
    }while(another_shop != 0);
    
        if(another_shop == 0){
            printf("Your tasks are done for today - enjoy your free time!\n");
            
    }

    return 0;
}
