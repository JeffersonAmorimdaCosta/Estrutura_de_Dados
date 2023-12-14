#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "funcionarios.h"

int main(void) {
    int n, opcao;
    char name[20];
    printf("Quantidade de funcionarios: ");
    scanf("%d", &n);
    Funcionario vet_func[n];
    Funcionario *vet_fpont[n];
    Funcionario *resultado;

    for(int i = 0; i < n; i++) {
        printf("Nome do funcionario: ");
        scanf("%s", vet_func[i].nome);
        printf("Valor pago por hora: ");
        scanf("%d", &vet_func[i].valor_hora);
        printf("Horas de trabalho mensal: ");
        scanf("%d", &vet_func[i].horas_mes);
    }

    for(int i = 0; i < n; i++) {
        vet_fpont[i] = &vet_func[i];
    }

    while(true) {
        system("cls");
        printf("1 - Exibir top 3 salários\n");
        printf("2 - Ordenar alfabeticamente (faca isso antes de usar as seguintes)\n");
        printf("3 - Busca binaria comum\n");
        printf("4 - Busca binaria com vetor para ponteiros\n");
        printf("5 - Encerrar programa\n\n");

        printf("Opcao desejada: ");
        setbuf(stdin, NULL);
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                if(n < 3) {
                    printf("Sem funcionarios no vetor ou quantidade insuficiente.");
                }
                else{
                    exibe_top3_salarios(n, vet_fpont);
                }
                break;
            case 2:
                if(n == 0) {
                    printf("Sem funcionarios no vetor");
                    break;
                }
                else {
                    ordem_alfabetica_func(n, vet_func);
                    printf("Funcionarios ordenados alfabeticamente!\n");
                }
                break;
            case 3:
                printf("Nome a ser buscado: ");
                setbuf(stdin, NULL);
                scanf("%s", name);
                if(busca_func(n, vet_func, name) == NULL) {
                    printf("Funcionario nao encontrado\n");
                    break;
                }
                else {
                    resultado = busca_func(n, vet_func, name);
                    printf("Pessoa encontrada: %s\n", resultado->nome);
                }
                break;
            case 4:
                printf("Nome a ser buscado: ");
                setbuf(stdin, NULL);
                scanf("%s", name);
                if(buscabin_func(n, vet_fpont, name) == NULL) {
                    printf("Funcionario nao encontrado ou nao ha funcionarios\n");
                    break;
                }
                else {
                    resultado = buscabin_func(n, vet_fpont, name);
                    printf("Pessoa encontrada: %s\n", resultado->nome);
                }
                break;
            case 5:
                printf("Encerrando o Programa...\n");
                exit(1);
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