#include <stdio.h>

#define MAX 10
#define ERROR -1

typedef int KEY;

typedef struct{
    KEY key;
}DATA;

typedef struct{
    DATA data[MAX+1];
    int size;
}QUEUE;

void init(QUEUE *queue){
    int i = 0;
    for(i = 0; i < MAX - 2; i++)
        queue->data[i].key = i*2;
    
    queue->size = i;
}

void show(QUEUE *queue){
    int i = 0;
    printf("\nQueue: \n");
    for(i = 0; i < MAX - 2; i++){
        printf("[ %d ]", queue->data[i].key);
    }
    printf("\n");
}

int push(KEY key, QUEUE *queue){
    if(queue->size >= MAX)
        return 0;
    
    queue->data[queue->size].key = key;
    queue->size++;
    return 1;
}

int pop(QUEUE *queue){
    if(queue->size <= 0)
        return 0;
    
    int i = 1;
    for(i = 1; i < queue->size; i++)
        queue->data[i-1].key = queue->data[i].key;

    queue->size--;
    return 1;
}

int search(KEY key, QUEUE *queue){
    queue->data[queue->size].key = key;
    int i = 0;
    while (queue->data[i].key != key)
        i++;
    
    if(i >= queue->size)
        return ERROR;

    return i;
}

int main(){
    QUEUE queue;
    init(&queue);
    show(&queue);

    push(16, &queue);
    show(&queue);

    pop(&queue);
    show(&queue);

    printf("\nsearching key 10...\n");
    printf("key found in index %d of the queue.\n", search(10, &queue));
}