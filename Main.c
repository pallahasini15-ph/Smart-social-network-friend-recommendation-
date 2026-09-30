#include <stdio.h>
#include "social_network.h"

void displayMenu(void) {
    printf("\n\n==============================================\n");
    printf("       SMART SOCIAL NETWORK SYSTEM\n");
    printf("       FRIEND RECOMMENDATION PROJECT\n");
    printf("==============================================\n");
    printf("1. Register User\n");
    printf("2. Display Users\n");
    printf("3. Add Friendship\n");
    printf("4. Display Friend List\n");
    printf("5. Display Graph\n");
    printf("6. BFS Traversal\n");
    printf("7. DFS Traversal\n");
    printf("8. Find Social Distance\n");
    printf("9. Find Mutual Friends\n");
    printf("10. Recommend Friends\n");
    printf("11. Save Data\n");
    printf("12. Exit\n");
    printf("==============================================\n");
    printf("Enter your choice: ");
}

int main(void) {
    int choice;
    loadData();

    printf("Welcome to Smart Social Network!\n");

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: registerUser(); break;
            case 2: displayUsers(); break;
            case 3: addFriendship(); break;
            case 4: displayFriends(); break;
            case 5: displayGraph(); break;
            case 6: bfs(); break;
            case 7: dfs(); break;
            case 8: findSocialDistance(); break;
            case 9: mutualFriends(); break;
            case 10: recommendFriends(); break;
            case 11: saveData(); break;
            case 12:
                saveData();
                freeMemory();
                printf("Thank you for using Smart Social Network!\n");
                break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 12);

    return 0;
}