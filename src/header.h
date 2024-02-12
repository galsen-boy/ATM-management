#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date {
    int month, day, year;
};

// all fields for each record of an account
struct Record {
    int id;
    int userId;
    char name[100];
    char country[100];
    int phone;
    char accountType[10];
    int accountNbr;
    double amount;
    struct Date deposit;
    struct Date withdraw;
};

struct User {
    int id;
    char name[50];
    char password[50];
};

// authentication functions
void loginMenu(char a[50], char pass[50]);
void registerMenu(int* id,char a[50], char pass[50]);
const char *getPassword(int* id, struct User u);

// system function
void createNewAccount(struct User u);
void mainMenu(struct User u, int doClear);
void checkAllAccounts(struct User u);
void CheckDetailsAccount(struct User u);
void removeAccount(struct User u);
void updateAccount(struct User u);
void makeTransaction(struct User u);
void transferAccount(struct User u);

// socket function
// void notifyUser(struct User u);
// void handleNotification(void * t);