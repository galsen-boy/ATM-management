#include <pthread.h>

#include "header.h"

void mainMenu(struct User u, int doClear) {
    int option;
    if (doClear == 1) {
        system("clear");
    }
    // pthread_t t;
    // pthread_create(&t, NULL, handleNotification, (void *)&t);

    printf("\n\n\t\t======= ATM =======\n\n");
    printf("\n\t\t-->> Feel free to choose one of the options below <<--\n");
    printf("\n\t\t[1]- Create a new account\n");
    printf("\n\t\t[2]- Update account information\n");
    printf("\n\t\t[3]- Check accounts\n");
    printf("\n\t\t[4]- Check list of owned account\n");
    printf("\n\t\t[5]- Make Transaction\n");
    printf("\n\t\t[6]- Remove existing account\n");
    printf("\n\t\t[7]- Transfer ownership\n");
    printf("\n\t\t[8]- Exit\n");
    scanf("%d", &option);

    switch (option) {
        case 1:
            createNewAccount(u);
            break;
        case 2:
            updateAccount(u);
            break;
        case 3:
            CheckDetailsAccount(u);
            break;
        case 4:
            checkAllAccounts(u);
            break;
        case 5:
            makeTransaction(u);
            break;
        case 6:
            removeAccount(u);
            break;
        case 7:
            transferAccount(u);
            break;
        case 8:
            exit(1);
            break;
        default:
            printf("Invalid operation!\n");
    }
};

void initMenu(struct User *u) {
    int r = 0;
    int option;
    system("clear");
    printf("\n\n\t\t======= ATM =======\n");
    printf("\n\t\t-->> Feel free to login / register :\n");
    printf("\n\t\t[1]- login\n");
    printf("\n\t\t[2]- register\n");
    printf("\n\t\t[3]- exit\n");
    while (!r) {
        scanf("%d", &option);
        switch (option) {
            case 1:
                loginMenu(u->name, u->password);
                if (strcmp(u->password, getPassword(&u->id, *u)) == 0) {
                    printf("\n\nPassword Match!");
                } else {
                    printf("\nWrong password!! or User Name\n");
                    exit(1);
                }
                r = 1;
                break;
            case 2:
                registerMenu(&u->id, u->name, u->password);
                r = 1;
                break;
            case 3:
                exit(1);
                break;
            default:
                printf("Insert a valid operation!\n");
        }
    }
};

int main() {
    struct User u;

    initMenu(&u);
    mainMenu(u, 1);
    return 0;
}
