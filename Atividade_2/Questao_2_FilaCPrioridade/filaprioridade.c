#include "filaprioridade.h"
#include <string.h>
#include <stdlib.h>

int size_preg(Queue *queuePregnant){
    int cont = 0; // Início do contador

    Node *ast = queuePregnant->head; // Declarando a variável auxiliar para percorrer a fila
    while (ast != NULL){ // Percorre a fila e faz a contagem
        cont ++;
        ast = ast->next;
    }

    return cont;
}

//Será feita a mesma coisa na função abaixo, a mudança é que será usada para fila de idosos.

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
    Node *new_node = (Node *) malloc(sizeof(Node)); // Aloca memória para o novo nó
    new_node->next = NULL; // Define o próximo nó como nulo

    if(new_node == NULL) {
        return 0; // Se a alocação não for bem sucedida, retorna-se 0.
    }

    //Inserção dos dados nas respectivas variáveis no nó
    strcpy(new_node->person.name, p.name); 
    strcpy(new_node->person.isPregnant, p.isPregnant);
    new_node->person.age = p.age;
    strcpy(new_node->person.cpf, p.cpf);

    // Caso a fila esteja vazia
    if (size_preg(queuePreg) == 0) {
        queuePreg->head = queuePreg->end = new_node; // Início e fim apontarão para o mesmo endereço
        return 1;
    }

    // Caso não esteja vazia, insere o novo nó como o próximo ao final, e define o novo final como o novo nó.
    queuePreg->end->next = new_node;
    queuePreg->end = new_node;
    return 1;
}

// A função abaixo fará a mesma coisa abaixo, sendo utilizada na fila de idosos.

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
  if(size_age(queueAge) == 0) { // Se a fila estiver vazia, retorna-se 0.
    return 0;
  }

  Node *temp = queueAge->head; // Declaração da variável temporária (para não perder o antigo início).
  queueAge->head = queueAge->head->next; // Novo início será o próximo da fila.
  free(temp); // Libera espaço alocado para o antigo início.
  return 1;
}

//Abaixo será feito a mesma coisa para a fila de gestantes.
int remove_preg(Queue *queuePreg) {
  if(size_preg(queuePreg) == 0) {
    return 0;
  }

  Node *temp = queuePreg->head;
  queuePreg->head = queuePreg->head->next;
  free(temp);
  return 1;
}
