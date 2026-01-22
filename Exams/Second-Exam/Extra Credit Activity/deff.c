#include "deff.h"

Usuario* buscarUsuario(Usuario *users, char *nome, int tam) {
    if (users == NULL) return NULL;
    for (int i = 0; i < tam; i++) {
        if (strcmp(users[i].nome, nome) == 0) return &users[i];
    }
    return NULL;
}

Usuario* buscarPorID(Usuario *users, int id, int tam) {
    if (users == NULL) return NULL;
    for (int i = 0; i < tam; i++) {
        if (users[i].id == id) return &users[i];
    }
    return NULL;
}

Usuario *addUser(Usuario *users, Usuario newUser, int *tam) {
    (*tam)++;
    Usuario *temp = (Usuario*)realloc(users, (*tam) * sizeof(Usuario));
    if (temp == NULL) {
        printf("Erro ao alocar memoria!\n");
        (*tam)--;
        return users;
    }
    newUser.id = *tam;
    newUser.idAmigos = NULL;
    newUser.qtdAmigos = 0;
    newUser.assistidos = NULL;
    newUser.qtdAssistidos = 0;
    temp[(*tam) - 1] = newUser;
    return temp;
}

Usuario *removeUser(Usuario *users, char remover[], int *tam) {
    for (int i = 0; i < *tam; i++) {
        if (strcmp(users[i].nome, remover) == 0) {
            users[i] = users[(*tam) - 1];
            (*tam)--;
            if (*tam == 0) { free(users); return NULL; }
            return (Usuario*)realloc(users, (*tam) * sizeof(Usuario));
        }
    }
    printf("O usuario %s nao foi achado.\n", remover);
    return users;
}

void addAmigo(Usuario *users, char enviaAm[], char recebeAm[], int tam) {
    Usuario *uE = buscarUsuario(users, enviaAm, tam);
    Usuario *uR = buscarUsuario(users, recebeAm, tam);
    if (!uE || !uR) {
        printf("Usuarios nao encontrados!\n");
        return;
    }
    uE->qtdAmigos++;
    uE->idAmigos = (int*)realloc(uE->idAmigos, uE->qtdAmigos * sizeof(int));
    uE->idAmigos[uE->qtdAmigos-1] = uR->id;

    uR->qtdAmigos++;
    uR->idAmigos = (int*)realloc(uR->idAmigos, uR->qtdAmigos * sizeof(int));
    uR->idAmigos[uR->qtdAmigos-1] = uE->id;
}

void removeAmigo(Usuario *users, char amigo1[], char amigo2[], int tam) {
    Usuario *u1 = buscarUsuario(users, amigo1, tam);
    Usuario *u2 = buscarUsuario(users, amigo2, tam);
    if (!u1 || !u2) {
        printf("Usuarios nao encontrados!\n");
        return;
    }
    for(int i = 0; i < u1->qtdAmigos; i++) {
        if (u1->idAmigos[i] == u2->id) {
            u1->idAmigos[i] = u1->idAmigos[u1->qtdAmigos - 1];
            u1->qtdAmigos--;
            break;
        }
    }
    for(int i = 0; i < u2->qtdAmigos; i++) {
        if (u2->idAmigos[i] == u1->id) {
            u2->idAmigos[i] = u2->idAmigos[u2->qtdAmigos - 1];
            u2->qtdAmigos--;
            break;
        }
    }
}

Recomendacao* gerarRecomendacoes(Usuario *users, char *nomeUser, int tam, int *totalRec) {
    *totalRec = 0;
    Usuario *u = buscarUsuario(users, nomeUser, tam);
    if (!u) return NULL;


    Recomendacao *lista = (Recomendacao*) malloc(100 * sizeof(Recomendacao));

    for (int i = 0; i < u->qtdAmigos; i++) {
        Usuario *amigo = buscarPorID(users, u->idAmigos[i], tam);
        if (!amigo) continue;

        for (int j = 0; j < amigo->qtdAssistidos; j++) {
            Filme fAmigo = amigo->assistidos[j].filme;


            int match = (fAmigo.tipo.acao && u->interesse.acao) ||
                        (fAmigo.tipo.comedia && u->interesse.comedia) ||
                        (fAmigo.tipo.drama && u->interesse.drama) ||
                        (fAmigo.tipo.terror && u->interesse.terror) ||
                        (fAmigo.tipo.romance && u->interesse.romance);
            if (!match) continue;


            int jaVisto = FALSE;
            for (int k = 0; k < u->qtdAssistidos; k++) {
                if (strcmp(u->assistidos[k].filme.titulo, fAmigo.titulo) == 0) {
                    jaVisto = TRUE;
                    break;
                }
            }
            if (jaVisto) continue;


            int existe = -1;
            for (int r = 0; r < *totalRec; r++) {
                if (strcmp(lista[r].filme.titulo, fAmigo.titulo) == 0) {
                    existe = r;
                    break;
                }
            }

            if (existe != -1) {
                lista[existe].frequencia++;
            } else {
                lista[*totalRec].filme = fAmigo;
                lista[*totalRec].frequencia = 1;
                (*totalRec)++;
            }
        }
    }

    for (int i = 0; i < (*totalRec) - 1; i++) {
        for (int j = 0; j < (*totalRec) - i - 1; j++) {
            if (lista[j].frequencia < lista[j+1].frequencia) {
                Recomendacao temp = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = temp;
            }
        }
    }

    return lista;
}

void limparMemoria(Usuario *users, int tam) {
    if (users == NULL) return;

    for (int i = 0; i < tam; i++) {

        if (users[i].assistidos != NULL) {
            free(users[i].assistidos);
        }

        if (users[i].idAmigos != NULL) {
            free(users[i].idAmigos);
        }
    }

    free(users);

}
