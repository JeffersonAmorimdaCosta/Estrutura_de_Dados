#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "listadinalu.h"

int main(void){ // Testes:
    StudentList alunos;
    short opcao;
    int pos, posicap;
    Student aluno, st;

    while(true) {
        system("cls");
        printf("Editor de lista encadeada - Atividade 1\n");
        printf("---------------------------------------\n");
        printf("0 - Encerrar programa\n");
        printf("1 - Criar lista\n");
        printf("2 - Verificacao da lista (vazia)\n");
        printf("3 - Tamanho da lista\n");
        printf("4 - Obter dados pela posicao\n");
        printf("5 - Obter posicao pela matricula\n");
        printf("6 - Inserir aluno no final da lista\n");
        printf("7 - Remover pela matricula\n");
        printf("8 - Exibicao dos dados\n");
        printf("9 - Inserir aluno na posicao\n");
        printf("10 - Inserir aluno de forma crescente\n");
        printf("11 - Remover na posicao\n");
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
                printf("\nPosição a ser pesquisada: ");
                scanf("%d", pos);
                searchStudentPos(&alunos, pos, &st);
                printf("\nMatrícula do aluno: %d\n", st.registration);
                printf("\nNome: %s\n", st.name);
                printf("\nNota 1: %d\n", st.grade1);
                printf("\n Nota 2: %d\n", st.grade2);
                break;
            case 5:
                break;
            case 6:
                printf("\n");
                printf("Matricula: ");
                scanf("%d", &aluno.registration);
                printf("\n");
                printf("Nome: ");
                scanf("%s", &aluno.name);
                printf("\n");
                printf("Nota 1: ");
                scanf("%f", &aluno.grade1);
                printf("\n");
                printf("Nota 2: ");
                scanf("%f", &aluno.grade2);
                printf("\n");
                insertEnd(&alunos, aluno);
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
            default:
                printf("Opção inserida é inválida.");
        }
        printf("\nAperte ENTER para voltar ao menu.");
        while(getchar() != '\n');
        getchar();
    }

    return 0;
}
