#include "listadup.h"
#include <stdio.h>
#include <stdlib.h>

void criar(ListaDE *l) {
    l->inicio = l->fim = NULL;
    l->tamanho = 0;
}

int vazia(ListaDE *l) {
    if(l->inicio == NULL) {
        return 1;
    }
    return 0;
}

int tamanho(ListaDE *l) {
    return l->tamanho;
}

int inserirFinal(ListaDE *l, TipoTrecho t) {
    No *novo = (No*) malloc(sizeof(No));

    novo->trecho = t;
    novo->ant = novo->prox = NULL;

    if(vazia(l)) {
        l->inicio = l->fim = novo;
        return 1;
    }
    l->fim->prox = novo;
    novo->ant = l->fim;
    l->fim = novo;
    l->tamanho++;
    return 1;
}

int buscaPorElemento(ListaDE *l, int id) {
    No *aux = l->inicio;
    int pos = 0;

    while(aux != NULL) {
        if(aux->trecho.idTrecho == id) {
            return pos;
        }
        pos++;
        aux = aux->prox;
    }
    return -1;
}

int inserirInicio(ListaDE *l, TipoTrecho t) {
    No *novo = (No*) malloc(sizeof(No));
    novo->trecho = t;
    novo->ant = novo->prox = NULL;
    l->tamanho++;

    if(vazia(l)) {
        l->inicio = l->fim = novo;
        return 1;
    }

    novo->prox = l->inicio;
    l->inicio->ant = novo;
    l->inicio = novo;
    return 1;
}

int inserirPosicao(ListaDE *l, TipoTrecho t, int pos) {
    if(pos < 0 || pos > l->tamanho) {
        return 0;
    }
    if(pos == 0) {
        return inserirInicio(l, t);
    }
    if(pos == l->tamanho) {
        return inserirFinal(l, t);
    }
    No *novo = (No*) malloc(sizeof(No));
    No *aux = l->inicio;

    for(int i = 0; i < pos - 1; i++) {
        aux = aux->prox;
    }
    novo->trecho = t;
    novo->ant = aux;
    novo->prox = aux->prox;
    aux->prox->ant = novo;
    aux->prox = novo;
    l->tamanho++;
    return 1;
}

int buscaPorPosicao(ListaDE *l, int pos) {
    if(pos < 0 || pos > l->tamanho) {
        return -1;
    }
    No *aux = l->inicio;
    for(int i = 0; i < pos; i++) {
        aux = aux->prox;
    }
    return aux->trecho.idTrecho;
}

int removerInicio(ListaDE *l) {
    if(vazia(l)) {
        return 0;
    }
    No *temp = l->inicio;
    l->inicio = l->inicio->prox;
    l->inicio->ant = NULL;
    free(temp);
    l->tamanho--;
    return 1;
}

int removerFim(ListaDE *l) {
    if(vazia(l)) {
        return 0;
    }
  No *temp = l->fim;
  l->fim = l->fim->ant;
  l->fim->prox = NULL;
  free(temp);
  return 1;
}

int remover(ListaDE *l, int id) {
    int posId = buscaPorElemento(l, id);

    if(posId == -1) {
        return 0;
    }
    if(posId == 0) {
        return removerInicio(l);
    }
    if(posId == l->tamanho-1) {
        return removerFim(l);
    }

    No *aux = l->inicio;
    for (int i = 0; i < posId - 1; i++) {
        aux = aux->prox;
    }

    No *temp = aux->prox;
    aux->prox->prox->ant = aux;
    aux->prox = aux->prox->prox;
    free(temp);
    l->tamanho--;
    return 1;
}

int percursoTotal(ListaDE *l) {
    int somaDistancias = 0;

    No *aux = l->inicio;
    while(aux != NULL) {
        somaDistancias += aux->trecho.distancia;
    }

    return somaDistancias;
}