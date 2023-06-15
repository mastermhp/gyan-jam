#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "loginxbanking.h"

void delay(int seconds) {
     // Delay function implementation
    time_t start_time = time(NULL);
    while (time(NULL) - start_time < seconds) {
        // Wait until the specified number of seconds has elapsed
    }
    Sleep(seconds * 1000);
}

void displayImage() {
    FILE *file = fopen("ascimg.txt", "r");

    if (file != NULL) {
        char ch;
        while ((ch = fgetc(file)) != EOF) {
            putchar(ch);
        }

        fclose(file);
    } else {
        printf("Unable to open the file.");
    }

     printf("\n\n");
}



int main(void) {
    system("color 0b");
    loadAccountsFromFile();

    displayImage();
    delay(3); // Delay for 3 seconds

    int choice;
    do {
        system("CLS");
        printf("\n\t\t\t\t** GYAN JAM  ************************************************\n\n");
        printf("\n\n\t\t\t\t******************  AUTHENTICATION MENU  ********************");
        printf("\n\t\t\t\t*                                                           *");
        printf("\n\t\t\t\t*                       1. SIGN UP                          *");
        printf("\n\t\t\t\t*                       2. LOGIN                            *");
        printf("\n\t\t\t\t*                       3. EXIT                             *");
        printf("\n\t\t\t\t*                                                           *");
        printf("\n\t\t\t\t*************************************************************");
        printf("\n\t\t\t\t                   Enter Your Choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                system("CLS");
                signup();
                break;
            case 2:
                system("CLS");
                loginMenu();
                break;
            case 3:
                system("CLS");
                printf("\n\n\n\n\t\t\t\t*************************************************************");
                printf("\n\t\t\t\t|                         Exiting....                       |");
                printf("\n\t\t\t\t|                                                           |");
                printf("\n\t\t\t\t|              'STAY CONNECTED' | 'THANK YOU'.              |");
                printf("\n\t\t\t\t*************************************************************\n\n\n\n\n\n\n\n\n\n\n\n");
                break;
            default:
                printf("\n\t\t\t\t | Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 3);

    return 0;
}
