#include <stdio.h>
#include <stdlib.h>
#define TAM 5

/*

Crie um programa em C que preencha uma matriz 5x5 com valores 
aleatórios (0 a 9) e a mostre na tela. 
Em seguida, encontre a sua transposta.

Obs.: matriz transposta é a matriz que se obtém da troca de linhas por colunas 

##(rand()%9)+0
*/
void imprimir (int mat[TAM][TAM]) {
    for (int i = 0; i<TAM; i++){
            for (int j=0; j<TAM; j++) {
                printf("%d ", mat[i][j]);
            }
            printf("\n");
        }
    printf("\n");   
}

int main() {
    // OBS: Daria para fazer a questão sem fazer outra matriz
    // seria só imprimir m[j][i];
    int matriz[TAM][TAM],mat_transp[TAM][TAM];
    //Criar a matriz
    for (int i = 0; i<TAM; i++) {
        for (int j = 0; j<TAM; j++) {
            //escolhe um num de 0 a 9
            matriz[i][j] = (rand()%9)+0;
            //cria a matriz transposta
            mat_transp[j][i] = matriz[i][j];
        }
    }

    //Imprimindo a Matriz
    printf("Matriz Normal! \n");
    imprimir(matriz);

    //Imprimindo a transposta
    printf("Matriz Transposta! \n");
    imprimir(mat_transp);

    return 0;
}
