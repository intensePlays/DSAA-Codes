#include <iostream>
using namespace std;

const int N = 4; 

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int board[N][N], int row, int col) {
    // Check left side of the row
    for (int i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    // Check upper diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check lower diagonal
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

bool solveNQueens(int board[N][N], int col) {
    if (col >= N) {
        printBoard(board);
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            res = solveNQueens(board, col + 1) || res;
            board[i][col] = 0;
        }
    }
    return res;
}

int main() {
    int board[N][N] = {0};

    if (!solveNQueens(board, 0)) {
        cout << "No solution exists for N = " << N << endl;
    }

    return 0;
}