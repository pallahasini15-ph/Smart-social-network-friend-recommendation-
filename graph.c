#include <stdio.h>
#include <stdlib.h>
#include "social_network.h"

void addEdgeOneWay(int u, int v) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) { printf("Memory allocation failed.\n"); return; }
    newNode->userIndex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

int areFriends(int u, int v) {
    Node *p = adj[u];
    while (p != NULL) {
        if (p->userIndex == v) return 1;
        p = p->next;
    }
    return 0;
}

void addFriendship(void) {
    int id1, id2;
    printf("Enter first user ID: "); scanf("%d", &id1);
    printf("Enter second user ID: "); scanf("%d", &id2);

    int u = findUserIndex(id1), v = findUserIndex(id2);
    if (u == -1 || v == -1) { printf("One or both users do not exist.\n"); return; }
    if (u == v) { printf("A user cannot be friends with themselves.\n"); return; }
    if (areFriends(u, v)) { printf("They are already friends.\n"); return; }

    addEdgeOneWay(u, v);
    addEdgeOneWay(v, u);
    printf("Friendship added: %s <-> %s\n", users[u].name, users[v].name);
}

void displayFriends(void) {
    int id;
    printf("Enter User ID: "); scanf("%d", &id);
    int u = findUserIndex(id);
    if (u == -1) { printf("User not found.\n"); return; }

    printf("\nFriends of %s:\n", users[u].name);
    Node *p = adj[u];
    if (p == NULL) { printf("No friends.\n"); return; }

    while (p != NULL) {
        printf("- %s (ID: %d)\n", users[p->userIndex].name,
               users[p->userIndex].id);
        p = p->next;
    }
}

void displayGraph(void) {
    if (userCount == 0) { printf("Graph is empty.\n"); return; }

    printf("\n========== SOCIAL NETWORK GRAPH ==========\n");
    for (int i = 0; i < userCount; i++) {
        printf("%s -> ", users[i].name);
        Node *p = adj[i];

        if (p == NULL) printf("NULL");
        while (p != NULL) {
            printf("%s", users[p->userIndex].name);
            p = p->next;
            if (p != NULL) printf(" -> ");
        }
        printf("\n");
    }
}

void freeMemory(void) {
    for (int i = 0; i < userCount; i++) {
        Node *p = adj[i];
        while (p != NULL) {
            Node *temp = p;
            p = p->next;
            free(temp);
        }
        adj[i] = NULL;
    }
}