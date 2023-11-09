#include "filaprioridade.h"
#include <string.h>
#include <stdlib.h>

int size_preg(Queue *queuePregnant){
    int cont = 0;

    Node *ast = queuePregnant->head;
    while (ast != NULL){ // Percorre a fila de pedido e faz a contagem
        cont ++;
        ast = ast->next;
    }

    return cont;
}

int size_age(Queue *queueAge){
    int cont = 0;

    Node *ast = queueAge->head;
    while (ast != NULL){ // Percorre a fila de pedido e faz a contagem
        cont ++;
        ast = ast->next;
    }

    return cont;
}

int insert_preg(Queue *queuePreg, Person p) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->next = NULL;

    if(new_node == NULL) {
        return 0;
    }

    strcpy(new_node->person.name, p.name);
    strcpy(new_node->person.isPregnant, p.isPregnant);
    new_node->person.age = p.age;
    strcpy(new_node->person.cpf, p.cpf);

    if (size_preg(queuePreg) == 0) {
        queuePreg->head = queuePreg->end = new_node;
        return 1;
    }

    queuePreg->end->next = new_node;
    queuePreg->end = new_node;
    return 1;
}

int insert_age(Queue *queueAge, Person p) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->next = NULL;

    if(new_node == NULL) {
        return 0;
    }

    strcpy(new_node->person.name, p.name);
    strcpy(new_node->person.isPregnant, p.isPregnant);
    new_node->person.age = p.age;
    strcpy(new_node->person.cpf, p.cpf);

    if (size_preg(queueAge) == 0) {
        queueAge->head = queueAge->end = new_node;
        return 1;
    }

    queueAge->end->next = new_node;
    queueAge->end = new_node;
    return 1;
}

int remove_age(Queue *queueAge) {
  if(size_age(queueAge) == 0) {
    return 0;
  }

  Node *temp = queueAge->head;
  queueAge->head = queueAge->head->next;
  free(temp);
  return 1;
}

int remove_preg(Queue *queuePreg) {
  if(size_preg(queuePreg) == 0) {
    return 0;
  }

  Node *temp = queuePreg->head;
  queuePreg->head = queuePreg->head->next;
  free(temp);
  return 1;
}
