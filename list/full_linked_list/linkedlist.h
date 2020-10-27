#include <stdio.h>
#include <stdlib.h>

#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

struct Node {
    int data;
    struct Node *next;
};

//adiciona um elemento no inicio da lista 
//retornar 0 se nao foi possivel alocar memoria; retornar 1 se conseguiu adicionar elemento
int add_first(struct Node **head, int value);

//adiciona um elemento no final da lista
void add_last(struct Node **head, int value);

//remove o primeiro node da lista
//retornar 0 se a lista for null; retornar 1 se conseguiu remover
int remove_first(struct Node **head);

//remove o ultimo node da lista
//retornar 0 se a lista for null; retornar 1 se conseguiu remover
int remove_last(struct Node **head);

//dado uma lista e um valor para pesquisar, exibir uma mensagem se o valor se encontra ou nao na lista
void search(struct Node *head, int value);

//retorna o tamanho da lista
int length(struct Node *head);

//exibe os elementos
void print(struct Node *head);

//exibe os n primeiros elementos
void print_nth_elements(struct Node *head, int n);

#endif