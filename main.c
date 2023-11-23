#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include <dos.h>
#include "loginxbanking.h"

void heading(){
    printf("\n\n");
    printf("\n\t\t\t\t\033[1;35m**\033[0m \033[1;05mGYAN JAM\033[0m \033[1;35m************************************************\033[0m\n\n");
    printf("\n\n\n\n\n");
}

void clearLine() {
    printf("\033[2K\r"); // Clear the entire line and move the cursor to the beginning
}

void moveCursorLeft(int n) {
    printf("\033[%dD", n); // Move the cursor n positions to the left
}

void moveCursorRight(int n) {
    printf("\033[%dC", n); // Move the cursor n positions to the right
}

int getTerminalWidth() {
    char* columns = getenv("COLUMNS");
    if (columns != NULL) {
        return atoi(columns);
    } else {
        return 125; // Default to 125 columns if COLUMNS environment variable is not set
    }
}

void advancedProgressBar(int totalIterations, int currentIteration, int barWidth, int terminalWidth) {
    float progress = (float)currentIteration / (float)totalIterations;
    int filledWidth = progress * barWidth;
    int emptyWidth = barWidth - filledWidth;
    int percentage = (int)(progress * 100);

    int spacesBefore = (terminalWidth - barWidth - 12) / 2; // Calculate number of spaces before the progress bar
    int spacesAfter = terminalWidth - barWidth - spacesBefore - 12; // Calculate number of spaces after the progress bar

    clearLine();
    for (int i = 0; i < spacesBefore; ++i) {
        printf(" ");
    }
    printf(" [");
    for (int i = 0; i < filledWidth; ++i) {
        printf("\033[1;35m#\033[0m");
    }
    for (int i = 0; i < emptyWidth; ++i) {
        printf("\033[1;32m-\033[0m");
    }
    printf("]");
    for (int i = 0; i < spacesAfter; ++i) {
        printf(" ");
    }
    moveCursorLeft(terminalWidth - 90); // Move the cursor to the loading percentage position
    printf("\033[1;35m%3d%%\033[0m", percentage);
    fflush(stdout);
}


void delay(int seconds) {
     // Delay function implementation
    time_t start_time = time(NULL);
    while (time(NULL) - start_time < seconds) {
        // Wait until the specified number of seconds has elapsed
    }
    Sleep(seconds * 1000);
}

void displayImage() {
    system("CLS");
    system("color 0b");
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
    heading();
    //Loading Bar
    int totalIterations = 100;
    int barWidth = 40;

    int terminalWidth = getTerminalWidth();

    int spacesBefore = (terminalWidth - barWidth - 12) / 2; // Calculate number of spaces before the progress bar
    int spacesAfter = terminalWidth - barWidth - spacesBefore - 12; // Calculate number of spaces after the progress bar

    for (int i = 0; i < spacesBefore; ++i) {
        printf(" ");
    }
    printf("Progress: [                    ]   0%%");
    fflush(stdout);

    for (int i = 0; i <= totalIterations; ++i) {
        advancedProgressBar(totalIterations, i, barWidth, terminalWidth);
        usleep(100000);  // Sleep for 100 milliseconds
    }

    system("CLS");
    heading();
    printf("\t\t\t\t\033[1;35m*************************************************************\033[0m");
    printf("\n\t\t\t\t\033[1;35m*                                                           *\033[0m");
    printf("\n\t\t\t\t\033[1;35m*                                                           *\033[0m");
    printf("\n\t\t\t\t\033[1;35m*\033[0m                 \033[1;32mProject Loading Complete\033[0m                  \033[1;35m*\033[0m");
    printf("\n\t\t\t\t\033[1;35m*                                                           *\033[0m");
    printf("\n\t\t\t\t\033[1;35m*                                                           *\033[0m");
    sleep(1);
    printf("\n\t\t\t\t\033[1;35m*************************************************************\033[0m");
    printf("\n\t\t\t\t\033[1;35m*                                                           *\033[0m");
    printf("\n\t\t\t\t\033[1;35m*\033[0m               Press \033[1;31m'ENTER'\033[0m || Back to \033[1;36m'LOGIN'\033[0m            \033[1;35m*\033[0m");
    printf("\n\t\t\t\t\033[1;35m*************************************************************\033[0m");
    getch();

    displayImage();
    delay(3); // Delay for 3 seconds

    loadAccountsFromFile();

    int choice;
    do {
        system("CLS");
        heading();
        printf("\t\t\t\t\033[1;35m******************\033[0m  AUTHENTICATION MENU  \033[1;35m********************\033[0m");
        printf("\n\t\t\t\t\033[1;35m*\033[0m                                                           \033[1;35m*\033[0m");
        printf("\n\t\t\t\t\033[1;35m*\033[0m                       1. SIGN UP                          \033[1;35m*\033[0m");
        printf("\n\t\t\t\t\033[1;35m*\033[0m                       2.\033[1;46m  LOG IN  \033[0m                        \033[1;35m*\033[0m");
        printf("\n\t\t\t\t\033[1;35m*\033[0m                       3.\033[1;41m   EXIT   \033[0m                        \033[1;35m*\033[0m");
        printf("\n\t\t\t\t\033[1;35m*\033[0m                                                           \033[1;35m*\033[0m");
        printf("\n\t\t\t\t\033[1;35m*************************************************************\033[0m");
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
                printf("\n\n\n\n\t\t\t\t\033[1;35m*************************************************************\033[0m");
                printf("\n\t\t\t\t\033[1;35m|\033[0m                         Exiting....                       \033[1;35m|\033[0m");
                printf("\n\t\t\t\t\033[1;35m|                                                           |\033[0m");
                printf("\n\t\t\t\t\033[1;35m|\033[0m              \033[1;45m'STAY CONNECTED' | 'THANK YOU'.\033[0m              \033[1;35m|\033[0m");
                printf("\n\t\t\t\t\033[1;35m*************************************************************\033[0m\n\n\n\n\n\n\n\n\n\n\n\n");
                break;
            default:
                printf("\n\t\t\t\t\033[1;31m | Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 3);

    return 0;
}
