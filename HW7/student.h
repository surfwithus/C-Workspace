#ifndef STUDENT_H
#define STUDENT_H

struct student {
    int id;
    char name[20];
    int score;
    struct student *next;
};

// Linked list operations
struct student* create_student(int id, const char* name, int score);
void insert_sorted(struct student **head, struct student *newNode);
struct student* search_student(struct student *head, int id);
int delete_student(struct student **head, int id);
void print_list(struct student *head);
void free_list(struct student *head);

#endif !STUDENT_H
