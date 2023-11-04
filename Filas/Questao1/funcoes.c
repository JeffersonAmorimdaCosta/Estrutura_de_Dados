#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

#define QUEUE_TYPE(queue) typeof(queue)

void start_queue(orderQueue *order_queue, paymentQueue *payment_queue, collectQueue *collect_queue){ // Cria as filas, definindo seus inicios e finais
    order_queue->head = order_queue->end = NULL;
    payment_queue->head = payment_queue->end = NULL;
    collect_queue->head = collect_queue->end = NULL;
}

int size_order(orderQueue *queue){
    int cont = 0;

    Node *ast = queue->head;
    while (ast != NULL){ // Percorre a fila de pedido e faz a contagem
        cont ++;
        ast = ast->next;
    }

    return cont;
}

int size_payment(paymentQueue *queue){
    int cont = 0;

    Node *ast = queue->head;
    while (ast != NULL){ // Percorre a fila de pagamento e faz a contagem
        cont ++;
        ast = ast->next;
    }

    return cont;
}

int size_collect(collectQueue *queue){
    int cont = 0;

    Node *ast = queue->head;
    while (ast != NULL){ // Percorre a fila de coletagem e faz a contagem
        cont ++;
        ast = ast->next;
    }

    return cont;
}

int insert_orderQueue(orderQueue *queue, char name[]){
    Node *new_node = (Node *) malloc(sizeof(Node)); // Cria o novo nó

    if (new_node == NULL){ // Verifica se alocou memoria
        return 0;
    }

    strcpy(new_node->name, name); // Atribui o nome o novo nome recebido com parametro
    new_node->next = NULL; // Define o proximo no como null

    if (size_order(queue) == 0){ // Verifica se está a fila está vazia
        queue->head = queue->end = new_node; // Define o inicio e o fim como o novo nó
        return 1;
    }

    else{ // Se não estiver vazia
        queue->end->next = new_node;
        queue->end = new_node;
        return 1;
    }
}

void display_order(orderQueue *queue){

    if (size_order(queue) == 0){
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

void display_payment(paymentQueue *queue){

    if (size_payment(queue) == 0){
        printf("A lista esta vazia\n");
    }

    else{
        Node *ast = queue->head;
        while (ast != NULL){ // Percorre a fila de pagamento e exibe
            printf("%s\n", ast->name);
            ast = ast->next;
        }
    }
}

void display_collect(collectQueue *queue){

    if (size_collect(queue) == 0){
        printf("A lista esta vazia\n");
    }

    else{
        Node *ast = queue->head;
        while (ast != NULL){ // Percorre a fila de coletagem e exibe
            printf("%s\n", ast->name);
            ast = ast->next;
        }
    }
}

int remove_orderQueue(orderQueue *order, paymentQueue *payment){
    if (size_order(order) == 0){
        return 0;
    }

    Node *ast = order->head;
    order->head = ast->next;

    if (size_payment(payment) == 0){
        payment->head = payment->end = ast;
        ast->next = NULL;
        return 1;
    }

    else{
        if (size_order(order) == 0){
            order->end = NULL;
        }

        payment->end->next = ast;
        payment->end = ast;
        ast->next = NULL;
        return 1;
    }

}

int remove_paymentQueue(paymentQueue *payment, collectQueue *collect){
    if (size_payment(payment) == 0){
        return 0;
    }

    Node *ast = payment->head;
    payment->head = ast->next;

    if (size_collect(collect) == 0){
        collect->head = collect->end = ast;
        ast->next = NULL;
        return 1;
    }

    else{
        if (size_payment(payment) == 0){
            payment->end = NULL;
        }
        collect->end->next = ast;
        collect->end = ast;
        ast->next = NULL;
        return 1;
    }
}

int remove_collectQueue(collectQueue *collect, char *name_removed){
    if (size_collect(collect) == 0){
        return 0;
    }

    else{
        if (size_collect(collect) == 1){
            collect->end = NULL;
        }
        Node *ast = collect->head;
        collect->head = ast->next;
        strcpy(name_removed, ast->name);
        free(ast);
        return 1;

    }
}