# 🎮 Tic-Tac-Toe Game

This is a simple 2-player Tic-Tac-Toe game implemented in C. The game allows two players to take turns choosing blocks on a 3x3 grid to either place an 'X' (Player 1) or 'O' (Player 2). The game checks for a winner after each turn and can also detect a draw if no more valid moves are available.

## Features

- **Player 1 vs Player 2**: Two players can play against each other.
- **Input Validation**: The game ensures that players can only make valid moves.
- **Winner Detection**: After every move, the game checks if there's a winner (either a row, column, or diagonal match).
- **Play Again Option**: Once the game finishes, players can choose to play again or exit the game.

## Files

- `tic_tac_toe.c`: The main C program for the Tic-Tac-Toe game.

## How to Compile and Run

1. **Ensure you have GCC installed**:  
   If you're using Linux or macOS, GCC is usually installed by default. On Windows, you can use MinGW.

2. **Compile the program**:
   ```bash
   gcc -o tic_tac_toe tic_tac_toe.c
