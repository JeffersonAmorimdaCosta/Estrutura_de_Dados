#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selectionSort(char cod[][5], int len);

int main(void){

    int n;

    printf("Digite o numero de codigos que vai inserir:\n");
    scanf("%d", &n);

    char codeList[n+1][5];

    for (int i=0; i<n; i++){
        setbuf(stdin, NULL);
        fgets(codeList[i], sizeof(codeList[i]), stdin);
        getchar();
    }

    selectionSort(codeList, n);

    printf("\n");
    for (int i=0; i<n; ++i){
        printf("%s\n", codeList[i]);
    }

    return 0;
}

void selectionSort(char cod[][5], int len){
    int menor, i, j;
    char aux[5];

    for (i=0; i<len; ++i){
        menor = i;
        for (j=i+1; j<len; ++j){
            if (atoi(cod[j]) < atoi(cod[menor])){
                menor = j;
            }
        }

        if (menor != i){
            strcpy(aux, cod[i]);
            strcpy(cod[i], cod[menor]);
            strcpy(cod[menor], aux);
        }
    }
}