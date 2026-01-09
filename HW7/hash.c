#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

struct student* table[TABLE_SIZE] = {NULL};

int hash(int id) {
    return id % TABLE_SIZE;
}

void hash_insert(int id, const char* name, int score) {
    int idx = hash(id);
    struct student *newNode = create_student(id, name, score);
    insert_sorted(&table[idx], newNode);
}

struct student* hash_search(int id) {
    int idx = hash(id);
    return search_student(table[idx], id);
}

int hash_delete(int id) {
    int idx = hash(id);
    return delete_student(&table[idx], id);
}

void hash_print_all() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d] -> ", i);
        print_list(table[i]);
        printf("\n");
    }
}

void hash_free_all() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        free_list(table[i]);
        table[i] = NULL;
    }
}
