#include <termios.h>

#include "header.h"

char *USERS = "./data/users.txt";

void loginMenu(char a[50], char pass[50]) {
    struct termios oflags, nflags;

    system("clear");
    printf("\n\n\n\t\t\t\t   Bank Management System\n\t\t\t\t\t User Login:");
    scanf("%s", a);

    tcgetattr(fileno(stdin), &oflags);
    nflags = oflags;
    nflags.c_lflag &= ~ECHO;
    nflags.c_lflag |= ECHONL;

    if (tcsetattr(fileno(stdin), TCSANOW, &nflags) != 0) {
        perror("tcsetattr");
        return exit(1);
    }
    printf("\n\n\n\n\n\t\t\t\tEnter the password to login:");
    scanf("%s", pass);

    // restore terminal
    if (tcsetattr(fileno(stdin), TCSANOW, &oflags) != 0) {
        perror("tcsetattr");
        return exit(1);
    }
};

const char *getPassword(int* id, struct User u) {
    FILE *fp;
    struct User userChecker;

    if ((fp = fopen(USERS, "r")) == NULL) {
        printf("❌ Error opening file\n");
        exit(1);
    }

    while (fscanf(fp, "%d %s %s", &userChecker.id, userChecker.name, userChecker.password) != EOF) {
        if (strcmp(userChecker.name, u.name) == 0) {
            fclose(fp);
            char *buff = userChecker.password;
            *id = userChecker.id;
            return buff;
        }
    }

    fclose(fp);
    return "no user found";
}

void registerMenu(int* id, char a[50], char pass[50]) {
    struct termios oflags, nflags;
    int lastId;
    char password[50];

    system("clear");
    printf("\n\n\n\t\t\t\t   Bank Management System\n\t\t\t\t\t User Login:");
    scanf("%s", a);

    tcgetattr(fileno(stdin), &oflags);
    nflags = oflags;
    nflags.c_lflag &= ~ECHO;
    nflags.c_lflag |= ECHONL;

    if (tcsetattr(fileno(stdin), TCSANOW, &nflags) != 0) {
        perror("tcsetattr");
        return exit(1);
    }

    printf("\n\n\n\n\n\t\t\t\tEnter the password to login:");
    scanf("%s", pass);

    if (tcsetattr(fileno(stdin), TCSANOW, &oflags) != 0) {
        perror("tcsetattr");
        return exit(1);
    }

    FILE *file;
    printf("Creating user...\n");
    if ((file = fopen(USERS, "a+")) == NULL) {
        printf("❌ Error opening file\n");
        return exit(1);
    }

    char userName[100];

    while (fscanf(file, "%d %s %s", &lastId, userName, password) != EOF) {
        if (strcmp(userName, a) == 0) {
            printf("❌ Error nickname already exists\n");
            return exit(1);
        }
    }

    lastId++;
    *id = lastId;

    fprintf(file, "%d %s %s\n", lastId, a, pass);
    fclose(file);
}
