#include <stdio.h>
#include "funcoes.h"

int main(void){ // Testes:

    orderQueue pedido;

    pedido.head = NULL;
    pedido.end = NULL;

    if (insert_orderQueue(&pedido, "Jefferson")){
        printf("Adicionado com sucesso\n");
    }

    else{
        printf("Deu erro\n");
    }

    if (insert_orderQueue(&pedido, "Pedro")){
        printf("Adicionado com sucesso\n");
    }

    else{
        printf("Deu erro\n");
    }

    if (insert_orderQueue(&pedido, "Felipe")){
        printf("Adicionado com sucesso\n");
    }

    else{
        printf("Deu erro\n");
    }

    if (insert_orderQueue(&pedido, "Jose")){
        printf("Adicionado com sucesso\n");
    }

    else{
        printf("Deu erro\n");
    }

    display(&pedido);

    return 0;
}