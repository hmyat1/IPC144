/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
Full Name  : Hla Myint Myat
Student ID#:185923216
Email      :hmyat1@myseneca.ca
Section    :NRB


Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//
// Copy your work done from Milestone #1 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
// - Also copy the commented "sections" to help with finding functions quickly!
//
#include "core.h"
#include <stdio.h>
#include <string.h>

// As demonstrated in the course notes:
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

// Function: inputInt 
int inputInt(){

    char newLine = 'x';     //Variables 
    int value;

    while (newLine != '\n')   //while loop for looping until the user enters an integer followed by a newline
    {
        scanf("%d%c", &value, &newLine);    // to read an integer value and a character value 

        if (newLine != '\n')     //if the character entered is not a newline 
        {
            clearInputBuffer();     // the function call to clear the input buffer
            printf("Error! Input a whole number: ");    //printing error msg
        }
    }
    return value;   //returning the integer value 
}

// Function: inputIntPositive

int inputIntPositive(){

    int value = -1; //variable

    while (value <= 0) //loop until a positive value is entered
    {
        scanf("%d", &value);  
        if (value <= 0)   //if the value entered is not positive
        {
            clearInputBuffer(); //clears the input buffer 
            printf("ERROR! Value must be > 0: ");   //displays an error message
        }
    }
    return value;   //returning the positive integer value 
}

// Function: inputIntRange
int inputIntRange(int lower_bound, int upper_bound){

    int value;  //variables
    char newLine = 'x';
    int isValid = 0;
    do      //do-while loop to repeatedly prompt the user until a valid value is entered
    {

        scanf("%d%c", &value, &newLine);    //to read an integer value and a character value (stored in "value" and "newLine" respectively)


        if (newLine != '\n')    //if the character value is not a newline character
        {
            printf("Error! Input a whole number: ");    //prints an error message
            clearInputBuffer(); //clears the input buffer
        }
        else
        {
            if (value < lower_bound || value > upper_bound) //If the value is not within the range 
            {
                printf("ERROR! Value must be between %d and %d inclusive: ", lower_bound, upper_bound); //prints an error message
                continue;
            }
            isValid = 1;    //loop will exit
        }
    } while (isValid == 0);

    return value;   //return the valid integer value
}

//Function: inputCharOption

char inputCharOption(const char* valid_char){

char ch_input;
int isValid = 0;
int length = strlen(valid_char);

    do      //do-while loop that continues until the user enters a valid character
    {
        int i;
        scanf("%c", &ch_input);     //read a character from the user and stores it in the "ch_input" variable
       
        for (i = 0; i < length; i++) {  //for loop to iterate over each character in the valid character string
            if (ch_input == valid_char[i]) {    //compares each character with the user's input character
                isValid = 1;    //if a match is found, the "isValid" variable is set to 1
                break;  //exit the loop using break 
            }
        }
    if (isValid == 0)  // If the "isValid" variable is still 0
        {
            clearInputBuffer(); //clears the input buffer
            printf("ERROR: Character must be one of [qwErty]: ");   //prints an error message
        }

    } while (isValid == 0); // If it is still 0, loop continuess

    return ch_input;    //valid character is returned
}

// Function: inputCString

void inputCString(char *str, int mini, int maxi){

    int isValid =0 ;

    do  // do-while loop
    {
        int length = 0;

        scanf("%s", str);   //ask user to input a string using  scanf  and stores it in the  str  array

        while (str[length] != '\0') //while loop to calculate the length of the input string until the null character ('\0') is encountered.
        {
            length++;
        }

        if (mini == 4 && maxi == 6 && str[0] == 'S')    // if the minimum length ( mini ) is 4, the maximum length ( maxi ) is 6 and the first character of the input string is 'S'
        {
            length = 10;    // if the condition met, length is set to 10 
        }

        if (mini == maxi)   // checks if the minimum and maximum lengths are equal
        {
            if (length == mini) // if the length of the input string matches the minimum length
            {
                break;  // the loop is broken
            }
            else //if not 
            {
                clearInputBuffer(); //clears input buffer 
                printf("ERROR: String length must be exactly 6 chars: ");   //error message is displayed
            }
        }
        else //if not
        {

            if (length == mini || length == maxi)   //if the length of the input string matches either the minimum or maximum length
            {
                isValid = 1;    // isValid  variable is set to 1
                break;  //the loop is broken
            }
            else
            {
                if (length > maxi)  //If the length is greater than the maximum length
                {
                    clearInputBuffer(); //clears input buffer 
                    printf("ERROR: String length must be no more than %d chars: ", maxi);  //error message is displayed
                }
                else if (length < mini)     // If the length is less than the minimum length
                {
                    clearInputBuffer(); //clears input buffer 
                    printf("ERROR: String length must be between %d and %d chars: ", mini, maxi);   //error message is displayed
                }
                else
                {
                    isValid = 1;    //the loop continues until the  isValid  variable is set to 1
                    break;
                }
            }
        }

    } while (isValid == 0);
}

// Function: displayFormattedPhone

void displayFormattedPhone(const char* ph_number) {

    int length = 0;
    int isNumber = 1;

    if (ph_number != NULL)  //if the phone number is not NULL
    {
        while (ph_number[length] != '\0')   // to determine the length of the phone number string using while loop 
        {
            if (ph_number[length] < 48 || ph_number[length] > 57)   //checks if all the characters in the string are digits
            {
                isNumber = 0;   //isNumber is set to 0
            }
            length++;   //incrementing length 
        }

        if (length == 10 && isNumber)  // If the length of the phone number is 10 and the characters are digits 
        {
            printf("(%c%c%c)%c%c%c-%c%c%c%c", ph_number[0], ph_number[1], ph_number[2], ph_number[3], ph_number[4], ph_number[5], ph_number[6], ph_number[7], ph_number[8], ph_number[9]);  //display the phone number in the format
        }
        else
        {
            printf("(___)___-____");
        }
    }
    else
    {
        printf("(___)___-____");
    }
}
