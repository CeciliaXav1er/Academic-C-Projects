#include <stdio.h>
/*
Escreva um programa onde o usuário preencha um vetor v1 com até n valores (n <= 50). 
Em seguida, armazene os valores em ordem inversa em outro vetor v2. Por fim,  mostre os valores de v2.
*/
void imprimir(int v[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", v[i]);
    }
}

int main(void){

    int v1[50], v2[50], size;
    //input do usuario
    do {
        printf("Escolha o tamanho do seu vetor! (Maximo de 50 valores): ");
        scanf("%d", &size);
    } while (size < 0 || size > 50);

    //imprimindo os valores em v1
    for (int i = 0; i < size; i++) {
        printf("%d - Numero = ", i + 1);
        scanf("%d", &v1[i]);
        v2[size-1-i] = v1[i];
    }

    printf("Valores de v1!\n");
    imprimir(v1, size);

    printf("\nValores de v2!\n");
    imprimir(v2, size);

    return 0;
}
