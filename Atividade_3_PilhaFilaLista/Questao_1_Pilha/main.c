#include <stdio.h>
#include "pilhaenc.h"

int main(void){ // Testes:

    Stack pilha;
    create(&pilha);

    if (stackUp(&pilha, 10)){
        printf("Adicionado com sucesso!\n");
    }

    display(&pilha);
    displayTop(&pilha);

    printf("-------------------\n");

    if (stackUp(&pilha, 20)){
        printf("Adicionado com sucesso!\n");
    }
    if (stackUp(&pilha, 30)){
        printf("Adicionado com sucesso!\n");
    }
    if (stackUp(&pilha, 40)){
        printf("Adicionado com sucesso!\n");
    }

    display(&pilha);
    displayTop(&pilha);

    printf("-------------------\n");

    if (unstack(&pilha)){
        printf("Removido com sucesso!\n");
    }

    display(&pilha);
    displayTop(&pilha);

    printf("-------------------\n");

    toEmpty(&pilha);
    if (sizeStack(&pilha) == 0){
        printf("A pilha esta vazia\n");
    }

    return 0;
}