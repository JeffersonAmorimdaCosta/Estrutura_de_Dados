#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    struct no *dir;
    struct no *esq;
    int dado;
} No;

typedef struct arv{
    No *raiz;
} Arv;

No* inserir(No *raiz, int valor){

    if (raiz == NULL){
        No *novo = (No *) malloc(sizeof(No));
        novo->dado = valor;
        novo->dir = novo->esq = NULL;
        return novo;
    }

    else{
        if (valor < raiz->dado){
            raiz->esq = inserir(raiz->esq, valor);
        }

        else if (valor > raiz->dado){
            raiz->dir = inserir(raiz->dir, valor);
        }
        return raiz;
    }
}

void exibirArv(No* raiz){
    if (raiz != NULL){
        exibirArv(raiz->esq);
        printf("%d ", raiz->dado);
        exibirArv(raiz->dir);
    }
}

int busca(No* raiz, int valor){
    if (raiz == NULL){
        return 0;
    }

    else{
        if (raiz->dado == valor){
            return 1;
        }

        else{
            if (valor < raiz->dado){
                return busca(raiz->esq, valor);
            }

            else{
                return busca(raiz->dir, valor);
            }
        }
    }
}

int tamanho(No* raiz){
    if (raiz == NULL){
        return 0;
    }

    else{
        return 1 + tamanho(raiz->esq) + tamanho(raiz->dir);
    }
}

No* remover(No *raiz, int valor){
    if (raiz == NULL){
        return NULL;
    }

    else{
        if (raiz->dado == valor){
            if ((raiz->esq == NULL) && (raiz->dir == NULL)){ // remover no folha
                free(raiz);
                return NULL;
            }

            else if ((raiz->esq == NULL) && (raiz->dir != NULL)){ // remover no so com filho a direita
                No *aux = raiz;
                raiz = raiz->dir;
                free(aux);
            }

            else if ((raiz->dir == NULL) && (raiz->esq != NULL)){ // remover no so com filho a esquerda
                No *aux = raiz;
                raiz = raiz->esq;
                free(aux);
            }

            else{                       // Remover no com 2 filhos
                No *aux = raiz->esq;
                while (aux->dir != NULL){
                    aux = aux->dir;
                }
                raiz->dado = aux->dado;
                aux->dado = valor;
                raiz->esq = remover(raiz->esq, valor);
            }
            return raiz; // Retorna a raiz para salvas as alterações
        }

        else{
            if (valor < raiz->dado){
                raiz->esq = remover(raiz->esq, valor);
            }

            else{
                raiz->dir = remover(raiz->dir, valor);
            }
            return raiz;
        }
    }
}