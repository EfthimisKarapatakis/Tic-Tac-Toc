#include <stdio.h>
#include <stdlib.h>

// 3x3 Tic-Tac-Toe board
char TABLE[3][3] = { {' ', ' ', ' '},
                    {' ', ' ', ' '},
                    {' ', ' ', ' '} };

// Array of available moves
int moves[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int move_count = 9;  // Total available moves

// Function to check if the move is valid and remove it from the options
int is_valid_move(int choice) {
    for (int i = 0; i < move_count; i++) {
        if (moves[i] == choice) {
            // Remove the move from the available list by shifting the rest of the moves
            for (int j = i; j < move_count - 1; j++) {
                moves[j] = moves[j + 1];
            }
            move_count--; // Decrease the count of available moves
            return 1;  // Valid move
        }
    }
    return 0;  // Invalid move
}

// Function to display the current game board
void show_table() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", TABLE[i][j]);
            if (j < 2) printf("|"); // Print column separators
        }
        if (i < 2) printf("\n---|---|---\n"); // Print row separators
    }
    printf("\n");
}

// Function to check for a winner
char check_winner() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (TABLE[i][0] == TABLE[i][1] && TABLE[i][1] == TABLE[i][2]) {
            return TABLE[i][0]; // Return 'X' or 'O'
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (TABLE[0][i] == TABLE[1][i] && TABLE[1][i] == TABLE[2][i]) {
            return TABLE[0][i]; // Return 'X' or 'O'
        }
    }

    // Check diagonals
    if (TABLE[0][0] == TABLE[1][1] && TABLE[1][1] == TABLE[2][2]) {
        return TABLE[0][0]; // Return 'X' or 'O'
    }
    if (TABLE[0][2] == TABLE[1][1] && TABLE[1][1] == TABLE[2][0]) {
        return TABLE[0][2]; // Return 'X' or 'O'
    }

    return ' '; // No winner yet
}

// Function to make a move for player1 (X)
void player1() {
    int choice1;
    int valid = 0;

    // Loop until the player makes a valid move
    while (!valid) {
        printf("Player 1 (X), choose a block: ");
        scanf("%d", &choice1);

        // Check if the move is valid
        if (is_valid_move(choice1)) {
            switch (choice1) {
                case 1: TABLE[0][0] = 'X'; break;
                case 2: TABLE[0][1] = 'X'; break;
                case 3: TABLE[0][2] = 'X'; break;
                case 4: TABLE[1][0] = 'X'; break;
                case 5: TABLE[1][1] = 'X'; break;
                case 6: TABLE[1][2] = 'X'; break;
                case 7: TABLE[2][0] = 'X'; break;
                case 8: TABLE[2][1] = 'X'; break;
                case 9: TABLE[2][2] = 'X'; break;
            }
            valid = 1; // Move is valid
        } else {
            printf("Invalid input. Choose a valid block!\n");
        }
    }
}

// Function to make a move for player2 (O)
void player2() {
    int choice2;
    int valid = 0;

    // Loop until the player makes a valid move
    while (!valid) {
        printf("Player 2 (O), choose a block: ");
        scanf("%d", &choice2);

        // Check if the move is valid
        if (is_valid_move(choice2)) {
            switch (choice2) {
                case 1: TABLE[0][0] = 'O'; break;
                case 2: TABLE[0][1] = 'O'; break;
                case 3: TABLE[0][2] = 'O'; break;
                case 4: TABLE[1][0] = 'O'; break;
                case 5: TABLE[1][1] = 'O'; break;
                case 6: TABLE[1][2] = 'O'; break;
                case 7: TABLE[2][0] = 'O'; break;
                case 8: TABLE[2][1] = 'O'; break;
                case 9: TABLE[2][2] = 'O'; break;
            }
            valid = 1; // Move is valid
        } else {
            printf("Invalid input. Choose a valid block!\n");
        }
    }
}

// Main game loop
int main() {
    start:
    char choice;
    int moves_played = 0; // To keep track of the number of moves made
    char winner = ' '; // Variable to track the winner

    while (moves_played < 9) { // Maximum 9 moves in a tic-tac-toe game
        show_table();   // Display the board

        // Alternate turns between player 1 and player 2
        if (moves_played % 2 == 0) {
            player1();
        } else {
            player2();
        }

        // Check for a winner after each move
        winner = check_winner();
        if (winner != ' ') {
            show_table(); // Show the final state of the board
            printf("Player %c wins!\n", winner);

            // Clear input buffer to avoid skipping the next input
            while ((getchar()) != '\n');  // Clear newline character
            printf("Do you want to play again? (y/n): ");
            scanf("%c", &choice);
            if (choice == 'y') {
                // Reset the board and game variables for a new game
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        TABLE[i][j] = ' '; // Reset the board
                    }
                }
                move_count = 9;  // Reset the available move count
                for (int i = 0; i < 9; i++) {
                    moves[i] = i + 1;  // Reset the available moves
                }
                moves_played = 0;  // Reset move counter
                goto start; // Restart the game
            } else {
                return 0; // Exit the game
            }
        }

        moves_played++;
    }

    show_table(); // Show the final state of the board
    printf("It's a draw!\n");

    // Clear input buffer to avoid skipping the next input
    while ((getchar()) != '\n');  // Clear newline character
    printf("Do you want to play again? (y/n): ");
    scanf("%c", &choice);
    if (choice == 'y') {
        // Reset the board and game variables for a new game
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                TABLE[i][j] = ' '; // Reset the board
            }
        }
        move_count = 9;  // Reset the available move count
        for (int i = 0; i < 9; i++) {
            moves[i] = i + 1;  // Reset the available moves
        }
        moves_played = 0;  // Reset move counter
        goto start; // Restart the game
    }

    return 0;
}
