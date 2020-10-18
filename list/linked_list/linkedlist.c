#include "linkedlist.h"


int init_ll(struct node **head, int data) {
    (*head) = (struct node *)malloc(sizeof(struct node));

    if (*head == NULL) {
        printf("init_ll - HEAD IS NULL\n");
        return 0;
    }

    (*head)->data = data;
    (*head)->next = NULL;

    return 1;
}


void print_ll(struct node *head) {
    int count=0;
    struct node *temp;

    temp = head;

	while (temp != NULL) {
        count++;
		printf("data: %d\n",temp->data);

		temp = temp->next;
	}

    printf("\n");
}


int insert_front_ll(struct node **head, int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL) {
		printf("temp IS NULL\n");
		return 0;
    }
	
	temp->data = data;

	temp->next = *head;

	*head = temp;

    return 1;
}


int remove_item_ll(struct node *head, int key) {
    if (head == NULL) {
        printf("remove_item_ll - HEAD IS NULl.\n");
        return 0;
    }

    struct node *temp;
    struct node *prev;

    temp = head;
    prev = NULL;

    // percorre ate achar key e remove a key
    while ((temp-> data != key) && (temp->next != NULL)) {
        prev = temp;
        temp = temp->next;
    }

	prev->next = temp->next;

	free(temp);
	temp = NULL;

    return 1;
}

