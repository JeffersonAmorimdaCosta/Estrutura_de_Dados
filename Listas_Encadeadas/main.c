#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "listadinalu.c"

int main(void){ // Testes:
    StudentList alunos;
    short opcao, posicao;
    Student aluno;

    while(true) {
        system("cls");
        printf("Editor de lista encadeada - Atividade 1\n");
        printf("---------------------------------------\n");
        printf("0 - Encerrar programa\n");
        printf("1 - Criar lista\n");
        printf("2 - Verificação da lista (vazia)\n");
        printf("3 - Tamanho da lista\n");
        printf("4 - Obter dados pela posicao\n");
        printf("5 - Obter posição pela matricula\n");
        printf("6 - Inserir aluno no final da lista\n");
        printf("7 - Remover pela matricula\n");
        printf("8 - Exibicao dos dados\n");
        printf("9 - Inserir aluno na posição\n");
        printf("10 - Inserir aluno de forma crescente\n");
        printf("11 - Remover na posicaoo\n");
        printf("12 - Pesquisar pela matricula ou nome\n\n");
        printf("Escolha uma opcao: ");
        scanf("%hd", &opcao);

        switch(opcao) {
            case 0:
                printf("Programa encerrado pelo usuario.");
                exit(0);
            case 1:
                create(&alunos);
                break;
            case 2:
                if(empty(&alunos) == 1) {
                    printf("\n\nSua lista esta vazia.");
                }
                else if(empty(&alunos) == 0) {
                    printf("\n\nSua lista nao esta vazia.");
                }
                break;
            case 3:
                printf("\nA lista possui o tamanho %d", size_list(&alunos));
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                break;
            case 12:
                break;
        }
    }

    return 0;
}