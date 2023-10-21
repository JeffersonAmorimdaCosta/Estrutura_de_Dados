#include <stdio.h>
#include <stdlib.h>
#include "listadinalu.h"

void create(StudentList *st_list){
    st_list->head = NULL;
}

int empty(StudentList *st_list){
    if (st_list->head == NULL){
        return 1;
    }

    return 0;
}

int size_list(StudentList *st_list){
    if (empty(st_list)){
        return 0;
    }

    else{
        int size_value = 0;

        Node *current_node = st_list->head;
        while (current_node != NULL){
            size_value ++;
            current_node = current_node->next;
        }

        return size_value;
    }
}