#include <stdio.h>
#include <stdlib.h> // Essencial para malloc, realloc e free
#include <string.h>

// 1. STRUCTS E UNIONS (Lab 11)
union Valor {
    float temp;
    int erro;
    char status;
};

typedef struct {
    char tipo; // 'T', 'E' ou 'S'
    union Valor dado; // Union economiza memória: só um campo é usado por vez
} PacoteSensor;

typedef struct {
    char modelo[50];
    int ano;
} Carro;

// Busca Binária Recursiva
int buscaBinaria(int *vet, int inicio, int fim, int alvo) {
    if (inicio > fim) return -1;
    int meio = (inicio + fim) / 2;
    if (vet[meio] == alvo) return meio;
    if (vet[meio] > alvo) return buscaBinaria(vet, inicio, meio - 1, alvo);
    return buscaBinaria(vet, meio + 1, fim, alvo);
}

// Checar Palíndromo Recursivo (Ex: 121 ou "osso")
int ehPalindromo(char str[], int s, int e) {
    if (s >= e) return 1;
    if (str[s] != str[e]) return 0;
    return ehPalindromo(str, s + 1, e - 1);
}

//Ponteiros
void inverterArray(int *ptr, int tam) {
    int *inicio = ptr;
    int *fim = ptr + tam - 1; // Aritmética de ponteiro
    while (inicio < fim) {
        int temp = *inicio;
        *inicio = *fim;
        *fim = temp;
        inicio++;
        fim--;
    }
}

int main() {
    // PONTEIROS
    int numeros[5] = {10, 20, 30, 40, 50};
    inverterArray(numeros, 5);
    printf("Array invertido: %d %d\n", numeros[0], numeros[1]);

    // ALOCAÇÃO DINÂMICA 
    // Malloc para um vetor
    int *v_dinamico = (int*) malloc(3 * sizeof(int));
    v_dinamico[0] = 100;

    // Realloc para aumentar o tamanho (Ex: Cadastro de Carros)
    v_dinamico = (int*) realloc(v_dinamico, 5 * sizeof(int));
    v_dinamico[3] = 400;
    free(v_dinamico); // Sempre limpe a memória alocada!

    // MATRIZ DINÂMICA 
    int linhas = 2, colunas = 2;
    int **matriz = (int**) malloc(linhas * sizeof(int*));
    for(int i = 0; i < linhas; i++) {
        matriz[i] = (int*) malloc(colunas * sizeof(int));
    }
    // Para acessar: matriz[i][j] = 10;
    
    // UNION E STRUCT NA PRÁTICA
    PacoteSensor p1;
    p1.tipo = 'T';
    p1.dado.temp = 36.5; // Aqui a union armazena o float
    printf("Sensor Tipo %c: %.1f C\n", p1.tipo, p1.dado.temp);

    // RECURSÃO
    int ordenado[] = {1, 3, 5, 7, 9};
    int pos = buscaBinaria(ordenado, 0, 4, 7);
    printf("O 7 esta na posicao: %d\n", pos);

    char palavra[] = "arara";
    if(ehPalindromo(palavra, 0, strlen(palavra)-1))
        printf("%s eh palindromo!\n", palavra);

    return 0;
}
