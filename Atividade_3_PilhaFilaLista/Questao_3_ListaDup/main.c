#include <stdio.h>
#include <stdlib.h>
#include "listadup.h"

int main(void) {
    ListaDE l;
    TipoTrecho t;
    criar(&l);

    int opc, valor;

    while (1){
        system("cls");
        printf("LISTA DUPLAMENTE ENCADEADA\n");
        printf("========================================\n");
        printf("0 - Encerrar Programa\n1 - Inserir no Final\n2 - Inserir no Inicio\n3 - Inserir na Posicao\n4 - Exibir Lista\n5 - Buscar Posicao por ID\n6 - Buscar ID por Posicao\n7 - Remover Inicio\n8 - Remover Fim\n9 - Remover pelo ID\n10 - Percurso Total\n\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opc);

        switch (opc){
            
            case 0:
                printf("Encerrando o Programa...\n");
                exit(1);
                break;
            
            case 1:
                printf("Digite o ID: ");
                scanf("%d", &t.idTrecho);
                printf("Digite a Direcao: ");
                setbuf(stdin, NULL);
                scanf("%c", &t.direcao);
                setbuf(stdin, NULL);
                printf("Digite a distancia: ");
                scanf("%f", &t.distancia);

                if (inserirFinal(&l, t)){
                    printf("Insercao feita com sucesso!\n");
                }

                else{
                    printf("Erro na alocacao de memoria.\n");
                }
                break;

            case 2:
                printf("Digite o ID: ");
                scanf("%d", &t.idTrecho);
                printf("Digite a Direcao: ");
                setbuf(stdin, NULL);
                scanf("%c", &t.direcao);
                setbuf(stdin, NULL);
                printf("Digite a distancia: ");
                scanf("%f", &t.distancia);

                if (inserirInicio(&l, t)){
                    printf("Insercao feita com sucesso!\n");
                }

                else{
                    printf("Erro  na alocacao de memoria.\n");
                }
                break;

            case 3:
                printf("Digite o ID: ");
                scanf("%d", &t.idTrecho);
                printf("Digite a Direcao: ");
                setbuf(stdin, NULL);
                scanf("%c", &t.direcao);
                setbuf(stdin, NULL);
                printf("Digite a distancia: ");
                scanf("%f", &t.distancia);
                printf("Digite a posicao em que deseja inserir: ");
                scanf("%d", &valor);

                if (inserirPosicao(&l, t, valor)){
                    printf("Insercao feita com sucesso!\n");
                }

                else{
                    printf("Erro na alocacao de memoria ou posicao invalida.\n");
                }
                break;
            
            case 4:
                exibir(&l);
                break;
            
            case 5:
                printf("Digite o ID para saber sua posicao: ");
                scanf("%d", &valor);

                if (buscaPorElemento(&l, valor) != -1){
                    printf("A posicao do ID %d eh %d", valor, buscaPorElemento(&l, valor));
                }

                else{
                    printf("ID nao encontrado!\n");
                }
                break;
            
            case 6:
                printf("Digite a POSICAO para saber seu ID: ");
                scanf("%d", &valor);

                if (buscaPorPosicao(&l, valor) != -1){
                    printf("O ID na posicao %d eh %d", valor, buscaPorPosicao(&l, valor));
                }

                else{
                    printf("Posicao nao contida na lista.\n");
                }
                break;

            case 7:
                if (removerInicio(&l)){
                    printf("Remocao feita com sucesso!\n");
                }

                else{
                    printf("Erro na remocao, a lista esta vazia.\n");
                }
                break;

            case 8:
                if (removerFim(&l)){
                    printf("Remocao feita com sucesso!\n");
                }

                else{
                    printf("Erro na remocao, a lista esta vazia.\n");
                }
                break;

            case 9:
                printf("Digite o ID que deseja remover: ");
                scanf("%d", &valor);

                if (remover(&l, valor)){
                    printf("Remocao pelo ID realizada com sucesso!\n");
                }

                else{
                    printf("Erro na remocao, o ID nao foi encontrado ou lista esta vazia.\n");
                }
                break;

            case 10:
                printf("O percurso total eh de: %.2f\n", percursoTotal(&l));
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }

        setbuf(stdin, NULL);
        printf("Pressione ENTER para continuar.\n");
        getchar();
    }

    return 0;
}