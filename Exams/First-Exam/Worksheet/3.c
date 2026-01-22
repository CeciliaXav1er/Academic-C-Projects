#include <stdio.h>
#define TAM 12
/*
Escreva um programa em C para deletar um valor de um vetor, 
em seguida, mostre esse vetor. O vetor não pode ficar com posições vazias.
*/

int main() {
    int valor, recomece, size;
    int v[TAM] = {1, 5, 0, 9, 2, 3, 1, 1, 1, 1, 1, 0};
    size = TAM;

    do {
        printf("Selecione o valor a ser excluido: ");
        scanf("%d", &valor);

        for (int i = 0; i<size; i++){
            if (v[i]==valor) {
                for (int j=i; j<size-1; j++) {
                    v[j] = v[j+1];
                }
                size--; //diminuindo o valor máximo
                i--; //reavaliando o novo v[i]
            }
        }
        if (size==0) { //checando se foram removidos todos os valores
            printf("Foram removidos todos os valores do vetor");
        }

        for (int i = 0; i<size; i++) {
            printf("%d ", v[i]);
        }

        //mantendo o código executavel novamente
        printf("\nDeseja continuar? Digite 1\nSe nao, digite 0\n");
        scanf("%d", &recomece);
        if (recomece != 1) {
            break;
        }
    } while (recomece);
    return 0;
}