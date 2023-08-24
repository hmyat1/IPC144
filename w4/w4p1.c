/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
Full Name  : Hla Myint Myat
Student ID#: 185923216
Email      : hmyat1@myseneca.ca
Section    : NRB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
///////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    
    char looptype;      //type of loop (D = do/while | W = while | F = for | Q = quit)
    int  iterate_num;  //number of iteration 
    int start;        //to keep track of the num of iteration within the loop
    
    //Header  
    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n\n");
    
    
    do{ //main do loop 
        start = 0;

            printf("D = do/while | W = while | F = for | Q = quit\n");
            printf("Enter loop type and the number of times to iterate (Quit=Q0): "); //Ask user to input information
            scanf(" %c%d",&looptype,&iterate_num); // store the user input into respective variables
        
    if(looptype != 'D' && looptype != 'W' && looptype != 'F' && looptype != 'Q'){  //if loop type is not equal to D, W, F, Q then print error statement 
                    printf("ERROR: Invalid entered value(s)!\n");
        
        }else if(looptype == 'Q'){  //else if user enter Q 
        
                if(iterate_num != 0){ //nested if (the num is not equal zero then print error)

                    printf("ERROR: To quit, the number of iterations should be 0!\n");

                }else{ //if num is equal to 0 , then execute the following codes

                    printf("\n+--------------------+\n");
                    printf("Loop application ENDED\n");
                    printf("+--------------------+\n");
                }
        }else if(looptype == 'D'){ //else if user enter D 
            
                if(iterate_num >= 3 && iterate_num <= 20){ //nested if the number is between 3 to 20 then print the following statement 
                
                    printf("DO-WHILE: ");

                    do{ // do loop to print the number of D entered by the user
                        printf("D");
                        start++;
                    }while(start < iterate_num);
                
                        printf("\n");

                }else{ // if the num is out of range then print the following statement 
                        printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            }
            
        }else if(looptype == 'W'){//else if the user enter W
            
            
                if(iterate_num >= 3 && iterate_num <= 20){ //nested if the num is between 3 to 20 then do the following tasks
                
                        printf("WHILE   : ");

                    while(start < iterate_num){
                        printf("W");
                        start++;
                }
                        printf("\n");
                
                }else{ //otherwise print error statement
                        printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            }
            
    }else{ //else for the main if 
            
            
            if(iterate_num >= 3 && iterate_num <= 20){ //nested if 
                
                        printf("FOR     : ");
                
                    for(start = 0;start < iterate_num ; start++){ // for loop to print the num of F entered by user
                        printf("F");
                }
                        printf("\n");

            }else{ //otherwise print error
                        printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            }
        }
        
                        printf("\n");
        
    }while(looptype != 'Q' || iterate_num != 0); //end of the main do loop 
    
    return 0;
}




