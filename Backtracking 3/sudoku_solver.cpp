#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == ch) return false;
        if (board[i][col] == ch) return false;
        int subRow = 3 * (row / 3) + i / 3;
        int subCol = 3 * (col / 3) + i % 3;
        if (board[subRow][subCol] == ch) return false;
    }
    return true;
}

bool solve(vector<vector<char>>& board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == '.' || board[row][col] == '0') {
                for (char ch = '1'; ch <= '9'; ch++) {
                    if (isValid(board, row, col, ch)) {
                        board[row][col] = ch;

                        if (solve(board))
                            return true;

                        board[row][col] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void printBoard(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<char>> board(9, vector<char>(9));
    cout << "Enter Sudoku board (use 0 or . for empty cells):\n";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char c;
            cin >> c;
            board[i][j] = c;
        }
    }

    if (solve(board)) {
        cout << "\nSolved Sudoku:\n";
        printBoard(board);
    } else {
        cout << "No solution exists!\n";
    }

    return 0;
}
