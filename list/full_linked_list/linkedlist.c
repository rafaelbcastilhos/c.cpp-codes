#include "linkedlist.h"

int add_first(struct Node **head, int value){
    struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
	
	if(temp == NULL)
		return 0;
	
	temp->data = value;	
	temp->next = (*head);
	(*head) = temp;

    return 1;	
}

void add_last(struct Node **head, int value){
    struct Node *aux;
    struct Node *temp = (struct Node *) malloc(sizeof(struct Node));

    temp->data = value;
    temp->next = NULL;

    if(*head == NULL)
        *head = temp;

    else{
        aux = *head;
        while(aux->next != NULL)
            aux = aux->next;

        aux->next = temp;
    }
}

int remove_first(struct Node **head){
    struct Node *temp;

    if (*head == NULL)
		return 0;

    temp = *head;
    *head = temp->next;

    free(temp);
    return 1;
}

int remove_last(struct Node **head){
    struct Node *temp, *aux;

    if(*head == NULL)
        return 0;

    if((*head)->next == NULL){
        *head = NULL;
        temp = *head;
    }

    else{
        aux = *head;
        while(aux->next->next != NULL)
            aux = aux->next;

        temp = aux->next;
        aux->next = NULL;
    }

    free(temp);
    return 1;
}

void search(struct Node *head, int value){
    int aux = 0;
	struct Node *temp = head;

    for(temp = head; temp != NULL; temp = temp->next){
        if(temp->data == value){
            aux = 1;
            printf("\nvalor %d está na lista!\n", value);
        }
    }

    if(aux == 0)
        printf("\nvalor %d não está na lista!\n", value);
}

int length(struct Node *head){
    int count = 0;
    struct Node *temp = head;

    while(temp != NULL){
        count++;
        temp = temp->next;
    }

    return count;
}

void print(struct Node *head){
	struct Node *temp = head;
	
    printf("\nelementos:\n");
    while (temp != NULL) {
        printf("%d ", temp->data); 
        temp = temp->next;
	}
}

void print_nth_elements(struct Node *head, int n){
    int count = 0;
	struct Node *temp = head;

    printf("\nprimeiros %d elementos:\n", n);
    if(n <= length(head)){
        while(count < n){
            printf("%d ", temp->data); 
            temp = temp->next;
            count++;
        }
    }

    else
        printf("\nlista não possui %d elementos\n", n);
}