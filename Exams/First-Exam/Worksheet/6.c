#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 5

/*
Crie um programa em C para encontrar a multiplicação 
dos elementos da diagonal principal de uma matriz. 
Essa matriz deve ser 5x5 e preenchida com valores aleatórios.
*/

int main() {
    srand(time(NULL)); // Não entendi direito o que faz, só para testar com outros numeros.
    int mat[TAM][TAM], mult=1;

    //criando a matriz
    for (int i = 0; i<TAM; i++) {
        for (int j=0; j<TAM; j++) {
            mat[i][j] = (rand()%9)+1;
        }
        mult = mult * (mat[i][i]);
    }

    for (int i = 0; i<TAM; i++) {
        for (int j=0; j<TAM; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Multiplicacao dos valores da diagonal principal: %d\n", mult);

    

    
    return 0;
}