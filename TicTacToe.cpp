#include <iostream>
#include "TicTacToe.h"

using namespace std;

// Constructor to initialize the board and set the starting player
TicTacToe::TicTacToe() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    currentPlayer = 'X'; // Starting player
}

// Function to draw the board
void TicTacToe::drawBoard() {
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

// Function to check if a player has won
bool TicTacToe::checkWin() {
    for (int i = 0; i < 3; i++) {
        // Check rows and columns for win
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }
    // Check diagonals for win
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }
    return false;
}

// Function to next move
bool TicTacToe::makeMove(int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = currentPlayer;
        return true;
    }
    else {
        cout << "Invalid move. Try again.\n";
        return false;
    }
}

// switching player
void TicTacToe::switchPlayer() {
    if (currentPlayer == 'X') {
        currentPlayer = 'O';
    }
    else {
        currentPlayer = 'X';
    }

}

// Function check for draw
bool TicTacToe::isDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false; // At least one cell is empty
            }
        }
    }
    return true; // All cells are filled
}

// Main game loop
void TicTacToe::playGame() {
    cout << "Welcome to Tic-Tac-Toe!\n";
    while (true) {
        drawBoard();
        int row, col;
        cout << "Player " << currentPlayer << ", enter row (1-3) and column (1-3): ";
        cin >> row >> col;

        if (makeMove(row-1, col-1)) {
            if (checkWin()) {
                drawBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }
            else if (isDraw()) {
                drawBoard();
                cout << "It's a draw!\n";
                break;
            }
            switchPlayer();
        }
    }
}
