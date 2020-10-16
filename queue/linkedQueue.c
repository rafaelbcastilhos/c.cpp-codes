#include <stdio.h>

typedef int KEY;

typedef struct NODE{
	KEY key;
	struct NODE* next;
}*POINTER;

POINTER newNode(KEY key){
    POINTER temp = (POINTER) malloc(sizeof(key));
	temp->key = key;
	temp->next  = NULL;
	return temp;
}

POINTER push(KEY key, POINTER node){
    POINTER temp = newNode(key);
    temp->next = node;
    return temp;
}

void show(POINTER node){
    while(node != NULL){
        printf("[%d]->", node->key);
        node = node->next; 
    }
    printf("\n");
}

void pop(POINTER node){
    POINTER noAnterior = node;
    while(node->next != NULL){
        noAnterior = node;
        node = node->next;
    }
    noAnterior->next = NULL;
    free(node);
}

int size(POINTER node){
    int count = 0;
    while(node != NULL){
        count++;
        node = node->next;
    }
    return count;
}

int main(){
    printf("\nadd 3 values:\n");
    POINTER queue = newNode(0);
    queue = push(1, queue);
    queue = push(2, queue);

    printf("show:\n");
    show(queue);
    printf("queue size: %d\n\n", size(queue));

    queue = push(3, queue);
    queue = push(4, queue);
    queue = push(5, queue);

    printf("show:\n");
    show(queue);
    printf("queue size: %d\n\n", size(queue));

    pop(queue);
    show(queue);

    pop(queue);
    show(queue);

    pop(queue);
    show(queue);

    printf("queue size: %d\n\n", size(queue));
    return 0;
}