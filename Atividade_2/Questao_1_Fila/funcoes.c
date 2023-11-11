#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

#define QUEUE_TYPE(queue) typeof(queue)

void start_queue(Queue *order_queue, Queue *payment_queue, Queue *collect_queue){ // Cria as filas, definindo seus inicios e finais
    order_queue->head = order_queue->end = NULL;
    payment_queue->head = payment_queue->end = NULL;
    collect_queue->head = collect_queue->end = NULL;
}

int size_queue(Queue *queue){
    int cont = 0;

    Node *ast = queue->head;
    while (ast != NULL){ // Percorre a fila de pedido e faz a contagem
        cont ++;
        ast = ast->next;
    }

    return cont;
}

int insert_orderQueue(Queue *queue, char name[]){
    Node *new_node = (Node *) malloc(sizeof(Node)); // Cria o novo nó

    if (new_node == NULL){ // Verifica se alocou memoria
        return 0;
    }

    strcpy(new_node->name, name); // Atribui o nome o novo nome recebido com parametro
    new_node->next = NULL; // Define o proximo no como null

    if (size_queue(queue) == 0){ // Verifica se está a fila está vazia
        queue->head = queue->end = new_node; // Define o inicio e o fim como o novo nó
        return 1;
    }

    else{ // Se não estiver vazia
        queue->end->next = new_node;
        queue->end = new_node;
        return 1;
    }
}

void display(Queue *queue){

    if (size_queue(queue) == 0){
        printf("A lista esta vazia\n");
    }

    else{
        Node *ast = queue->head;
        while (ast != NULL){ // Percorre a fila de pedido e exibe
            printf("%s\n", ast->name);
            ast = ast->next;
        }
    }
}

int remove_queue(Queue *previousQueue, Queue *nextQueue){
    if (size_queue(previousQueue) == 0){
        return 0;
    }

    Node *ast = previousQueue->head; // Variável assistente
    previousQueue->head = ast->next;

    if (size_queue(nextQueue) == 0){
        nextQueue->head = nextQueue->end = ast;
        ast->next = NULL;
        return 1;
    }

    else{
        if (size_queue(previousQueue) == 0){
            previousQueue->end = NULL;
        }

        nextQueue->end->next = ast;
        nextQueue->end = ast;
        ast->next = NULL;
        return 1;
    }

}

int remove_collectQueue(Queue *queue, char *name_removed){
    if (size_queue(queue) == 0){
        return 0;
    }

    else{
        if (size_queue(queue) == 1){
            queue->end = NULL;
        }
        Node *ast = queue->head;
        queue->head = ast->next;
        strcpy(name_removed, ast->name);
        free(ast);
        return 1;

    }
}