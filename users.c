#include <stdio.h>
#include <string.h>
#include "social_network.h"

User users[MAX_USERS];
Node *adj[MAX_USERS] = {NULL};
int userCount = 0;

int findUserIndex(int id) {
    for (int i = 0; i < userCount; i++)
        if (users[i].id == id) return i;
    return -1;
}

void registerUser(void) {
    if (userCount >= MAX_USERS) { printf("User limit reached.\n"); return; }

    int id;
    char name[NAME_LEN];

    printf("Enter User ID: ");
    scanf("%d", &id);

    if (findUserIndex(id) != -1) {
        printf("User ID already exists.\n");
        return;
    }

    printf("Enter User Name: ");
    scanf(" %49[^\n]", name);

    users[userCount].id = id;
    strcpy(users[userCount].name, name);
    adj[userCount] = NULL;
    userCount++;

    printf("User registered successfully.\n");
}

void displayUsers(void) {
    if (userCount == 0) { printf("No users registered.\n"); return; }

    printf("\n----- Registered Users -----\n");
    printf("%-10s %-30s\n", "ID", "Name");
    for (int i = 0; i < userCount; i++)
        printf("%-10d %-30s\n", users[i].id, users[i].name);
}