#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    Node *first_node = st_list->head;

    if ((first_node->data.registration == regist)){
        st_list->head = first_node->next;
        free(first_node);
        return 1;
    }

    Node *current_node = st_list->head;
    while (current_node != NULL){
        if (current_node->next->data.registration == regist){
            Node *ass = current_node->next;
            current_node->next = current_node->next->next;
            free(ass);
            return 1;
        }
        current_node = current_node->next;
    }

    return 0;
}

int removeStudentPos(StudentList *st_list, int pos){
    if (empty(st_list) || pos < 0 || pos > size_list(st_list)){ // Verifica se a lista esta vazia ou a posicao informada inválida
        return 0;
    }

    Student st_found; // Criando estudante para aproveitar a função searchStudentPos e retornar se há algum aluno nessa posicao

    if (!(searchStudentPos(st_list, pos, &st_found))){
        return 0;
    }

    if (pos == 0){ // Se for o primeiro elemento
        Node *first_node = st_list->head;
        st_list->head = first_node->next;
        free(first_node);
        return 1;
    }

    int current_pos = 0;
    Node *current_node = st_list->head;
    while (current_node != NULL){ // Procurar em que posição esta o estudante que irá ser removido
        if (pos == current_pos + 1){
            Node *ass = current_node->next;
            current_node->next = current_node->next->next;
            free(ass);
            return 1;
            }
        current_node = current_node->next;
        current_pos ++;
    }
}

int schStudentNameEnrollment(StudentList *st_list, void *data, int type){
    if (type == 0){
        int *point_regist = (int *) data;
        int st_regist = *point_regist;

        Node *current_node = st_list->head;
        while (current_node != NULL){
            if (current_node->data.registration == st_regist){
                printf("Nome: %s\nMatricula: %d\nNota 1: %.2f\nNota 2: %.2f\n", current_node->data.name, current_node->data.registration, current_node->data.grade1, current_node->data.grade2);
            }
            current_node = current_node->next;
        }
    }

    else{
        char *point_name = (char *) data;
        char st_name[50];
        strcpy(st_name, point_name);

        Node *current_node = st_list->head;
        while (current_node != NULL){
            if (strcmp(current_node->data.name, st_name) == 0){
                printf("Nome: %s\nMatricula: %d\nNota 1: %.2f\nNota 2: %.2f\n", st_name, current_node->data.registration, current_node->data.grade1, current_node->data.grade2);
            }
            current_node = current_node->next;
        }
    }
}