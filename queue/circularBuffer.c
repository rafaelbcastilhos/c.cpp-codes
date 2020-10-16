#include <stdio.h>
#include <stdlib.h>

typedef int KEY;

typedef struct TEMP{
    KEY key;
    struct TEMP *next;
}NODE, *POINTER;

typedef struct{
    POINTER head;
}QUEUE;

void init(QUEUE *queue){
    queue->head = (POINTER)malloc(sizeof(NODE));
    queue->head->next = queue->head;
}

POINTER search(KEY key, QUEUE queue, POINTER* prev){
    *prev = queue.head;

    POINTER pos = queue.head->next;
    queue.head->key = key;
    while(pos->key != key){
        *prev = pos;
        pos = pos->next;
    }
    if(pos != queue.head)
        return pos;
    else
        return NULL;
}

POINTER head(QUEUE queue){
    POINTER head = queue.head->next;
    return head->key;
}

int pop(KEY key, QUEUE *queue){
    POINTER temp, prev;
    temp = search(key, *queue, &prev);
    if(temp == NULL)
        return 0;
    prev->next = temp->next;
    free(temp);
    return 1;
}

void push(KEY key, QUEUE *queue){
    POINTER prev = queue->head;
    POINTER pos = queue->head->next;

    while(pos->key < key && pos != queue->head){
        prev = pos;
        pos = pos->next;
    }
    
    POINTER newNode = (POINTER) malloc(sizeof(NODE));
    newNode->key = key;
    newNode->next = pos;
    prev->next = newNode;
}

POINTER show(QUEUE queue){
    POINTER pos = queue.head->next;
    while(pos != queue.head){
        printf("[%d]->", pos->key);
        pos = pos->next;
    }
    printf("\n");
}

int main(){
    QUEUE queue;

    init(&queue);
	push(0, &queue);
	push(1, &queue);
	push(2, &queue);
	push(3, &queue);
	push(4, &queue);
	push(5, &queue);
	show(queue);

	pop(0, &queue);
	show(queue);

	pop(2, &queue);
	show(queue);

	pop(4, &queue);
	show(queue);

    POINTER temp;
    int value = 1;
    if(search(value, queue, &temp) != NULL)
        printf("key %d found.\n", value);
    else
        printf("key %d not found...\n", value);
    
    return 0;
}