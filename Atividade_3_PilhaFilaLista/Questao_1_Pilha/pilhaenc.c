#include <stdio.h>
#include <stdlib.h>
#include "pilhaenc.h"

void create(Stack *s){
    s->top = NULL;
}

int sizeStack(Stack *s){
    
    Node *ast = s->top;
    int size = 0;
    while (ast != NULL){
        size ++;
        ast = ast->next;
    }
    return size;
}

int stackUp(Stack *s, int value){
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = value;

    if (new_node == NULL){
        return 0;
    }

    if (s->top == NULL){
        new_node->next = NULL;
        s->top = new_node;
    }

    else{
        new_node->next = s->top;
        s->top = new_node;
    }

    return 1;
}

int unstack(Stack *s){
    if (s->top == NULL){
        return 0;
    }

    Node *ast = s->top;
    s->top = ast->next;
    free(ast);
    return 1;
}

void displayTop(Stack *s){
    if (s->top == NULL){
        return;
    }

    else{
        printf("O elemento que se encontra no topo: %d\n", s->top->data);
        return;
    }    
}

void display(Stack *s){
    if (s->top == NULL){
        return;
    }

    else{
        Node *ast = s->top;
        printf("De cima para baixo:\n");
        while (ast != NULL){
            printf("%d ", ast->data);
            ast = ast->next;
        }
        printf("\n");
        return;
    }
}

void toEmpty(Stack *s){
    if (s->top == NULL){
        return;
    }

    while (s->top != NULL){
        unstack(s);
    }
    return;
}

