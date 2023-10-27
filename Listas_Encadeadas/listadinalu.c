#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listadinalu.h"

void create(StudentList *st_list){
    st_list->head = NULL; // Primeiro nó é NULL
}

int empty(StudentList *st_list){
    if (st_list->head == NULL){ // Se o primeiro nó for NULL, a lista está vazia
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
        while (current_node != NULL){ // A cada iteração ele adiciona 1 ao tamanho da lista (size_value)
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

    Node *new_node = (Node *) malloc(sizeof(Node)); // Aloca memória para o novo nó

    if (new_node == NULL){
        return 0;
    }

    new_node->data = st;
    new_node->next = NULL; // Define o proximo do ultimo nó como NULL

    if (empty(st_list)){
        st_list->head = new_node;
        return 1;
    }

    Node *current_node = st_list->head;
    while (current_node->next != NULL){ // Percorre a lista para obter o endereço do ultimo nó
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
    while (current_node != NULL){ // Percorre a lista e a cada iteração adiciona 1 ao contador para encontrar a posição desejada
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
    while (current_node != NULL){ // Percorre a lista e printa os nomes dos estudantes
        printf("%s\n", current_node->data.name);
        current_node = current_node->next;
    }
}

int removeStudentRegist(StudentList *st_list, int regist){
    if (empty(st_list)){
        return 0;
    }

    Node *first_node = st_list->head; // Ponteiro auxiliar para guardar o endereço do primeiro nó

    if ((first_node->data.registration == regist)){ // Se o aluno com matrícula que deseja remover for o primeiro da lista
        st_list->head = first_node->next;
        free(first_node);
        return 1;
    }

    Node *current_node = st_list->head;
    while (current_node != NULL){ // Se o aluno com matrícula que deseja remover não for o primeiro da lista
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
    if (type == 0){ // Se o tipo = 0 (matrícula)
        int *point_regist = (int *) data; // Muda o tipo do ponteiro data para int e atribui ao ponteiro "point_regist"
        int st_regist = *point_regist;

        Node *current_node = st_list->head;
        while (current_node != NULL){
            if (current_node->data.registration == st_regist){
                printf("Nome: %s\nMatricula: %d\nNota 1: %.2f\nNota 2: %.2f\n", current_node->data.name, current_node->data.registration, current_node->data.grade1, current_node->data.grade2);
                return 1;            
            }
            current_node = current_node->next;
        }
    }

    else if (type == 1){ // Se o tipo = 1 (nome)
        char *point_name = (char *) data; // Muda o tipo do ponteiro data para char e atribui ao ponteiro "point_name"
        char st_name[50];
        strcpy(st_name, point_name);

        Node *current_node = st_list->head;
        while (current_node != NULL){
            if (strcmp(current_node->data.name, st_name) == 0){
                printf("Nome: %s\nMatricula: %d\nNota 1: %.2f\nNota 2: %.2f\n", st_name, current_node->data.registration, current_node->data.grade1, current_node->data.grade2);
                return 1;            
            }
            current_node = current_node->next;
        }
    }

    else{ // Se tipo não nem 1 nem 0
        return 0;
    }
}
    

int insertStudentPos(StudentList *st_list, Student st, int pos){
    if (empty(st_list) || pos < 0 || pos > size_list(st_list)){
        return 0;
    }

    Node *new_node = (Node *) malloc(sizeof(Node)); // Aloca memória para o novo nó

    new_node->data = st; // o dado do novo nó vai ser o estudante (st) recebido como parãmetro

    if (pos == 0){ // Se for adicionar na primeira posicao
        Node *ass = st_list->head;
        st_list->head = new_node;
        new_node->next = ass;
        return 1;
    }

    int current_pos = 0;

    Node *current_node = st_list->head; // Se não for para adicionar na primeira posicao
    while (current_node != NULL){
        if (pos == current_pos + 1){ // Se a proxima posição (current_pos + 1) é a que queremos inserir o novo nó
            Node *ass = current_node->next;
            current_node->next = new_node;
            new_node->next = ass;
            return 1;
        }
        current_node = current_node->next;
        current_pos ++;
    }
}

int insertSortLowerId(StudentList *st_list, Student st){

    Node *new_node = (Node *) malloc(sizeof(Node));

    if (new_node == NULL){
        return 0;
    }

    new_node->data = st;

    if ((empty(st_list)) || (st_list->head->data.registration > st.registration)){ // Se o primeiro tiver matrícula maior que o novo estudante
        Node *ass = st_list->head;
        st_list->head = new_node;
        new_node->next = ass;
        return 1;
    }

    Node *current_node = st_list->head;
    while (current_node->next != NULL){ // Se o primeiro não tiver a matrícula maior que a do novo estudante
        if (current_node->next->data.registration > st.registration){
            Node *ass = current_node->next;
            current_node->next = new_node;
            new_node->next = ass;
            return 1;
        }
        current_node = current_node->next;
    }
    new_node->next = NULL; // Se não encontrou nenhum aluno com matrícula maior que a do novo estudante, então ele passa a ser o ultimo
    current_node->next = new_node;

    return 1;
}