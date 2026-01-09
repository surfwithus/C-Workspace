#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
int main(void) {
    int id, score;
    char name[20];

    id = 101; strcpy(name, "Bob Kim"); score = 88;
    hash_insert(id, name, score);
    id = 1021; strcpy(name, "Tom Cruise"); score = 78;
    hash_insert(id, name, score);
    id = 1012; strcpy(name, "Taylor Swift"); score = 58;
    hash_insert(id, name, score);
    id = 1011; strcpy(name, "Milli Vanilli"); score = 18;
    hash_insert(id, name, score);
    id = 2033; strcpy(name, "G Dragon"); score = 98;
    hash_insert(id, name, score);
    id = 1033; strcpy(name, "Aimyon"); score = 92;
    hash_insert(id, name, score);

    struct student *s = hash_search(1011);
    if (s)
        printf("Found: %d %s %d\n", s->id, s->name, s->score);
    else
        printf("Not Found.\n");

    s = hash_search(3011);
    if (s)
        printf("Found: %d %s %d\n", s->id, s->name, s->score);
    else
        printf("Not Found.\n");

    hash_print_all();

    hash_free_all();

    return 0;
}