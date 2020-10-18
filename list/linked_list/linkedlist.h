#include <stdio.h>
#include <stdlib.h>


#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__


struct node {
    int data;
    struct node *next;
};


int init_ll(struct node **head, int data);

void print_ll(struct node *head);

int insert_front_ll(struct node **head, int data);

int remove_item_ll(struct node *head, int key);



#endif
