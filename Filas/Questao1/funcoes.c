#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

#define QUEUE_TYPE(queue) typeof(queue)

void start_queue(orderQueue *order_queue, paymentQueue *payment_queue, collectQueue *collect_queue){
    order_queue->head = order_queue->end = NULL;
    payment_queue->head = payment_queue->end = NULL;
    collect_queue->head = collect_queue->end = NULL;
}

int empty_order(orderQueue *queue){
    if (queue->head == NULL && queue->end == NULL){
        return 1;
    }
    return 0;
}

int empty_payment(paymentQueue *queue){
    if (queue->head == NULL && queue->end == NULL){
        return 1;
    }
    return 0;

}

int empty_collect(collectQueue *queue){
    if (queue->head == NULL && queue->end == NULL){
        return 1;
    }
    return 0;

}

int insert_orderQueue(orderQueue *queue, char name[]){
    Node *new_node = (Node *) malloc(sizeof(Node)); // Cria o novo nó

    if (new_node == NULL){ // Verifica se alocou memoria
        return 0;
    }

    strcpy(new_node->name, name);
    new_node->next = NULL;

    if (empty_order(queue)){ // Verifica se está a fila está vazia
        queue->head = queue->end = new_node;
        return 1;
    }

    else{
        queue->end->next = new_node;
        queue->end = new_node;
        return 1;
    }
}

void display_order(orderQueue *queue){

    if (empty_order(queue)){
        printf("A lista esta vazia\n");
    }

    else{
        Node *ass = queue->head;
        while (ass != NULL){
            printf("%s\n", ass->name);
            ass = ass->next;
        }
    }
}

void display_payment(paymentQueue *queue){

    if (empty_payment(queue)){
        printf("A lista esta vazia\n");
    }

    else{
        Node *ass = queue->head;
        while (ass != NULL){
            printf("%s\n", ass->name);
            ass = ass->next;
        }
    }
}

void display_collect(collectQueue *queue){

    if (empty_collect(queue)){
        printf("A lista esta vazia\n");
    }

    else{
        Node *ass = queue->head;
        while (ass != NULL){
            printf("%s\n", ass->name);
            ass = ass->next;
        }
    }
}

int remove_orderQueue(orderQueue *order, paymentQueue *payment){
    if (empty_order(order)){
        return 0;
    }

    Node *ass = order->head;
    order->head = ass->next;

    if (empty_payment(payment)){
        payment->head = payment->end = ass;
        ass->next = NULL;
        return 1;
    }

    payment->end->next = ass;
    payment->end = ass;
    ass->next = NULL;
    return 1;

}