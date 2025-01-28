#include <iostream>
#include <vector>
using namespace std;

// Function to display the board
void displayBoard(const vector<vector<char> > &board) {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << " " << board[i][j];
            if (j < 2) cout << " |";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

// Function to check if there is a winner
char checkWinner(const vector<vector<char> > &board) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];

    return ' '; // No winner yet
}

// Function to check if the board is full
bool isBoardFull(const vector<vector<char> > &board) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == ' ')
                return false;
    return true;
}

int main() {
    vector<vector<char> > board(3, vector<char>(3, ' '));
    char currentPlayer = 'O';
    char winner = ' ';

    cout << "Welcome to Tic-Tac-Toe!\n";

    while (true) {
        displayBoard(board);

        // Get the current player's move
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column, 0-based): ";
        cin >> row >> col;

        // Validate the move
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        // Make the move
        board[row][col] = currentPlayer;

        // Check for a winner
        winner = checkWinner(board);
        if (winner != ' ') {
            displayBoard(board);
            cout << "Player " << winner << " wins!\n";
            break;
        }

        // Check for a draw
        if (isBoardFull(board)) {
            displayBoard(board);
            cout << "The game is a draw!\n";
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'O') ? 'X' : 'O';
    }

    return 0;
}

