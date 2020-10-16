#include <stdio.h>
#include <stdlib.h>

typedef struct list* link;

typedef struct list{
    int data;
    link next;
}List;

List* init();
List* push(List *list, int data);
void show(List *l);
int empty(List *l);
List* search(List* list, int data);

List* init(){
    return NULL;
}

List* push(List* list, int data){
    List* new = (List*) malloc(sizeof (list));
    new->data = data;
    new->next = list;
    return new;
}

void show(List *l){
  List *temp;
    for(temp = l; temp != NULL; temp = temp->next)
        printf("|%d|-->", temp ->data);
    
    printf("| NULL | \n");
}

int empty(List *list){
    return list == NULL;
}

List* search(List* list, int data){
    List* temp;
    for(temp = list; temp != NULL; temp = temp->next){
        if(temp->data == data)
        return temp;
    }
    return NULL;
}
int main(){
    List *p; int num;
    
    p = init();
    show(p);
    p = push(p, 1);
    show(p);
    p = push(p, 2);
    show(p);
    p = push(p, 3);
    show(p);
    p = push(p, 4);
    show(p);
    p = push(p, 5);
    show(p);

    printf("\nenter a number to search in the list: "); 
    scanf("%d", &num);
    
    if(search(p, num))
        printf("\nfound %d!\n", num);    

    else printf("\nnot found %d!\n", num);
    
    return 0;
}