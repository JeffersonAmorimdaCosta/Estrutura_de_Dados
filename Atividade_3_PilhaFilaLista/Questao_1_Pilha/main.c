#include <stdio.h>
#include <limits.h>
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
    if (stackUp(&pilha, 50)){
        printf("Adicionado com sucesso!\n");
    }
    if (stackUp(&pilha, 60)){
        printf("Adicionado com sucesso!\n");
    }
    if (stackUp(&pilha, 70)){
        printf("Adicionado com sucesso!\n");
    }


    display(&pilha);
    displayTop(&pilha);

    printf("-------------------\n");

    if (unstack(&pilha) != INT_MIN){
        printf("Removido com sucesso!\n");
    }

    display(&pilha);
    displayTop(&pilha);

    printf("-------------------\n");

    if (reverse(&pilha)){
        printf("A pilha foi invertida com sucesso!\n");
    }

    display(&pilha);

    return 0;
}