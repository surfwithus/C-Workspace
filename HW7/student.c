#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

struct student* create_student(int id, const char* name, int score) {
    struct student *s = malloc(sizeof(struct student));
    // implement this section
    if (!s) return NULL;

    s->id = id;
    strncpy(s->name, name, 19);
    s->name[19] = '\0';
    s->score = score;
    s->next = NULL;

    return s;
}

// Insert by sorted ID
void insert_sorted(struct student **head, struct student *newNode) {
    if (*head == NULL || (*head)->id > newNode->id) {
        // implement this section
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct student *cur = *head;
    while (cur->next != NULL && cur->next->id < newNode->id) {
        // implement this section
        cur = cur->next;
    }
    // implement this section
    newNode->next = cur->next;
    cur->next = newNode;
}

struct student* search_student(struct student *head, int id) {
    struct student *cur = head;
    while (cur != NULL) {
        // implement this section
        if (cur->id == id) return cur;
        cur = cur->next;
    }
    return NULL;
}

int delete_student(struct student **head, int id) {
    if (*head == NULL) return 0;

    struct student *cur = *head;

    if (cur->id == id) {
        *head = cur->next;
        free(cur);
        return 1;
    }

    struct student *prev = cur;
    cur = cur->next;

    while (cur != NULL) {
        if (cur->id == id) {
            prev->next = cur->next;
            free(cur);
            return 1;
        }
        prev = cur;
        cur = cur->next;
    }

    return 0;
}

void print_list(struct student *head) {
    struct student *cur = head;
    while (cur != NULL) {
        // implement this section
        printf("(%d, %s, %d) -> ", cur->id, cur->name, cur->score);
        cur = cur->next;
    }
    printf("NULL");
}

void free_list(struct student *head) {
    struct student *cur;
    while (head != NULL) {
        // implement this section
        cur = head;
        head = head->next;
        free(cur);
    }
}