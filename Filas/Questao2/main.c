#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "filapessoas.h"

int main(void){
  Queue filaNormal, filaIdosos, filaGestantes;
  Person p;
  int opc;
  int valor = 10;

  do{
    system("cls");
    printf("FILA DE PESSOAS\n");
    printf("--------------------------------\n");
    printf("1 - Exibir a Fila\n2 - Entrar na Fila\n3 - Sair da Fila\n4 - Primeiro da Fila\n5 - Quantidade de Pessoas na Fila\n6 - Sair\n\n");
    printf("Digite sua opcao:\n");

    scanf("%d", &opc);

    switch (opc){

      case 1:
        display(&filaNormal, &filaIdosos, &filaGestantes);
        break;

      case 2:
        printf("%d\n", valor);
        break;

      case 3:
        if (remove_queue(&filaNormal, &filaIdosos, &filaGestantes)){
          printf("Primeira pessoa da fila removida com suceso!\n");
        }

        else{
          printf("Erro na remocao, pois a fila esta vazia\n");
        }
        break;

      case 4:
        display_first(&filaNormal, &filaIdosos, &filaGestantes);
        break;

      case 5:
        printf("Neste momento ha %d pessoas na fila!\n", size_queue(&filaNormal, &filaIdosos, &filaGestantes));
        break;

      case 6:
        printf("Encerrando o programa...\n");
        exit(1);
        break;

    }

    printf("Pressione ENTER para continuar.\n");
    setbuf(stdin, NULL);
    getchar();

  } while (opc != 6);
  
  return 0;
}
