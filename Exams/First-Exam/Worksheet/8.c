#include <stdio.h>
#include <stdlib.h>
#define TAM1 3
#define TAM2 2
#define TAM3 3
/*
Crie um programa em C que, dada duas matrizes reais  Am x n e Bn x p, calcule o produto de A por B.
*/

int main() {

    int A[TAM1][TAM2];
    int B[TAM2][TAM3];
    int C[TAM1][TAM3];


    int soma = 0;
    
    //Criação das matrizes

    for (int i = 0; i<TAM1; i++) {
        for (int j = 0; j<TAM2; j++) {
            //escolhe um num de 0 a 9
            A[i][j] = (rand()%9)+1;
        }
    }

    for (int i = 0; i<TAM2; i++) {
        for (int j = 0; j<TAM3; j++) {
            //escolhe um num de 0 a 9
            B[i][j] = (rand()%9)+1;
        }
    }

    //fazendo o produto
    for (int m = 0; m<TAM1; m++) {
        for (int p = 0; p<TAM3; p++) {
            soma = 0;
            for (int n = 0; n<TAM2; n++) {
                soma += A[m][n] * B[n][p];
            }
            C[m][p] = soma;
        }
    }

    //Imprimindo as matrizes
    for (int i = 0; i<TAM1; i++){
            for (int j=0; j<TAM2; j++) {
                printf("%d ", A[i][j]);
            }
            printf("\n");
        }
    printf("\n"); 

    for (int i = 0; i<TAM2; i++){
        for (int j=0; j<TAM3; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < TAM1; i++) {
        for (int j = 0; j < TAM3; j++) {
            printf("%d ", C[i][j]);
        }
    printf("\n");
}
    return 0;
}