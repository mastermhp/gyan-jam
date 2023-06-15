#ifndef LOGINXBANKING_H
#define LOGINXBANKING_H

void saveAccountsToFile();
void loadAccountsFromFile();

void createAccount(const char* fullName, const char* email, const char* address, const char* phoneNumber, const char* password);
void promptSignupDetails(char* fullName, char* email, char* address, char* phoneNumber, char* password, char* confirmPassword);
void signup();

void promptLoginDetails(char* phoneNumber, char* password);
int login(const char* phoneNumber, const char* password);
void loginMenu();

void cashIn(const char* phoneNumber);
void cashOut(const char* phoneNumber);
void sendMoney(const char* senderPhoneNumber);
void transactionDetails(const char* phoneNumber);

#endif // BANKING_H

