#ifndef DEFF_H
#define DEFF_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    int acao, comedia, drama, terror, romance;
} Genero;

typedef struct {
    int completo;
    int dia_semana;
    char turno[20];
} Status;

typedef struct {
    char titulo[100];
    char descricao[300];
    char produtora[100];
    Genero tipo;
    int duracao;
    int ano;
} Filme;

typedef struct {
    Filme filme;
    Status estado;
} Historico;

typedef struct Usuario {
    int id;
    char nome[100];
    int idade;
    Genero interesse;
    Historico *assistidos;
    int qtdAssistidos;
    int *idAmigos;
    int qtdAmigos;
} Usuario;

typedef struct {
    Filme filme;
    int frequencia;
} Recomendacao;

// Assinaturas das fun��es
Usuario* buscarUsuario(Usuario *users, char *nome, int tam);
Usuario* buscarPorID(Usuario *users, int id, int tam);
Usuario* addUser(Usuario *users, Usuario newUser, int *tam);
Usuario* removeUser(Usuario *users, char remover[], int *tam);
Recomendacao* gerarRecomendacoes(Usuario *users, char *nomeUser, int tam, int *totalRec);
void limparMemoria(Usuario *users, int tam);
void addAmigo(Usuario *users, char enviaAm[], char recebeAm[], int tam);
void removeAmigo(Usuario *users, char amigo1[], char amigo2[], int tam);
#endif
