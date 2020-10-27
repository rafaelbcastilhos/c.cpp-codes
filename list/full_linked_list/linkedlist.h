#include <stdio.h>
#include <stdlib.h>

#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

struct Node {
    int data;
    struct Node *next;
};

int add_first(struct Node **head, int value);

void add_last(struct Node **head, int value);

int remove_first(struct Node **head);

int remove_last(struct Node **head);

void search(struct Node *head, int value);

int length(struct Node *head);

void print(struct Node *head);

void print_nth_elements(struct Node *head, int n);

#endif
