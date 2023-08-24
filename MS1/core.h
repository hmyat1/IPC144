/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 1
Full Name  : Hla Myint Myat
Student ID#: 185923216
Email      : hmyat1@mtseneca.ca
Section    : NRB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/


// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

// Function: inputInt 
int inputInt();

// Function: inputIntPositive
int inputIntPositive();

// Function: inputIntRange 
int inputIntRange(int lower_bound, int upper_bound);

// Function: inputCharOption
char inputCharOption(const char* valid_char);

// Function: inputCString
void inputCString(char *str, int mini, int maxi);

// Function: displayFormattedPhone
void displayFormattedPhone(const char* ph_number);
