#include <stdio.h>
#include "funcoes.h"

int main(void){ // Testes:

    orderQueue pedido;
    paymentQueue pagamento;
    collectQueue coletar;

    pedido.head = NULL;
    pedido.end = NULL;

    pagamento.head = NULL;
    pagamento.end = NULL;

    coletar.head = NULL;
    coletar.end = NULL;

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

    display_order(&pedido);

    if (remove_orderQueue(&pedido, &pagamento)){
        printf("Removido da lista de pedido com sucesso\n");
    }

    printf("Lista de pedido:\n");
    display_order(&pedido);

    printf("Lista de pagamento:\n");
    display_payment(&pagamento);

    return 0;
}