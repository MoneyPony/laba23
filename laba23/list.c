#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"

int main() {
    List myList;
    initlist(&myList);

    int choice;
    do {
        printf("\n1. Insert Front (int)\n");
        printf("2. Insert Back (int)\n");
        printf("3. Insert Front (string)\n");
        printf("4. Insert Back (string)\n");
        printf("5. Check if the list is empty\n");
        printf("6. Get the length of the list\n");
        printf("7. Destroy an item\n");
        printf("8. Find item by number\n");
        printf("9. Find item by name\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter an integer to insert at the front: ");
            int intValue;
            scanf("%d", &intValue);
            insertfront(&myList, intValue);
            break;

        case 2:
            printf("Enter an integer to insert at the back: ");
            scanf("%d", &intValue);
            insertback(&myList, intValue);
            break;

        case 3:
            printf("Enter a string to insert at the front: ");
            char strValue[80];
            scanf("%s", strValue);
            insertfrontStr(&myList, strValue);
            break;

        case 4:
            printf("Enter a string to insert at the back: ");
            scanf("%s", strValue);
            insertbackStr(&myList, strValue);
            break;

        case 5:
            printf("Is the list empty? %s\n", isempty(&myList) ? "Yes" : "No");
            break;

        case 6:
            printf("Length of the list: %d\n", length(myList));
            break;

        case 7:
            printf("Enter a number to destroy from the list: ");
            int destroyValue;
            scanf("%d", &destroyValue);
            struct listitem* destroyNode = getitem(myList, destroyValue);
            if (destroyNode != NULL) {
                destroyItem(&myList, destroyNode);
                printf("Item destroyed.\n");
            }
            else {
                printf("Item not found.\n");
            }
            break;

        case 8:
            printf("Enter a number to find in the list: ");
            int findNumber;
            scanf("%d", &findNumber);
            struct listitem* foundNodeNumber = getitem(myList, findNumber);
            if (foundNodeNumber != NULL) {
                printf("Item found: %d\n", foundNodeNumber->number);
            }
            else {
                printf("Item not found.\n");
            }
            break;

        case 9:
            printf("Enter a name to find in the list: ");
            scanf("%s", strValue);
            struct listitem* foundNodeName = getitemStr(myList, strValue);
            if (foundNodeName != NULL) {
                printf("Item found: %s\n", foundNodeName->name);
            }
            else {
                printf("Item not found.\n");
            }
            break;

        case 0:
            // Free allocated memory before exiting
            while (myList != NULL) {
                struct listitem* temp = myList;
                myList = myList->next;
                free(temp);
            }
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice. Please enter a number between 0 and 9.\n");
        }

    } while (choice != 0);

    return 0;
}