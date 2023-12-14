#include "arvbinpesq.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  Arvore arv;
  criar(&arv);
  Funcionario funcio;
  int matric;
  int opc;
  
  while (1){
    system("cls");
    printf("Manipulação de Árvore\n");
    printf("======================================\n");
    printf("1 - Inserir Funcionário\n2 - Remover Funcionário\n3 - Buscar Funcionário\n4 - Exibir Funcionário\n5 - Sair\n\n");
    printf("Digite sua opcao: ");

    scanf("%d", &opc);

    switch (opc){

      case 1:
        printf("Digite o nome:\n");
        setbuf(stdin, NULL);
        scanf("%s", funcio.nome);
        printf("Digite o valor da hora:\n");
        scanf("%f", &funcio.valor_hora);
        printf("Digite a quantidade de horas mes: \n");
        scanf("%d", &funcio.horas_mes);
        printf("Digite a matricula:\n");
        scanf("%d", &matric);

        if (inserir(&arv, funcio, matric)){
          printf("Funcionario inserido com sucesso!\n");
        }

        else{
          printf("Erro na alocacao ou matricula ja existente.\n");
        }

        break;
      
      case 2:
        printf("Digite a matricula do funcionario que deseja remover:\n");
        scanf("%d", &matric);

        if (remover(&arv, matric)){
          printf("Funcionario removido com sucesso!\n");
        }

        else{
          printf("Matricula nao encontrada.\n");
        }
        break;

      case 3:
        printf("Digite a matricula do funcionario que deseja buscar:\n");
        scanf("%d", &matric);

        if (busca(arv.raiz, matric)){
          printf("Este funcionario esta presente na arvore!\n");
        }

        else{
          printf("Matricula nao encontrada.\n");
        }
        break;
      case 4:
        printf("\n");
        exibir(arv.raiz, 0);
        break;

      case 5:
        printf("Encerrando o programa!\n");
        exit(1);
        break;

      default:
        printf("Opcao invalida!\n");
        break;
    }

    setbuf(stdin, NULL);
    printf("Pressione ENTER para continuar.\n");
    getchar();
  }
  return 0;
}