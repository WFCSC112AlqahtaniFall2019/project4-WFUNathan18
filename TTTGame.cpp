/* Class: TicTacToe
 * Author: [FINISH ME]
 * Description: A program that implements the game Tic-Tac-Toe
 */

#include <iostream>
#include <ctime>
#include "TicTacToe.h"
using namespace std;

int main() {
    int playerNum;
    int inputRow, inputCol;
    char playAgain = 'y';

    // FINISH ME
    while (playAgain == 'y') {
        cout << "Would you like to play a one-player game against me or a two-player game with a friend/enemy? (input 1 or 2) ";
        cin >> playerNum;

        if (playerNum == 1) { // Message for one-player game
            cout << "Very well, you'll be Player 1 and the computer will be Player 2" << endl;
        }

        TicTacToe().initializeBoard();

        if (playerNum == 1) { // For one-player game against computer using randomly generated numbers
            while (!TicTacToe().checkForWin() && !TicTacToe().isBoardFull()) {
                TicTacToe().printBoard();

                cout << "Player " << TicTacToe().getCurrentPlayerNumber() << "'s turn" << endl;
                if (TicTacToe().getCurrentPlayerNumber() == 1) {
                    cout << "Please input the coordinates of where you would like to place the mark ";
                    cin >> inputRow >> inputCol;
                    TicTacToe().placeMark(inputRow, inputCol);
                }

                else if (TicTacToe().getCurrentPlayerNumber() == 2) {
                    srand(time(0));
                    inputRow = ((rand() % 3) + 1);
                    inputCol = ((rand() % 3) + 1);
                    TicTacToe().placeMark(inputRow, inputCol);
                }

                TicTacToe().changePlayer();
            }
        }

        else if (playerNum == 2) { // For two-player game

        }

        if (TicTacToe().isBoardFull()) {
            cout << "The board is now full. Nobody wins. And more importantly, everyone loses" << endl;
            cout << "Play again? (y/n) ";
            cin >> playAgain;
        }
    }
    return 0;
}