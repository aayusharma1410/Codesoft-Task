#include <iostream>
using namespace std;

// The game board
char board[3][3];

// Function to display the game board
void displayBoard() {
    cout << " 1 | 2 | 3" << endl;
    cout << " ---------" << endl;
    cout << " 4 | 5 | 6" << endl;
    cout << " ---------" << endl;
    cout << " 7 | 8 | 9" << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) {
                cout << "|";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << " ---------" << endl;
        }
    }
}

// Function to check if a player has won
bool checkWin(char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to check if the game is a draw
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char currentPlayer = 'X';
    int move;

    // Initialize the game board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }

    while (true) {
        displayBoard();

        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        // Convert move to board coordinates
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        // Check if the move is valid
        if (board[row][col] != ' ') {
            cout << "Invalid move, try again." << endl;
            continue;
        }

        // Update the game board
        board[row][col] = currentPlayer;

        // Check if the current player has won
        if (checkWin(currentPlayer)) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        // Check if the game is a draw
        if (checkDraw()) {
            displayBoard();
            cout << "It's a draw!" << endl;
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    cout << "Play again? (y/n): ";
    char response;
    cin >> response;

    if (response == 'y') {
        main();
    }

    return 0;
}