#include <stdio.h>
#include <string.h>
#define TAM1 13
#define TAM2 11
#define TAM3 (TAM1 + TAM2)

/*
Considere dois vetores v1 e v2 ordenados de maneira não-decrescente. 
Crie um programa que mescle v1 e v2 em um terceiro vetor v3, 
de maneira que v3 também fique ordenado.
*/

int main() {

    int v1[TAM1] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 20, 22, 30};
    int v2[TAM2] = {0,2, 4, 6, 8, 10, 12, 14, 16, 18, 19};

    int i, j, k;

    i = 0;
    j = 0;
    k = 0;

    int v3[TAM3];
    //Para ambos os vetores
    while (i < TAM1 && j < TAM2) {
        if (v1[i] <= v2[j]) { 
            v3[k] = v1[i]; 
            i++;
        } else {
            v3[k] = v2[j];
            j++;
        }
        k++;
    }
    //Medida de segurança caso eles sejam de tamanhos diferentes
    while (i<TAM1) {
        v3[k] = v1[i];
        i++;
        k++;
    }
    while (j<TAM2) {
        v3[k] = v2[j];
        j++;
        k++;
    }
           
    for (int i = 0; i < k; i++) {
        printf("%d ", v3[i]);
    }

    printf("\n");

    return 0;

}