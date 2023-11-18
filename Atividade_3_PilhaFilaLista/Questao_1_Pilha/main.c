#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "pilhaenc.h"

int main(){
    
    Stack pilha;
    int opc, valor;

    while (1){
        system("cls");
        printf("Editor de Pilha v1.0\n");
        printf("==============================\n");
        printf("0 - Encerrar Programa\n1 - Inicializar\n2 - Empilhar\n3 - Desempilhar\n4 - Elemento do Topo\n5 - Imprimir Pilha\n6 - Inverter Elementos da Pilha\n7 - Esvaziar a Pilha\n8 - Mudar de Pilha\n\n");
        printf("Digite sua opcao: ");
        printf("\n");

        scanf("%d", &opc);

        switch (opc)
        {
        case 0:
            printf("Encerrando o programa...\n");
            exit(1);
            break;

        case 1:
            create(&pilha);
            printf("Pilha criada com sucesso!\n");
            break;

        case 2:
            printf("Digite o valor que deseja empilhar: \n");
            scanf("%d", &valor);
            
            if (stackUp(&pilha, valor)){
                printf("Elemento inserido com sucesso!\n");
            }
            else{
                printf("Erro na alocacao de memoria.\n");
                exit(1);
            }
            break;

        case 3:
            valor = unstack(&pilha);
            if (valor != INT_MIN){
                printf("O valor %d foi removido da pilha.\n", valor);
            }
            else{
                printf("Erro na remocao, a pilha esta vazia.\n");
            }
            break;

        case 4:
            if (sizeStack(&pilha) == 0){
                printf("Nao eh possivel exibir o elemento, porque a fila esta vazia.\n");
            }

            else{
                displayTop(&pilha);
            }
            break;

        case 5:
            if (sizeStack(&pilha) == 0){
                printf("Nao eh possivel imprimir a pilha, porque a fila esta vazia.\n");
            }

            else{
                display(&pilha);
            }
            break;

        case 6:
            if (reverse(&pilha)){
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
                toEmpty(&pilha);
                printf("Pilha esvaziada com sucesso!\n");
            }

            else{
                printf("Esvaziamento de pilha cancelado!\n");
            }
            break;
        
        case 8:
            // Falta fazer!
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
