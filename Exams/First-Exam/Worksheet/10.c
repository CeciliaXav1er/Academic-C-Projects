#include <stdio.h>
#include <string.h>
#define TAM 5

/*
Crie um programa em C para checar se uma string é palíndromo ou não
ex.: 
Entrada = RADAR
Saída = É palíndromo
*/

int main() {

    char arr1[TAM+1] = {"SALAS"};
    char arr2[TAM+1];
    int check=0;

    for (int i = 0, j = TAM - 1; i < TAM; i++, j--) {
        arr2[j] = arr1[i];
    }
    arr2[TAM] = '\0';


    for (int i = 0; i < TAM; i++) {
        if (arr1[i]==arr2[i]) {
            check++;
        }
    }
    if (check==(TAM)) {
        printf("E palindromo");
    } else {
        printf("n e palindromo");
    }
    return 0;
}