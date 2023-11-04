#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funcoes.h"

int main(void){ // Testes:

    orderQueue pedido;
    paymentQueue pagamento;
    collectQueue coletar;
    char nome[30], pessoa_coleta[30];
    short opcao;

    start_queue(&pedido, &pagamento, &coletar);

    while(true) {
        printf("Restaurante Rei do Mocoto - Fila inteligente\n");
        printf("--------------------------------------------\n");
        printf("1 - Inserir cliente na fila de pedido\n");
        printf("2 - Remover cliente da fila de pedido\n");
        printf("3 - Remover cliente da fila de pagamento\n");
        printf("4 - Remover cliente da fila de encomenda\n\n");
        printf("Opcao desejada: ");
        scanf("%hd", &opcao);
        switch(opcao){
            case 1:
                printf("Nome do cliente a ser inserido: ");
                scanf("%s", nome);
                if(insert_orderQueue(&pedido, nome) == 1) {
                    printf("Cliente inserido com sucesso na fila.\n");
                }
                else{
                    printf("Houve um problema na insercao do cliente, tente novamente.\n");
                }
                break;
            case 2:
                if(remove_orderQueue(&pedido, &pagamento) == 1) {
                    printf("Cliente na primeira posicao da fila de pedido foi inserido na fila de pagamento\n");
                }
                else{
                    printf("Nao há clientes na fila de pedidos\n");
                }
                break;
            case 3:
                if(remove_paymentQueue(&pagamento, &coletar) == 1) {
                    printf("Cliente na primeira posicao da fila de pagamento foi inserido na fila para encomenda\n");
                }
                else{
                    printf("Nao ha pessoas na fila de pagamento\n");
                }
                break;
            case 4:
                if(remove_collectQueue(&coletar, pessoa_coleta) == 1) {
                    printf("Cliente '%s' da fila de encomenda pode retirar seu pedido!\n", pessoa_coleta);
                }
                else{
                    printf("Nao ha pessoas na fila de encomenda.\n");
                }
                break;
            default:
                printf("Encerrando programa.");
                exit(0);                
        }
        printf("Aperte ENTER para voltar ao menu.");
        while(getchar() != '\n');
        getchar();        
    }

    return 0;
}