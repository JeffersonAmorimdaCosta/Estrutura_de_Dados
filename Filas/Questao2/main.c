#include <stdio.h>
#include <string.h>
#include "filapessoas.h"

int main(void){
  Queue filaNormal, filaIdosos, filaGestantes;
  Person p;

  start_Queue(&filaNormal, &filaIdosos, &filaGestantes);
  printf("%d\n", size_queue(&filaNormal, &filaIdosos, &filaGestantes));
  p.age = 15;
  p.cpf = 11122233344;
  strcpy(p.isPregnant, "NAO");
  strcpy(p.name, "Carla");
  insert_Queue(&filaNormal, &filaIdosos, &filaGestantes, p);
  printf("%d\n", size_queue(&filaNormal, &filaIdosos, &filaGestantes));
  p.age = 20;
  p.cpf = 11122255544;
  strcpy(p.isPregnant, "SIM");
  strcpy(p.name, "Carlita");
  insert_Queue(&filaNormal, &filaIdosos, &filaGestantes, p);
  display_first(&filaNormal, &filaIdosos, &filaGestantes);
  printf("%d\n", size_queue(&filaNormal, &filaIdosos, &filaGestantes));
  p.age = 25;
  p.cpf = 11122255545;
  strcpy(p.isPregnant, "SIM");
  strcpy(p.name, "Ingride");
  insert_Queue(&filaNormal, &filaIdosos, &filaGestantes, p);
  p.age = 75;
  p.cpf = 12222255545;
  strcpy(p.isPregnant, "NAO");
  strcpy(p.name, "Joao");
  insert_Queue(&filaNormal, &filaIdosos, &filaGestantes, p);
  remove_queue(&filaNormal, &filaIdosos, &filaGestantes);
  display(&filaNormal, &filaIdosos, &filaGestantes);
  
  return 0;
}
