#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "pilhaenc.h"

int main(){
    
    Stack pilha1, pilha2, pilha3;
    create(&pilha1); create(&pilha2); create(&pilha3);
    Stack *pilha_atual = &pilha1;
    int opc, valor, atual = 1;

    while (1){
        system("cls");
        printf("Editor de Pilha v1.0 | PILHA ATUAL: Pilha %d\n", atual);
        printf("==============================\n");
        printf("1 - Encerrar Programa\n2 - Empilhar\n3 - Desempilhar\n4 - Elemento do Topo\n5 - Imprimir Pilha\n6 - Inverter Elementos da Pilha\n7 - Esvaziar a Pilha\n8 - Mudar de Pilha\n\n");
        printf("Digite sua opcao: ");
        printf("\n");

        scanf("%d", &opc);

        switch (opc){

        case 1:
            printf("Encerrando o programa...\n");
            exit(1);
            break;
            
        case 2:
            printf("Digite o valor que deseja empilhar: \n");
            scanf("%d", &valor);
            
            if (stackUp(pilha_atual, valor)){
                printf("Elemento inserido com sucesso!\n");
            }
            else{
                printf("Erro na alocacao de memoria.\n");
                exit(1);
            }
            break;

        case 3:
            valor = unstack(pilha_atual);
            if (valor != INT_MIN){
                printf("O valor %d foi removido da pilha.\n", valor);
            }
            else{
                printf("Erro na remocao, a pilha esta vazia.\n");
            }
            break;

        case 4:
            if (sizeStack(pilha_atual) == 0){
                printf("Nao eh possivel exibir o elemento, porque a fila esta vazia.\n");
            }

            else{
                displayTop(pilha_atual);
            }
            break;

        case 5:
            if (sizeStack(pilha_atual) == 0){
                printf("Nao eh possivel imprimir a pilha, porque a fila esta vazia.\n");
            }

            else{
                display(pilha_atual);
            }
            break;

        case 6:
            if (reverse(pilha_atual)){
                printf("Inversao feita com sucesso!\n");
            }

            else{
                printf("Erro na inversao, a pilha esta vazia.\n");
            }
            break;

        case 7:
            printf("Voce tem certeza que quer esvaziar a pilha?\nDigite 1 para SIM e 0 para NAO\n");
            scanf("%d", &valor);

            if (valor == 1){
                toEmpty(pilha_atual);
                printf("Pilha esvaziada com sucesso!\n");
            }

            else{
                printf("Esvaziamento de pilha cancelado!\n");
            }
            break;
        
        case 8:
            printf("Pilha 1 - [1]\nPilha 2 - [2]\nPilha 3 - [3]\n\nSelecione a pilha que desesja manipular agora: ");
            
            while (1){
                scanf("%d", &valor);
                if (valor == 1){
                    pilha_atual = &pilha1;
                    break;
                }

                else if (valor == 2){
                    pilha_atual = &pilha2;
                    break;
                }

                else if (valor == 3){
                    pilha_atual = &pilha3;
                    break;
                }

                else{
                    printf("Opcao invalida! Tente novamente.\n");
                }
            }
            atual = valor;
            printf("Pilha alterada com sucesso!\n");
            break;
            
        default:
            printf("Opcao invalida!\n");
            break;
        }

        setbuf(stdin, NULL); 
        printf("Pressione ENTER para continuar!\n");
        getchar();
    }
    return 0;
}
