#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define TITLE printf("Player %d, it's your turn\n", current_player)
#define ERROR printf("\nError(Invalid answer)\nSelect another number(s):\n");

void play(int table[3][3], int current_player);
void init_mat(int table[3][3]);
void remade_mat (int table[3][3]);
int win(int table[3][3]);
int draw (int table[3][3]);
int restart ();

int main() {

    // Initializes the matrix with zeros
    int table[3][3] = {0};
    int current_player = 1;
    play(table, current_player);
    win(table);

}

void play(int table[3][3], int current_player) {
    while (TRUE) {
        int i=0, j=0;
    
    // Runs the game and sets the players
    while((win(table)) == (draw(table))) {
        init_mat(table);
        TITLE;
            scanf("%d %d", &i, &j);
            while (table[i][j]>=1 || i>=3 || j>=3) {
                ERROR;
                scanf("%d %d", &i, &j);
            }
            if (current_player==1) {
                table[i][j] = 1;
                current_player = 2;
            } else if (current_player==2) {
                table[i][j] =2;
                current_player = 1;
            }
    }
    // Checks if the game has a winner or is a draw, and then asks players if they want to continue 
        
        if (win(table)) {
            printf("Player %d is the winner!\n", current_player);
            if (restart()) {
                remade_mat(table);
                //the last player will choose firt
                continue;
            } else {break;}
    
        } else if (draw(table)) {
        
            printf("Draw!!");
            if (restart()) {
                remade_mat(table);
                current_player = 1;
                continue;
            } else {break;}

        }

    }
}

void init_mat(int table[3][3]) {  // Initializes the matrix
    
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }

    // Provides a better visualization of the positions
    printf("=-=-=-=-=-=\nCheat Sheet\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d%d ", i, j);
        }
        printf("\n");
    }
    printf("\n");


}

void remade_mat (int table[3][3]) { // Resets the matrix to all zeros for a new game
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            table[i][j] = 0;
        }
    }
}

int win(int table[3][3]) { 
    int i=0, j=0;
    for (; i<3; i++) {
        // line
        if (table[i][0] != 0 && table[i][0] == table[i][1] && table[i][1] == table[i][2]) {
            return TRUE;
        }
        //diagonal
        if (table[i][0] != 0 && table[i][i] == table[i+1][i+1] && table[i+1][i+1] == table[i+2][i+2]) {
            return TRUE;
        }
        
        for(; j<3; j++) {
            
            //column
            if (table[0][j] != 0 && table[0][j] == table[1][j] && table[1][j] == table[2][j]) {
                return TRUE;
            }

            //counter-diagonal
            if (table[2][0] != 0 && table[1][1]==table[2][0] && table[1][1]==table[0][2]) {
                return TRUE;
            }

        }
    }
    return FALSE;
}

int draw (int table[3][3]) {
    if (win(table)) {return FALSE;}
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (table[i][j]==0) {return FALSE;}
        }
    }
    return TRUE;
}

int restart () { // Allows the players to restart the game without having to re-run the code
    int remake=0;
    printf("Want to continue? 0(No)/1(Yes):\n");
            scanf("%d", &remake);
            while (!(remake == 0 || remake == 1)) {
                ERROR;
                printf("0(No)/1(Yes):\n");
                scanf("%d", &remake);
            }
    return remake;
}
