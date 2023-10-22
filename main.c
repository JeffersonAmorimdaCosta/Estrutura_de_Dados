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

    if (insertEnd(&my_list, st1)){
        printf("Inserido com sucesso!\n");
    }

    if (insertEnd(&my_list, st2)){
        printf("Inserido com sucesso!\n");
    }

    Student st3;

    if (searchStudentPos(&my_list, 1, &st3)){
        printf("A matricula: %s\n", st3.name);
    }

    else{
        printf("Nao encontrado!\n");
    }

    displayStudents(&my_list);

    if (removeStudentRegist(&my_list, 1011)){
        printf("Aluno removido com sucesso!\n");
    }

    displayStudents(&my_list);

    return 0;
}