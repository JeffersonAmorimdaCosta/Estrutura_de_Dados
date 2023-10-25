#include <stdio.h>
#include <string.h>
#include "listadinalu.h"

int main(void){ // Testes:

    StudentList my_list;

    create(&my_list);

    Student st1;

    st1.grade1 = 10;
    st1.grade2 = 10;
    strcpy(st1.name, "Jefferson");
    st1.registration = 1001;

    Student st2;

    st2.grade1 = 10;
    st2.grade2 = 10;
    strcpy(st2.name, "Fernando");
    st2.registration = 1011;

    Student st3;

    st3.grade1 = 10;
    st3.grade2 = 10;
    strcpy(st3.name, "Fulano dital");
    st3.registration = 1010;

    if (insertEnd(&my_list, st1)){
        printf("Inserido com sucesso!\n");
    }

    if (insertEnd(&my_list, st2)){
        printf("Inserido com sucesso!\n");
    }

    if (insertEnd(&my_list, st3)){
        printf("Inserido com sucesso!\n");
    }

    displayStudents(&my_list);

    if (removeStudentRegist(&my_list, 1010)){
        printf("Removido com sucesso!\n");
    }

    displayStudents(&my_list);

    return 0;
}