#include <stdio.h>
#define TAM 8
#define TRUE 1
#define FALSE 0
/*
Escreva um programa em C para contar o número total de elementos duplicados em um vetor.
*/

int main() {
    
    int v[TAM] = {0, 5, 2, 3, 2, 3, 2, 5};
    int encontrado[TAM] = {0};
    int contador = 0, found;
    
    for (int i = 0; i < TAM; i++) {
        if (encontrado[i]==1) {
            continue;
        }
        found = FALSE;
        for (int j = i+1; j < TAM; j++) {
            if (v[i] == v[j]) {
                found = TRUE;
                encontrado[j] = 1;
            }
        }
        if (found) {
            contador++;
            encontrado[i] = 1;
        }
    }
    printf("O número de duplicatas é %d", contador);
    return 0;
}