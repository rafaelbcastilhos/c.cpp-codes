#include <stdio.h>
#include "abb.h"

struct BstNode *novo_no(int valor) {
    struct BstNode *temp = (struct BstNode *) malloc(sizeof(struct BstNode));
    temp->data = valor;
    temp->left = temp->right = NULL;
    return temp;
}

struct BstNode *add_no(struct BstNode *raiz, int valor) {
    if(raiz == NULL)
        return novo_no(valor);

    else if (valor <= raiz->data)
        raiz->left = add_no(raiz->left, valor);

    else
        raiz->right = add_no(raiz->right, valor);

    return raiz;
}

struct BstNode *acha_substituto(struct BstNode *raiz){
    while(raiz->left != NULL)
        raiz = raiz->left;
    return raiz;
}

struct BstNode *remove_no(struct BstNode *raiz, int valor) {
    if(raiz == NULL)
        return NULL;

    else if(valor < raiz->data)
        raiz->left = remove_no(raiz->left, valor);

    else if(valor > raiz->data)
        raiz->right = remove_no(raiz->right, valor);

    else {
        if(raiz->left == NULL && raiz->right == NULL) {
            free(raiz);
            raiz = NULL;
        }
        else if(raiz->left == NULL) {
            struct BstNode *temp = raiz;
            raiz = raiz->right;
            free(temp);
        }
        else if(raiz->right == NULL) {
            struct BstNode *temp = raiz;
            raiz = raiz->left;
            free(temp);
        }
        else {
            struct BstNode *temp = acha_substituto(raiz->right);
            raiz->data = temp->data;
            raiz->right = remove_no(raiz->right, temp->data);
        }
    }
    return raiz;
}

void print_infixa(struct BstNode *raiz) {
    if(raiz != NULL) {
        print_infixa(raiz->left);
        printf("%d ", raiz->data);
        print_infixa(raiz->right);
    }
}

void print_preordem(struct BstNode *raiz) {
    if(raiz != NULL) {
        printf("%d ", raiz->data);
        print_preordem(raiz->left);
        print_preordem(raiz->right);
    }
}

void print_posordem(struct BstNode *raiz) {
    if(raiz != NULL) {
        print_posordem(raiz->left);
        print_posordem(raiz->right);
        printf("%d ", raiz->data);
    }
}

int buscar(struct BstNode *raiz, int valor) {
    if(raiz != NULL){
        if(raiz->data == valor)
            return 1;
        if(raiz->data > valor)
            return buscar(raiz->left, valor);
        else
            return buscar(raiz->right, valor);
    }
    else
        return 0;
}

int qtde_nos(struct BstNode *raiz){
    if (raiz != NULL)
        return 1 + qtde_nos(raiz->left) + qtde_nos(raiz->right);
    return 0;
}

int maior(struct BstNode *raiz){
	if(raiz==NULL)
		return 0;

	while(raiz->right!=NULL)
		raiz = raiz->right;
	return raiz->data;
}

int menor(struct BstNode *raiz){
	if(raiz==NULL)
		return 0;

	while(raiz->left!=NULL)
		raiz = raiz->left;

	return raiz->data;
}
