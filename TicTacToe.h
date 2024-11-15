#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe {
private:
    char board[3][3];       // Game board
    char currentPlayer;     // Current player ('X' or 'O')

public:
    // Constructor to initialize board and set the start player as x
    TicTacToe();

    // Function to draw the board
    void drawBoard();

    // Function to check if a player has won
    bool checkWin();

    // Function to make a move
    bool makeMove(int row, int col);

    // Function to switch to the other player
    void switchPlayer();

    // Function that check match is draw or not
    bool isDraw();

    // Main game loop
    void playGame();
};

#endif

