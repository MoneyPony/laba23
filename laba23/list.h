#pragma once
#ifndef _LIST_H
#define _LIST_H

struct listitem {
    int number;
    char name[80];
    struct listitem* next;
};

typedef struct listitem* List;

void initlist(List* lst) {
    *lst = NULL;
}

void insertfront(List* lst, int val) {
    struct listitem* newNode = (struct listitem*)malloc(sizeof(struct listitem));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newNode->number = val;
    newNode->next = *lst;
    *lst = newNode;
}

void insertback(List* lst, int val) {
    struct listitem* newNode = (struct listitem*)malloc(sizeof(struct listitem));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newNode->number = val;
    newNode->next = NULL;

    if (*lst == NULL) {
        *lst = newNode;
    }
    else {
        struct listitem* current = *lst;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void insertfrontStr(List* lst, char* str) {
    struct listitem* newNode = (struct listitem*)malloc(sizeof(struct listitem));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    strncpy(newNode->name, str, sizeof(newNode->name));
    newNode->next = *lst;
    *lst = newNode;
}

void insertbackStr(List* lst, char* str) {
    struct listitem* newNode = (struct listitem*)malloc(sizeof(struct listitem));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    strncpy(newNode->name, str, sizeof(newNode->name));
    newNode->next = NULL;

    if (*lst == NULL) {
        *lst = newNode;
    }
    else {
        struct listitem* current = *lst;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

bool isempty(List* lst) {
    return *lst == NULL;
}

int length(List lst) {
    int count = 0;
    struct listitem* current = lst;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

void destroyItem(List* lst, struct listitem* node) {
    if (*lst == node) {
        *lst = node->next;
        free(node);
    }
    else {
        struct listitem* current = *lst;
        while (current != NULL && current->next != node) {
            current = current->next;
        }

        if (current != NULL) {
            current->next = node->next;
            free(node);
        }
    }
}

struct listitem* getitem(List lst, int n) {
    struct listitem* current = lst;

    while (current != NULL && current->number != n) {
        current = current->next;
    }

    return current;
}

struct listitem* getitemStr(List lst, char* str) {
    struct listitem* current = lst;

    while (current != NULL && strcmp(current->name, str) != 0) {
        current = current->next;
    }

    return current;
}
#endif