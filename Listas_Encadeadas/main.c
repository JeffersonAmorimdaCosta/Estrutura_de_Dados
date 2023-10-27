#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "listadinalu.h"

int main(void){ // Testes:
    StudentList alunos;
    create(&alunos);
    short opcao;
    int pos, matricula, post, posi, tipo;
    Student aluno, st;
    char nick[30];

    while(true) {
        system("clear");
        printf("Editor de lista encadeada - Atividade 1\n");
        printf("---------------------------------------\n");
        printf("1 - Encerrar programa\n");
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
            case 1:
                printf("Programa encerrado pelo usuario.");
                exit(0);
            case 2:
                if(empty(&alunos)) {
                    printf("\n\nSua lista esta vazia.");
                }
                else{
                    printf("\n\nSua lista nao esta vazia.");
                }
                break;
            case 3:
                printf("\nA lista possui o tamanho %d", size_list(&alunos));
                break;
            case 4:
                printf("\nPosição a ser pesquisada: ");
                scanf("%d", &pos);
                if (searchStudentPos(&alunos, pos, &st)){
                    printf("\nMatrícula do aluno: %d\n", st.registration);
                    printf("\nNome: %s\n", st.name);
                    printf("\nNota 1: %f\n", st.grade1);
                    printf("\n Nota 2: %f\n", st.grade2);
                }

                else{
                    printf("Aluno nao encontrado ou posicao invalida.\n");
                }
                break;
            case 5:
                printf("Matricula do aluno: ");
                scanf("%d", &matricula);
                if (searchPosRegist(&alunos, matricula, &post)){
                    printf("O aluno com a matricula '%d' está na posição %d\n", matricula, post);
                }
                
                else{
                    printf("A lista esta vazia ou o aluno nao foi encontrado.\n");
                }
                break;
            case 6:
                printf("\n");
                printf("Matricula: ");
                scanf("%d", &aluno.registration);
                printf("\n");
                printf("Nome: ");
                scanf("%s", aluno.name);
                printf("\n");
                printf("Nota 1: ");
                scanf("%f", &aluno.grade1);
                printf("\n");
                printf("Nota 2: ");
                scanf("%f", &aluno.grade2);
                printf("\n");
                if (insertEnd(&alunos, aluno)){
                    printf("Aluno adicionado com sucesso!\n");
                }

                else{
                    printf("Nao foi possivel alocar memoria.\n");
                }
                break;
            case 7:
                printf("\nMatricula do aluno a ser removido: ");
                scanf("%d", &matricula);
                if(removeStudentRegist(&alunos, matricula)) {
                  printf("Estudante com a matrícula '%d' removido com sucesso!\n", matricula);
                }
                else {
                  printf("Nao ha estudante com essa matricula na lista.");
                }
                break;
            case 8:
                printf("\n");
                displayStudents(&alunos);
                break;
            case 9:
                printf("\n");
                printf("Matricula: ");
                scanf("%d", &aluno.registration);
                printf("\n");
                printf("Nome: ");
                scanf("%s", aluno.name);
                printf("\n");
                printf("Nota 1: ");
                scanf("%f", &aluno.grade1);
                printf("\n");
                printf("Nota 2: ");
                scanf("%f", &aluno.grade2);
                printf("\n\n");
                printf("Posicao que deseja inserir o aluno: ");
                scanf("%d", &posi);
                printf("\n");
                if(insertStudentPos(&alunos, aluno, posi) == 0) {
                  printf("Posicao invalida ou lista vazia");
                }
                if(insertStudentPos(&alunos, aluno, posi) == 1) {
                  printf("Aluno inserido com sucesso!");
                }
                break;
            case 10:
                printf("\n");
                printf("Matricula: ");
                scanf("%d", &aluno.registration);
                printf("\n");
                printf("Nome: ");
                scanf("%s", aluno.name);
                printf("\n");
                printf("Nota 1: ");
                scanf("%f", &aluno.grade1);
                printf("\n");
                printf("Nota 2: ");
                scanf("%f", &aluno.grade2);
                if (insertSortLowerId(&alunos, aluno)){
                    printf("Aluno adicionado com sucesso!\n");
                }
                else{
                    printf("Nao foi possivel alocar memoria.\n");
                }
                break;
            case 11:
                printf("Posicao que deseja remover:");
                scanf("%d", &pos);
                if(removeStudentPos(&alunos, pos)) {
                    printf("Aluno removido com sucesso!");
                }
                else{
                    printf("Lista vazia ou posicao inexistente");
                }
             
                break;
            case 12:
                printf("Tipo de pesquisa (0-Matricula/1-Nome): ");
                scanf("%d", &tipo);
                printf("\n");
                if(tipo==0) {
                  printf("Matricula a ser pesquisada: ");
                  scanf("%d", &matricula);
                  if (!(schStudentNameEnrollment(&alunos, &matricula, tipo))){
                    printf("A lista esta vazia ou algum dado nao foi encontrado.\n");
                  }
                }
                else if(tipo==1) {
                  printf("Nome a ser pesquisado: ");
                  scanf("%s", nick);
                  if (!(schStudentNameEnrollment(&alunos, &nick, tipo))){
                    printf("A lista esta vazia ou algum dado nao foi encontrado.\n");
                  }
                }
                break;
            default:
                printf("Opção inserida é invalida.\n");
        }
        printf("Aperte ENTER para voltar ao menu.");
        while(getchar() != '\n');
        getchar();
    }

    return 0;
}