#include <stdio.h>
#include <stdlib.h>

struct Produto {
    char type;
    char description[50];
};

struct Hash {
    struct Produto produto;
    struct Hash *next;
};

int add(struct Hash **head);

void search(struct Hash *head);

void count(struct Hash *head);