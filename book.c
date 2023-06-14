#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"

void addBook()
{
    struct Book_info book;
    system("CLS");
    int count = 0;
    FILE *bookFile = fopen("book.dat", "ab");
    if (bookFile == NULL)
    {
        printf("\n\t\t\t\t |Error in opening file.");
        return;
    }
    // Add book logic
    printf("\n\t\t\t\t************************  ADD BOOK  *************************");
    printf("\n\t\t\t\t*                                                           *");
    printf("\n\t\t\t\t*                                                           *");
    printf("\n\t\t\t\t* | Enter Book ID\t\t:\t ");
    scanf("%d", &book.id);
    printf("\t\t\t\t* | Enter Book Name\t\t:\t ");
    scanf("%s", book.name);
    printf("\t\t\t\t* | Enter Author Name\t\t:\t ");
    scanf("%s", book.author);
    printf("\t\t\t\t* | Enter Quantity\t\t:\t ");
    scanf("%d", &book.quantity);
    printf("\t\t\t\t* | Enter Price\t\t\t:\t ");
    scanf("%d", &book.price);
    printf("\t\t\t\t* | Enter Rack Number\t\t:\t ");
    scanf("%d", &book.rack);
    fwrite(&book, sizeof(struct Book_info), 1, bookFile);
    fclose(bookFile);
    printf("\t\t\t\t*************************************************************");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t*************************************************************");
    printf("\n\t\t\t\t*                                                           *");
    printf("\n\t\t\t\t*                | Book added successfully.                 *");
    printf("\n\t\t\t\t*               Press 'ENTER' || Back to Menu               *");
    printf("\n\t\t\t\t*************************************************************");
    getch();
}

void viewBook()
{
    struct Book_info book;
    system("CLS");
    int count = 0;
    FILE *bookFile = fopen("book.dat", "rb");
    if (bookFile == NULL)
    {
        printf("\n\t\t\t\t |Error in opening file.");
        return;
    }
    // View book logic
    printf("\n\t\t\t\t**********************  VIEW BOOKS  *************************\n");
    printf("\n\n\n\t\t--------------------------------------------------------------------------------------");
    printf("\n\t\t|   ID |           Book Name |              Author |  Quantity |   Price |  Rack No. |");
    printf("\n\t\t--------------------------------------------------------------------------------------");
    while (fread(&book, sizeof(struct Book_info), 1, bookFile) > 0)
    {
        printf("\n\t\t| %4d | %19s | %19s | %9d | %7d | %9d |", book.id, book.name, book.author, book.quantity, book.price, book.rack);
        count++;
    }
    printf("\n\t\t--------------------------------------------------------------------------------------");
    fclose(bookFile);
    if (count == 0)
    {
        printf("\n\t\t\t\t*************************************************************");
        printf("\n\t\t\t\t*                                                           *");
        printf("\n\t\t\t\t*                    Book not found!                        *");
        printf("\n\t\t\t\t*************************************************************");
    }
    printf("\n\n\n\n\n\n\n\n\t\t\t\t*************************************************************");
    printf("\n\t\t\t\t*                                                           *");
    printf("\n\t\t\t\t*               Press 'ENTER' || Back to Menu               *");
    printf("\n\t\t\t\t*************************************************************");
    getch();
}

void searchBook()
{
    struct Book_info book;
    system("CLS");
    char name[MAX_TITLE_LENGTH];
    int flag = 0;
    FILE *bookFile = fopen("book.dat", "rb");
    if (bookFile == NULL)
    {
        printf("\n\t\t\t\t |Error in opening file.");
        return;
    }
    // Search book logic
    printf("\n\t\t\t\t**********************  SEARCH BOOK  ***********************");
    printf("\n\t\t\t\t*                                                          *");
    printf("\n\t\t\t\t* |Enter Book Name to search  :  ");
    scanf("%s", name);
    printf("\n\n\n\t\t--------------------------------------------------------------------------------------");
    printf("\n\t\t|   ID |           Book Name |              Author |  Quantity |   Price |  Rack No. |");
    printf("\n\t\t--------------------------------------------------------------------------------------");
    while (fread(&book, sizeof(struct Book_info), 1, bookFile) > 0)
    {
        if (strcmp(name, book.name) == 0)
        {
            printf("\n\t\t| %4d | %19s | %19s | %9d | %7d | %9d |", book.id, book.name, book.author, book.quantity, book.price, book.rack);
            flag = 1;
            break;
        }
    }
    printf("\n\t\t--------------------------------------------------------------------------------------");
    fclose(bookFile);
    if (flag == 0)
    {
        printf("\n\n\n\n\n\n\n\n\t\t\t\t*************************************************************");
        printf("\n\t\t\t\t*                                                           *");
        printf("\n\t\t\t\t*                    Book not found!                        *");
        printf("\n\t\t\t\t*************************************************************");
    }
    printf("\n\t\t\t\t*************************************************************");
    printf("\n\t\t\t\t*                                                           *");
    printf("\n\t\t\t\t*               Press 'ENTER' || Back to Menu               *");
    printf("\n\t\t\t\t*************************************************************");
    getch();
}

void editBook()
{
    struct Book_info book;
    system("CLS");
    int id, found = 0;
    FILE *bookFile;
    // Edit book logic
    printf("\n\t\t\t\t*************************  EDIT BOOK  ***********************");
    printf("\n\t\t\t\t*                                                           *");
    printf("\n\t\t\t\t* |Enter Book ID to edit\t:\t ");
    scanf("%d", &id);
    printf("\t\t\t\t*                                                           *");
    printf("\n\t\t\t\t*************************************************************");
    bookFile = fopen("book.dat", "r+b");
    if (bookFile == NULL)
    {
        printf("\n\t\t\t\t |Error in opening file.");
        return;
    }
    while (fread(&book, sizeof(struct Book_info), 1, bookFile) > 0 && found == 0)
    {
        if (id == book.id)
        {
            found = 1;
            printf("\n\t\t\t\t* | Enter New Book Name\t\t:\t ");
            scanf("%s", book.name);
            printf("\t\t\t\t* | Enter New Author Name\t:\t ");
            scanf("%s", book.author);
            printf("\t\t\t\t* | Enter New Quantity\t\t:\t ");
            scanf("%d", &book.quantity);
            printf("\t\t\t\t* | Enter New Price\t\t:\t ");
            scanf("%d", &book.price);
            printf("\t\t\t\t* | Enter New Rack Number\t:\t ");
            scanf("%d", &book.rack);

            fseek(bookFile, ftell(bookFile) - sizeof(struct Book_info), 0);
            fwrite(&book, sizeof(struct Book_info), 1, bookFile);
            fclose(bookFile);
            printf("\n\t\t\t\t*************************************************************");
            printf("\n\t\t\t\t*                                                           *");
            printf("\n\t\t\t\t*                 Book edited successfully.                 *");
            printf("\n\t\t\t\t*************************************************************");
            printf("\n\n\n\n\n\n\n\n\t\t\t\t*************************************************************");
            printf("\n\t\t\t\t*                                                           *");
            printf("\n\t\t\t\t*               Press 'ENTER' || Back to Menu               *");
            printf("\n\t\t\t\t*************************************************************");
            getch();
        }
    }
    if (found == 0)
    {
        printf("\n\t\t\t\t*************************************************************");
        printf("\n\t\t\t\t*                    Book not found!                        *");
        fclose(bookFile);
        printf("\n\t\t\t\t*************************************************************");
        printf("\n\t\t\t\t*                                                           *");
        printf("\n\t\t\t\t*               Press 'ENTER' || Back to Menu               *");
        printf("\n\t\t\t\t*************************************************************");
        getch();
    }
}

void deleteBook()
{
    struct Book_info book;
    system("CLS");
    int id, found = 0;
    FILE *bookFile, *temp;
    printf("\n\t\t\t\t************************  DELETE BOOK  **********************");
    printf("\n\t\t\t\t*                                                           *");
    printf("\n\t\t\t\t* |Enter Book ID to delete\t:\t");
    scanf("%d", &id);
    printf("\t\t\t\t*                                                           *");
    printf("\n\t\t\t\t*************************************************************");
    bookFile = fopen("book.dat", "rb");
    if (bookFile == NULL)
    {
        printf("\n\t\t\t\t |Error in opening file.");
        return;
    }
    temp = fopen("temp.dat", "wb");
    if (temp == NULL)
    {
        printf("\n\t\t\t\t |Error in opening file.");
        return;
    }
    while (fread(&book, sizeof(struct Book_info), 1, bookFile) > 0)
    {
        if (id != book.id)
        {
            fwrite(&book, sizeof(struct Book_info), 1, temp);
        }
        else
        {
            found = 1;
        }
    }
    fclose(bookFile);
    fclose(temp);
    if (found == 0)
    {
        printf("\n\n\n\n\n\n\n\n\t\t\t\t*************************************************************");
        printf("\n\t\t\t\t*                                                           *");
        printf("\n\t\t\t\t*                    Book not found!                        *");
        printf("\n\t\t\t\t*************************************************************");
        remove("temp.dat");
    }
    else
    {
        remove("book.dat");
        rename("temp.dat", "book.dat");
        printf("\n\n\n\n\n\n\n\n\t\t\t\t*************************************************************");
        printf("\n\t\t\t\t*                                                           *");
        printf("\n\t\t\t\t*               |Book deleted successfully.                 *");
    }
    printf("\n\t\t\t\t*************************************************************");
    printf("\n\t\t\t\t*                                                           *");
    printf("\n\t\t\t\t*               Press 'ENTER' || Back to Menu               *");
    printf("\n\t\t\t\t*************************************************************");
    getch();
}

void help()
{
    system("CLS");
    printf("\n\t\t\t\t*************************************************************");
    printf("\n\t\t\t\t*                          HELP MENU                         *");
    printf("\n\t\t\t\t*************************************************************");
    printf("\n\t\t\t\t*                                                           *");
    printf("\n\t\t\t\t*  addBook()   : Add a new book to the collection.          *");
    printf("\n\t\t\t\t*  viewBook()  : View details of a specific book.           *");
    printf("\n\t\t\t\t*  searchBook(): Search for a book by title or author.      *");
    printf("\n\t\t\t\t*  editBook()  : Edit the details of a book.                *");
    printf("\n\t\t\t\t*  deleteBook(): Delete a book from the collection.         *");
    printf("\n\t\t\t\t*  help()      : Display this help menu.                    *");
    printf("\n\t\t\t\t*                                                           *");
    printf("\n\t\t\t\t*************************************************************");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t*************************************************************");
    printf("\n\t\t\t\t*                                                           *");
    printf("\n\t\t\t\t*               Press 'ENTER' || Back to Menu               *");
    printf("\n\t\t\t\t*************************************************************");
    getch();
}


