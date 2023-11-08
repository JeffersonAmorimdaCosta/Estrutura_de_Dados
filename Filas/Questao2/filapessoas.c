#include "filaprioridade.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void start_Queue(Queue *filaNormal, Queue *filaIdosos, Queue *filaGestantes) {
    filaNormal->head = filaNormal->end = NULL;
    filaIdosos->head = filaIdosos->end = NULL;
    filaGestantes->head = filaGestantes->end = NULL;
}

int size_queue(Queue *queueNormal, Queue *queueAge, Queue *queuePreg) {
    int contNormal = 0, contTotal = 0;

    int contIdosos = size_age(queueAge); 
    int contGestantes = size_preg(queuePreg);

    Node *aux = queueNormal->head;
    while(aux != NULL) {
        contNormal++;
        aux = aux->next;
    }
    contTotal = (contNormal + contGestantes + contIdosos);

    return contTotal;
}

int insert_Queue(Queue *filaNormal, Queue *filaIdosos, Queue *filaGestantes, Person p) {

    for(int i = 0; p.isPregnant[i]; i++) {
      p.isPregnant[i] = toupper(p.isPregnant[i]);
    }
  
    if(strcmp(p.isPregnant, "SIM") == 0) {
        if(insert_preg(filaGestantes, p) == 1) {
            return 1;
        }
    }
    if(p.age >= 65) {
        if(insert_age(filaIdosos, p) == 1) {
            return 1;
        }
    }
    if (strcmp(p.isPregnant, "NAO") == 0 && p.age < 65) {
        Node *new_node = (Node*) malloc(sizeof(Node));

        if(new_node == NULL) {
            return 0;
        }

        strcpy(new_node->person.name, p.name);
        strcpy(new_node->person.isPregnant, p.isPregnant);
        new_node->person.age = p.age;
        strcpy(new_node->person.cpf, p.cpf);

        if (size_queue(filaNormal, filaIdosos, filaGestantes) == 0) {
            filaNormal->head = filaNormal->end = new_node;
            return 1;
        }

        filaNormal->end->next = new_node;
        filaNormal->end = new_node;
        return 1;
    }
}

void display_first(Queue *fila, Queue *filaIdosos, Queue *filaGestantes) {
  if(size_preg(filaGestantes) > 0) {
    printf("CPF: %ld\n", filaGestantes->head->person.cpf);
    printf("Nome: %s\n", filaGestantes->head->person.name);
    printf("Idade: %d\n", filaGestantes->head->person.age);
    printf("Gestante: %s\n", filaGestantes->head->person.isPregnant);
  }
  else if(size_age(filaIdosos) > 0) {
    printf("CPF: %ld\n", filaIdosos->head->person.cpf);
    printf("Nome: %s\n", filaIdosos->head->person.name);
    printf("Idade: %d\n", filaIdosos->head->person.age);
    printf("Gestante: %s\n", filaIdosos->head->person.isPregnant);
  }
  else if(size_queue(fila, filaIdosos, filaGestantes) > 0) {
    printf("CPF: %ld\n", fila->head->person.cpf);
    printf("Nome: %s\n", fila->head->person.name);
    printf("Idade: %d\n", fila->head->person.age);
    printf("Gestante: %s\n", fila->head->person.isPregnant);
  }
}

void display(Queue *filaNormal, Queue *filaIdosos, Queue *filaGestantes) {
  int counter = 1;
  Node *aux;

  for(aux = filaGestantes->head; aux != NULL; aux = aux->next, counter++) {
    printf("%d. %s\n", counter, aux->person.name);
  }
  for(aux = filaIdosos->head; aux != NULL; aux = aux->next, counter++) {
    printf("%d. %s\n", counter, aux->person.name);
  }
  for(aux = filaNormal->head; aux != NULL; aux = aux->next, counter++) {
    printf("%d. %s\n", counter, aux->person.name);
  }
}

int remove_queue(Queue *fila, Queue *filaIdosos, Queue *filaGestantes) {
  if(size_preg(filaGestantes) > 0) {
    if(remove_preg(filaGestantes) == 1) {
        return 1;
    }
  }
  else if(size_age(filaIdosos) > 0) {
    if(remove_age(filaIdosos) == 1) {
        return 1;
    }
  }
  else if(size_age(filaIdosos) == 0 && size_preg(filaGestantes) == 0) {
    if (size_queue(fila, filaIdosos, filaGestantes) == 0) {
      return 0;
    }
    Node *temp = fila->head;
    fila->head = fila->head->next;
    free(temp);
    return 1;
  }
}
