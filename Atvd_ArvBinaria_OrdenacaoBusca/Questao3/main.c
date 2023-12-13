#include "arvbinpesq.h"
#include <string.h>
#include <stdio.h>

int main(void) {
  Arvore arv;
  criar(&arv);
  Arvore arv2;
  criar(&arv2);
  /* inserir(&arv,9);
   inserir(&arv,5);
   inserir(&arv,14);
   inserir(&arv,2);
   inserir(&arv,6);
   inserir(&arv,12);
   inserir(&arv,18);
   inserir(&arv,1);

   inserir(&arv,3);
   inserir(&arv,7);
   inserir(&arv,17);*/

  Funcionario func, func2, func3, func4;
  int matricula;
  func.horas_mes = 10;
  strcpy(func.nome, "Paulo");
  func.valor_hora = 5;
  func2.horas_mes = 50;
  strcpy(func2.nome, "PL");
  func2.valor_hora = 8;
  func3.horas_mes = 10;
  strcpy(func3.nome, "Po");
  func.valor_hora = 5;
  insere(&arv, func, 1);
  insere(&arv, func2, 2);
  insere(&arv, func3, 3);
  remover(&arv, 1);
  matricula = 2;
  if(busca(arv.raiz, matricula) == 1) {
    printf("O funcionario com a matricula %d existe na arvore.", matricula);
  }
  inserir_rec(arv.raiz, func, 7);


  printf("\nFormato de Arvore: \n");

  // printf("In-ordem: \n");
  exibir(arv.raiz, 0);
  /* printf("Apos remocao: \n");
   remover(&arv,9);
   exibir(arv.raiz, 0);*/

  /*printf("\nFormato de Arvore: \n");
  remover(&arv,9);
  exibir(arv.raiz,0);*/
  return 0;
}