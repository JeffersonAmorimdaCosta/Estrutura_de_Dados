#include <stdio.h>
#include "listadup.h"

int main(void) {
    ListaDE l;
    TipoTrecho t;
    criar(&l);

    t.direcao = 'E';
    t.distancia = 50;
    t.idTrecho = 1;
    
    if(inserirFinal(&l, t)) {
        printf("Trecho inserido\n");
    }

    percursoTotal(&l);

    return 0;
}