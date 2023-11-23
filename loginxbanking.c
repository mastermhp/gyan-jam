#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loginxbanking.h"
#include "book.h"


#define MAX_ACCOUNTS 100
#define ACCOUNTS_FILE "accounts.txt"

// Forward declaration for the Transaction structure
typedef struct {
    char senderPhoneNumber[20];
    char receiverPhoneNumber[20];
    double amount;
} Transaction;

#define MAX_TRANSACTIONS 100

// Definition of the Account structure
typedef struct {
    char fullName[50];
    char email[50];
    char address[100];
    char phoneNumber[20];
    char password[20];
    double balance;
    Transaction transactions[MAX_TRANSACTIONS];
    int numTransactions;
} Account;



Account accounts[MAX_ACCOUNTS];
int numAccounts = 0;


void saveAccountsToFile() {
    FILE* file = fopen(ACCOUNTS_FILE, "w");
    if (file == NULL) {
        printf("\n\t\t\t\t\033[1;31m* | Error: Unable to open file for writing.\033[0m\n");
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
        printf("\n\t\t\t\t\033[1;31m* | Error: Unable to open file for reading.\033[0m\n");
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
        printf("\n\t\t\t\t\033[1;31m* | Error: Maximum number of accounts reached.\033[0m\n");
        return;
    }

    strcpy(accounts[numAccounts].fullName, fullName);
    strcpy(accounts[numAccounts].email, email);
    strcpy(accounts[numAccounts].address, address);
    strcpy(accounts[numAccounts].phoneNumber, phoneNumber);
    strcpy(accounts[numAccounts].password, password);
    accounts[numAccounts].balance = 0;

    numAccounts++;

    printf("\n\t\t\t\t\033[1;32m* | Account created successfully.\033[0m\n");

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
        printf("\n\t\t\t\t\033[1;31m* | Password and confirm password do not match. Please try again.\033[0m\n");
        return;
    }
    createAccount(fullName, email, address, phoneNumber, password);
}

void loginMenu() {
    char userType;
    heading();
    printf("\n\t\t\t\t\033[1;31m* | Are you an admin or user? (A/U)\t: \033[0m\t");
    scanf(" %c", &userType);

    if (userType == 'A' || userType == 'a') {
        // Admin login
        adminLogin();
    } else if (userType == 'U' || userType == 'u') {
        // User login
        userLogin();
    } else {
        printf("\n\t\t\t\t\033[1;31m* | Invalid user type. Please try again.\033[0m\n");
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
        printf("\n\t\t\t\t\033[1;35m*************************************************************\033[0m");
        printf("\n\t\t\t\t\033[1;35m*                                                           *\033[0m");
        printf("\n\t\t\t\t\033[1;35m*\033[0m                 | Admin login successful.                 \033[1;35m*\033[0m");
        printf("\n\t\t\t\t\033[1;35m*\033[0m               Press \033[1;31m'ENTER'\033[0m || Back to \033[1;36m'MENU'\033[0m           \033[1;35m*\033[0m");
        printf("\n\t\t\t\t\033[1;35m*************************************************************\033[0m");
        getch();
        // Perform admin-related operations
        int choice;
        do {
            system("CLS");
            heading();
            printf("\n\t\t\t\t\033[1;35m***********************\033[0m  ADMIN MENU  \033[1;35m************************\033[0m");
            printf("\n\t\t\t\t\033[1;35m*\033[0m __For Shop System                                         \033[1;35m*\033[0m");
            printf("\n\t\t\t\t\033[1;35m*\033[0m                      1. ADD BOOK                          \033[1;35m*\033[0m");
            printf("\n\t\t\t\t\033[1;35m*\033[0m                      2. VIEW BOOKS                        \033[1;35m*\033[0m");
            printf("\n\t\t\t\t\033[1;35m*\033[0m                      3. SEARCH BOOK                       \033[1;35m*\033[0m");
            printf("\n\t\t\t\t\033[1;35m*\033[0m                      4. EDIT BOOK                         \033[1;35m*\033[0m");
            printf("\n\t\t\t\t\033[1;35m*\033[0m                      5. DELETE BOOK                       \033[1;35m*\033[0m");
            printf("\n\t\t\t\t\033[1;35m*\033[0m                      6. HELP                              \033[1;35m*\033[0m");
            printf("\n\t\t\t\t\033[1;35m*\033[0m                                                           \033[1;35m*\033[0m");
            printf("\n\t\t\t\t\033[1;35m*\033[0m __For User System                                         \033[1;35m*\033[0m");
            printf("\n\t\t\t\t\033[1;35m*\033[0m                      7. Add User                          \033[1;35m*\033[0m");
            printf("\n\t\t\t\t\033[1;35m*\033[0m                      8. Delete User                       \033[1;35m*\033[0m");
            printf("\n\t\t\t\t\033[1;35m*\033[0m                      9. All Users                         \033[1;35m*\033[0m");
            printf("\n\t\t\t\t\033[1;35m*\033[0m                      10.Logout                            \033[1;35m*\033[0m");
            printf("\n\t\t\t\t\033[1;35m*************************************************************\033[0m");
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
                    printf("\n\t\t\t\t\033[1;31m* | Adding a user...\033[0m\n");

                    // Function to add a new user

                    if (numAccounts < MAX_ACCOUNTS) {
                    char fullName[50];
                    char email[50];
                    char address[100];
                    char phoneNumber[20];
                    char password[20];
                    char confirmPassword[20];

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

                    // Check if the password and confirm password match
                    if (strcmp(password, confirmPassword) != 0) {
                        printf("\n\t\t\t\t\033[1;31m* | Password and confirm password do not match. Please try again.\033[0m\n");
                        return;
                    }

                        // Create the account
                        createAccount(fullName, email, address, phoneNumber, password);
                    } else {
                        printf("\n\t\t\t\t\033[1;31m* | Error: Maximum number of accounts reached.\033[0m\n");
                        getch();
                    }

                    printf("\n\t\t\t\t\033[1;31m*************************************************************\033[0m");
                    printf("\n\t\t\t\t\033[1;31m*                                                           *\033[0m");
                    printf("\n\t\t\t\t\033[1;35m*\033[0m               Press \033[1;31m'ENTER'\033[0m || Back to \033[1;36m'MENU'\033[0m           \033[1;35m*\033[0m");
                    printf("\n\t\t\t\t\033[1;31m*************************************************************\033[0m");
                    getch();
                    break;
                case 8:
                    // Delete User
                    system("CLS");
                    printf("\n\t\t\t\t\033[1;31m* | Deleting a user...\033[0m\n");
                     char phoneNumberToDelete[20];

                    // Get the phone number to delete
                    printf("\n\t\t\t\t* | Enter phone number to delete: ");
                    scanf(" %[^\n]s", phoneNumberToDelete);

                    int found = 0;
                    for (int i = 0; i < numAccounts; i++) {
                        if (strcmp(accounts[i].phoneNumber, phoneNumberToDelete) == 0) {
                            // Shift remaining accounts to fill the gap
                            for (int j = i; j < numAccounts - 1; j++) {
                                accounts[j] = accounts[j + 1];
                            }
                            numAccounts--;
                            found = 1;
                            printf("\n\t\t\t\t\033[1;32m* | User '%s' deleted successfully!\033[0m\n", phoneNumberToDelete);
                            saveAccountsToFile();
                            break;
                        }
                    }

                    if (!found) {
                        printf("\n\t\t\t\t\033[1;31m* | User '%s' not found!\033[0m\n", phoneNumberToDelete);
                    }


                    printf("\n\t\t\t\t\033[1;31m*************************************************************\033[0m");
                    printf("\n\t\t\t\t\033[1;31m*                                                           *\033[0m");
                    printf("\n\t\t\t\t\033[1;35m*\033[0m               Press \033[1;31m'ENTER'\033[0m || Back to \033[1;36m'MENU'\033[0m           \033[1;35m*\033[0m");
                    printf("\n\t\t\t\t\033[1;31m*************************************************************\033[0m");
                    getch();
                    break;
                case 9:
                    // View All Users
                    system("CLS");
                    printf("\n\t\t\t\t\033[1;31m* | Viewing all users...\033[0m\n");
                    for (int i = 0; i < numAccounts; i++) {
                        printf("\n\t\t\t\t* | Full Name: %s\n", accounts[i].fullName);
                        printf("\t\t\t\t* | Email: %s\n", accounts[i].email);
                        printf("\t\t\t\t* | Address: %s\n", accounts[i].address);
                        printf("\t\t\t\t* | Phone Number: %s\n", accounts[i].phoneNumber);
                        // Add more fields as needed
                        printf("\t\t\t\t* | Balance: %.2lf\n", accounts[i].balance);
                        printf("\n");
                    }
                    printf("\n\t\t\t\t\033[1;31m*************************************************************\033[0m");
                    printf("\n\t\t\t\t\033[1;31m*                                                           *\033[0m");
                    printf("\n\t\t\t\t\033[1;35m*\033[0m               Press \033[1;31m'ENTER'\033[0m || Back to \033[1;36m'MENU'\033[0m           \033[1;35m*\033[0m");
                    printf("\n\t\t\t\t\033[1;31m*************************************************************\033[0m");
                    getch();
                    break;
                case 10:
                    // Logout
                    system("CLS");
                    printf("\n\t\t\t\t\033[1;31m* | Logging out...\033[0m\n");
                    printf("\n\t\t\t\t\033[1;31m*************************************************************\033[0m");
                    printf("\n\t\t\t\t\033[1;31m*                                                           *\033[0m");
                    printf("\n\t\t\t\t\033[1;35m*\033[0m               Press \033[1;31m'ENTER'\033[0m || Back to \033[1;36m'MENU'\033[0m           \033[1;35m*\033[0m");
                    printf("\n\t\t\t\t\033[1;31m*************************************************************\033[0m");
                    getch();
                    break;
                default:
                    printf("\n\t\t\t\t\033[1;31m* | Invalid choice. Please try again.\033[0m\n");
                    break;
            }
        } while (choice != 10);
    } else {
        printf("\n\t\t\t\t\033[1;31m* | Invalid admin credentials. Please try again.\033[0m\n");
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
            printf("\n\n\n\n\t\t\t\t\033[1;35m*************************************************************\033[0m");
            printf("\n\t\t\t\t\033[1;35m*                                                           *\033[0m");
            printf("\n\t\t\t\t\033[1;35m*\033[0m                 | User login successful.                  \033[1;35m*\033[0m");
            printf("\n\t\t\t\t\033[1;35m*\033[0m               Press \033[1;31m'ENTER'\033[0m || Back to \033[1;36m'MENU'\033[0m           \033[1;35m*\033[0m");
            printf("\n\t\t\t\t\033[1;35m*************************************************************\033[0m");
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
            heading();
            printf("\n\t\t\t\t\033[1;35m**********************\033[0m  USER MENU  \033[1;35m*************************\033[0m");
            printf("\n\t\t\t\t\033[1;35m*\033[0m                                                           \033[1;35m*\033[0m");
            printf("\n\t\t\t\t\033[1;35m*\033[0m                   1. VIEW BOOKS                           \033[1;35m*\033[0m");
            printf("\n\t\t\t\t\033[1;35m*\033[0m                   2. SEARCH BOOK                          \033[1;35m*\033[0m");
            printf("\n\t\t\t\t\033[1;35m*\033[0m                   3. \033[1;36mCheck Balance\033[0m                        \033[1;35m*\033[0m");
            printf("\n\t\t\t\t\033[1;35m*\033[0m                   4. Cash In                              \033[1;35m*\033[0m");
            printf("\n\t\t\t\t\033[1;35m*\033[0m                   5. Cash Out                             \033[1;35m*\033[0m");
            printf("\n\t\t\t\t\033[1;35m*\033[0m                   6. Send Money                           \033[1;35m*\033[0m");
            printf("\n\t\t\t\t\033[1;35m*\033[0m                   7. Transaction Details                  \033[1;35m*\033[0m");
            printf("\n\t\t\t\t\033[1;35m*\033[0m                   8. HELP                                 \033[1;35m*\033[0m");
            printf("\n\t\t\t\t\033[1;35m*\033[0m                   9. \033[1;41mLogout\033[0m                               \033[1;35m*\033[0m");
            printf("\n\t\t\t\t\033[1;35m*\033[0m                                                           \033[1;35m*\033[0m");
            printf("\n\t\t\t\t\033[1;35m*************************************************************\033[0m");
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
                    printf("\n\n\n\n\t\t\t\t\033[1;31m*************************************************************\033[0m");
                    printf("\n\t\t\t\t\033[1;35m*                                                           *\033[0m");
                    printf("\n\t\t\t\t\033[1;35m*\033[0m               Press \033[1;31m'ENTER'\033[0m || Back to \033[1;36m'MENU'\033[0m             \033[1;35m*\033[0m");
                    printf("\n\t\t\t\t\033[1;35m*************************************************************\033[0m");
                    getch();
                    break;
                case 4:
                    system("CLS");
                    cashIn(phoneNumber);
                    printf("\n\n\n\n\t\t\t\t\033[1;31m*************************************************************\033[0m");
                    printf("\n\t\t\t\t\033[1;35m*\033[0m                                                           \033[1;35m*\033[0m");
                    printf("\n\t\t\t\t\033[1;35m*\033[0m               Press \033[1;31m'ENTER'\033[0m || Back to \033[1;36m'MENU'\033[0m             \033[1;35m*\033[0m");
                    printf("\n\t\t\t\t\033[1;35m*************************************************************\033[0m");
                    getch();
                    break;
                case 5:
                    system("CLS");
                    cashOut(phoneNumber);
                    printf("\n\n\n\n\t\t\t\t\033[1;31m*************************************************************\033[0m");
                    printf("\n\t\t\t\t\033[1;35m*\033[0m                                                           \033[1;35m*\033[0m");
                    printf("\n\t\t\t\t\033[1;35m*\033[0m               Press \033[1;31m'ENTER'\033[0m || Back to \033[1;36m'MENU'\033[0m             \033[1;35m*\033[0m");
                    printf("\n\t\t\t\t\033[1;35m*************************************************************\033[0m");
                    getch();
                    break;
                case 6:
                    system("CLS");
                    sendMoney(phoneNumber);
                    printf("\n\n\n\n\t\t\t\t\033[1;35m*************************************************************\033[0m");
                    printf("\n\t\t\t\t\033[1;35m*\033[0m                                                           \033[1;35m*\033[0m");
                    printf("\n\t\t\t\t\033[1;35m*\033[0m               Press \033[1;31m'ENTER'\033[0m || Back to \033[1;36m'MENU'\033[0m             \033[1;35m*\033[0m");
                    printf("\n\t\t\t\t\033[1;35m*************************************************************\033[0m");
                    getch();
                    break;
                case 7:
                    system("CLS");
                    transactionDetails(phoneNumber);
                    printf("\n\n\n\n\t\t\t\t\033[1;35m*************************************************************\033[0m");
                    printf("\n\t\t\t\t\033[1;35m*\033[0m                                                           \033[1;35m*\033[0m");
                    printf("\n\t\t\t\t\033[1;35m*\033[0m               Press \033[1;31m'ENTER'\033[0m || Back to \033[1;36m'MENU'\033[0m             \033[1;35m*\033[0m");
                    printf("\n\t\t\t\t\033[1;35m*************************************************************\033[0m");
                    getch();
                    break;
                case 8:
                    system("CLS");
                    printf("\n\t\t\t\t\033[1;35m*\033[0m                   8. HELP                                 \033[1;35m*\033[0m");
                    break;
                case 9:
                    system("CLS");
                    printf("\n\n\n\n\t\t\t\t\033[1;35m*************************************************************\033[0m");
                    printf("\n\t\t\t\t\033[1;35m|\033[0m                     Logging Out User...                   \033[1;35m|\033[0m");
                    printf("\n\t\t\t\t\033[1;35m|\033[0m                                                           \033[1;35m|\033[0m");
                    printf("\n\t\t\t\t\033[1;35m|\033[0m                  'LOGGED OUT SUCCeSSFULL'                 \033[1;35m|\033[0m");
                    printf("\n\t\t\t\t\033[1;35m*************************************************************\033[0m");
                    break;
                default:
                    system("CLS");
                    printf("\n\t\t\t\t\033[1;31m|   Invalid choice. Please try again.\033[0m\n");
                    break;
            }
        } while (choice != 9);
    } else {
        printf("\n\t\t\t\t\033[1;31m* | Invalid phone number or password. Please try again.\033[0m\n");
    }
}

void checkBalance(const char* phoneNumber) {
    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].phoneNumber, phoneNumber) == 0) {
            printf("\n\t\t\t\t\t\t  \033[1;35m __________________________\033[0m");
            printf("\n\t\t\t\t\t\t  \033[1;35m|\033[0m \033[1;45m\tBalance: %.2lf\033[0m     \033[1;35m|\033[0m", accounts[i].balance);
            printf("\n\t\t\t\t\t\t  \033[1;35m|__________________________|\033[0m");
            return;
        }
    }

    printf("\n\t\t\t\t\033[1;31m*\t\t| Account not found.\n");
}

void cashIn(const char* phoneNumber) {
    double amount;
    printf("\n\t\t\t\t*\t\t| Enter amount to cash in\t\t: ");
    scanf("%lf", &amount);

    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].phoneNumber, phoneNumber) == 0) {
            accounts[i].balance += amount;
            printf("\n\t\t\t\t\033[1;32m*| Cash in successful. New balance\t: %.2lf\033[0m\n", accounts[i].balance);
            saveAccountsToFile();
            return;
        }
    }

    printf("\n\t\t\t\t\033[1;31m*\t\t| Account not found.\033[0m\n");
}

void cashOut(const char* phoneNumber) {
    double amount;
    printf("\n\t\t\t\t*\t\t| Enter amount to cash out\t\t: ");
    scanf("%lf", &amount);

    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].phoneNumber, phoneNumber) == 0) {
            if (amount <= accounts[i].balance) {
                accounts[i].balance -= amount;
                printf("\n\t\t\t\t\033[1;32m*| Cash out successful. New balance\t: %.2lf\033[0m\n", accounts[i].balance);
                saveAccountsToFile();
                return;
            } else {
                printf("\n\t\t\t\t\033[1;31m*\t\t| Insufficient balance.\033[0m\n");
                return;
            }
        }
    }

    printf("\n\t\t\t\t\033[1;31m*\t\t| Account not found.\033[0m\n");
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
        printf("\n\t\t\t\t\033[1;31m*\t\t| Sender account not found.\033[0m\n");
        return;
    }

    if (receiverIndex == -1) {
        printf("\n\t\t\t\t\033[1;31m*\t\t| Receiver account not found.\033[0m\n");
        return;
    }

     if (amount <= accounts[senderIndex].balance) {
        accounts[senderIndex].balance -= amount;
        accounts[receiverIndex].balance += amount;

        // Record the transaction in the sender's account
        strcpy(accounts[senderIndex].transactions[accounts[senderIndex].numTransactions].senderPhoneNumber, senderPhoneNumber);
        strcpy(accounts[senderIndex].transactions[accounts[senderIndex].numTransactions].receiverPhoneNumber, receiverPhoneNumber);
        accounts[senderIndex].transactions[accounts[senderIndex].numTransactions].amount = amount;
        accounts[senderIndex].numTransactions++;

        // Record the transaction in the receiver's account
        strcpy(accounts[receiverIndex].transactions[accounts[receiverIndex].numTransactions].senderPhoneNumber, senderPhoneNumber);
        strcpy(accounts[receiverIndex].transactions[accounts[receiverIndex].numTransactions].receiverPhoneNumber, receiverPhoneNumber);
        accounts[receiverIndex].transactions[accounts[receiverIndex].numTransactions].amount = amount;
        accounts[receiverIndex].numTransactions++;

        printf("\n\t\t\t\t\033[1;32m*\t\t| Money sent successfully.\033[0m\n");
        saveAccountsToFile();
    } else {
        printf("\n\t\t\t\t\033[1;31m*\t\t| Insufficient balance.\033[0m\n");
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
            printf("\n\t\t\t\t\t\t| Transaction History:\n");

            for (int j = 0; j < accounts[i].numTransactions; j++) {
                printf("\n\t\t\t\t\t\t| Sender: %s\n", accounts[i].transactions[j].senderPhoneNumber);
                printf("\n\t\t\t\t\t\t| Receiver: %s\n", accounts[i].transactions[j].receiverPhoneNumber);
                printf("\n\t\t\t\t\t\t| Amount: %.2lf\n", accounts[i].transactions[j].amount);
                printf("\n\t\t\t\t\t\t| ----------------------------------------\n");
            }

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\n\t\t\t\t\033[1;31m*\t\t| Account not found.\033[0m\n");
    }
}
