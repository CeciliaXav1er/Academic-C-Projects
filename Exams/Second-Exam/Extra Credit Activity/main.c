#include "deff.h"

int main() {
    Usuario *perfis = NULL;
    int totalUsuarios = 0;
    int opcao = -1;
    char nomeAux1[100], nomeAux2[100];
    Usuario novo;

    while (opcao != 0) {
        printf("\n==============================");
        printf("\n      SISTEMA DE FILMES       ");
        printf("\n==============================");
        printf("\n1. Adicionar Usuario");
        printf("\n2. Remover Usuario");
        printf("\n3. Adicionar Amigo");
        printf("\n4. Remover Amigo");
        printf("\n5. Adicionar Filme Assistido");
        printf("\n6. Ver Historico");
        printf("\n7. Recomendar Filmes");
        printf("\n0. Sair");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n--- Novo Usuario ---");
                printf("\nNome: "); scanf(" %[^\n]", novo.nome);
                printf("Idade: "); scanf("%d", &novo.idade);
                printf("Interesse em Acao (0/1): ");
                scanf("%d", &novo.interesse.acao);
                printf("Interesse em Comedia (0/1): ");
                scanf("%d", &novo.interesse.comedia);
                printf("Interesse em Drama (0/1): ");
                scanf("%d", &novo.interesse.drama);
                printf("Interesse em Terror (0/1): ");
                scanf("%d", &novo.interesse.terror);
                printf("Interesse em Romance (0/1): ");
                scanf("%d", &novo.interesse.romance);

                perfis = addUser(perfis, novo, &totalUsuarios);
                printf("\nUsuario cadastrado com sucesso!");
                break;

            case 2:
                printf("\nNome do usuario para remover: ");
                scanf(" %[^\n]", nomeAux1);
                perfis = removeUser(perfis, nomeAux1, &totalUsuarios);
                printf("\nNao se va... Usuario removido com sucesso");
                break;

            case 3:
                printf("\nNome de quem envia o convite: ");
                scanf(" %[^\n]", nomeAux1);
                printf("Nome de quem recebe o convite: ");
                scanf(" %[^\n]", nomeAux2);
                addAmigo(perfis, nomeAux1, nomeAux2, totalUsuarios);
                printf("\nEba! Amizade formada!");
                break;

            case 4:
                printf("\nNome do primeiro amigo: ");
                scanf(" %[^\n]", nomeAux1);
                printf("Nome do segundo amigo: ");
                scanf(" %[^\n]", nomeAux2);
                removeAmigo(perfis, nomeAux1, nomeAux2, totalUsuarios);
                printf("\nPoxa... Amizade desfeita!");
                break;

            case 5:
                printf("\nNome do usuario: ");
                scanf(" %[^\n]", nomeAux1);
                Usuario *u = buscarUsuario(perfis, nomeAux1, totalUsuarios);
                if (u != NULL) {
                    //m� pratica, por�m, a fun��o ficaria sobrecarregada de printfs e scanf
                    u->qtdAssistidos++;
                    u->assistidos = (Historico*)realloc(u->assistidos, u->qtdAssistidos * sizeof(Historico));
                    int fIdx = u->qtdAssistidos - 1;

                    printf("\n--- Dados do Filme (%d) ---", u->qtdAssistidos);
                    printf("\nNome do Filme: ");
                    scanf(" %[^\n]", u->assistidos[fIdx].filme.titulo);
                    printf("Descricao: ");
                    scanf(" %[^\n]", u->assistidos[fIdx].filme.descricao);
                    printf("Produtora: ");
                    scanf(" %[^\n]", u->assistidos[fIdx].filme.produtora);
                    printf("Duracao (min): ");
                    scanf("%d", &u->assistidos[fIdx].filme.duracao);
                    printf("Ano de Lancamento: ");
                    scanf("%d", &u->assistidos[fIdx].filme.ano);
                    printf("\n--- Genero do Filme (0/1) ---");
                    printf("\nAcao: ");
                    scanf("%d", &u->assistidos[fIdx].filme.tipo.acao);
                    printf("Comedia: ");
                    scanf("%d", &u->assistidos[fIdx].filme.tipo.comedia);
                    printf("Drama: ");
                    scanf("%d", &u->assistidos[fIdx].filme.tipo.drama);
                    printf("Terror: ");
                    scanf("%d", &u->assistidos[fIdx].filme.tipo.terror);
                    printf("Romance: ");
                    scanf("%d", &u->assistidos[fIdx].filme.tipo.romance);
                    printf("\n--- Status ---");
                    printf("\nAssistiu ate o fim? (0/1): ");
                    scanf("%d", &u->assistidos[fIdx].estado.completo);
                    printf("Dia (1-7): ");
                    scanf("%d", &u->assistidos[fIdx].estado.dia_semana);
                    printf("Turno: ");
                    scanf(" %[^\n]", u->assistidos[fIdx].estado.turno);
                    printf("\nFilme adicionado ao historico de %s!", u->nome);
                } else printf("\nUsuario nao encontrado!");
                break;

            case 6:
                printf("\nNome do usuario para ver historico: ");
                scanf(" %[^\n]", nomeAux1);
                Usuario *uLog = buscarUsuario(perfis, nomeAux1, totalUsuarios);
                if (uLog) {
                    printf("\n--- MEU HISTORICO (%s) ---", uLog->nome);
                    for(int i=0; i < uLog->qtdAssistidos; i++)
                        printf("\n- %s", uLog->assistidos[i].filme.titulo);

                    printf("\n--- HISTORICO DOS AMIGOS ---");
                    for(int i=0; i < uLog->qtdAmigos; i++) {
                        Usuario *amigo = buscarPorID(perfis, uLog->idAmigos[i], totalUsuarios);
                        if(amigo) for(int j=0; j < amigo->qtdAssistidos; j++)
                            printf("\n%s assistiu: %s", amigo->nome, amigo->assistidos[j].filme.titulo);
                    }
                } else printf("\nUsuario nao encontrado!");
                break;

            case 7:
            printf("\nGerar recomendacoes para: ");
            scanf(" %[^\n]", nomeAux1);

            int totalEncontrado = 0;
            Recomendacao *listaRec = gerarRecomendacoes(perfis, nomeAux1, totalUsuarios, &totalEncontrado);

            if (listaRec != NULL) {
                printf("\n--- RECOMENDACOES PARA %s ---", nomeAux1);

                if (totalEncontrado == 0) {
                    printf("\nNenhuma sugestao nova baseada nos seus interesses.");
                } else {
                    for (int i = 0; i < totalEncontrado; i++) {
                        printf("\n%d. %s", i + 1, listaRec[i].filme.titulo);
                        printf("\n   Popularidade entre amigos: %d", listaRec[i].frequencia);
                        printf("\n   Descricao: %s\n", listaRec[i].filme.descricao);
                    }
                }
                free(listaRec); // Limpa a mem�ria tempor�ria da lista
            } else {
                printf("\nUsuario nao encontrado!");
            }
            break;

            case 0:
                limparMemoria(perfis, totalUsuarios);
                printf("\nEncerrando programa...\n");
                break;
        }
    }
    return 0;
}
