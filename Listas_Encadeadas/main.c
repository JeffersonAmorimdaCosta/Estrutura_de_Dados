#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "listadinalu.h"

int main(void){ // Testes:
    StudentList alunos;
    short opcao;
    Student aluno;

    while(true) {
        system("cls");
        printf("Editor de lista encadeada - Atividade 1\n");
        printf("---------------------------------------\n");
        printf("0 - Encerrar programa");
        printf("1 - Criar lista\n");
        printf("2 - Verificação da lista (vazia)\n");
        printf("3 - Tamanho da lista\n");
        printf("4 - Obter dados pela posição\n");
        printf("5 - Obter posição pela matrícula\n");
        printf("6 - Inserir aluno no final da lista\n");
        printf("7 - Remover pela matrícula\n");
        printf("8 - Exibição dos dados\n");
        printf("9 - Inserir aluno na posição\n");
        printf("10 - Inserir aluno de forma crescente\n");
        printf("11 - Remover na posição\n");
        printf("12 - Pesquisar pela matrícula ou nome\n\n");
        printf("Escolha uma opção: ");
        scanf("%hd", opcao);

        switch(opcao) {
            case 0:
                printf("Programa encerrado pelo usuário.");
                exit(0);
            case 1:
                create(&alunos);
                break;
            case 2:
                if(empty(&alunos) == 1) {
                    printf("\n\nSua lista está vazia.");
                }
                else if(empty(&alunos) == 0) {
                    printf("\n\nSua lista não está vazia.");
                }
                break;
            case 3:
                printf("\nA lista possui o tamanho %d", size_list(&alunos));
                break;
        }
    }

    return 0;
}