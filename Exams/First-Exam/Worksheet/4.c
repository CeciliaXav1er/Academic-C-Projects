#include <stdio.h>
#define TAM 5
/*
Escreva um programa que ordene um vetor (inteiros) de maneira não-decrescente.
*/
int main() {
    int v[TAM] = {1,70,5,1002,9}; 
    int aux;

    for (int i = 0; i<TAM-1; i++) {
        if (v[i] > v[i+1]) {
            aux = v[i];
            v[i] = v[i+1];
            v[i+1] = aux;
            i=0; // Para caso haja valores duplicados, se for garantido que não estejam presentes no v, n precisa
        }
    }

    for (int i = 0; i<TAM; i++) {
        printf("%d ", v[i]);
    }
    return 0;
}