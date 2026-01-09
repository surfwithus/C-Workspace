#ifndef HASH_H
#define HASH_H

#include "student.h"
#define TABLE_SIZE 10

extern struct student* table[TABLE_SIZE];
int hash(int id);
void hash_insert(int id, const char* name, int score);
struct student* hash_search(int id);
int hash_delete(int id);
void hash_print_all();
void hash_free_all();
#endif !HASH_H