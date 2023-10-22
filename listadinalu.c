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

int searchPosRegist(StudentList *st_list, int regist, int *pos){
    if (empty(st_list)){
        return 0;
    }

    int count = 0;
    Node *current_node = st_list->head;
    while (current_node != NULL){
        if (current_node->data.registration == regist){
            *pos = count;
            return 1;
        }
        count ++;
        current_node = current_node->next;
    }

    return 0;
}

int insertEnd(StudentList *st_list, Student st){

    Node *new_node = (Node *) malloc(sizeof(Node));

    if (new_node == NULL){
        return 0;
    }

    new_node->data = st;
    new_node->next = NULL;

    if (empty(st_list)){
        st_list->head = new_node;
        return 1;
    }

    Node *current_node = st_list->head;
    while (current_node->next != NULL){
        current_node = current_node->next;
    }

    current_node->next = new_node;
    return 1;

}

int searchStudentPos(StudentList *st_list, int pos, Student *st){
    if (empty(st_list) || pos < 0 || pos > (size_list(st_list))){
        return 0;
    }

    int count = 0;
    Node *current_node = st_list->head;
    while (current_node != NULL){
        if (pos == count){
            *st = current_node->data;
            return 1;
        }
        count ++;
    }

    return 0;
}

void displayStudents(StudentList *st_list){
    if (empty(st_list)){
        printf("A lista esta vazia!");
    }

    Node *current_node = st_list->head;
    while (current_node != NULL){
        printf("%s\n", current_node->data.name);
        current_node = current_node->next;
    }
}

int removeStudentRegist(StudentList *st_list, int regist){
    if (empty(st_list)){
        return 0;
    }

    if ((st_list->head->data.registration == regist)){
        if (size_list(st_list) == 1){
            Node *ass = st_list->head;
            st_list->head = NULL;
            free(st_list->head);
            return 1;
        }

        else{
            Node *ass = st_list->head;
            st_list->head = st_list->head->next;
            free(ass);
            return 1;
        }
    }

    Node *current_node = st_list->head;
    while (current_node != NULL){
        if (current_node->next->data.registration == regist){
            if (current_node->next->next == NULL){
                Node *ass = current_node->next;
                current_node->next = NULL;
                free(ass);
                return 1;
            }

            else{
                Node *ass = current_node->next;
                current_node->next = current_node->next->next;
                free(ass);
                return 1;
            }
        }
        current_node = current_node->next;
    }

    return 0;
}

