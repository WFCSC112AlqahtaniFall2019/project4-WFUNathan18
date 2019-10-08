/* Class: TicTacToe
 * Author: Nathan Maynard
 * Description: A program that implements the game Tic-Tac-Toe
 */

#include <iostream>
#include <ctime>
#include "TicTacToe.h"
using namespace std;

int main() {
    TicTacToe board;
    int playerNum;
    int inputRow, inputCol;
    char playAgain = 'y';

    // FINISH ME
    while (playAgain == 'y') {
        cout << "Would you like to play a one-player game against me or a two-player game with a friend/enemy? (input 1 or 2) " << endl;
        cin >> playerNum;

        if (playerNum == 1) { // Message for one-player game
            cout << endl << "Very well, you'll be Player 1 and the computer will be Player 2" << endl;
        }

        board.initializeBoard();


        if (playerNum == 1) { // For one-player game against computer using randomly generated numbers
            while (!board.checkForWin() && !board.isBoardFull()) {
                board.printBoard();

                cout << "Player " << board.getCurrentPlayerNumber() << "'s turn" << endl;
                if (board.getCurrentPlayerNumber() == 1) { // Player's Turn
                    cout << "Please input the coordinates of where you would like to place the mark " << endl;
                    cin >> inputRow >> inputCol;
                    board.placeMark(inputRow, inputCol);
                }

                else if (board.getCurrentPlayerNumber() == 2) { // Computer's Turn
                    srand(time(0));
                    inputRow = (rand() % 3);
                    inputCol = (rand() % 3);
                    board.placeMark(inputRow, inputCol);
                }

                if (board.checkForWin()) { // Check for win
                    cout << "Player " << board.getCurrentPlayerNumber() << " wins!" << endl;
                    cout << "Play again? (y/n)" << endl;
                    cin >> playAgain;
                }

                board.changePlayer(); // Change Turn

                if (board.checkForWin() && (board.getCurrentPlayerNumber() == 2)) {
                    board.changePlayer(); // Intentionally change player so that when a new game starts, it will be Player 1's turn first
                }

            }
        }

        else if (playerNum == 2) { // For two-player game
            while (!board.checkForWin() && !board.isBoardFull()) {
                board.printBoard();

                cout << "Player " << board.getCurrentPlayerNumber() << "'s turn" << endl;
                cout << "Please input the coordinates of where you would like to place the mark " << endl;
                cin >> inputRow >> inputCol;
                board.placeMark(inputRow, inputCol);

                if (board.checkForWin()) { // If a player wins
                    cout << "Player " << board.getCurrentPlayerNumber() << " wins!" << endl;
                    cout << "Play again? (y/n)" << endl;
                    cin >> playAgain;
                }

                board.changePlayer(); // Change Turn

                if (board.checkForWin() && (board.getCurrentPlayerNumber() == 2)) {
                    board.changePlayer(); // Intentionally change player so that when a new game starts, it will be Player 1's turn first
                }
            }
        }

        if (board.isBoardFull()) { // If the board is filled
            cout << "The board is now full. Nobody wins. And more importantly, everyone loses" << endl;
            cout << "Play again? (y/n)" << endl;
            cin >> playAgain;
        }
    }

    cout << "Goodbye!" << endl;

    return 0;
}