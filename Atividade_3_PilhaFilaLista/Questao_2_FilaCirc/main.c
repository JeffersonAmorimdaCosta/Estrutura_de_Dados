#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "filaseqcirc.h"

int main(void) {
    FilaSeqCir f;
    int valorRetirado, primeiroValor, ultimoValor, elemento;
    short opcao;
    criarFila(&f);

    while(true) {
        system("cls");
        printf("Fila Circular\n\n");
        printf("1 - Enfileirar\n");
        printf("2 - Desenfileirar\n");
        printf("3 - Primeiro elemento\n");
        printf("4 - Ultimo elemento\n");
        printf("5 - Exibir fila\n");
        printf("6 - Encerrar programa\n\n");
        printf("Opcao desejada: ");
        scanf("%hd", &opcao);

        switch(opcao) {
            case 1:
                printf("\nElemento a ser inserido: ");
                scanf("%d", &elemento);
                if(entrar(&f, elemento) == 1) {
                    printf("\nElemento inserido com sucesso!\n");
                }
                else {
                    printf("Fila cheia ou erro na insercao.\n");
                }
                break;
            case 2:
                if(sair(&f, &valorRetirado) == 1)
                    printf("\nO elemento %d foi retirado da fila.\n", valorRetirado);
                else
                    printf("Fila vazia ou erro na remocao!\n");
                break;
            case 3:
                if(primeiro(&f, &primeiroValor) == 1)
                    printf("\n\nO primeiro valor na sua fila e: %d\n", primeiroValor);
                else
                    printf("Sua fila esta vazia");
                break;
            case 4:
                if(ultimo(&f, &ultimoValor) == 1)
                    printf("\n\nO ultimo valor na sua fila e: %d\n", ultimoValor);
                else
                    printf("Sua fila esta vazia\n");
                break;
            case 5:
                printf("\n");
                printf("[");
                exibir(&f);
                printf("]\n");
                break;
            case 6:
                printf("Programa encerrado pelo usuario.\n");
                exit(0);
            default:
                printf("Insira uma opcao entre 1 e 6.\n");               
        }
        printf("Aperte ENTER para voltar ao menu.");
        while(getchar() != '\n');
        getchar();
    }
    
    return 0;
}