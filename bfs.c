#include <stdio.h>
#include "social_network.h"

void bfs(void) {
    int id;
    printf("Enter starting User ID: "); scanf("%d", &id);
    int start = findUserIndex(id);
    if (start == -1) { printf("User not found.\n"); return; }

    int visited[MAX_USERS] = {0}, queue[MAX_USERS];
    int front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;

    printf("\nBFS Traversal: ");
    while (front < rear) {
        int u = queue[front++];
        printf("%s", users[u].name);

        Node *p = adj[u];
        while (p != NULL) {
            int v = p->userIndex;
            if (!visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
            p = p->next;
        }
        if (front < rear) printf(" -> ");
    }
    printf("\n");
}

int socialDistance(int start, int target) {
    int visited[MAX_USERS] = {0}, distance[MAX_USERS];
    int queue[MAX_USERS], front = 0, rear = 0;

    for (int i = 0; i < MAX_USERS; i++) distance[i] = -1;

    queue[rear++] = start;
    visited[start] = 1;
    distance[start] = 0;

    while (front < rear) {
        int u = queue[front++];
        if (u == target) return distance[u];

        Node *p = adj[u];
        while (p != NULL) {
            int v = p->userIndex;
            if (!visited[v]) {
                visited[v] = 1;
                distance[v] = distance[u] + 1;
                queue[rear++] = v;
            }
            p = p->next;
        }
    }
    return -1;
}

void findSocialDistance(void) {
    int id1, id2;
    printf("Enter first User ID: "); scanf("%d", &id1);
    printf("Enter second User ID: "); scanf("%d", &id2);

    int u = findUserIndex(id1), v = findUserIndex(id2);
    if (u == -1 || v == -1) { printf("One or both users do not exist.\n"); return; }

    int distance = socialDistance(u, v);
    if (distance == -1)
        printf("No connection exists between the users.\n");
    else
        printf("Social Distance between %s and %s = %d\n",
               users[u].name, users[v].name, distance);
}