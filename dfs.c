#include <stdio.h>
#include "social_network.h"

static void dfsRecursive(int u, int visited[]) {
    visited[u] = 1;
    printf("%s", users[u].name);

    Node *p = adj[u];
    while (p != NULL) {
        int v = p->userIndex;
        if (!visited[v]) {
            printf(" -> ");
            dfsRecursive(v, visited);
        }
        p = p->next;
    }
}

void dfs(void) {
    int id;
    printf("Enter starting User ID: "); scanf("%d", &id);
    int start = findUserIndex(id);
    if (start == -1) { printf("User not found.\n"); return; }

    int visited[MAX_USERS] = {0};
    printf("\nDFS Traversal: ");
    dfsRecursive(start, visited);
    printf("\n");
}