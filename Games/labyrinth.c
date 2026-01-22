/*
Um labirinto qualquer pode ser representado em termos de espaços 
em branco e *. As paredes são representadas com * e os espaços 
em branco como caminho. Existe ainda uma marcação da posição 
inicial com a letra E e da saída com a letra S. 
Considere ainda que o labirinto pode ser de qualquer tamanho*.

Ex: Labirinto 10x10
*********S
*   *    *
* * * ** *
* *   *  *
* *** ** *
*   *    *
*** * ** *
*   *    *
* *** ****
E********

Dado labirinto neste modelo, implemente:
a) um função, interativa, para encontrar 
um caminho da entrada até a saída. No fim, 
a função deve imprimir as posições do caminho.

b) uma reimplemnetação da primeira função (letra a), 
mas de maneira recursiva. No fim, a função deve imprimir 
as posições do caminho.

*Caso tenha dificuldade de gerar um labirinto, peça a uma IA gerar um exemplo.
*/

#include <stdio.h>
#include <stdlib.h>
#define ROW 20
#define COL 21
#define VALID new_row >= 0 && new_row < num_row && new_col >= 0 && new_col < num_col && maze[new_row][new_col] != '*' && visited[new_row][new_col] == 0

int **create_matrix(int row, int col);
void free_matrix(int **mat, int row);
int valid_path_recursiva(char maze[ROW][COL], int **visited, int row, int col, int num_row, int num_col);
int valid_path_interativa(char maze[ROW][COL], int **visited, int row, int col, int num_row, int num_col);
void find_E(char maze[ROW][COL],int row, int col, int *start_row, int *start_col);
void print_maze(char maze[ROW][COL], int row, int col);

// OBS: Não é necessário ficar repetindo o ROW e COL toda hora, porem fiz assim para quando for incrementar a criação dos labirintos!! 

int main() {
    int start_row=-1, start_col=-1;

    int **visited = create_matrix(ROW, COL);
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            visited[i][j] = 0;
        }
    }

char maze[ROW][COL] = {
        "E*******************",
        "  *   *            *", 
        "* * * * ********** *",
        "*   * * *        * *",
        "***** * * ****** * *",
        "*     * * *    * * *",
        "* ***** * * ** * * *",
        "* *     * * *  *   *",
        "* * ***** * * ** ***",
        "* *       * * *  * *",
        "* ********* * * ** *",
        "* *       * * *    *",
        "* * ***** * * ******",
        "* * *     * *      *",
        "* * * ***** ****** *",
        "*   *            * *",
        "***** ********** * *",
        "*       *      * * *",
        "* ******* **** *  S*",
        "********************"
    };

    find_E(maze, ROW, COL, &start_row, &start_col);
    printf("A Entrada esta em: maze[%d][%d]\n", start_row, start_col);
    if (start_row != -1) {
        printf("\n--- Metodo Recursivo ---\n");
        if (valid_path_recursiva(maze, visited, start_row, start_col, ROW, COL)) {
            print_maze(maze, ROW, COL);
        }

        for(int i=0; i<ROW; i++){
            for(int j=0; j<COL; j++){
                visited[i][j] = 0; // Reseta visitados
                if(maze[i][j] == 'x') maze[i][j] = ' '; // Limpa caminho
            }
        }

        printf("\n--- Metodo Interativo ---\n");
        if (valid_path_interativa(maze, visited, start_row, start_col, ROW, COL)) {
            print_maze(maze, ROW, COL);
        }
        else {
            printf("\nNao existe saida!");
        }
    }
    free_matrix(visited, ROW);
    return 0;
}

void find_E(char maze[ROW][COL],int row, int col, int *start_row, int *start_col) {
    for (int i = 0; i < row; i++) {
        for (int j=0; j < col; j++) {
            if (maze[i][j] == 'E') {
                *start_row = i;
                *start_col = j;
                return;
            }
        }
    }
}

int valid_path_recursiva(char maze[ROW][COL], int **visited, int row, int col, int num_row, int num_col) {
    int direction[8][2] = {
        {-1, 0}, // up
        {1, 0},  // down
        {0, -1}, // left
        {0, 1},  // right

        {-1, -1},// left upper  diagonal
        {-1, 1}, // right uper diagonal
        {1, -1},  // left lower diagonal
        {1, 1}   // right lower diagonal
    };

    if (maze[row][col]=='S') {
        // printf("%d %d", row, col);
        return 1;
    }

    visited[row][col] = 1;


    for (int i = 0; i < 8; i++) {

        int new_row = row + direction[i][0];
        int new_col = col + direction[i][1];

        if(VALID){
           if (valid_path_recursiva(maze, visited, new_row, new_col, num_row, num_col)) {
                // Se achou a saída lá na frente, imprime este passo
                if(maze[row][col]!='E') {
                    maze[row][col]='x';
                }
                return 1;            
           }
        }
    }

    return 0;
}

int valid_path_interativa(char maze[ROW][COL], int **visited, int row, int col, int num_row, int num_col) {
    
    int max = COL*ROW;
    int **selected_dir = create_matrix(max, 2);
    int first = -1;
    int direction[8][2] = {
        {-1, 0}, // up
        {1, 0},  // down
        {0, -1}, // left
        {0, 1},  // right
        {-1, -1},// left upper  diagonal
        {-1, 1}, // right uper diagonal
        {1, -1},  // left lower diagonal
        {1, 1}   // right lower diagonal
    };

    //colocando o inicio na matriz da direções
    first++;
    selected_dir[first][0] = row;
    selected_dir[first][1] = col;
    visited[row][col] = 1;

    //Loop infinito para a chegar até a conclusão
    while (first > -1) {

        int curr_row = selected_dir[first][0];
        int curr_col = selected_dir[first][1];

        //Vendo se ja achou o S
        if (maze[curr_row][curr_col]=='S') {
            free_matrix(selected_dir, max);
            return 1;
        }
        
        //Variável para n ter que repetir o mar de if feioso
        int moved = 0;
        
        //precisa ser um for, ele vai rodar até achar uma que encontre, ou simplesmente vai voltar uma posição!!!!
        for (int i = 0; i < 8; i++) {
            
            int new_row = curr_row + direction[i][0];
            int new_col = curr_col + direction[i][1];
            
            if(VALID){
                
                //Empilha 
                first++;
                selected_dir[first][0] = new_row;
                selected_dir[first][1] = new_col;

                visited[new_row][new_col] = 1;

                    if(maze[new_row][new_col]!='E' && maze[new_row][new_col]!='S') {
                        maze[new_row][new_col]='x';
                    }

                moved = 1;
                break; // Se achou o código sinaliza com o moved, e ele segue o loop até achar o S
            }
        }
        
        if (!(moved)) { //Se o acabou e não entrou no if, ele n achou nenhuma posição válida
            // Remove marcação visual
            if(maze[curr_row][curr_col] == 'x') {
                maze[curr_row][curr_col] = ' ';
            }
            first--; // Desempilha
        }
    }
    free_matrix(selected_dir, max);
    return 0;
}

int **create_matrix(int row, int col) {
    int **mat = NULL;
    mat = (int**)malloc(row * sizeof(int *));
    if (mat == NULL) return NULL;

    for (int i=0; i<row; i++) {
        mat[i] = (int*)malloc(col*sizeof(int));
        if (mat[i]==NULL) {
            free_matrix(mat, i);
            return NULL;
        }
    }
    return mat;
}

void free_matrix(int **mat, int row) {
    if (mat == NULL) return;
    for (int i = 0; i<row; i++){
        free(mat[i]);
    }
    free(mat);
}

void print_maze(char maze[ROW][COL], int row, int col) {
    for (int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            char value = maze[i][j];
            
            if (value == '*'){
                printf("||");
            }
            else if (value == 'x') {
                printf("oo");
            }
            else if (value == 'E' || value == 'S') {
                printf("%c%c", value, value);
            }
            else {
                printf("  ");
            }
            
        }
        printf("\n");
    }
}
