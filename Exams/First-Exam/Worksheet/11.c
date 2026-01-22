#include <stdio.h>
#include <string.h>

/*
Escreva um programa C para contar o número total de palavras em uma string usando loop.
*/

int main() {
    char arr[] = {"meu deus me ajuda"};
    int size = strlen(arr), contador=1; //palavra = ' ' +1
    
    for (int i = 0; i < size; i++) {
        if (arr[i] == ' ') {
            contador++;
        }
    }

    printf("O numero de palavras e: %d", contador);
    return 0;
}