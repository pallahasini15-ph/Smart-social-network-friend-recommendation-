#include <stdio.h>
#include "social_network.h"

int countMutualFriends(int u, int candidate) {
    int count = 0;
    Node *p = adj[u];
    while (p != NULL) {
        if (areFriends(p->userIndex, candidate)) count++;
        p = p->next;
    }
    return count;
}

void mutualFriends(void) {
    int id1, id2;
    printf("Enter first User ID: "); scanf("%d", &id1);
    printf("Enter second User ID: "); scanf("%d", &id2);

    int u = findUserIndex(id1), v = findUserIndex(id2);
    if (u == -1 || v == -1) { printf("One or both users do not exist.\n"); return; }

    int count = 0;
    printf("\nMutual Friends of %s and %s:\n", users[u].name, users[v].name);

    Node *p = adj[u];
    while (p != NULL) {
        if (areFriends(p->userIndex, v)) {
            printf("- %s\n", users[p->userIndex].name);
            count++;
        }
        p = p->next;
    }

    if (count == 0) printf("No mutual friends.\n");
    printf("Total Mutual Friends = %d\n", count);
}

void recommendFriends(void) {
    int id;
    printf("Enter User ID for recommendations: "); scanf("%d", &id);
    int u = findUserIndex(id);
    if (u == -1) { printf("User not found.\n"); return; }

    Recommendation rec[MAX_USERS];
    int count = 0;

    for (int i = 0; i < userCount; i++) {
        if (i == u || areFriends(u, i)) continue;

        int mutual = countMutualFriends(u, i);
        if (mutual > 0) {
            int distance = socialDistance(u, i);
            rec[count].userIndex = i;
            rec[count].mutualCount = mutual;
            rec[count].distance = distance;
            rec[count].score = (mutual * 10) - distance;
            count++;
        }
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (rec[j].score > rec[i].score) {
                Recommendation temp = rec[i];
                rec[i] = rec[j];
                rec[j] = temp;
            }
        }
    }

    printf("\n========== FRIEND RECOMMENDATIONS ==========\n");
    if (count == 0) { printf("No recommendations available.\n"); return; }

    printf("%-20s %-15s %-15s %-10s\n",
           "User", "Mutual Friends", "Distance", "Score");

    for (int i = 0; i < count; i++) {
        int v = rec[i].userIndex;
        printf("%-20s %-15d %-15d %-10d\n",
               users[v].name, rec[i].mutualCount,
               rec[i].distance, rec[i].score);
    }
}