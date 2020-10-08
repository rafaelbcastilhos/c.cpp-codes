#include <stdio.h>
#include <stdlib.h>
#include "static_queue.h"

int main() {
    int choice;
    queue_t q;

    init(&q);

    while (1) {
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                insert(&q);
                break;
            case 2:
                delete(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                exit(1);
            default:
                printf("Wrong choice \n");
        }
    }
}
