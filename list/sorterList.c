#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
	int data;
	struct node *next;
} List;

List *push(int data, List *list) {
	List *new;
    List *p, *pR;

	new = (List *)malloc(sizeof(List));
	new->data = data;
    new->next = NULL;

    if (!list) 
        return new;

    for (pR = NULL, p = list; p ; pR = p, p = p->next) {
        if (data < p->data)
            break;
    }

    if (!pR) {
        new->next = p;
        return new;
    }
    else if (p == NULL)
        pR->next = new;

    else {
        pR->next = new;
        new->next = p;
    }	
	return list;
}

void show(List *list) {
    List *p;
    if (!list) {
        printf("empty.\n");
        return;
    }
    
    for (p = list; p; p = p->next)
        printf("%d  ", p->data);
    printf("\n");
}

int counter(List *list) {
    List *p;
    int total = 0;
    for (p = list; p; p = p->next, total++);

    return total;
}

List *generate(List *list, int size) {
    srand(time(NULL));
    int i;
    for (i = 0; i < size; i++ )
        list = push((60 + rand() % 300), list);

    return list;
}

float avg(List *list) {
    int size = counter(list);
    if (size == 0)
        return 0;

    int sum = 0;
    List *p;

    for (p = list; p ; p = p->next)
        sum = sum + p->data;
    
    return sum / size;
}

int smaller(List *list) {
    if (!list)
        return -1;

    return list->data;
}

int bigger(List *list) {
    if (!list)
        return -1;
    List *p;
    for (p = list; p->next ; p = p->next);

    return p->data;
}

int main() {
	List *list = NULL;

    list = generate(list,8);
    printf("the list contains: %d numbers\n", counter(list));
    show(list);

    printf("the average is: %.2f\n", avg(list));
    printf("the bigger is: %d\n", bigger(list));
    printf("the smaller is: %d\n", smaller(list));

	return 1;
}
