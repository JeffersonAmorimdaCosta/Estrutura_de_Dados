#include "arvbinpesq.h"
#include <stdio.h>
#include <stdlib.h>

// Apenas alterei os locais em que deveriam ser mudados para funcionamento com o funcionario.

// cria a árvore
void criar(Arvore *a) { a->raiz = NULL; }

// exibe a árvore com os respectivos galhos que indicam o nível
void exibir(NoArv *r, int n) {
  if (r != NULL) {
    char galho[] = "---";
    exibir(r->esq, n + 1);
    for (int i = 0; i < n; i++) {
      printf("%s", galho);
    }
    printf("%s\n", r->dado.nome);
    exibir(r->dir, n + 1);
  }
}

// insere um novo elemento recursivamente
NoArv *inserir_rec(NoArv *raiz, Funcionario func, int matricula) {
  if (raiz == NULL) {
    NoArv *novo = (NoArv *)malloc(sizeof(NoArv));
    novo->dado = func;
    novo->chave = matricula;
    novo->esq = novo->dir = NULL;
    raiz = novo;
  } else {
    if (matricula < raiz->chave) {
      raiz->esq = inserir_rec(raiz->esq, func, matricula);
    } else {
      raiz->dir = inserir_rec(raiz->dir, func, matricula);
    }
  }
  return raiz;
}

// insere usando uma chamada recursiva dentro de uma função
void insere(Arvore *a, Funcionario func, int matricula) { a->raiz = inserir_rec(a->raiz, func, matricula); }

// insere um novo elemento de forma iterativa
int inserir(Arvore *a, Funcionario func, int matricula) {
  NoArv *novo = malloc(sizeof(NoArv));
  // arvore vazia
  if (novo == NULL)
    return 0;
  novo->dado = func;
  novo->chave = matricula;
  novo->esq = novo->dir = NULL;
  if (a->raiz == NULL) {
    a->raiz = novo;
    return 1;
  }
  // arvore com elementos
  NoArv *atual = a->raiz;
  NoArv *anterior = NULL;
  while (atual != NULL) {
    anterior = atual;
    if (matricula == atual->chave)
      return 0;
    if (matricula > atual->chave)
      atual = atual->dir;
    else
      atual = atual->esq;
  }
  // indicando a posicao do novo no
  if (matricula > anterior->chave)
    anterior->dir = novo;
  else
    anterior->esq = novo;
  return 1;
}

// busca um novo elemento na arvore e retorna se existe ou não
int busca(NoArv *raiz, int matricula) {
  NoArv *atual = raiz;
  while (atual != NULL) {
    if (atual->chave == matricula)
      return 1;
    if (matricula > atual->chave)
      atual = atual->dir;
    else
      atual = atual->esq;
  }
  return 0;
}

// função que define um novo sucessor em casos de remoção de nós com dois filhos
NoArv *sucessor(NoArv *atual) {
  NoArv *pai = atual;

  atual = atual->esq;
  if (atual->dir == NULL) {
    return atual;
  }

  while (atual->dir != NULL) {
    pai = atual;
    atual = atual->dir;
  }

  NoArv *aux = pai->dir;
  pai->dir = NULL;
  return aux;
}

// função para remoção que abrange os casos de nó folha, um filho (Esquerda ou Direita) e dois filhos.
int remover(Arvore *a, int matricula) {
  if (busca(a->raiz, matricula) == 0)
    return 0;

  // Procura o elemento a ser deletado
  NoArv *atual = a->raiz;
  NoArv *pai = atual;
  while (atual->chave != matricula) {
    pai = atual;
    if (matricula > atual->chave)
      atual = atual->dir;
    else
      atual = atual->esq;
  }

  // No folha
  if (atual->dir == NULL && atual->esq == NULL) {
    if (atual == a->raiz) {
      free(atual); // raiz
      a->raiz = NULL;
    } else {
      if (pai->dir->chave == matricula) {
        free(pai->dir); // free(atual)
        pai->dir = NULL;
      } else {
        free(pai->esq); // free(atual)
        pai->esq = NULL;
      }
    }
    return 1;
  }

  // No so com filho da direita
  if (atual->dir != NULL && atual->esq == NULL) {
    if (atual == a->raiz) {
      a->raiz = atual->dir;
      free(atual);
    } else if (pai->dir->chave == matricula) {
      NoArv *temp = pai->dir;
      pai->dir = atual->dir;
      free(temp);
    } else {
      NoArv *temp = pai->esq;
      pai->esq = atual->dir;
      free(temp);
    }
    return 1;
  }

  // No so com filho da esquerda
  if (atual->dir == NULL && atual->esq != NULL) {
    if (atual == a->raiz) {
      a->raiz = atual->esq;
      free(atual);
    } else if (pai->dir->chave == matricula) {
      NoArv *temp = pai->dir;
      pai->dir = atual->esq;
      free(temp);
    } else {
      NoArv *temp = pai->dir;
      pai->esq = atual->esq;
      free(temp);
    }

    return 1;
  }

  // No com filho a direita e esquerda
  if (atual->dir != NULL && atual->esq != NULL) {
    NoArv *suc = sucessor(atual);
    if (atual == a->raiz)
      a->raiz = suc;
    else if (pai->dir->chave == matricula)
      pai->dir = suc;
    else
      pai->esq = suc;
    suc->dir = atual->dir;
    if (atual->esq != suc)
      suc->esq = atual->esq;
    NoArv *temp = atual;
    free(temp);
  }
  return 1;
}
