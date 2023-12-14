#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcionarios.h"

void ordem_alfabetica_func(int tam, Funcionario *vf) {
    int continua, fim = tam-1;
    Funcionario aux;

    while (continua != -1){
        continua = -1;
        for (int i=0; i<fim; i++){
            if (strcmp(vf[i].nome, vf[i+1].nome) > 0){
                aux = vf[i];
                vf[i] = vf[i+1];
                vf[i+1] = aux;
                continua = i;
            }
        }
        fim --;
    }
}

Funcionario *busca_func(int n, Funcionario *vf, char *nome){

    int inicio = 0, meio, fim = n-1;
    while (inicio <= fim){
        meio = (fim + inicio) / 2;

        if (strcmp(vf[meio].nome, nome) == 0){
            return &vf[meio];
        }

        else if (strcmp(vf[meio].nome, nome) > 0){
            fim = meio -1;
        }

        else{
            inicio = meio + 1;
        }
    }
    return NULL;
}

Funcionario *buscabin_func(int n, Funcionario *vf[], char *nome) {

    int inicio = 0, meio, fim = n-1;
    while (inicio <= fim){
        meio = (fim + inicio) / 2;

        if (strcmp(vf[meio]->nome, nome) == 0){
            return vf[meio];
        }

        else if (strcmp(vf[meio]->nome, nome) > 0){
            fim = meio -1;
        }

        else{
            inicio = meio + 1;
        }
    }
    return NULL;
}


Funcionario *exibe_top3_salarios(int n, Funcionario *vf[]) {
    if (n == 0) {
        printf("Nao ha funcionarios\n");
        return NULL;
    }

    float salario[n];
    for (int i = 0; i < n; i++) {
        salario[i] = vf[i]->horas_mes * vf[i]->valor_hora;
    }
    
    int indices[n];
    for (int i = 0; i < n; i++) {
        indices[i] = i;
    }

    for (int i = 1; i < n; i++) {
        int atual = indices[i];
        int j = i - 1;

        while (j >= 0 && salario[atual] > salario[indices[j]]) {
            indices[j + 1] = indices[j];
            j = j - 1;
        }
        indices[j + 1] = atual;
    }
    int contador_pos = 1;
    for (int i = 0; i < 3; i++, contador_pos++) {
        int indice = indices[i];
        printf("%d lugar: %s\n", contador_pos, vf[indice]->nome);
    }
    return vf[indices[0]];
}