#include <stdio.h>
#include <stdlib.h>
#include "static_queue.h"

void init(queue_t *q){
    q->data = malloc(sizeof(int)*MAX);

	if(q->data == NULL)
		return;

    q->front = 0;
    q->rear = -1;
}

void insert(queue_t *q){
    int item;
    if(q->rear == MAX - 1)
        printf("Queue Overflow \n");

    else {
        if(q->front== - 1)
            q->front = 0;
        printf("Insert the element in queue : ");
        scanf("%d", &item);
        q->rear = q->rear + 1;
        q->data[q->rear] = item;
    }
}

void delete(queue_t *q){
    if(q->front == - 1 || q->front > q->rear){
        printf("Queue Underflow \n");
        return;
    }

    else{
        printf("Element deleted from queue is : %d\n", q->data[q->front]);
        q->front++;
    }
}

void display(queue_t *q){
    int i;
    if(q->front == - 1)
        printf("Queue is empty \n");

    else{
        printf("Queue is : \n");
        for(i = q->front; i <= q->rear; i++)
            printf("%d ", q->data[i]);
        printf("\n");
    }
}