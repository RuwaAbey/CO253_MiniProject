#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#define tab printf("\t\t\t") //The #define statement defines a macro named 'tab' that expands to the printf statement "\t\t\t"
#define MAX_CONTACTS 100

// Declare a boolean variable named "isRunning" and initialize it to true
bool isRunning = true;

// Define a structure named "contact" with four members: name, phone, email, and address
// Define another structure named "find" with the same members as "contact"
typedef struct{
    char name[20];
    char phone[20];
    char email[30];
    char address[20];
}contact,find;

void ErrorAndRestart(char* error[100]);
bool isNameInArray(char* targetName);
bool isPhoneNumberInArray(char* targetNumber);
bool isAddressInArray(char* targetAddress);
bool isEmailInArray(char* targetEmail);
void AddNewContact() ;
void ListNewContacts();
void removeNewLine(char* str) ;
void GoBackOrExit();
void Exit();
void listContact();
void searchContacts();
void editContacts();
void deleteContacts();
void deleteAllContacts();





// Declare an integer variable named "contactCount" and initialize it to 0
int contactCount = 0;

// Declare an array of type "contact" named "contacts" with size MAX_CONTACTS
contact contacts[MAX_CONTACTS];

// Define a function named "ErrorAndRestart" that takes a pointer to a character array as a parameter
// The function prints the error message and restarts the program
void ErrorAndRestart(char* error[100]) {
    printf("%s\n", error);
    int i = 0;
    printf("Restarting the program: ");
    
    // Print a series of dots to simulate a loading animation
    for (i = 0; i < 10; i++) {
        printf(".");
        Sleep(500);
    }
    
    // Clear the console screen and call the main function to restart the program
    system("cls");
    main();
}

// Function to check if a given name is present in the contacts array
bool isNameInArray(char* targetName) {
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].name, targetName) == 0) {
            return true; // Name found in the array
        }
    }
    return false; // Name not found in the array
}

// Function to check if a given phone number is present in the contacts array
bool isPhoneNumberInArray(char* targetNumber) {
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].phone, targetNumber) == 0) {
            return true; // Phone number found in the array
        }
    }
    return false; // Phone number not found in the array
}


// Function to check if a given address is present in the contacts array
bool isAddressInArray(char* targetAddress) {
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].address, targetAddress) == 0) {
            return true; // Address found in the array
        }
    }
    return false; // Address not found in the array
}

// Function to check if a given email is present in the contacts array
bool isEmailInArray(char* targetEmail) {
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].email, targetEmail) == 0) {
            return true; // Email found in the array
        }
    }
    return false; // Email not found in the array
}

// Function to add a new contact to the contacts array
void AddNewContact() {
    FILE* AllContactTestFile;
    AllContactTestFile = fopen("contact.txt", "a+"); // Open the file in append mode
    contact newContact;

    system("cls");
    tab; printf("======================\n");
    tab; printf("       NEW CONTACT\n");
    tab; printf("======================\n");

    tab; printf("*Name should be unique and maximum 20 characters long.\n"); 
    tab; printf("Input name: "); fflush(stdin); gets(newContact.name);
   

    if (strlen(newContact.name) > 20) {
        ErrorAndRestart("!!!!Name Length Error"); // Display error message for name length exceeding the limit
        return;
    }
    if (isNameInArray(newContact.name) == 1) {
        ErrorAndRestart("!!!Name Already Exists!!!"); // Display error message for duplicate name
        return;
    }
    printf("\n");
    tab; printf("*Phone should be unique and maximum 20 characters long.\n"); 
    tab; printf("Input phone: "); fflush(stdin); gets(newContact.phone);

    if (strlen(newContact.phone) > 20) {
        ErrorAndRestart("!!!!Phone Length Error"); // Display error message for phone length exceeding the limit
        return;
    }
    if (isPhoneNumberInArray(newContact.phone) == 1) {
        ErrorAndRestart("!!!Phone Already Exists!!!"); // Display error message for duplicate phone number
        return;
    }

    printf("\n");
    tab; printf("*Address should be unique and maximum 30 characters long.\n"); 
    tab; printf("Input address: "); fflush(stdin); gets(newContact.address);
    
    
    if (strlen(newContact.address) > 20) {
        ErrorAndRestart("!!!!Address Length Error"); // Display error message for address length exceeding the limit
        return;
    }
    if (isAddressInArray(newContact.address) == 1) {
        ErrorAndRestart("!!!Address Already Exists!!!"); // Display error message for duplicate address
        return;
    }
    
    printf("\n");
    tab; printf("*Email should be unique and maximum 30 characters long.\n"); 
    tab; printf("Input Email: "); fflush(stdin); gets(newContact.email);
    

    if (strlen(newContact.email) > 20) {
        ErrorAndRestart("!!!!Email Length Error"); // Display error message for email length exceeding the limit
        return;
    }
    if (isEmailInArray(newContact.email) == 1) {
        ErrorAndRestart("!!!Email Already Exists!!!"); // Display error message for duplicate email
        return;
    }

    fprintf(AllContactTestFile,"%s\n", newContact.name); // Write name to the file
    fprintf(AllContactTestFile,"%s\n", newContact.phone); // Write phone number to the file
    fprintf(AllContactTestFile,"%s\n", newContact.address); // Write address to the file
    fprintf(AllContactTestFile,"%s\n", newContact.email); // Write email to the file
    fprintf(AllContactTestFile,"----------------------------\n"); // Add a separator in the file

    contacts[contactCount++] = newContact; // Add the new contact to the contacts array
    fclose(AllContactTestFile); // Close the file
    tab; printf("======SUCCESSFUL========\n\n");
    printf("\n");

    system("pause");

    GoBackOrExit(); // Prompt for going back or exiting the program
}


// Function to list new contacts from the file and populate the contacts array
void ListNewContacts() {
    contact newContact;

    FILE* AllContactTestFile;
    char line[30];
    AllContactTestFile = fopen("contact.txt", "r"); // Open the file in read mode

    while (fgets(line, sizeof(line), AllContactTestFile) != NULL) {
        line[strcspn(line, "\n")] = '\0'; // Remove the newline character

        strcpy(newContact.name, line); // Read name from the file and assign it to the new contact

        fgets(line, sizeof(line), AllContactTestFile);
        line[strcspn(line, "\n")] = '\0'; // Remove the newline character
        strcpy(newContact.phone, line); // Read phone number from the file and assign it to the new contact

        fgets(line, sizeof(line), AllContactTestFile);
        line[strcspn(line, "\n")] = '\0'; // Remove the newline character
        strcpy(newContact.address, line); // Read address from the file and assign it to the new contact

        fgets(line, sizeof(line), AllContactTestFile);
        line[strcspn(line, "\n")] = '\0'; // Remove the newline character
        strcpy(newContact.email, line); // Read email from the file and assign it to the new contact

        contacts[contactCount++] = newContact; // Add the new contact to the contacts array
    }

    fclose(AllContactTestFile); // Close the file
}


// Function to remove newline character from a string
void removeNewLine(char* str) {
    size_t newlinePos = strcspn(str, "\n"); // Find the position of the newline character in the string

    if (str[newlinePos] == '\n') { // If a newline character is found
        str[newlinePos] = '\0'; // Replace it with the null character to remove it
    }
}

// Function to prompt the user to go back or exit
void GoBackOrExit() {
    char option;
    getchar(); // Clear the input buffer

    printf("Go Back (b)? or Exit (0)? ");
    scanf("%c", &option);

    if (option == '0') {
        Exit(); // Call the Exit function to terminate the program
    } else {
        system("cls"); // Clear the console screen
    }
}


// Function to exit the program
void Exit() {
    getchar(); // Clear the input buffer

    printf("Are You Sure You Want to Exit? (Y/N): ");
    char YesOrNo;
    scanf("%c", &YesOrNo);

    if (YesOrNo == 'Y' || YesOrNo == 'y') {
        system("cls"); // Clear the console screen

        char ThankYou[100] = "===== Thank You =====\n";
        char SeeYouSoon[100] = "===== See You Soon =====\n";
        int i = 0;

        for (i = 0; i < strlen(ThankYou); i++) {
            printf("%c", ThankYou[i]);
            Sleep(40); // Delay for a smooth printing effect
        }

        for (i = 0; i < strlen(SeeYouSoon); i++) {
            printf("%c", SeeYouSoon[i]);
            Sleep(40); // Delay for a smooth printing effect
        }

        isRunning = false; // Set the program's running status to false to exit the main loop
    }
}

// Function to list all contacts
void listContact() {
    tab; printf("======================\n");
    tab; printf("       LIST CONTACT\n");
    tab; printf("======================\n");

    // Print table headers
    printf("|====================|====================|==============================|====================|\n");
    printf("|        Name        |    Phone Number    |              Address         |          Email     |\n");
    printf("|====================|====================|==============================|====================|\n");

    char* FormatedName = NULL;
    int found = 0;

    for (int i = 0; i < contactCount; i++) {
        found = 1;

        // Format and print each contact's information in a row
        FormatedName = strdup(contacts[i].name);
        removeNewLine(FormatedName);
        printf("|");
        printf("%-20s", FormatedName);
        printf("|");

        FormatedName = strdup(contacts[i].phone);
        removeNewLine(FormatedName);
        printf("%-20s", FormatedName);
        printf("|");

        FormatedName = strdup(contacts[i].address);
        removeNewLine(FormatedName);
        printf("%-30s", FormatedName);
        printf("|");

        FormatedName = strdup(contacts[i].email);
        removeNewLine(FormatedName);
        printf("%-20s", FormatedName);
        printf("|");

        printf("\n");
        printf("|--------------------|--------------------|------------------------------|--------------------|\n");
    }

    // If no contacts were found, display a message
    if (found == 0) {
        printf("No record contact\n\n");
        system("pause");
    }

    system("pause");
    GoBackOrExit(); // Go back or exit the program
}


// Function to search contacts
void searchContacts() {
    int found = 0;
    find search;

    system("cls");
    tab; printf("======================\n");
    tab; printf("       SEARCH CONTACT\n");
    tab; printf("======================\n");

    char searchName[20];
    
    tab; printf("Enter name: "); fflush(stdin); gets(search.name);
    tab; printf("Enter phone number: "); fflush(stdin); gets(search.phone);
    
    if(strlen(search.name) > 20){
        ErrorAndRestart("!!!!Name Length Error!!!");
        return;
    }

    if (contacts == NULL) {
        printf("No entry.\n");
        return;
    }

    for (int i = 0; i < contactCount; i++) {
        // Compare the name and phone number of each contact with the search criteria
        if ((strcmp(contacts[i].name, search.name) || strcmp(contacts[i].phone, search.phone)) == 0) {
            found = 1;
            printf("Contact found:\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone Number: %s\n", contacts[i].phone);
            printf("Address: %s\n", contacts[i].address);
            printf("Email: %s\n", contacts[i].email);
            system("pause");
            break;
        }
    }
    
    if (found == 0) {
        printf("Contact not found.\n\n");
        system("pause");
    }

    system("pause");
    GoBackOrExit(); // Go back or exit the program
}


// Function to edit contacts
void editContacts() {
    contact newContact;
    find check;
    system("cls"); // Clear the console screen
    int ch;
    FILE *AllContactTestFile, *NewContactRecordFile;
    AllContactTestFile = fopen("contact.txt", "r");
    NewContactRecordFile = fopen("temp.txt", "w");

    tab; printf("======================\n");
    tab; printf("       EDIT CONTACT\n");
    tab; printf("======================\n");
    printf("Enter name: ");
    fflush(stdin);
    gets(check.name);

    if (strlen(check.name) > 20) {
        ErrorAndRestart("!!!!Name Length Error!!!");
        return;
    }

    int found = 0;
    for (int i = 0; i < contactCount; i++) {
        
        if (strcmp(contacts[i].name, check.name) == 0){
            found = 1;

            do {
                tab; printf("======================\n");
                tab; printf("       EDIT CONTACT\n");
                tab; printf("======================\n");
                tab; printf("What do you want to edit?\n");
                tab; printf("1. Name\n");
                tab; printf("2. Phone\n");
                tab; printf("3. Address\n");
                tab; printf("4. Email\n");
                tab; printf("0. Exit\n");
                tab; printf("======================\n");
                tab; printf("   Enter option: ");
                scanf("%d", &ch);

                switch (ch) {
                    case 1:
                        printf("Enter new name: ");
                        fflush(stdin);
                        fgets(newContact.name, sizeof(newContact.name), stdin);
                        removeNewLine(newContact.name); // Strip the newline character
                        strcpy(contacts[i].name, newContact.name);
                        tab; printf("=======SUCCESSFUL=======\n\n");
                        system("pause");
                        break;

                    case 2:
                        printf("Enter new phone: ");
                        fflush(stdin);
                        fgets(newContact.phone, sizeof(newContact.phone), stdin);
                        removeNewLine(newContact.phone); // Strip the newline character
                        strcpy(contacts[i].phone, newContact.phone);
                        tab; printf("=======SUCCESSFUL=======\n\n");
                        system("pause");
                        break;

                    case 3:
                        printf("Enter new address: ");
                        fflush(stdin);
                        fgets(newContact.address, sizeof(newContact.address), stdin);
                        removeNewLine(newContact.address); // Strip the newline character
                        strcpy(contacts[i].address, newContact.address);
                        tab; printf("=======SUCCESSFUL=======\n\n");
                        system("pause");
                        break;

                    case 4:
                        printf("Enter new email: ");
                        fflush(stdin);
                        fgets(newContact.email, sizeof(newContact.email), stdin);
                        removeNewLine(newContact.email); // Strip the newline character
                        strcpy(contacts[i].email, newContact.email);
                        tab; printf("=======SUCCESSFUL=======\n\n");
                        system("pause");
                        break;

                    case 0:
                        // Write the edited contact to the new file
                        fprintf(NewContactRecordFile, "%s\n", contacts[i].name);
                        fprintf(NewContactRecordFile, "%s\n", contacts[i].phone);
                        fprintf(NewContactRecordFile, "%s\n", contacts[i].address);
                        fprintf(NewContactRecordFile, "%s\n", contacts[i].email);
                        break;
                }
  
            } while (ch != 0);

        }
        else {
            // Write the contact to the new file as it is
            fprintf(NewContactRecordFile, "%s\n", contacts[i].name);
            fprintf(NewContactRecordFile, "%s\n", contacts[i].phone);
            fprintf(NewContactRecordFile, "%s\n", contacts[i].address);
            fprintf(NewContactRecordFile, "%s\n", contacts[i].email);

        }
    }

    fclose(AllContactTestFile);
    fclose(NewContactRecordFile);
    remove("contact.txt");
    rename("temp.txt", "contact.txt");

    if (found == 0) {
        printf("Contact not found.\n");
        system("pause");
    }
    else {
        for (int i = 0; i < contactCount; i++) {
            // Reset each field of the contact to its initial or default value
            strcpy(contacts[i].name, "");
            strcpy(contacts[i].phone, "");
            strcpy(contacts[i].address, "");
            strcpy(contacts[i].email, "");
        }
    }

    // Reset the contact count to 0
    contactCount = 0;

    ListNewContacts();

    GoBackOrExit();
}


// Function to delete contacts
void deleteContacts(){
    contact li;
    find check;
    int ch, found = 0;
    FILE *AllContactTestFile, *NewContactRecordFile;
    AllContactTestFile = fopen("contact.txt","r");
    NewContactRecordFile = fopen("temp.txt","w");
    system("cls");
    tab; printf("======================\n");
    tab; printf("       DELETE CONTACT\n");
    tab; printf("======================\n");
    printf("Enter name: ");
    fflush(stdin);
    gets(check.name);

    if (strlen(check.name) > 20) {
        ErrorAndRestart("!!!!Name Length Error!!!");
        return;
    }

    // Loop through the contacts to find the one to be deleted
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].name, check.name) == 0) {
            found = 1;
        } else {
            // Write the contact to the new file if it's not the one to be deleted
            fprintf(NewContactRecordFile, "%s\n", contacts[i].name);
            fprintf(NewContactRecordFile, "%s\n", contacts[i].phone);
            fprintf(NewContactRecordFile, "%s\n", contacts[i].address);
            fprintf(NewContactRecordFile, "%s\n", contacts[i].email);
        }
    }

    fclose(AllContactTestFile);
    fclose(NewContactRecordFile);
    remove("contact.txt");
    rename("temp.txt", "contact.txt");

    if(found == 0) {
        printf("Cannot find the name.\n\n");
        system("pause");
    } else {
        // Reset the fields of the contacts to their initial or default values
        for (int i = 0; i < contactCount; i++) {
            strcpy(contacts[i].name, "");
            strcpy(contacts[i].phone, "");
            strcpy(contacts[i].address, "");
            strcpy(contacts[i].email, "");
        }
    }

    // Reset the contact count to 0
    contactCount = 0;

    // Reload the contacts from the file
    ListNewContacts();
    printf("=======SUCCESSFUL=======\n\n");
    system("pause");
    
    // Prompt user to go back or exit
    GoBackOrExit();
}

// Function to delete all contacts
void deleteAllContacts(){
    system("cls");
    tab; printf("**** Delete All The Contacts ****");

    char Option;
    getchar();
    printf("Are you sure you want to delete all the contacts? (Y/N): ");
    scanf("%c",&Option);
    
    if(Option=='Y' || Option=='y'){
        int i;
        
        // Remove the contact file
        remove("contact.txt");
        
        // Create an empty contact file
        FILE *AllContactTextxtFile = fopen("contact.txt","a");
        fclose(AllContactTextxtFile);
        
        // Reset each field of the contacts to their initial or default values
        for (int i = 0; i < contactCount; i++) {
            strcpy(contacts[i].name, "");
            strcpy(contacts[i].phone, "");
            strcpy(contacts[i].address, "");
            strcpy(contacts[i].email, "");
        }
        
        char Deleting[100] = "Deleting....";
        
        // Display the deletion progress
        for(i=0;i<strlen(Deleting);i++){
            printf("%c",Deleting[i]);
            Sleep(40);
        }
        
        printf("\nSuccessfully Deleted All Contacts!\n\n");
    }
    
    // Prompt user to go back or exit
    GoBackOrExit();
}


// Function to display user guidelines
void UserGuideline(){
    system("cls"); // Clear the console screen
    tab; printf("**** My-Contact Management System ****\n");
    tab; printf("User Guideline\n");
    tab; printf("===============================\n");
    tab; printf("This Program is created using C Language.\n");
    tab; printf("[>] Contact information will be stored in a text file.\n");
    tab; printf("[>] You will find the text file in the same folder.\n");
    tab; printf("[>] The text file is created automatically.\n");
    tab; printf("[>] Name, Phone, Address and Email should be unique.\n");
    tab; printf("[>] The maximum length of the name is 20 characters.\n");
    tab; printf("[>] The maximum length of the phone number is 20 characters.\n");
    tab; printf("[>] The maximum length of the address is 30 characters.\n");
    tab; printf("[>] The maximum length of the email is 20 characters.\n");
    tab; printf("===============================\n");

    GoBackOrExit(); // Prompt the user to go back or exit
}





// Main function
void main(){
    
    int i;
    int ch;
    tab;
    ListNewContacts(); // Display the list of new contacts

    char AppStarting[100] = "Application is Starting....";
    for(i=0;i<strlen(AppStarting);i++){
        printf("%c",AppStarting[i]);
        Sleep(100);
    }
    system("cls"); // Clear the console screen

    do{
        // Display the main menu
        tab; printf("======================\n");
        tab; printf("       MAIN MENU\n");
        tab; printf("======================\n");
        tab; printf("[1] Add a new Contact\n");
        tab; printf("[2] Show All Contacts\n");
        tab; printf("[3] Search for Contact\n");
        tab; printf("[4] Edit a Contact\n");
        tab; printf("[5] Delete a contact\n");
        tab; printf("[6] Delete all contacts\n");
        tab; printf("[7] User Guideline\n");
        tab; printf("[0] Exit\n");
        tab; printf("======================\n");
        tab; printf("Enter option: ");
        scanf("%d", &ch);

        switch(ch){
            case 1: AddNewContact(); break;      // Call the function to add a new contact
            case 2: listContact(); break;        // Call the function to display all contacts
            case 3: searchContacts(); break;     // Call the function to search for a contact
            case 4: editContacts(); break;       // Call the function to edit a contact
            case 5: deleteContacts(); break;     // Call the function to delete a contact
            case 6: deleteAllContacts(); break;  // Call the function to delete all contacts
            case 7: UserGuideline(); break;      // Call the function to display user guidelines
        }
        GoBackOrExit(); // Prompt the user to go back or exit

    } while(ch != 0);

    void Exit();

    
}

