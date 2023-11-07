#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filapessoas.h"
#include "filaprioridade.h"

void start_Queue(Queue *fila) {
    fila->head = fila->end = NULL;
}

int size_queue(Queue *queueNormal, Queue *queueAge, Queue *queuePreg){
    int cont = 0, contTotal = 0;

    Node *ast = queueNormal->head;
    while (ast != NULL){ // Percorre a fila de pedido e faz a contagem
        cont ++;
        ast = ast->next;
    }

    contTotal = cont + size_Queue_age(queueAge) + size_Queue_preg(queuePreg);

    return contTotal;
}

void display(Queue *fila, Queue *filaIdosos, Queue *filaGestantes) {
    if (size_queue(fila, filaIdosos, filaGestantes) == 0){
        printf("A lista esta vazia\n");
    }

    else{
        display_by_Preg(filaGestantes);
        display_by_age(filaIdosos);
        Node *ast = fila->head;
        while (ast != NULL){ // Percorre a fila de pedido e exibe
            printf("%s\n", ast->person->name);
            ast = ast->next;
        }
    }
}

void display_first(Queue *fila, Queue *filaIdosos, Queue *filaGestantes) {
    if(size_Queue_preg(filaGestantes) == 0) {
        if(size_Queue_age(filaIdosos) == 0) {
            printf("CPF: %d", fila->head->person->cpf);
            printf("Nome: %s", fila->head->person->name);
            printf("Idade: %d", fila->head->person->age);
            printf("Gestante: %s", fila->head->person->isPregnant);
        }
        else if(size_Queue_age(filaIdosos) > 0) {
            printf("CPF: %d", filaIdosos->head->person->cpf);
            printf("Nome: %s", filaIdosos->head->person->name);
            printf("Idade: %d", filaIdosos->head->person->age);
            printf("Gestante: %s", filaIdosos->head->person->isPregnant);            
        }
    }
    else if(size_Queue_preg(filaGestantes) > 0) {
            printf("CPF: %d", filaGestantes->head->person->cpf);
            printf("Nome: %s", filaGestantes->head->person->name);
            printf("Idade: %d", filaGestantes->head->person->age);
            printf("Gestante: %s", filaGestantes->head->person->isPregnant);    
    }
}

int insert_Queue(Queue *fila, Queue *filaIdosos, Queue *filaGestantes, Person p) {
    Node *new_node = (Node *) malloc(sizeof(Node)); // Cria o novo nó

    if (new_node == NULL){ // Verifica se alocou memoria
        return 0;
    }

    if(new_node->person->isPregnant[0] == 'S' || new_node->person->isPregnant[0] == 's') {
        insert_by_preg(filaGestantes, p);
    }
    if(new_node->person->age >= 65) {
        insert_by_age(filaIdosos, p);
    }

    else {
        strcpy(new_node->person->name, p.name); // Atribui o nome o novo nome recebido com parametro
        strcpy(new_node->person->isPregnant, p.isPregnant);
        new_node->person->age = p.age;
        new_node->person->cpf = p.cpf;
        new_node->next = NULL; // Define o proximo no como null
    }

    if (size_queue(fila, filaIdosos, filaGestantes) == 0 && size_Queue_age(filaIdosos) == 0 && size_Queue_preg(filaGestantes) == 0){ // Verifica se está a fila está vazia
        fila->head = fila->end = new_node; // Define o inicio e o fim como o novo nó
        return 1;
    }

    else{ // Se não estiver vazia
        fila->end->next = new_node;
        fila->end = new_node;
        return 1;
    }
}

int remove_Queue(Queue *fila, Queue *filaIdosos, Queue *filaGestantes) {
    if (size_queue(fila, filaGestantes, filaIdosos) == 0){
        return 0;
    }

    if(size_Queue_preg(filaGestantes) == 0) {
        if(size_Queue_age(filaIdosos) == 0) {
            Node *temp = fila->head; // Variável assistente
            fila->head = fila->head->next;
            free(temp);
            return 1;
        }
        else if((size_Queue_age(filaIdosos)) > 0) {
            remove_by_age(filaIdosos);
        }
    }
    else if(size_Queue_preg(filaGestantes) > 0) {
        remove_by_preg(filaGestantes);
    }
}