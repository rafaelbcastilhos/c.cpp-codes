#include <stdio.h>
#include <stdlib.h>

#ifndef __ABB_H__
#define __ABB_H__

struct BstNode {
    int data;
    struct BstNode *left;
    struct BstNode *right;
};

struct BstNode *add_no(struct BstNode *raiz, int valor);

struct BstNode *remove_no(struct BstNode *raiz, int valor);

int buscar(struct BstNode *raiz, int valor);

int qtde_nos(struct BstNode *raiz);

int maior(struct BstNode *raiz);

int menor(struct BstNode *raiz);

void print_infixa(struct BstNode *raiz);

void print_preordem(struct BstNode *raiz);

void print_posordem(struct BstNode *raiz);

#endif
