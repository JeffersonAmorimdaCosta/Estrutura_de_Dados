#include "filaprioridade.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size_Queue_age(Queue *filaprIdosos) {
    int cont = 0;

    Node *ast = filaprIdosos->head;
    while (ast != NULL){ // Percorre a fila de pedido e faz a contagem
        cont ++;
        ast = ast->next;
    }

    return cont;
}

int size_Queue_preg(Queue *filaprGestantes) {
    int cont = 0;

    Node *ast = filaprGestantes->head;
    while (ast != NULL){ // Percorre a fila de pedido e faz a contagem
        cont ++;
        ast = ast->next;
    }

    return cont;
}

int insert_by_age(Queue *filaprIdosos, Person p) {
    Node *new_node = (Node *) malloc(sizeof(Node)); // Cria o novo nó

    if (new_node == NULL){ // Verifica se alocou memoria
        return 0;
    }

    strcpy(new_node->person->name, p.name); // Atribui o nome o novo nome recebido com parametro
    strcpy(new_node->person->isPregnant, p.isPregnant);
    new_node->person->age = p.age;
    new_node->person->cpf = p.cpf; 
    new_node->next = NULL; // Define o proximo no como null

    if (size_Queue_age(filaprIdosos) == 0){ // Verifica se está a fila está vazia
        filaprIdosos->head = filaprIdosos->end = new_node; // Define o inicio e o fim como o novo nó
        return 1;
    }

    else{ // Se não estiver vazia
        filaprIdosos->end->next = new_node;
        filaprIdosos->end = new_node;
        return 1;
    }
}

int insert_by_preg(Queue *filaprGestantes, Person p) {
    Node *new_node = (Node *) malloc(sizeof(Node)); // Cria o novo nó

    if (new_node == NULL){ // Verifica se alocou memoria
        return 0;
    }

    strcpy(new_node->person->name, p.name); // Atribui o nome o novo nome recebido com parametro
    strcpy(new_node->person->isPregnant, p.isPregnant);
    new_node->person->age = p.age;
    new_node->person->cpf = p.cpf; 
    new_node->next = NULL; // Define o proximo no como null

    if (size_Queue_preg(filaprGestantes) == 0){ // Verifica se está a fila está vazia
        filaprGestantes->head = filaprGestantes->end = new_node; // Define o inicio e o fim como o novo nó
        return 1;
    }

    else{ // Se não estiver vazia
        filaprGestantes->end->next = new_node;
        filaprGestantes->end = new_node;
        return 1;
    }
}

int remove_by_age(Queue *filaprIdosos) {
    if (size_Queue_age(filaprIdosos) == 0){
        return 0;
    }

    Node *ast = filaprIdosos->head; // Variável assistente
    filaprIdosos->head = ast->next;

    Node *temp = filaprIdosos->head; // Variável assistente
    filaprIdosos->head = filaprIdosos->head->next;
    free(temp);
    return 1;
}

int remove_by_preg(Queue *filaprGestantes) {
    if (size_Queue_preg(filaprGestantes) == 0){
        return 0;
    }

    Node *ast = filaprGestantes->head; // Variável assistente
    filaprGestantes->head = ast->next;

    Node *temp = filaprGestantes->head; // Variável assistente
    filaprGestantes->head = filaprGestantes->head->next;
    free(temp);
    return 1;
}

void display_by_age(Queue *filaprIdosos) {
    if (size_Queue_age(filaprIdosos) == 0){
        printf("A lista esta vazia\n");
    }

    else{
        Node *ast = filaprIdosos->head;
        while (ast != NULL){ // Percorre a fila de pedido e exibe
            printf("%d\n", ast->person->cpf);
            printf("%s\n", ast->person->name);
            printf("%d\n", ast->person->age);
            printf("%s\n", ast->person->isPregnant);
            ast = ast->next;
        }
    }
}

void display_by_Preg(Queue *filaprGestantes) {
    if (size_Queue_preg(filaprGestantes) == 0){
        printf("A lista esta vazia\n");
    }

    else{
        Node *ast = filaprGestantes->head;
        while (ast != NULL){ // Percorre a fila de pedido e exibe
            printf("%d\n", ast->person->cpf);
            printf("%s\n", ast->person->name);
            printf("%d\n", ast->person->age);
            printf("%s\n", ast->person->isPregnant);
            ast = ast->next;
        }
    }
}