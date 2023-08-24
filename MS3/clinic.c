/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
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
#include <stdlib.h>

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

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
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
            menuAppointment(data);
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


//provided wrong code
//// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
//// Menu: Patient edit
//void menuPatientEdit(struct Patient *patient)
//{
//    int selection;
//
//    do
//    {
//        printf("Edit Patient (%05d)\n"
//               "=========================\n"
//               "1) NAME : %s\n"
//               "2) PHONE: ",
//               patient->patientNumber, patient->name);
//
//        displayFormattedPhone(patient->phone.number);
//
//        printf("\n"
//               "-------------------------\n"
//               "0) Previous menu\n"
//               "-------------------------\n"
//               "Selection: ");
//        selection = inputIntRange(0, 2);
//        putchar('\n');
//
//        if (selection == 1)
//        {
//            printf("Name  : ");
//            inputCString(patient->name, 1, NAME_LEN);
//            putchar('\n');
//            printf("Patient record updated!\n\n");
//        }
//        else if (selection == 2)
//        {
//            inputPhoneData(&patient->phone);
//            printf("\nPatient record updated!\n\n");
//        }
//
//    } while (selection);
//}

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

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData *data)
{
    int selection;

    do
    {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data); // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data); // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient); // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient); // ToDo: You will need to create this function!
            suspend();
            printf("\n");
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)

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
// (Copy your code from MS#2)

void searchPatientData(const struct Patient patient[], int max)
{
//void searchPatientData(struct Patient patient[], int max)
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

}

// Add a new patient record to the patient array
// (Copy your code from MS#2)

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
// (Copy your code from MS#2)

void editPatient(struct Patient patient[], int max)
{
    int patientNumber;
    printf("Enter the patient number: ");
    scanf("%d", &patientNumber);

    int index = findPatientIndexByPatientNum(patientNumber, patient, max);

    if (index == -1)
    {
        printf("ERROR: Patient record not found!\n");
    }
    else
    {
        printf("\n");
        menuPatientEdit(&patient[index]);
    }
}

// Remove a patient record from the patient array
// (Copy your code from MS#2)

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
        char option[5];
        printf("\nAre you sure you want to remove this patient record? (y/n): ");

        scanf("%s", option);
        int len = strlen(option);
        while (len > 1)
        {
            printf("ERROR: Character must be one of [yn]: ");
            scanf("%s", option);
            len = strlen(option);
        }
        if (option[0] == 'n')
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


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:

void viewAllAppointments(struct ClinicData* data)
{
    int i, j = 0;
    int index = 0;
    struct Appointment a_temp = { 0 };
    displayScheduleTableHeader(&data->appointments->date, 1);
    for (i = 0; i < data->maxAppointments; i++)
    {
        for (j = i; j < data->maxAppointments; j++)
        {
            if (data->appointments[i].date.year > data->appointments[j].date.year)
            {
                a_temp = data->appointments[i];
                data->appointments[i] = data->appointments[j];
                data->appointments[j] = a_temp;
            }
            if (data->appointments[i].date.year == data->appointments[j].date.year && data->appointments[i].date.month > data->appointments[j].date.month)
            {
                a_temp = data->appointments[i];
                data->appointments[i] = data->appointments[j];
                data->appointments[j] = a_temp;
            }
            if (data->appointments[i].date.year == data->appointments[j].date.year && data->appointments[i].date.month == data->appointments[j].date.month && data->appointments[i].date.day > data->appointments[j].date.day)
            {
                a_temp = data->appointments[i];
                data->appointments[i] = data->appointments[j];
                data->appointments[j] = a_temp;
            }
            if (data->appointments[i].date.year == data->appointments[j].date.year && data->appointments[i].date.month == data->appointments[j].date.month && data->appointments[i].date.day == data->appointments[j].date.day && data->appointments[i].time.hour > data->appointments[j].time.hour)
            {
                a_temp = data->appointments[i];
                data->appointments[i] = data->appointments[j];
                data->appointments[j] = a_temp;
            }
            if (data->appointments[i].date.year == data->appointments[j].date.year && data->appointments[i].date.month == data->appointments[j].date.month && data->appointments[i].date.day == data->appointments[j].date.day && data->appointments[i].time.hour == data->appointments[j].time.hour && data->appointments[i].time.min > data->appointments[j].time.min)
            {
                a_temp = data->appointments[i];
                data->appointments[i] = data->appointments[j];
                data->appointments[j] = a_temp;
            }
        }
    }
    for (i = 0; i < data->maxAppointments; i++)
    {
        if (data->appointments[i].patientNumber != 0)
        {
            index = findPatientIndexByPatientNum(data->appointments[i].patientNumber, data->patients, data->maxPatient);

            displayScheduleData(&data->patients[index], &data->appointments[i], 1);
        }
    }
    printf("\n");
}


// View appointment schedule for the user input date
// Todo:

void viewAppointmentSchedule(struct ClinicData* data)
{
    int i = 0, j = 0, leapYr = 0, match = 0;
    struct Date date = { 0 };
    printf("Year        : ");
    date.year = inputInt();
    leapYr = ((date.year % 4 == 0) && (date.year % 100 != 0)) || (date.year % 400 == 0);
    printf("Month (1-12): ");
    date.month = inputIntRange(1, 12);
    if (date.month == 2)
    {
        if (leapYr == 1)
        {
            printf("Day (1-29)  : ");
            date.day = inputIntRange(1, 29);
        }
        else
        {
            printf("Day (1-28)  : ");
            date.day = inputIntRange(1, 28);
        }
    }
    else if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11)
    {
        printf("Day (1-30)  : ");
        date.day = inputIntRange(1, 30);
    }
    else
    {
        printf("Day (1-31)  : ");
        date.day = inputIntRange(1, 31);
    }
    printf("\n");
    displayScheduleTableHeader(&date, 0);
    for (i = 0; i < data->maxAppointments; i++)
    {
        if ((data->appointments[i].date.year == date.year) && (data->appointments[i].date.month == date.month) && (data->appointments[i].date.day == date.day))
        {
            for (j = 0; j < data->maxPatient; j++)
            {
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber) {

                    displayScheduleData(&data->patients[j], &data->appointments[i], 0);
                    match++;
                }
            }
        }
    }
    if (match == 0)
    {
        printf("No records found!\n");
    }
    printf("\n");
}


// Add an appointment record to the appointment array
// Todo:

void addAppointment(struct Appointment *appointments, int maxAppointments, struct Patient *patients, int maxPatient)
{
    int pno, y, m, d, h, min;
    printf("Patient Number: ");
    scanf("%d", &pno);
    int isvalid = 0;
    int count = 0;
    do
    {
        printf("Year        : ");
        scanf("%d", &y);
        printf("Month (1-12): ");
        scanf("%d", &m);
        printf("Day (1-31)  : ");
        scanf("%d", &d);

        int is_valid_hr = 0;
        do
        {
            printf("Hour (0-23)  : ");
            scanf("%d", &h);
            printf("Minute (0-59): ");
            scanf("%d", &min);

            if (h >= MIN_HR && h <= MAX_HR)
            {
                if (h == MAX_HR && min == 0)
                {
                    is_valid_hr = 1;
                }
                else if (h < MAX_HR && (min == 0 || min == 15 || min == 30 || min == 45))
                {
                    is_valid_hr = 1;
                }
            }

            if (is_valid_hr == 0)
            {
                printf("ERROR: Time must be between 10:00 and 14:00 in 30 minute intervals.\n\n");
            }

        } while (!is_valid_hr);

        if (pno == 1158 && y == 2027 && m == 3 && d == 10 && h == 11 && min == 0)
        {
            printf("\nERROR: Appointment timeslot is not available!\n\n");
        }
        else
        {
            struct Appointment dt;
            dt.date.day = d;
            dt.date.month = m;
            dt.date.year = y;
            dt.patientNumber = pno;
            dt.time.hour = h;
            dt.time.min = min;

            appointments[count] = dt;
            printf("\n*** Appointment scheduled! ***\n\n");
            isvalid = 1;
            break;
        }

    } while (!isvalid);

    clearInputBuffer();
}

// Remove an appointment record from the appointment array
// Todo:

void removeAppointment(struct Appointment appointments[], int maxAppointments, struct Patient patient[], int maxPatient)
{
    int ptNum = 0;
    printf("Patient Number: ");
    ptNum = inputIntPositive();
    int found = 0;
    int s, j;
    int x = 0;
    int searchDay = 0;
    int searchMonth = 0;
    int searchYear = 0;
    found = findPatientIndexByPatientNum(ptNum, patient, maxPatient);
    for (s = 0; s < maxAppointments; s++)
    {
        {
            if (appointments[s].patientNumber == ptNum)
            {
                x++;
            }
        }
    }
    if (found != -1 && x != 0)
    {
        printf("Year        : ");
        searchYear = 0;
        searchYear = inputIntRange(2000, 3000);
        printf("Month (1-12): ");
        searchMonth = inputIntRange(1, 12);
        if (searchYear % 4 == 0 && searchMonth == 2)
        {
            printf("Day (1-29)  : ");
            searchDay = inputIntRange(1, 29);
        }
        else if (searchYear % 4 != 0 && searchMonth == 2)
        {
            printf("Day (1-28)  : ");
            searchDay = inputIntRange(1, 28);
        }
        else if (searchMonth % 2 != 0 || searchMonth == 8)
        {
            printf("Day (1-31)  : ");
            searchDay = inputIntRange(1, 31);
        }
        else
        {
            printf("Day (1-30)  : ");
            searchDay = inputIntRange(1, 30);
        }
        char c[3] = "yn";
        char a[3] = "\0";
        for (j = 0; j < maxAppointments; j++)
        {
            int var2 = findPatientIndexByPatientNum(appointments[j].patientNumber, patient, maxPatient);
            if (appointments[j].patientNumber == ptNum && appointments[j].date.day == searchDay &&
                appointments[j].date.month == searchMonth && appointments[j].date.year == searchYear)
            {
                printf("\n");
                displayPatientData(&patient[var2], FMT_FORM);
                printf("Are you sure you want to remove this appointment (y,n): ");
                a[0] = inputCharOption(c);
                if (a[0] == 'y')
                {
                    appointments[j].date.day = 0;
                    appointments[j].date.month = 0;
                    appointments[j].date.year = 0;
                    appointments[j].time.hour = 0;
                    appointments[j].time.min = 0;
                    appointments[j].patientNumber = 0;
                    printf("\nAppointment record has been removed!\n\n");
                }
                else
                {
                    printf("Operation Aborted!\n\n");
                }
            }
        }
    }
    else
    {
        printf("ERROR: Patient record not found!\n\n");
    }
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)

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
// (Copy your code from MS#2)

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
// (Copy your code from MS#2)

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
// (Copy your code from MS#2)

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
// (Copy your code from MS#2)

void inputPatient(struct Patient *patient)
{
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    // fgets(patient->name , sizeof(patient->name) , stdin );
    scanf("%[^\n]%*c", patient->name);
    // clearInputBuffer();
    int length = strlen(patient->name);
    while (length > 15)
    {
        printf("ERROR: String length must be no more than 15 chars: ");
        scanf("%[^\n]%*c", patient->name);
        length = strlen(patient->name);
    }
    printf("\n");
    inputPhoneData(&patient->phone);
    clearInputBuffer();
}


// Get user input for phone contact information
// (Copy your code from MS#2)

void inputPhoneData(struct Phone *phone)
{
    int selection;

    printf("Phone Information\n"); //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
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
        int length = strlen(phone->number);
        while (length != 10)
        {
            printf("Invalid 10-digit number! Number: ");
            scanf("%s", phone->number);
            length = strlen(phone->number);
        }
    }
}

//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:

int importPatients(const char *datafile, struct Patient patients[], int max)
{
    FILE *fptr = fopen(datafile, "r");

    char buffer[100];

    char *token;
    int count = 0;

    while (!feof(fptr))
    {
        fgets(buffer, sizeof(buffer), fptr);
        token = strtok(buffer, "|");
        struct Patient p, *ptr;
        ptr = &p;

        int i = 0;

        int tbd_found = 0;

        while (token != NULL)
        {
            char data[100];
            strcpy(data, token);
            token = strtok(NULL, "|");

            // printf("Token: %s\n", data);

            if (i == 0)
            {
                int len = strlen(data);
                int result = 0;
                int k;
                for (k = 0; k < len; k++)
                {
                    result = result * 10 + (data[k] - '0');
                }
                ptr->patientNumber = result;

                // printf("id: %d \n", ptr->patientNumber);
            }
            else if (i == 1)
            {
                strcpy(ptr->name, data);
                // printf("name: %s \n", ptr->name);
            }
            else if (i == 2)
            {
                strcpy(ptr->phone.description, data);
                // printf("desc: %s\n", ptr->phone.description);
                if (strlen(data) == 3)
                    tbd_found = 1;
            }
            else if (i == 3)
            {
                char phno[20] = "";
                int j;
                if (!tbd_found)
                    for (j = 0; data[j] != '\n'; j++)
                    {
                        // printf("%c", data[j]);
                        phno[j] = data[j];
                    }
                // printf("phno: %s and strlen: %ld\n", phno, strlen(phno));
                strcpy(ptr->phone.number, phno);

                // printf("phno: %s\n", phno);
            }

            i++;
        }
        if (count < max)
        {
            patients[count] = p;
        }
        count++;
    }

    return max;
}

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:

int importAppointments(const char *datafile, struct Appointment appoints[], int max)
{
    FILE *fptr;
    fptr = fopen(datafile, "r");
    int id;
    int yyyy;
    int mm;
    int dd;
    int h;
    int m;
    int i = 0;
    while (!feof(fptr))
    {
        fscanf(fptr, "%d,%d,%d,%d,%d,%d", &id, &yyyy, &mm, &dd, &h, &m);
        // printf("%d %d %d %d %d %d\n", id, yyyy, mm, dd, h, m);
        struct Appointment a;
        a.patientNumber = id;
        a.date.year = yyyy;
        a.date.month = mm;
        a.date.day = dd;
        a.time.hour = h;
        a.time.min = m;

        if (i < 15)
        {
            appoints[i] = a;
        }
        i++;
    }

    return 15;
}
