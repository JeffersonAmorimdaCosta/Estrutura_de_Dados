#include <stdio.h>
#include "funcoes.h"

int main(void){ // Testes:

    orderQueue pedido;
    paymentQueue pagamento;
    collectQueue coletar;

    start_queue(&pedido, &pagamento, &coletar);

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

    if (remove_orderQueue(&pedido, &pagamento)){
        printf("Removido da lista de pedido com sucesso\n");
    }

    printf("Lista de pedido:\n");
    display_order(&pedido);

    printf("Lista de pagamento:\n");
    display_payment(&pagamento);

    if (remove_paymentQueue(&pagamento, &coletar)){
        printf("Removido da lista de pagamento com sucesso\n");
    }

    printf("Lista de pagamento:\n");
    display_payment(&pagamento);

    printf("Lista de coletagem:\n");
    display_collect(&coletar);

    char nome[50];

    if (remove_collectQueue(&coletar, nome)){
        printf("O %s finalizou seu processo de compra.\n", nome);
    }

    printf("Lista de pedido:\n");
    display_order(&pedido);

    printf("Lista de pagamento:\n");
    display_payment(&pagamento);

    printf("Lista de coletagem:\n");
    display_collect(&coletar);

    return 0;
}