#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

const int PORT = 8080;

void notifyUser(struct User u) {
    int socket_desc;
    struct sockaddr_in server;
    char *message, server_reply[50];

    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        puts("connect error");
    }

    puts("Connected\n");

    message = u.name;
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        puts("Send failed");
    }
    puts("Data Send\n");
}

void handleNotification(void * t) {
    int sock, new_sock;
    struct sockaddr_in server, client;
    char buffer[50];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        puts("\nbind failed\n");
    } else {
        puts("\nbind done");
    }

    listen(sock, 3);

    puts("\nWaiting for incoming connections...\n");

    socklen_t clilen = sizeof(client);
    if (new_sock = accept(sock, (struct sockaddr *)&client, &clilen) < 0) {
        puts("\naccept failed\n");
    }
    if (recv(new_sock, buffer, strlen(buffer), 0) < 0) {
        puts("recv failed");
    }
    printf("buffer is %s", buffer);
}