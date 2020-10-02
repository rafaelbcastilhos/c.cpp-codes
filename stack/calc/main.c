#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

int main(void){
	stack_t st;
	int i, ans, aux, peek;

	st_init(&st, 5);

    do{
        ans = st_menu();
        switch(ans){
            case 1:
                aux = st_calculadora(&st);
                break;
            case 2:
                st_push(&st, aux);
                break;
            case 3:
                peek = st_peek(&st);
                printf("resultado anterior: %d\n", peek);
                break;
            case 4:
                while(!st_empty(&st)){
                    st_pop(&st, i);
                    printf("pop: X\n");
                }
                break;
            case 5:
                return -1;
        }
    }while(ans != 5);


	st_destroy(&st);

	return 0;
}
