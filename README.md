#  C Programming Studies

A personal repository documenting my journey learning the **C programming language** as a Computer Science student at UFMA.

This collection includes mini-games, data structure implementations, pointer exercises, and algorithmic solutions developed for university courses and personal practice.

> *Note: The source code comments and variable names are originally in Portuguese (PT-BR), preserving the context of the academic assignments.*

##  Repository Contents

The projects are organized into the following categories:

###  Mini-Games
Simple console-based games to practice logic and control flow.
- **Tic-Tac-Toe (`tic_tac_toe.c`):** Classic implementation of the game with win/loss logic.
- **Maze Solver (`labirinto.c`):** Algorithms to navigate and solve matrix-based mazes.

###  Algorithms & Fundamentals
Core concepts of programming.
- **Pointers & Memory:** Exercises focused on memory manipulation and address arithmetic (`ponteiros.c`).
- **Matrices:** Operations like matrix multiplication and traversal (`mult_matrizes`).
- **File Handling:** Reading from and writing to local files (`guardar_manipular_dados.c`).

###  Academic Reviews
- **Exam Prep:** Solutions for "Provas" (Exams) covering various topics from the curriculum (`revisao_prova.c`, `revisao_prova2.c`).

## Project Structure

```text
C-Programming-Studies/
├── Games/          
├── Exams/
|    ├── Firts-Exam/
|    └── Second-Exam/       
└── README.md
```

##  How to Compile and Run

You can compile any of these files using a standard C compiler like GCC.


**Example (Tic-Tac-Toe):**
```bash
# Compile
gcc Games/tic_tac_toe.c -o tictactoe

# Run
./tictactoe
