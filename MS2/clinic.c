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
#include <string.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit


void menuPatientEdit(struct Patient* patient)
{
    int selection;
     do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
         displayFormattedPhone(patient->phone.number);
         printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
         if (selection == 1)
        {
            printf("Name  : ");
            fflush(stdin);
            fgets(patient->name, NAME_LEN, stdin);
            patient->name[strcspn(patient->name, "\n")] = '\0';
            printf("\nPatient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("\nPatient record updated!\n\n");
        }
     } while (selection);
}


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    displayPatientTableHeader();
    int i;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
            displayPatientData(&patient[i], fmt);
    }
    printf("\n");
}


// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

//void searchPatientData(struct Patient patient[], int max)
void searchPatientData(const struct Patient *patient, int max) 
{
    int selection;

    // char option_con;
    do
    {
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");
        scanf("%d", &selection);
        printf("\n");
        if (selection == 1)
        {
            searchPatientByPatientNumber(patient, max);
            printf("\n");
            suspend();
        }
        if (selection == 2)
        {
            searchPatientByPhoneNumber(patient, max);
            printf("\n");
            suspend();
        }

    } while (selection != 0);

    //menuPatient(patient, max);
}

// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void addPatient(struct Patient patient[], int max)
{
    int index = -1;
    int i;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == 0)
        {
            index = i;
            break;
        }
    }

    if (index < 0)
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
    else
    {
        patient[index].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[index]);
        printf("\n*** New patient record added ***\n\n");
    }
}


// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void editPatient(struct Patient patient[], int max)
{
    int patientNumber;
    printf("Enter the patient number: ");
    scanf("%d", &patientNumber);
    printf("\n");

    int index = findPatientIndexByPatientNum(patientNumber, patient, max);

    if (index == -1)
    {
        printf("ERROR: Patient record not found!\n");
    }
    else
    {
        menuPatientEdit(&patient[index]);
    }
}


// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void removePatient(struct Patient patient[], int max)
{
    int patientNumber;
    printf("Enter the patient number: ");
    scanf("%d", &patientNumber);

    int index = findPatientIndexByPatientNum(patientNumber, patient, max);

    if (index == -1)
    {
        printf("\nERROR: Patient record not found!\n\n");
    }
    else
    {
        printf("\n");
        displayPatientData(&patient[index], FMT_FORM);
        char option;
        printf("\nAre you sure you want to remove this patient record? (y/n): ");
        scanf(" %c", &option);
        if (option == 'n')
        {
            printf("Operation aborted.\n\n");
        }
        else
        {

            strcpy(patient[index].name, "");
            patient[index].patientNumber = 0;
            strcpy(patient[index].phone.description, "");
            strcpy(patient[index].phone.number, "");
            printf("Patient record has been removed!\n\n");
        }
    }
    clearInputBuffer();
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int patient_number;
    int count = 0;
    printf("Search by patient number: ");
    scanf("%d", &patient_number);
    printf("\n");

    int i;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == patient_number)
        {
            count++;
            displayPatientData(&patient[i], FMT_FORM);
            break;
        }
    }

    if (count == 0)
    {
        printf("*** No records found ***\n");
    }

    clearInputBuffer();
}

// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    char phone_number[20];
    printf("Search by phone number: ");
    clearInputBuffer();

    fgets(phone_number, sizeof(phone_number), stdin);
    int count = 0;
    printf("\n");

    char pn[20] = "";

    int i;
    for (i = 0; phone_number[i] != '\n'; i++)
    {
        pn[i] = phone_number[i];
    }

    displayPatientTableHeader();
    if (phone_number[0] != '\n')
    {
        int i;
        for (i = 0; i < max; i++)
        {

            if (strcmp(patient[i].phone.number, pn) == 0)
            {
                count++;
                displayPatientData(&patient[i], FMT_TABLE);
            }
        }
    }
    if (phone_number[0] == '\n' || phone_number[0] == '1')
    {
        printf("\n*** No records found ***\n");
    }
}

// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

int nextPatientNumber(const struct Patient patient[], int max)
{
    int largest = 0;
    int i;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber > largest)
        {
            largest = patient[i].patientNumber;
        }
    }

    return ++largest;
}

// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
    int index = -1;
    int i;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == patientNumber)
        {
            index = i;
            break;
        }
    }
    return index;
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void inputPatient(struct Patient *patient)
{
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    //fgets(patient->name , sizeof(patient->name) , stdin );
    scanf("%[^\n]%*c", patient->name);
    //clearInputBuffer();
    printf("\n");
    inputPhoneData(&patient->phone);
    clearInputBuffer();
}

// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void inputPhoneData(struct Phone *phone)
{
    int selection;

    printf("Phone Information\n");             
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n2. Home\n3. Work\n4. TBD\n");
    printf("Selection: ");
    scanf("%d", &selection);

    if (selection == 1)
    {
        strcpy(phone->description, "CELL");
    }
    else if (selection == 2)
    {
        strcpy(phone->description, "HOME");
    }
    else if (selection == 3)
    {
        strcpy(phone->description, "WORK");
    }
    else
    {
        strcpy(phone->description, "TBD");
        strcpy(phone->number, "");
    }

    if (selection != 0 && selection != 4)
    {
        printf("\nContact: %s\n", phone->description);
        clearInputBuffer();
        printf("Number : ");
        scanf("%s", phone->number);
    }
}
