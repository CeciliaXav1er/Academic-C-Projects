#include<stdio.h>

int multiplicar(int num1, int num2) {
    int res;
    res = num1 * num2;
    return(res);
}

int main(void) 
{
    //váriáveis
    int num = 10; //atribuindo valor para a variável
    float num2 = 6.79;
    char letra = 'a';
    char frase[10] = "Bom dia!";
    double num3 = 1.23356; //cal cientificos, MAIOR PRECISÃO
    int valor1, valor2, soma, sub, mult, di, numero, resto, dia, cont;
    float nota1, nota2, media, freq;

    
    //Chamando Funções
    int v1, v2, resultado;
    printf("Digite o primeiro valor inteiro: ");
    scanf("%d",  &v1);
    printf("Digite o segundo valor inteiro: ");
    scanf("%d",  &v2);

    resultado = multiplicar(v1, v2);

    printf("Resultado = %d\n\n", resultado);
    
    //Uso do comando printf
    printf("Exibindo o num inteiro %d\n", num); //%d inteiro decimal
    printf("Exibindo o num real %f\n", num2);
    printf("Exibindo o char %c\n", letra);
    printf("%s\n", frase);
    printf("Exibindo o num double %f\n", num3);
    printf("Exibindo:%d, %f, %c, %s, %f\n", num, num2, letra, frase, num3);
    
    printf("Hello, World!\n");
    
    //Uso do scanf
    printf("Digite um num inteiro:\n");
    scanf("%d", &valor1);
    printf("Digite um num inteiro:\n");
    scanf("%d", &valor2);

    //operações
    soma = valor1 + valor2;
    sub = valor1 - valor2;
    mult = valor1 * valor2;
    di = valor1 / valor2; // divisão inteira

    printf("valor da soma de %d + %d = %d \n", valor1, valor2, soma);
    printf("valor da subtracao de %d - %d = %d \n", valor1, valor2, sub);
    printf("valor da multiplicacao de %d * %d = %d \n", valor1, valor2, mult);
    printf("valor da divisao de %d + %d / %d \n", valor1, valor2, di);
    
    printf("Digite um num inteiro: ");
    scanf("%d", &numero);
    resto = numero%2; //dividindo a variavel por dois e recebendo o resto
    printf("Resto da divisao: %d\n", resto);
    
    if(resto==0)
    {
        printf("Numero par!\n");
    }
    else
    {
        printf("Numero impar!\n");
    }
    
    printf("Digite um numero de 1 a 7 : ");
    scanf("%d", &dia);
    
    switch(dia) {
        case 1:
        printf("Domingo\n");
        break;
        
        case 2:
        printf("Segunda\n");
        break;
        
        case 3:
        printf("Terça\n");
        break;
        
        case 4:
        printf("Quarta\n");
        break;
        
        case 5:
        printf("Quinta\n");
        break;
        
        case 6:
        printf("Sexta\n");
        break;
        
        case 7:
        printf("Sabado\n");
        break;
        
        default:
        printf("Valor Invalido!\n");
    }
    
    // Operador Ternário
    printf("Digite um nuemro inteiro:");
    scanf("%d", &numero);
    
    // Condição a testar ? verdadeiro : falso
    numero > 0 ? printf("Positivo\n") : printf("Negativo\n");
    
    //Formatação de casas decimais
    printf("Digite a frequencia: ");
    scanf("%f", &freq);
    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);
    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);
    
    media = (nota1 + nota2) / 2;
    printf("Media = %.1f\n", media); //formatação
    
    //if aninhado
    if(media >= 6 && freq >= 75) //operador logico AND
    {
        printf("Aprovado!\n");
    } else {
        if (media < 3 || freq < 75) //operador logico OR
        {
            printf("Reprovado!\n");
        } else {
            printf("Em recuperacao!\n");
        }
    }
    
    // ---- Estrutura de Repetição FOR ----
    //(inicio; fim; incremento ou decremento)
    for (cont = 100; cont >= 0; cont--) {
        printf("%d - Boa Tarde!\n", cont);
    }
    
    // ---- Estrutura de Repetição WHILE ----
    cont = 1;
    while(cont <= 5) {
        printf("%d - Linguagem C \n", cont);
        cont++;
    }
    
    // ---- Estrutura de Repetição DO WHILE ----
    // garante que os comandos sejam executados pelo menos uma vez
    cont = 1;
    #define TESTE cont>0
    do {
        printf("Digite um valor positivo: \n");
        scanf("%d", &cont);
        if (TESTE) { printf("Numero Invalido!\n"); }
    } while (TESTE);
    
    // Declarando e Inicializando o vetor v1
    float vetor1[4] = {7.1, 8.4, 9.5, 5.2};
    printf("Exibindo os Valores do Vetor \n\n");
    printf("vetor1[0] = %.1f\n", vetor1[0]);
    printf("vetor1[1] = %.1f\n", vetor1[1]);
    printf("vetor1[2] = %.1f\n", vetor1[2]);
    printf("vetor1[3] = %.1f\n\n", vetor1[3]);
    
    int i;
    for(i=0; i<4; i++){
        printf("vetor1[%d] = %.1f\n", i, vetor1[i]);
    }
    
    // Declarando uma matriz
    #define LINHAS 2
    #define COLUNAS 2
    
    int matriz[LINHAS][COLUNAS], i, j;
    
    printf ("\nDigite um valor para a matriz\n\n");
    //recebendo os valores da matriz
    for (i=0; i<LINHAS; i++) { //controla a linha
        for (j=0; j<COLUNAS; j++) { //controla a coluna
        printf("\nElemento[%d][%d] = ", i, j);
        scanf("%d", &matriz[i][j]);
        }
    }

    printf("\n\n------------ Saida de Dados ------------\n\n");
    for (i=0; i<LINHAS; i++) { //controla a linha
        for (j=0; j<COLUNAS; j++) { //controla a coluna
            printf("\nElemento[%d][%d] = %d", i, j, matriz[i][j]);
        }
    }
struct ficha_aluno {
    int matricula;
    float nota1;
    float nota2;
};

struct ficha_aluno aluno;

printf("Informe o numero de matricula: ");
scanf("%d", &aluno.matricula);

printf("Informe a 1a nota: ");
scanf("%f", &aluno.nota1);

printf("Informe a 2a nota: ");
scanf("%f", &aluno.nota2);

printf("\n\n ------------ Lendo os Dados da Struct ------------\n\n");
printf("Matricula ------ %d\n", aluno.matricula);
printf("Nota 1 --------- %.2f\n", aluno.nota1);
printf("Nota 2 --------- %.2f\n", aluno.nota2);

    return 0;
}
