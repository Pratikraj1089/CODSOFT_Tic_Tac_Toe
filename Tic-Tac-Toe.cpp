#include <iostream>
#include "TicTacToe.h"

using namespace std;

int main() {
    char playAgain;

    do {
        TicTacToe game;  // Create oject of the TicTacToe class
        game.playGame();  // Start the game

        // ask for play again or exit
        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;

       

    } while (playAgain == 'Y'  || playAgain == 'y');  // If  'Y', play again

    cout << "Thank you for playing! Goodbye.\n";
    return 0;
}
