#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "banking.h"
#include "book.h"


#define MAX_ACCOUNTS 100
#define ACCOUNTS_FILE "accounts.txt"

typedef struct {
    char fullName[50];
    char email[50];
    char address[100];
    char phoneNumber[20];
    char password[20];
    double balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int numAccounts = 0;


void saveAccountsToFile() {
    FILE* file = fopen(ACCOUNTS_FILE, "w");
    if (file == NULL) {
        printf("\n\t\t\t\t* | Error: Unable to open file for writing.\n");
        return;
    }

    for (int i = 0; i < numAccounts; i++) {
        fprintf(file, "%s;%s;%s;%s;%s;%lf\n", accounts[i].fullName, accounts[i].email, accounts[i].address,
                accounts[i].phoneNumber, accounts[i].password, accounts[i].balance);
    }

    fclose(file);
}

void loadAccountsFromFile() {
    FILE* file = fopen(ACCOUNTS_FILE, "r");
    if (file == NULL) {
        printf("\n\t\t\t\t* | Error: Unable to open file for reading.\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char* token = strtok(line, ";");
        strcpy(accounts[numAccounts].fullName, token);

        token = strtok(NULL, ";");
        strcpy(accounts[numAccounts].email, token);

        token = strtok(NULL, ";");
        strcpy(accounts[numAccounts].address, token);

        token = strtok(NULL, ";");
        strcpy(accounts[numAccounts].phoneNumber, token);

        token = strtok(NULL, ";");
        strcpy(accounts[numAccounts].password, token);

        token = strtok(NULL, ";");
        accounts[numAccounts].balance = atof(token);

        numAccounts++;
    }

    fclose(file);
}

void createAccount(const char* fullName, const char* email, const char* address, const char* phoneNumber, const char* password) {
    if (numAccounts >= MAX_ACCOUNTS) {
        printf("\n\t\t\t\t* | Error: Maximum number of accounts reached.\n");
        return;
    }

    strcpy(accounts[numAccounts].fullName, fullName);
    strcpy(accounts[numAccounts].email, email);
    strcpy(accounts[numAccounts].address, address);
    strcpy(accounts[numAccounts].phoneNumber, phoneNumber);
    strcpy(accounts[numAccounts].password, password);
    accounts[numAccounts].balance = 0;

    numAccounts++;

    printf("\n\t\t\t\t* | Account created successfully.\n");

    saveAccountsToFile();
}

void promptSignupDetails(char* fullName, char* email, char* address, char* phoneNumber, char* password, char* confirmPassword) {
    printf("\n\t\t\t\t* | Enter full name    \t:   ");
    scanf(" %[^\n]s", fullName);
    printf("\n\t\t\t\t* | Enter email     \t:   ");
    scanf(" %[^\n]s", email);
    printf("\n\t\t\t\t* | Enter address    \t:   ");
    scanf(" %[^\n]s", address);
    printf("\n\t\t\t\t* | Enter phone no.    \t:   ");
    scanf(" %[^\n]s", phoneNumber);
    printf("\n\t\t\t\t* | Enter password     \t:   ");
    scanf(" %[^\n]s", password);
    printf("\n\t\t\t\t* | Confirm password    :   ");
    scanf(" %[^\n]s", confirmPassword);
}

void signup() {
    char fullName[50];
    char email[50];
    char address[100];
    char phoneNumber[20];
    char password[20];
    char confirmPassword[20];

    promptSignupDetails(fullName, email, address, phoneNumber, password, confirmPassword);
    // Check if the password and confirm password match
    if (strcmp(password, confirmPassword) != 0) {
        printf("\n\t\t\t\t* | Password and confirm password do not match. Please try again.\n");
        return;
    }
    createAccount(fullName, email, address, phoneNumber, password);
}

void loginMenu() {
    char userType;
    printf("\n\t\t\t\t** GYAN JAM  ************************************************\n\n");

    printf("\n\t\t\t\t* | Are you an admin or user? (A/U)\t: \t");
    scanf(" %c", &userType);

    if (userType == 'A' || userType == 'a') {
        // Admin login
        adminLogin();
    } else if (userType == 'U' || userType == 'u') {
        // User login
        userLogin();
    } else {
        printf("\n\t\t\t\t* | Invalid user type. Please try again.\n");
    }


}
void adminLogin() {
    char adminUsername[20];
    char adminPassword[20];

    printf("\n\n\n\t\t\t\t \t\t| Enter admin username  : ");
    scanf(" %[^\n]s", adminUsername);
    printf("\n\t\t\t\t \t\t| Enter admin password  : ");
    scanf(" %[^\n]s", adminPassword);

    // Check admin credentials
    if (strcmp(adminUsername, "admin") == 0 && strcmp(adminPassword, "admin123") == 0) {
        printf("\n\n\n\n");
        printf("\n\t\t\t\t*************************************************************");
        printf("\n\t\t\t\t*                                                           *");
        printf("\n\t\t\t\t*                 | Admin login successful.                 *");
        printf("\n\t\t\t\t*               Press 'ENTER' || Back to Menu               *");
        printf("\n\t\t\t\t*************************************************************");
        getch();

        // Perform admin-related operations
        int choice;
        do {
            system("CLS");
            printf("\n\t\t\t\t** GYAN JAM  ************************************************\n\n");
            printf("\n");
            printf("\n\t\t\t\t***********************  ADMIN MENU  ************************");
            printf("\n\t\t\t\t* __For Shop System                                         *");
            printf("\n\t\t\t\t*                      1. ADD BOOK                          *");
            printf("\n\t\t\t\t*                      2. VIEW BOOKS                        *");
            printf("\n\t\t\t\t*                      3. SEARCH BOOK                       *");
            printf("\n\t\t\t\t*                      4. EDIT BOOK                         *");
            printf("\n\t\t\t\t*                      5. DELETE BOOK                       *");
            printf("\n\t\t\t\t*                      6. HELP                              *");
            printf("\n\t\t\t\t*                                                           *");
            printf("\n\t\t\t\t* __For User System                                         *");
            printf("\n\t\t\t\t*                      7. Add User     (Under construction) *");
            printf("\n\t\t\t\t*                      8. Delete User  (Under construction) *");
            printf("\n\t\t\t\t*                      9. All Users    (Under construction) *");
            printf("\n\t\t\t\t*                     10. Logout                            *");
            printf("\n\t\t\t\t*************************************************************");
            printf("\n\t\t\t\t                    Enter Your Choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    // Add Book
                    addBook();
                    break;
                case 2:
                    // View Books
                    viewBook();
                    break;
                case 3:
                    // Search Book
                    searchBook();
                    break;
                case 4:
                    // Edit Book
                    editBook();
                    break;
                case 5:
                    // Delete Book
                    deleteBook();
                    break;
                case 6:
                    // Help
                    help();
                    break;
                case 7:
                    // Add User
                    system("CLS");
                    printf("\n\t\t\t\t* | Adding a user...\n");
                    printf("\n\t\t\t\t*************************************************************");
                    printf("\n\t\t\t\t*                                                           *");
                    printf("\n\t\t\t\t*               Press 'ENTER' || Back to Menu               *");
                    printf("\n\t\t\t\t*************************************************************");
                    getch();
                    break;
                case 8:
                    // Delete User
                    system("CLS");
                    printf("\n\t\t\t\t* | Deleting a user...\n");
                    printf("\n\t\t\t\t*************************************************************");
                    printf("\n\t\t\t\t*                                                           *");
                    printf("\n\t\t\t\t*               Press 'ENTER' || Back to Menu               *");
                    printf("\n\t\t\t\t*************************************************************");
                    getch();
                    break;
                case 9:
                    // View All Users
                    system("CLS");
                    printf("\n\t\t\t\t* | Viewing all users...\n");
                    printf("\n\t\t\t\t*************************************************************");
                    printf("\n\t\t\t\t*                                                           *");
                    printf("\n\t\t\t\t*               Press 'ENTER' || Back to Menu               *");
                    printf("\n\t\t\t\t*************************************************************");
                    getch();
                    break;
                case 10:
                    // Logout
                    system("CLS");
                    printf("\n\t\t\t\t* | Logging out...\n");
                    printf("\n\t\t\t\t*************************************************************");
                    printf("\n\t\t\t\t*                                                           *");
                    printf("\n\t\t\t\t*               Press 'ENTER' || Back to Menu               *");
                    printf("\n\t\t\t\t*************************************************************");
                    getch();
                    break;
                default:
                    printf("\n\t\t\t\t* | Invalid choice. Please try again.\n");
                    break;
            }
        } while (choice != 10);
    } else {
        printf("\n\t\t\t\t* | Invalid admin credentials. Please try again.\n");
    }
}

void userLogin() {
    char phoneNumber[20];
    char password[20];

    printf("\n\n\n\t\t\t\t \t\t| Enter phone number\t: \t");
    scanf(" %[^\n]s", phoneNumber);
    printf("\n\t\t\t\t \t\t| Enter password\t: \t");
    scanf(" %[^\n]s", password);

    // Check user credentials
    int loggedIn = 0;
    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].phoneNumber, phoneNumber) == 0 && strcmp(accounts[i].password, password) == 0) {
            //printf("\n\t\t\t\t* | User login successful.\n");
            printf("\n\n\n\n\t\t\t\t*************************************************************");
            printf("\n\t\t\t\t*                                                           *");
            printf("\n\t\t\t\t*                 | User login successful.                  *");
            printf("\n\t\t\t\t*               Press 'ENTER' || Back to Menu               *");
            printf("\n\t\t\t\t*************************************************************");
            getch();
            loggedIn = 1;
            break;
        }
    }

    if (loggedIn) {
        // Perform user-related operations
        int choice;
        do {
            system("CLS");
            printf("\n\t\t\t\t** GYAN JAM  ************************************************\n\n");
            printf("\n");
            printf("\n\t\t\t\t**********************  USER MENU  *************************");
            printf("\n\t\t\t\t*                                                           *");
            printf("\n\t\t\t\t*                   1. VIEW BOOKS                           *");
            printf("\n\t\t\t\t*                   2. SEARCH BOOK                          *");
            printf("\n\t\t\t\t*                   3. Check Balance                        *");
            printf("\n\t\t\t\t*                   4. Cash In                              *");
            printf("\n\t\t\t\t*                   5. Cash Out                             *");
            printf("\n\t\t\t\t*                   6. Send Money                           *");
            printf("\n\t\t\t\t*                   7. Transaction Details                  *");
            printf("\n\t\t\t\t*                   8. HELP                                 *");
            printf("\n\t\t\t\t*                   9. Logout                               *");
            printf("\n\t\t\t\t*                                                           *");
            printf("\n\t\t\t\t*************************************************************");
            printf("\n\t\t\t\t                    Enter Your Choice: ");

            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    system("CLS");
                    viewBook();
                    break;
                case 2:
                    system("CLS");
                    searchBook();
                    break;
                case 3:
                    system("CLS");
                    checkBalance(phoneNumber);
                    printf("\n\n\n\n\t\t\t\t*************************************************************");
                    printf("\n\t\t\t\t*                                                           *");
                    printf("\n\t\t\t\t*               Press 'ENTER' || Back to Menu               *");
                    printf("\n\t\t\t\t*************************************************************");
                    getch();
                    break;
                case 4:
                    system("CLS");
                    cashIn(phoneNumber);
                    printf("\n\n\n\n\t\t\t\t*************************************************************");
                    printf("\n\t\t\t\t*                                                           *");
                    printf("\n\t\t\t\t*               Press 'ENTER' || Back to Menu               *");
                    printf("\n\t\t\t\t*************************************************************");
                    getch();
                    break;
                case 5:
                    system("CLS");
                    cashOut(phoneNumber);
                    printf("\n\n\n\n\t\t\t\t*************************************************************");
                    printf("\n\t\t\t\t*                                                           *");
                    printf("\n\t\t\t\t*               Press 'ENTER' || Back to Menu               *");
                    printf("\n\t\t\t\t*************************************************************");
                    getch();
                    break;
                case 6:
                    system("CLS");
                    sendMoney(phoneNumber);
                    printf("\n\n\n\n\t\t\t\t*************************************************************");
                    printf("\n\t\t\t\t*                                                           *");
                    printf("\n\t\t\t\t*               Press 'ENTER' || Back to Menu               *");
                    printf("\n\t\t\t\t*************************************************************");
                    getch();
                    break;
                case 7:
                    system("CLS");
                    transactionDetails(phoneNumber);
                    printf("\n\n\n\n\t\t\t\t*************************************************************");
                    printf("\n\t\t\t\t*                                                           *");
                    printf("\n\t\t\t\t*               Press 'ENTER' || Back to Menu               *");
                    printf("\n\t\t\t\t*************************************************************");
                    getch();
                    break;
                case 8:
                    system("CLS");
                    printf("\n\t\t\t\t*                   8. HELP                                 *");
                    break;
                case 9:
                    system("CLS");
                    printf("\n\n\n\n\t\t\t\t*************************************************************");
                    printf("\n\t\t\t\t|                     Logging Out User...                   |");
                    printf("\n\t\t\t\t|                                                           |");
                    printf("\n\t\t\t\t|                  'LOGGED OUT SUCCeSSFULL'                 |");
                    printf("\n\t\t\t\t*************************************************************");
                    break;
                default:
                    system("CLS");
                    printf("\n\t\t\t\t|   Invalid choice. Please try again.\n");
                    break;
            }
        } while (choice != 9);
    } else {
        printf("\n\t\t\t\t* | Invalid phone number or password. Please try again.\n");
    }
}

void checkBalance(const char* phoneNumber) {
    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].phoneNumber, phoneNumber) == 0) {
            printf("\n\t\t\t\t\t\t   __________________________");
            printf("\n\t\t\t\t\t\t  | Balance\t: %.2lf    |", accounts[i].balance);
            printf("\n\t\t\t\t\t\t  |__________________________|");
            return;
        }
    }

    printf("\n\t\t\t\t*\t\t| Account not found.\n");
}

void cashIn(const char* phoneNumber) {
    double amount;
    printf("\n\t\t\t\t*\t\t| Enter amount to cash in\t\t: ");
    scanf("%lf", &amount);

    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].phoneNumber, phoneNumber) == 0) {
            accounts[i].balance += amount;
            printf("\n\t\t\t\t*| Cash in successful. New balance\t: %.2lf\n", accounts[i].balance);
            saveAccountsToFile();
            return;
        }
    }

    printf("\n\t\t\t\t*\t\t| Account not found.\n");
}

void cashOut(const char* phoneNumber) {
    double amount;
    printf("\n\t\t\t\t*\t\t| Enter amount to cash out\t\t: ");
    scanf("%lf", &amount);

    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].phoneNumber, phoneNumber) == 0) {
            if (amount <= accounts[i].balance) {
                accounts[i].balance -= amount;
                printf("\n\t\t\t\t*| Cash out successful. New balance\t: %.2lf\n", accounts[i].balance);
                saveAccountsToFile();
                return;
            } else {
                printf("\n\t\t\t\t*\t\t| Insufficient balance.\n");
                return;
            }
        }
    }

    printf("\n\t\t\t\t*\t\t| Account not found.\n");
}

void sendMoney(const char* senderPhoneNumber) {
    char receiverPhoneNumber[20];
    double amount;

    printf("\n\t\t\t\t*\t\t| Enter receiver's phone number : ");
    scanf(" %[^\n]s", receiverPhoneNumber);
    printf("\n\t\t\t\t*\t\t| Enter amount to send\t: ");
    scanf("%lf", &amount);

    int senderIndex = -1, receiverIndex = -1;

    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].phoneNumber, senderPhoneNumber) == 0) {
            senderIndex = i;
        } else if (strcmp(accounts[i].phoneNumber, receiverPhoneNumber) == 0) {
            receiverIndex = i;
        }
    }

    if (senderIndex == -1) {
        printf("\n\t\t\t\t*\t\t| Sender account not found.\n");
        return;
    }

    if (receiverIndex == -1) {
        printf("\n\t\t\t\t*\t\t| Receiver account not found.\n");
        return;
    }

    if (amount <= accounts[senderIndex].balance) {
        accounts[senderIndex].balance -= amount;
        accounts[receiverIndex].balance += amount;
        printf("\n\t\t\t\t*\t\t| Money sent successfully.\n");
        saveAccountsToFile();
    } else {
        printf("\n\t\t\t\t*\t\t| Insufficient balance.\n");
    }
}

void transactionDetails(const char* phoneNumber) {
    printf("\n\t\t\t\t*\t| Transaction details for account: %s\n", phoneNumber);
    printf("\n\t\t\t\t\t\t| ----------------------------------------\n");

    int found = 0;

    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].phoneNumber, phoneNumber) == 0) {
            printf("\n\t\t\t\t\t\t| Full Name: %s\n", accounts[i].fullName);
            printf("\n\t\t\t\t\t\t| Email: %s\n", accounts[i].email);
            printf("\n\t\t\t\t\t\t| Address: %s\n", accounts[i].address);
            printf("\n\t\t\t\t\t\t| Phone Number: %s\n", accounts[i].phoneNumber);
            printf("\n\t\t\t\t\t\t| Balance: %.2lf\n", accounts[i].balance);
            printf("\n\t\t\t\t\t\t| ----------------------------------------\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\n\t\t\t\t*\t\t| Account not found.\n");
    }
}

