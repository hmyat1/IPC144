/*****************************************************************************
<assessment name example: Workshop - #4 (Part-1)>
Full Name : Hla Myint Myat
Student ID#:185923216
Email :hmyat1@senecacollege.ca
Section :NFF
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************/




#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
    
    char type;
    int count;
    int start;
    
    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n\n");
    
    
    
    
    do{
        start = 0;
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d",&type,&count);
        
        if(type != 'D' && type != 'W' && type != 'F' && type != 'Q'){
        
        printf("ERROR: Invalid entered value(s)!\n");
        
        
        }else if(type == 'Q'){
            
            if(count != 0){
                printf("ERROR: To quit, the number of iterations should be 0!\n");
            }else{
                printf("\n+--------------------+\n");
                printf("Loop application ENDED\n");
                printf("+--------------------+\n");
            }
        }else if(type == 'D'){
            
            if(count >= 3 && count <= 20){
                
                printf("DO-WHILE: ");

                do{
                    printf("D");
                    start++;
                }while(start < count);
                
                printf("\n");
            }else{
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            }
            
        }else if(type == 'W'){
            
            
            if(count >= 3 && count <= 20){
                
                printf("WHILE   : ");
                while(start < count){
                    printf("W");
                    start++;
                }
                printf("\n");
                
                
            }else{
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            }
            
        }else{
            
            
            if(count >= 3 && count <= 20){
                
                printf("FOR     : ");
                
                for(start = 0;start < count ; start++){
                    printf("F");
                }
                
                printf("\n");
                
                
            }else{
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            }
        }
        
        printf("\n");
        
    }while(type != 'Q' || count != 0);
    
    

    return 0;
}




