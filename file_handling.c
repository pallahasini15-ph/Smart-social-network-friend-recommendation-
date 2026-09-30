#include <stdio.h>
#include <string.h>
#include "social_network.h"

void saveData(void) {
    FILE *fp = fopen("users.txt", "w");
    if (fp == NULL) { printf("Unable to open users.txt\n"); return; }

    for (int i = 0; i < userCount; i++)
        fprintf(fp, "%d|%s\n", users[i].id, users[i].name);
    fclose(fp);

    fp = fopen("friendships.txt", "w");
    if (fp == NULL) { printf("Unable to open friendships.txt\n"); return; }

    for (int i = 0; i < userCount; i++) {
        Node *p = adj[i];
        while (p != NULL) {
            if (i < p->userIndex)
                fprintf(fp, "%d %d\n", users[i].id, users[p->userIndex].id);
            p = p->next;
        }
    }
    fclose(fp);
    printf("Data saved successfully.\n");
}

void loadData(void) {
    FILE *fp = fopen("users.txt", "r");
    if (fp == NULL) return;

    char line[200];
    while (fgets(line, sizeof(line), fp) != NULL && userCount < MAX_USERS) {
        int id;
        char name[NAME_LEN];
        if (sscanf(line, "%d|%49[^\n]", &id, name) == 2) {
            users[userCount].id = id;
            strcpy(users[userCount].name, name);
            adj[userCount] = NULL;
            userCount++;
        }
    }
    fclose(fp);

    fp = fopen("friendships.txt", "r");
    if (fp == NULL) return;

    int id1, id2;
    while (fscanf(fp, "%d %d", &id1, &id2) == 2) {
        int u = findUserIndex(id1), v = findUserIndex(id2);
        if (u != -1 && v != -1 && !areFriends(u, v)) {
            addEdgeOneWay(u, v);
            addEdgeOneWay(v, u);
        }
    }
    fclose(fp);
}