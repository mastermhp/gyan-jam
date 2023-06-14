#ifndef BOOK_H
#define BOOK_H

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100

struct Book_info {
    int id;
    char name[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int quantity;
    int price;
    int rack;
};

void addBook();
void viewBook();
void searchBook();
void editBook();
void deleteBook();
void help();

#endif  // BOOK_H
