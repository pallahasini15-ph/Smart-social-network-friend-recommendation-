#ifndef SOCIAL_NETWORK_H
#define SOCIAL_NETWORK_H

#define MAX_USERS 100
#define NAME_LEN 50

typedef struct User { int id; char name[NAME_LEN]; } User;
typedef struct Node { int userIndex; struct Node *next; } Node;
typedef struct Recommendation {
    int userIndex, mutualCount, distance, score;
} Recommendation;

extern User users[MAX_USERS];
extern Node *adj[MAX_USERS];
extern int userCount;

int findUserIndex(int id);
void registerUser(void);
void displayUsers(void);
int areFriends(int u, int v);
void addEdgeOneWay(int u, int v);
void addFriendship(void);
void displayFriends(void);
void displayGraph(void);
void bfs(void);
void dfs(void);
int socialDistance(int start, int target);
void findSocialDistance(void);
int countMutualFriends(int u, int candidate);
void mutualFriends(void);
void recommendFriends(void);
void saveData(void);
void loadData(void);
void freeMemory(void);
void displayMenu(void);

#endif