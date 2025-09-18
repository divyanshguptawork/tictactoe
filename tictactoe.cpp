#include <iostream>
#include <map>
using namespace std;

int main() {
    // Scoreboard
    int xWins = 0, oWins = 0, ties = 0;

    while (true) {
        // Create the board
        char board[3][3];
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = ' ';

        char currentPlayer = 'X';
        bool gameOver = false;

        while (!gameOver) {
            // Print the board
            cout << "\n  1   2   3\n";
            char rows[3] = {'a', 'b', 'c'};
            for (int i = 0; i < 3; i++) {
                cout << rows[i] << " ";
                for (int j = 0; j < 3; j++) {
                    cout << board[i][j];
                    if (j < 2) cout << " | ";
                }
                cout << "\n";
                if (i < 2) cout << "  ---------\n";
            }

            // Ask for a move
            cout << "Player " << currentPlayer << ", enter your move (e.g., a1, b3): ";
            string move;
            cin >> move;

            int row = -1, col = -1;
            if (move.size() == 2) {
                if (move[0] == 'a' || move[0] == 'A') row = 0;
                if (move[0] == 'b' || move[0] == 'B') row = 1;
                if (move[0] == 'c' || move[0] == 'C') row = 2;
                if (move[1] == '1') col = 0;
                if (move[1] == '2') col = 1;
                if (move[1] == '3') col = 2;
            }

            if (row == -1 || col == -1) {
                cout << "Invalid move format! Try again.\n";
                continue;
            }
            if (board[row][col] != ' ') {
                cout << "That spot is already taken! Try again.\n";
                continue;
            }

            // Place the move
            board[row][col] = currentPlayer;

            // Check winner
            bool win = false;
            for (int i = 0; i < 3; i++) {
                if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) win = true;
                if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) win = true;
            }
            if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) win = true;
            if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) win = true;

            if (win) {
                cout << "Player " << currentPlayer << " wins!\n";
                if (currentPlayer == 'X') xWins++;
                else oWins++;
                gameOver = true;
            }

            // Check tie
            bool full = true;
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    if (board[i][j] == ' ') full = false;

            if (!win && full) {
                cout << "It's a tie!\n";
                ties++;
                gameOver = true;
            }

            // Switch players
            if (!gameOver) {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        // Show scoreboard
        cout << "\nScoreboard:\n";
        cout << "X Wins: " << xWins << "\n";
        cout << "O Wins: " << oWins << "\n";
        cout << "Ties:   " << ties << "\n";

        // Play again?
        cout << "\nPlay again? (y/n): ";
        char again;
        cin >> again;
        if (again != 'y' && again != 'Y') {
            cout << "Thanks for playing!\n";
            break;
        }
    }

    return 0;
}
