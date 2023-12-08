#include <stdio.h>
#include <string.h>
#include "funcionario.h"

void ordem_alfabetica_func(int tam, Funcionario *vf){
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

Funcionario *buscabin_func(int n, Funcionario *vf[], char *nome);
Funcionario *exibe_top3_salarios(int n, Funcionario *vf[], char *nome); 